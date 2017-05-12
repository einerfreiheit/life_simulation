#include "SimpleDisplay.h"

SimpleDisplay::SimpleDisplay()
{

}

SimpleDisplay::~SimpleDisplay()
{
}
void SimpleDisplay::update ( const cv::Mat* visualization )
{

  cv::namedWindow ( "123", CV_WINDOW_NORMAL );
  cv::resizeWindow ( "123", 640, 480 );
  cv::imshow ( "123", *visualization );


  cv::waitKey ( 10 );
}
void SimpleDisplay::update (World *world){
 return; 
  
}
