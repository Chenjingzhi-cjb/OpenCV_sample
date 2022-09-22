#include "sample.h"


int sample_base1(const Mat &img) {
    if (img.empty()) {
        printf("Could not load the image...");
        return 1;
    } else {
        return 0;
    }
}


void open_camera_sample() {
    VideoCapture capture(0);

    while (true) {
        Mat frame;
        capture >> frame;

        imshow("video", frame);

        int key = cvWaitKey(10);
        if (key == 27)  // ESC
            break;
    }
}


int filter2d_sample(const Mat &img, const Mat &kernel) {
    if (sample_base1(img)) return -1;

    // 初始化卷积核示例
    // Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 7, -1, 0, -1, 0);

    // 打印卷积核
    cout << "csv\n" << format(kernel, Formatter::FMT_CSV) << endl;
    /* 其他方式
    cout << "default1\n" << kernel << endl;
    cout << "default2\n" << format(kernel, Formatter::FMT_DEFAULT) << endl;
    cout << "c\n" << format(kernel, Formatter::FMT_C) << endl;
    cout << "numpy\n" << format(kernel, Formatter::FMT_NUMPY)  << endl;
    cout << "matlab\n" << format(kernel, Formatter::FMT_MATLAB) << endl;
    cout << "python\n" << format(kernel, Formatter::FMT_PYTHON) << endl;
     */

    Mat dst = Mat::zeros(img.size(), img.type());
    filter2D(img, dst, img.depth(), kernel);  // src.depth 为位图深度，有 32、24、8 等

    namedWindow("original", CV_WINDOW_AUTOSIZE);
    imshow("original", img);
    namedWindow("dst", CV_WINDOW_AUTOSIZE);
    imshow("dst", dst);
    waitKey(0);

    return 0;
}


int gray_sample(Mat &img) {
    if (sample_base1(img)) return -1;

//    // 用函数 at 遍历多通道 Mat 对象中的所有值
//    for (int r = 0; r < img.rows; ++r) {
//        for (int c = 0; c < img.cols; ++c) {
//#if 1
//            cout << img.at<Vec3b>(r, c) << ", ";  // Vec3b == Vec<uchar, 3>
//#else
//            unsigned int blue = img.at<Vec3b>(r, c)[0];
//            unsigned int green = img.at<Vec3b>(r, c)[1];
//            unsigned int red = img.at<Vec3b>(r, c)[2];
//            cout << "[" << blue << ", " << green << ", " << red << "], ";
//#endif
//        }
//        cout << endl;
//    }

    Mat gray_img;
    cvtColor(img, gray_img, CV_RGB2GRAY);

//    // 用函数 at 遍历单通道 Mat 对象中的所有值 并 进行灰度反差处理
//    for (int r = 0; r < gray_img.rows; ++r) {
//        for (int c = 0; c < gray_img.cols; ++c) {
//            unsigned int m = gray_img.at<uchar>(r, c);
//            cout << m << ", ";
//            gray_img.at<uchar>(r, c) = 255 - int(gray_img.at<uchar>(r, c));  // 灰度反差处理
//        }
//        cout << endl;
//    }

    namedWindow("original", CV_WINDOW_AUTOSIZE);
    imshow("original", img);
    namedWindow("gray", CV_WINDOW_AUTOSIZE);
    imshow("gray", gray_img);
    waitKey(0);

    return 0;
}


int bgr_channel_spilt_sample(const Mat &img) {
    if (sample_base1(img)) return -1;

    vector<Mat> planes;
    split(img, planes);

    namedWindow("original", CV_WINDOW_AUTOSIZE);
    imshow("original", img);
    namedWindow("blue", CV_WINDOW_AUTOSIZE);
    imshow("blue", planes[0]);
    namedWindow("green", CV_WINDOW_AUTOSIZE);
    imshow("green", planes[1]);
    namedWindow("red", CV_WINDOW_AUTOSIZE);
    imshow("red", planes[2]);
    waitKey(0);

    return 0;
}


int image_mosaic_sample(const Mat &img1, const Mat &img2, int type) {
    if (sample_base1(img1) || sample_base1(img2)) return -1;

    Mat combine;

    if (type == 0) {
        hconcat(img1, img2, combine);  // 图像水平方向拼接
    } else if (type == 1) {
        vconcat(img1, img2, combine);  // 图像垂直方向拼接
    } else {
        cout << "Parameter type error, please input 0 or 1." << endl;
        return 0;
    }

    namedWindow("combine", CV_WINDOW_AUTOSIZE);
    imshow("image", combine);
    waitKey(0);

    return 0;
}
