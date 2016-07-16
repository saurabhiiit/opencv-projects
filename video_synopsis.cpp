#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include <cv.h>
#include <highgui.h>

using namespace cv;
using namespace std;

int main()
{
  VideoCapture capture("vid1.avi");
  int flag=0;
  if(!capture.isOpened())
  return -1;
  double rate = capture.get(CV_CAP_PROP_FPS);
  //cout<<rate<<endl;
  bool stop(false);
  Mat frame;
  Mat pframe;
  Mat diff;
  Mat gray_frame;
  Mat pgray_frame;

  namedWindow("Extracted Frame",WINDOW_NORMAL);
  int delay = 1000/rate;
  while(!stop)
  {
    if(!capture.read(frame))
    break;
    //cout<<rate<<endl;
    //Mat diff = frame-pframe;
    // if(countNonZero(frame-pframe) <)
    // {
    //   flag=1;
    // }
    // else
    //   flag=0;
    // if(flag==0)
    capture>>pframe;
    cvtColor(frame, gray_frame, CV_RGB2GRAY);
    cvtColor(pframe, pgray_frame, CV_RGB2GRAY);
    absdiff(gray_frame,pgray_frame,diff);
    //imshow("Extracted Frame",diff);
    // waitKey(0);
       for(int y=0;y<frame.rows;y++)
       {
         for(int x=0;x<frame.cols;x++)
         {
      //     //cout<<image.type()<<endl;
      //     //change below two parameter for the color green and blue;
      //     if(diff.at<uchar>(x,y)==pframe.at<Vec3b>(i,j))
    //  cout<<int(diff.at<uchar>(x,y))<<endl;
      if(int(diff.at<uchar>(Point(x,y)))==0)
      flag=1;
      else
      flag=0;
      //     {
      //       flag=1;
      //     }
      //     else
      //     flag=0;
    }
         }
         if(flag==0)
       imshow("Extracted Frame",frame);

       waitKey(delay-8);
      // frame.copyTo(pframe);

/*
      for(int i=0;i<frame.rows;i++)
      {
         for(int j=0;j<frame.cols;j++)
         if(diff.at<uchar>(Point(i,j))==0)
         flag=1;
         else
         flag=0;
      if(flag==0)
    imshow("Extracted Frame",frame);


    frame.copyTo(pframe);
    if(waitKey(delay)>=0)
    stop =true;
  }
  capture.release();
}
*/
}
capture.release();
return 0;
}
