#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

Mat image;

// void salt_pep()
// {
//
//   for(int i=0;i<image.rows;i++)
//   {
//     for(int j=0;j<image.cols;j++)
//     {
//       //cout<<image.type()<<endl;
//       //change below two parameter for the color green and blue;
//       image.at<Vec3b>(i,j)[1]=0;
//       image.at<Vec3b>(i,j)[2]=0;
//     }
//   }
// }
int main()
{
  char c;
  image = imread("messi.jpg");
//  cout<<image.channels<<endl;
  //salt_pep();
  namedWindow("Image",WINDOW_AUTOSIZE);
  cout<<image.type()<<endl;
  cout<<image.size()<<endl;
  cout<<image.rows<<endl;
  cout<<image.cols<<endl;
  cout<<image.at<Vec3b>(50,44)<<endl;
  cout<<image.at<Vec3b>(51,44)<<endl;
  if(image.at<Vec3b>(50,44)==image.at<Vec3b>(51,44))
  cout<<"cong"<<endl;


  imshow("Image",image);
  c=waitKey(0);
  if(c==27)
  {
    cout<<"phodehoyr"<<endl;
  }
  return 0;
}
