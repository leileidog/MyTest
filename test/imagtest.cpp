#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include <opencv2\imgproc\types_c.h>
#include <opencv2/core/utils/logger.hpp>
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;


Mat src, mid, dst;
int a = 0;
string s; //查找的图片地址
string output;//存储图片的地址



//查找图片
void image_input(string input) {
	
	src = imread(input);
	if (src.empty()) {
		cout << "未找到该图像" << endl;
		cout << "请输入图像地址：";
		cin >> s;
		image_input(s);
	}
	return ;
}




//对图像进行操作
void fun(Mat src, Mat mid, Mat dst,int a) {
	
	switch (a) {
		case 1:
			cvtColor(src, dst, CV_BGR2GRAY);//彩色图转为灰度图
			imshow("原图", src);
			imshow("灰度图", dst);
			imwrite(output, dst);
			waitKey(0);			
			break;
		case 2:
			//缩放到统一尺寸,,给出指定的大小，以默认的双线性插值方式 INTER_LINEAR
			// resize(src,dst_resize,Size(123,456)); //最简方式

			//按指定比例缩放
			cout << "请输入缩放比例：";
			double r;
			cin >> r;
			resize(src, dst, Size(src.cols * r, src.rows * r), (0, 0), (0, 0), 3);
			imshow("原图", src);
			imshow("缩放图", dst);
			imwrite(output, dst);
			waitKey(0);
			break;
		case 3:
			//均值滤波无法克服边缘像素信息丢失的缺陷，原因是均值滤波是基于平均权重。
			blur(src, dst, Size(3, 3));//均值滤波
			imshow("原图", src);
			imshow("均值滤波", dst);
			imwrite(output, dst);
			waitKey(0);
			break;
		case 4:
			//高斯滤波虽然克服了均值滤波的缺陷，但是无法完全避免，因为没有考虑像素值得不同，只是基于空间分布考虑。
			GaussianBlur(src, dst, Size(3, 3), 11, 11);//高斯滤波
			imshow("原图", src);
			imshow("高斯滤波", dst);
			imwrite(output, dst);
			waitKey(0);
			break;
		case 5:
			medianBlur(src, dst, 3);//中值滤波
			imshow("原图", src);
			imshow("中值滤波", dst);
			imwrite(output, dst);
			waitKey(0);
			break;
		case 6:
			//双边滤波避免了边缘信息丢失，保留了图像的轮廓不变。
			bilateralFilter(src, dst, 15, 100, 3);//双边滤波
			imshow("原图", src);
			imshow("双边滤波", dst);
			imwrite(output, dst);
			waitKey(0);
			break;
		case 7:
			cvtColor(src, mid, CV_BGR2GRAY);//彩色图转为灰度图
			Canny(mid, dst, 50, 150);//canny边缘检测
			imshow("原图", src);
			imshow("边缘检测", dst);
			imwrite(output, dst);
			waitKey(0);
			break;
		case 8:			
			cout << "原图的宽、高分别为：" << src.size().width << "," << src.size().height << endl;
			int r_start, r_end, c_start, c_end;
			cout << "请输入剪裁图片像素的行首、行尾、列首、列尾" << endl;
			cin >> r_start >> r_end >> c_start >> c_end;
			dst = src(Range(r_start, r_end), Range(c_start, c_end));			
			imshow("原图", src);
			imshow("剪裁后的图片", dst);
			imwrite(output, dst);
			waitKey(0);
			break;
		case 9:
			cvtColor(src, mid, CV_BGR2GRAY);//彩色图转为灰度图
			adaptiveThreshold(mid, dst, 255, 1, 0, 5, 0);//自适应阈值分割
			imshow("原图", src);
			imshow("阈值分割后的图片", dst);
			imwrite(output, dst);
			waitKey(0);
			break;
		case 10:
			cvtColor(src, mid, CV_BGR2GRAY);//彩色图转为灰度图
			equalizeHist(mid,dst);//直方图均衡化是通过拉伸像素强度分布范围来增强图像对比度的一种方法
			imshow("原图", src);
			imshow("灰度图", mid);
			imshow("直方图均衡化后的图片", dst);
			imwrite(output, dst);
			waitKey(0);
			break;

	}
	return ;
}

void pre() {
	cout << "功能：" << endl;
	cout << "	1.彩色图转为灰度图 " << endl;
	cout << "	2. 按指定比例缩放" << endl;
	cout << "	3. 均值滤波" << endl;
	cout << "	4. 高斯滤波" << endl;
	cout << "	5. 中值滤波" << endl;
	cout << "	6. 双边滤波" << endl;
	cout << "	7. canny边缘检测" << endl;
	cout << "	8. 剪裁图像" << endl;
	cout << "	9. 自适应阈值分割" << endl;
	cout << "	10. 直方图均衡化" << endl;
}

int main(int argc,char *argv[]) {
	
	while (1) {
		pre();
		cout << "请输入图像地址：";
		cin >> s;		
		image_input(s);		
				
		cout << "请输入想实现的功能的编号：";
		cin >> a;
		cout << "请输入存储地址：";
		cin >> output;
		
		fun(src, mid, dst, a);
			
	}

	return 0;
}