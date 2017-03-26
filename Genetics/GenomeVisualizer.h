#ifndef GENOMEVISUALIZER_H
#define GENOMEVISUALIZER_H

#include "Genome.h"
#include <opencv2/opencv.hpp>

class GenomeVisualizer
{
public:
    static cv::Mat visualize(GenomePtr genome);
    
private:
    static cv::Scalar getAllelColor(float allel);
    
    static const int geneWidth = 40;
    static const int geneHeight = 20;
};

#endif // GENOMEVISUALIZER_H
