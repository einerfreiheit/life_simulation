#include "SimpleVideoRecord.h"
#include "../SimulationData.h"
#include <iostream>
SimpleVideoRecord::SimpleVideoRecord()
{
  cv::Mat output;
  output = cv::Mat::zeros (
             cv::Size ( SimulationData::getInst()->mapHeightToSet,
                        SimulationData::getInst()->mapWidthToSet ), CV_8UC3 );
  writer.open (SimulationData::getInst()->outputPath +"./output.avi", CV_FOURCC ( 'M', 'J', 'P', 'G' ), 25.0,
                output.size(), true );
}

SimpleVideoRecord::~SimpleVideoRecord()
{
}
void SimpleVideoRecord::update (const  cv::Mat* visualization )
{
  cv::Mat output;
  cv::resize ( *visualization, output, visualization->size(), 1, 1,
               cv::INTER_NEAREST );

  writer.write ( output );

}
void SimpleVideoRecord::update(World *world){
 return; 
  
}

