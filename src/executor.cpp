#include <iostream>
#include "nanodet.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <sstream>
#include <string>

using namespace std;


void pthelp(){
	cout << "please input arguments like\n"
	<< "executor modelpath modeltype imagepath"
        << "exetucor ./ rvm-640 a.jpg" << endl;
    //./../model rvm-640 ../images/zhaoliying.jpg
}

int main(int argc, char* argv[]){
    if(argc < 4){
	pthelp();
	return -1;
    }
    cout << "videomatting enter" <<endl;
    NanoDet detector;
    //load model
     const int target_sizes[] =
    {
        512,
        640,
    };

    const float mean_vals[][3] =
    {
        {123.675f, 116.28f,  103.53f},
        {123.675f, 116.28f,  103.53f},
    };

    const float norm_vals[][3] =
    {
        {0.01712475f, 0.0175f, 0.01742919f},
        {0.01712475f, 0.0175f, 0.01742919f},
    };
    cout << "load model" << endl;
    stringstream ss;
    ss << argv[1];
    ss << "/";
    ss << argv[2];
    string str = ss.str();
    detector.load(str.c_str(), target_sizes[1], mean_vals[1], norm_vals[1], false);
    vector<Object> objs;
    cv::Mat img;
    std::cout << "img path:" << argv[3] << std::endl;
    img = cv::imread(argv[3]);
    std::cout << "load image ok" << std::endl;
    cv::imshow("11", img);
    cv::Mat dst(640, 480, CV_8UC3);
    //cv::Mat dst;
	//dst = cv::Mat::zeros(img.size(), img.type());
    //unknoe
    //cv::resize(img, dst, cv::Size(0,0), 4, 4, 2);
    //双线性插值
    //cv::resize(img, dst, cv::Size(), 0.5，0.5);
    //立方插值
    cv::resize(img, dst, dst.size(), cv::INTER_CUBIC);
    cout << "src channel size:" << img.channels() << " width:" << img.cols << " height:" << img.rows << endl;
    cout << "dst channel size:" << dst.channels() << " width:" << dst.cols << " height:" << dst.rows << endl;
    detector.detect(dst, objs);
    detector.draw(dst, objs);
    cv::imshow("11", img);
    cv::waitKey();

    cout << "videomatting exit" <<endl;
    return 0;
}
