// CvDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "csrface.h"

//加载Opencv库及头文件
#include <opencv\cv.hpp>
#include <opencv2\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2/face.hpp>

using namespace cv;
using namespace face;
using namespace std;

//#pragma comment(lib, "opencv_world340d.lib")
#pragma comment(lib, "opencv_world340.lib")

int _tmain(int argc, _TCHAR* argv[])
{
#if 0
	printf("%d", 0xff);
	Mat srcImg = imread("C:\\Users\\long\\Documents\\Tencent Files\\707010543\\Image\\Group\\cat.jpg");
	imshow("显示图片", srcImg);

	Size cvSize = Size(15, 15);

	Mat ele = getStructuringElement(MORPH_ELLIPSE, cvSize);
	Mat dstImg;
	erode(srcImg, dstImg, ele);
	imshow("腐蚀效果", dstImg);

	Mat blurImg;
	blur(srcImg, blurImg, Size(15, 15));
	imshow("均值滤波", blurImg);

	//边缘检测
	Mat edge, grayImg;
	cvtColor(srcImg, grayImg, CV_BGR2GRAY);		//转换绘图图像
	blur(grayImg, edge, Size(3, 3));			//3X3内核降噪
	Canny(edge, edge, 3, 9, 3);					//运行Canny算子
	imshow("边缘检测", edge);

	//读取并播放视频
	VideoCapture vc(0);
	Mat edges;
	//vc.open("1.avi");
	int inx = 0;
	while (true)
	{
		Mat frame;
		vc >> frame;
		cvtColor(frame, edges, COLOR_BGR2GRAY);
		blur(edges, edges, Size(7, 7));
		Canny(edges, edges, 0, 30, 3);
		imshow("视频显示", edges);

		char filepath[200];
		memset(filepath, '\0', sizeof(filepath));
		sprintf(filepath, "C:\\Users\\long\\Documents\\Tencent Files\\707010543\\Image\\Group\\%d.jpg", inx);
		imwrite(filepath, edges);
		inx++;
		if (waitKey(30) >= 0)break;
	}
	waitKey(6000);
#endif 

	//人脸世界
	VideoCapture cap(0);
	if (!cap.isOpened())
		return -1;

	Mat fream;
	Mat edges;
	Mat gray;

	CascadeClassifier cascade;
	bool stop = false;
	cascade.load("D:\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_alt.xml");
	Ptr<FaceRecognizer> model = EigenFaceRecognizer::create();

	return 0;
}

void createAlphaMat(Mat &mat)
{
	for (int inx = 0; inx < mat.rows; ++inx)
	{
		for (int jnx = 0; jnx < mat.cols; ++jnx)
		{
			Vec4b& rgba = mat.at<Vec4b>(inx, jnx);
			rgba[0] = UCHAR_MAX;
			rgba[1] = saturate_cast<uchar>((float(mat.cols - jnx))/ ((float)mat.cols)* UCHAR_MAX);
		}
	}
}

