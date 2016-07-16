#include<iostream>
#include "opencv2/opencv.hpp"
#include <cv.h>
#include <highgui.h>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

Mat src; Mat src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);
Mat drawing;
Mat pframe;
Mat pgray_frame;
Mat diff;
int flag=0;
/// Function header
void thresh_callback(int, void* );


int main()
{
  VideoCapture capture("vid1.avi");
  if(!capture.isOpened())
  return -1;
  double rate = capture.get(CV_CAP_PROP_FPS);
  //cout<<rate<<endl;
  bool stop(false);
  char* source_window = "Source";
  namedWindow( source_window, WINDOW_AUTOSIZE );
  int delay = 1000/rate;

  while(!stop)
  {
    if(!capture.read(src))
    break;
    capture>>pframe;
    cvtColor( src, src_gray, COLOR_BGR2GRAY );
    GaussianBlur( src_gray, src_gray, Size(21,21),0 );
    cvtColor(pframe, pgray_frame, CV_RGB2GRAY);
    absdiff(src_gray,pgray_frame,diff);
    thresh_callback( 0, 0 );
    waitKey(0);

  }
  return(0);
}

/** @function thresh_callback */
void thresh_callback(int, void* )
{
  Mat threshold_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  /// Detect edges using Threshold
  threshold( src_gray, threshold_output, thresh, 255, THRESH_BINARY );
  /// Find contours
  for(int y=0;y<src.rows;y++)
  {
    for(int x=0;x<src.cols;x++)
    {
      if(int(diff.at<uchar>(Point(x,y)))==0)
      flag=1;
      else
      flag=0;
        flag=0;
    }
    }
         if(flag==0)
  findContours( threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
  /// Approximate contours to polygons + get bounding rects and circles
  vector<vector<Point> > contours_poly( contours.size() );
  vector<Rect> boundRect( contours.size() );


  for( int i = 0; i < contours.size(); i++ )
     { approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
       boundRect[i] = boundingRect( Mat(contours_poly[i]) );
     }


  /// Draw polygonal contour + bonding rects + circles
  drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
  for( int i = 0; i< contours.size(); i++ )
     {
       if(contourArea(contours[i])>400)
       {
       Scalar color = Scalar( rng.uniform(0, 0), rng.uniform(255,255), rng.uniform(0,0) );
    //   drawContours( drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
       rectangle( src, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );
     }
   }

  imshow("Source",src);
}
