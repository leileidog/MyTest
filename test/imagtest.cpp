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
string s; //���ҵ�ͼƬ��ַ
string output;//�洢ͼƬ�ĵ�ַ



//����ͼƬ
void image_input(string input) {
	
	src = imread(input);
	if (src.empty()) {
		cout << "δ�ҵ���ͼ��" << endl;
		cout << "������ͼ���ַ��";
		cin >> s;
		image_input(s);
	}
	return ;
}




//��ͼ����в���
void fun(Mat src, Mat mid, Mat dst,int a) {
	
	switch (a) {
		case 1:
			cvtColor(src, dst, CV_BGR2GRAY);//��ɫͼתΪ�Ҷ�ͼ
			imshow("ԭͼ", src);
			imshow("�Ҷ�ͼ", dst);
			imwrite(output, dst);
			waitKey(0);			
			break;
		case 2:
			//���ŵ�ͳһ�ߴ�,,����ָ���Ĵ�С����Ĭ�ϵ�˫���Բ�ֵ��ʽ INTER_LINEAR
			// resize(src,dst_resize,Size(123,456)); //���ʽ

			//��ָ����������
			cout << "���������ű�����";
			double r;
			cin >> r;
			resize(src, dst, Size(src.cols * r, src.rows * r), (0, 0), (0, 0), 3);
			imshow("ԭͼ", src);
			imshow("����ͼ", dst);
			imwrite(output, dst);
			waitKey(0);
			break;
		case 3:
			//��ֵ�˲��޷��˷���Ե������Ϣ��ʧ��ȱ�ݣ�ԭ���Ǿ�ֵ�˲��ǻ���ƽ��Ȩ�ء�
			blur(src, dst, Size(3, 3));//��ֵ�˲�
			imshow("ԭͼ", src);
			imshow("��ֵ�˲�", dst);
			imwrite(output, dst);
			waitKey(0);
			break;
		case 4:
			//��˹�˲���Ȼ�˷��˾�ֵ�˲���ȱ�ݣ������޷���ȫ���⣬��Ϊû�п�������ֵ�ò�ͬ��ֻ�ǻ��ڿռ�ֲ����ǡ�
			GaussianBlur(src, dst, Size(3, 3), 11, 11);//��˹�˲�
			imshow("ԭͼ", src);
			imshow("��˹�˲�", dst);
			imwrite(output, dst);
			waitKey(0);
			break;
		case 5:
			medianBlur(src, dst, 3);//��ֵ�˲�
			imshow("ԭͼ", src);
			imshow("��ֵ�˲�", dst);
			imwrite(output, dst);
			waitKey(0);
			break;
		case 6:
			//˫���˲������˱�Ե��Ϣ��ʧ��������ͼ����������䡣
			bilateralFilter(src, dst, 15, 100, 3);//˫���˲�
			imshow("ԭͼ", src);
			imshow("˫���˲�", dst);
			imwrite(output, dst);
			waitKey(0);
			break;
		case 7:
			cvtColor(src, mid, CV_BGR2GRAY);//��ɫͼתΪ�Ҷ�ͼ
			Canny(mid, dst, 50, 150);//canny��Ե���
			imshow("ԭͼ", src);
			imshow("��Ե���", dst);
			imwrite(output, dst);
			waitKey(0);
			break;
		case 8:			
			cout << "ԭͼ�Ŀ��߷ֱ�Ϊ��" << src.size().width << "," << src.size().height << endl;
			int r_start, r_end, c_start, c_end;
			cout << "���������ͼƬ���ص����ס���β�����ס���β" << endl;
			cin >> r_start >> r_end >> c_start >> c_end;
			dst = src(Range(r_start, r_end), Range(c_start, c_end));			
			imshow("ԭͼ", src);
			imshow("���ú��ͼƬ", dst);
			imwrite(output, dst);
			waitKey(0);
			break;
		case 9:
			cvtColor(src, mid, CV_BGR2GRAY);//��ɫͼתΪ�Ҷ�ͼ
			adaptiveThreshold(mid, dst, 255, 1, 0, 5, 0);//����Ӧ��ֵ�ָ�
			imshow("ԭͼ", src);
			imshow("��ֵ�ָ���ͼƬ", dst);
			imwrite(output, dst);
			waitKey(0);
			break;
		case 10:
			cvtColor(src, mid, CV_BGR2GRAY);//��ɫͼתΪ�Ҷ�ͼ
			equalizeHist(mid,dst);//ֱ��ͼ���⻯��ͨ����������ǿ�ȷֲ���Χ����ǿͼ��Աȶȵ�һ�ַ���
			imshow("ԭͼ", src);
			imshow("�Ҷ�ͼ", mid);
			imshow("ֱ��ͼ���⻯���ͼƬ", dst);
			imwrite(output, dst);
			waitKey(0);
			break;

	}
	return ;
}

void pre() {
	cout << "���ܣ�" << endl;
	cout << "	1.��ɫͼתΪ�Ҷ�ͼ " << endl;
	cout << "	2. ��ָ����������" << endl;
	cout << "	3. ��ֵ�˲�" << endl;
	cout << "	4. ��˹�˲�" << endl;
	cout << "	5. ��ֵ�˲�" << endl;
	cout << "	6. ˫���˲�" << endl;
	cout << "	7. canny��Ե���" << endl;
	cout << "	8. ����ͼ��" << endl;
	cout << "	9. ����Ӧ��ֵ�ָ�" << endl;
	cout << "	10. ֱ��ͼ���⻯" << endl;
}

int main(int argc,char *argv[]) {
	
	while (1) {
		pre();
		cout << "������ͼ���ַ��";
		cin >> s;		
		image_input(s);		
				
		cout << "��������ʵ�ֵĹ��ܵı�ţ�";
		cin >> a;
		cout << "������洢��ַ��";
		cin >> output;
		
		fun(src, mid, dst, a);
			
	}

	return 0;
}