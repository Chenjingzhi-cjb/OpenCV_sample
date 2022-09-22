#include <iostream>
#include "sample.h"


int main() {
    Mat img = imread("../lena.png");

//    Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 7, -1, 0, -1, 0);
//    filter2d_sample(img, kernel);

    gray_sample(img);

    return 0;
}


