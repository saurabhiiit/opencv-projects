#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

Mat src; Mat src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

/// Function header
void thresh_callback(int, void* );

/** @function main */
int main( )
{
  /// Load source image and convert it to gray
  src = imread( "scarl.jpg");

  /// Convert image to gray and blur it
  cvtColor( src, src_gray, COLOR_BGR2GRAY );
  blur( src_gray, src_gray, Size(3,3) );

  /// Create Window
  char* source_window = "Source";
  namedWindow( source_window, WINDOW_AUTOSIZE );

    createTrackbar( " Threshold:", "Source", &thresh, max_thresh, thresh_callback );
  thresh_callback( 0, 0 );
  imshow( source_window, src );
  waitKey(0);
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
  findContours( threshold_output, contours, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE, Point(0, 0) );


  /// Approximate contours to polygons + get bounding rects and circles
  vector<vector<Point> > contours_poly( contours.size() );
  vector<Rect> boundRect( contours.size() );

/*for(int i=0; i<contours.size();i++)
{
  int maxx=contours[i][0].x;
  int maxy=contours[i][0].y;
  int minx=contours[i][0].x;
  int miny=contours[i][0].x;
  for(int j=0;j<contours[i].size();j++)
  {
    if(contours[i][j].x>maxx)
    {
      maxx=contours[i][j];
    }
    if(contours[i][j].x<minx)
    {
      minx=countours[i][j];
    }
    if(countours[i][j].y>maxy)
    {
      maxy=contours[i][j];
    }
    if(contours[i][j].y<miny)
    {
      miny=contours[i][j];
    }
  }
}
*/
  for( int i = 0; i < contours.size(); i++ )
     {
       approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
       boundRect[i] = boundingRect( Mat(contours[i]) );
     }

  /// Draw polygonal contour + bonding rects + circles
  Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
  for( int i = 0; i< contours.size(); i++ )
     {
       if(contourArea(contours[i])>1000)
       {
       Scalar color = Scalar( rng.uniform(0, 0), rng.uniform(255,255), rng.uniform(0,0) );
      // drawContours( drawing, contours_poly, 3, color, 1, 8, vector<Vec4i>(), 0, Point() );
       rectangle( src, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );
    //   cout<< contours[i]<<endl;
     }
   }

}
