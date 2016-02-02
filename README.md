# HW1-Q2-2
* 首先程式會顯示圖片的長寬，
* 接下來輸入希望燈光出現在圖片的哪個位置，以(直，橫)座標表示，
* 輸出結果圖片。

# Implementation
以之前meeting的專案為基底，pixptr[0] ,pixptr[1] ,pixptr[2]分別代表Blue ,Green ,Red三種顏色，<br/>
首先利用 i 和 j 顯示出圖片的長寬，並以左上角為原點，輸入希望燈光出現的位置 ( a , b ) ，<br/>
利用圖片中各像素的座標減掉輸入的座標值，將其取絕對值 ( m , n )，( m^2 + n^2)^1/2 算出距離，<br/>
以 l , w , r , q 分別為寬度的 1/100 , 1/80 , 1/25 , 1/15 作為判斷與input座標點的距離判斷基準，<br/>
離圓心距離** d < l 者為純色光源 ** ， ** d > l && d < w 者為最高亮度** ，<br/>
 ** d > w && d < r 者為次高亮度** ， ** d > r && d < q 者為再次高亮度**，<br/>
最後顯示出結果圖片。<br/>
```
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
```

# Theory
* 三原色光模式
* 直角座標系
* 距離公式

# Disparity result
操作介面:<br/>
<img src="Image 1.png" ><br/>
原圖:<br/>
<img src="image/night.jpg" ><br/>
輸入位置(100,331)顯示出的結果:<br/>
<img src="image/Result.png" ><br/>

# Reference
1.  meeting 的 專案<br/>
2.  圖片出處 http://thepolysh.com/blog/2014/05/13/photos-of-tokyo-at-night/
3.  色碼表 http://tool.oschina.net/commons?type=3
4.  Visual C++.NET图像处理编程 作者：陆宗骐，金登男
5.  c++ 運算式 http://it-easy.tw/sqrtpow/
