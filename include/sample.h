#ifndef SAMPLE_H
#define SAMPLE_H

#include <iostream>
#include "opencv2/opencv.hpp"
#include <vector>

using namespace std;
using namespace cv;


int sample_base1(const Mat &img);

void open_camera_sample();

int filter2d_sample(const Mat &img, const Mat &kernel);

int gray_sample(Mat &img);

int bgr_channel_spilt_sample(const Mat &img);

int image_mosaic_sample(const Mat &img1, const Mat &img2, int type);


#endif  // SAMPLE_H
