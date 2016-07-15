// This program will display the image

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
  char c;
  Mat image = imread("clark.jpg");
  namedWindow("My image");
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
