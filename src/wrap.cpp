#include "opencv2/opencv.hpp"

using namespace cv;

int main(void)
{
    Mat srcImg = imread("CNY_100_V2015_HN81501614_20191029170550fixed.bmp");
    //设置空矩阵用于保存目标图像
	Mat dst;
	//设置原图变换顶点
	Point2f AffinePoints0[3] = { Point2f(22, 3160), Point2f(23, 2002), Point2f(635, 2003) };
	//设置目标图像变换顶点
	Point2f AffinePoints1[3] = { Point2f(0, 0), Point2f(100, 0), Point2f(100, 50) };
	//计算变换矩阵
	Mat Trans = getAffineTransform(AffinePoints0, AffinePoints1);
	//矩阵仿射变换
	warpAffine(srcImg, dst, Trans, Size(100, 50));
    
    Rect rect(0,0,100,50);
    Mat roi = dst(rect);
    
    imwrite("test.bmp",roi);
    return 0;
}
