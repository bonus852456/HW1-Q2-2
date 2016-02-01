// 

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main(){

	cv::Mat image;
	image = cv::imread("../image/night.jpg");   // Read the file
	uchar *pixptr;
	if(image.empty()){
		std::cout << "圖片不見了QQ";
		system ("pause");
		return 0;
	}
	int a, b , l , q , w , r , m , n , x , y ,d;
	cout << "Total rows of the image are :"<< image.rows<<endl;
	cout << "Total column of the image are :" << image.cols<< endl;
	cout << "please enter the coordinate of the light : (x,y)";
	cin >> a >> b;
	l = image.cols / 100;
	w = image.cols / 80;
	r = image.cols / 25;
	q = image.cols / 15;
	for(int i=0; i<image.rows; i++){
		pixptr = image.ptr<uchar>(i);
			for (int j = 0; j < image.cols; j++){
				m = i - a;
				m = abs(m);
				x = pow(m, 2);
				n = j - b;
				n = abs(n);
				y = pow(n, 2);
				d = x + y;
				d = sqrt(d);
				if (d<=l)
				{
					pixptr[0] = 205;//b
					pixptr[1] = 250;//g
					pixptr[2] = 255;//r
					pixptr += 3;

				}
				else if (d > l && d < w)
				{
					pixptr[0] = pixptr[0] * 4.5;
					pixptr[1] = pixptr[1] * 4.5;
					pixptr[2] = pixptr[2] * 4.5;
					pixptr += 3;

				}
				else if (d > w && d < r)
				{
					pixptr[0] = pixptr[0] * 3;
					pixptr[1] = pixptr[1] * 3;
					pixptr[2] = pixptr[2] * 3;
					pixptr += 3;

				}
				else if (d > r && d < q)
				{
					pixptr[0] = pixptr[0] * 2;
					pixptr[1] = pixptr[1] * 2;
					pixptr[2] = pixptr[2] * 2;
					pixptr += 3;

				}
				else {
					pixptr[0] = pixptr[0] * 1;
					pixptr[1] = pixptr[1] * 1;
					pixptr[2] = pixptr[2] * 1;
					pixptr += 3;
				}
			}
		
	}
	cv::imwrite("../image/Result.png", image);
	cv::imshow("Traverse result", image);
    cv::waitKey(0);
	return(0);
}