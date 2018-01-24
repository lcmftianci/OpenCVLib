#include <opencv2\core.hpp>
#include <opencv2\face.hpp>
#include <opencv2\highgui.hpp>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <iostream>

using namespace cv;
using namespace cv::face;
using namespace std;

void read_csv(const char *filename, vector<Mat>& images, vector<int>labels, char separator = ';')
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		cout << "File not valid.\n";
		return;
	}
	char path[128];
	int lab;

	while (memset(path, 0, sizeof(path)), fscanf(fp, "%s;%d", path, &lab) != EOF)
	{
		images.push_back(imread(path));
		labels.push_back(lab);
	}

	return;
}
int main()
{
	vector<Mat>images;
	vector<int>labels;
	char *filename = "C:\\faces\\csv.txt";
	read_csv(filename, images, labels);
	if (images.size() <= 1)
	{
		cout << "Need More pics\n";
		return 0;
	}
	int height = images[0].rows;
	Mat testSample = images[images.size() - 1];
	int testLable = labels[labels.size() - 1];
	images.pop_back();
	labels.pop_back();
	Ptr<FaceRecognizer> model = createEigenFaceRecognizer();
	model->train(images, labels);
	int prediclabel;
	double confidence;
	model->predict(testSample, prediclabel, confidence);
	imshow("test", testSample);

	cout << testLable << "\t" << confidence << endl;
	waitKey(0);
	return 0;
}