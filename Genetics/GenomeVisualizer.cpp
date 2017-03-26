#include "GenomeVisualizer.h"

cv::Mat GenomeVisualizer::visualize(GenomePtr genome){
    int width = genome->chromosomes.size() * geneWidth;
    int height = 0;
    for (const auto chromosome : genome->chromosomes){
        height = std::max(height, (int)chromosome->genes.size());
    }
    height *= geneHeight;
    
    cv::Mat vis = cv::Mat::zeros(height, width, CV_8UC3);
    for (size_t x = 0; x < genome->chromosomes.size(); x++){
        for (size_t y = 0; y < genome->chromosomes[x]->genes.size(); y++){
            const Gene &gene = genome->chromosomes[x]->genes[y];
            int posX = x * geneWidth;
            int posY = y * geneHeight;
            cv::rectangle(vis, cv::Rect(posX, posY, geneWidth / 6, geneHeight), getAllelColor(gene.allel1));
            cv::rectangle(vis, cv::Rect(posX + geneWidth - geneWidth / 6, posY, geneWidth / 6, geneHeight), getAllelColor(gene.allel2));
            cv::putText(vis, std::to_string(gene.type), cv::Point(posX, posY), CV_FONT_NORMAL, 0.7, cv::Scalar(255, 0, 0), 2);
        }
    }
    return vis;
}

cv::Scalar GenomeVisualizer::getAllelColor(float allel){
    if (allel > 0){
        return cv::Scalar(0, allel*255, 0);
    }else{
        return cv::Scalar(0, 0, -allel*255);
    }
}
