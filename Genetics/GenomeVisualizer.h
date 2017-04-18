#ifndef GENOMEVISUALIZER_H
#define GENOMEVISUALIZER_H

#include "Genome.h"
#include <opencv2/opencv.hpp>

class GenomeVisualizer
{
public:
    static cv::Mat visualize ( GenomePtr genome );

private:
    static cv::Scalar getAllelColor ( float allel );
    static void drawGene ( const Gene &gene, cv::Mat &vis, int posX, int posY );

    static const int geneWidth = 40;
    static const int geneHeight = 20;
    static const int chromosomesOffset = 10;
};

#endif // GENOMEVISUALIZER_H
