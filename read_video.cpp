#include<iostream>
#include "opencv2/opencv.hpp"
#include <cv.h>
#include <highgui.h>

using namespace cv;
using namespace std;

int main()
{
  VideoCapture capture("vid1.avi");
  if(!capture.isOpened())
  return -1;
  double rate = capture.get(CV_CAP_PROP_FPS);
  //cout<<rate<<endl;
  bool stop(false);
  Mat frame;
  namedWindow("Extracted Frame");
  int delay = 1000/rate;
  while(!stop)
  {
    if(!capture.read(frame))
    break;
    //cout<<rate<<endl;
    imshow("Extracted Frame",frame);
    if(waitKey(delay)>=0)
    stop =true;
  }
  capture.release();
}
