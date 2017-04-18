#include "GenomeVisualizer.h"

cv::Mat GenomeVisualizer::visualize ( GenomePtr genome ) {
    int width = genome->chromosomes.size() * ( geneWidth + chromosomesOffset ) - chromosomesOffset;
    int height = 0;
    for ( const auto chromosome : genome->chromosomes ) {
        height = std::max ( height, ( int ) chromosome->genes.size() );
        }
    height *= geneHeight;

    cv::Mat vis = cv::Mat::zeros ( height, width, CV_8UC3 );
    for ( size_t x = 0; x < genome->chromosomes.size(); x++ ) {
        for ( size_t y = 0; y < genome->chromosomes[x]->genes.size(); y++ ) {
            const Gene &gene = genome->chromosomes[x]->genes[y];
            int posX = x * ( geneWidth + chromosomesOffset );
            int posY = y * geneHeight;
            drawGene ( gene, vis, posX, posY );
            }
        }
    return vis;
    }


void GenomeVisualizer::drawGene ( const Gene &gene, cv::Mat &vis, int posX, int posY ) {
    cv::rectangle ( vis, cv::Rect ( posX, posY, geneWidth / 6, geneHeight ), getAllelColor ( gene.allel1 ), -1 );
    cv::rectangle ( vis, cv::Rect ( posX + geneWidth - geneWidth / 6, posY, geneWidth / 6, geneHeight ), getAllelColor ( gene.allel2 ), -1 );
    cv::putText ( vis, std::to_string ( gene.type ), cv::Point ( posX + geneWidth/6, posY + geneHeight - 2 ), CV_FONT_NORMAL, 0.6, cv::Scalar ( 255, 0, 0 ), 2 );
    }

cv::Scalar GenomeVisualizer::getAllelColor ( float allel ) {
    if ( allel > 0 ) {
        return cv::Scalar ( 0, allel*255, 0 );
        }
    else {
        return cv::Scalar ( 0, 0, -allel*255 );
        }
    }
