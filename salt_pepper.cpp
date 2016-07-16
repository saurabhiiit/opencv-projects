#include<iostream>
#include "opencv2/opencv.hpp"
#include <cv.h>
#include <highgui.h>

using namespace cv;
using namespace std;

int main()
{
  char c;
  Mat image = imread("scarl.jpg");
  namedWindow("My image");
  for(int i=0;i<image.rows;i++)
  {
    for(int j=0;j<image.cols;j++)
    {
      //cout<<image.type()<<endl;
      //change below two parameter for the color green and blue;
      image.at<Vec3b>(i,j)[1]=0;
      image.at<Vec3b>(i,j)[2]=0;
    }
  }
  imshow("My image",image);
  c=waitKey(0);
  if(c==27){
    cout<<"phodehoyr"<<endl;
  }
  else{
    imshow("My image",image);
    waitKey(5000);
  }
  return 0;
}
