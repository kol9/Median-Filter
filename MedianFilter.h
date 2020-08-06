//
// Created by Nikolay Yarlychenko on 05.08.2020.
//
#ifndef MEDIANFILTER_MEDIANFILTER_H
#define MEDIANFILTER_MEDIANFILTER_H

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace cv;

class MedianFilter
{
private:
    cv::Mat* _changedImage;
    cv::Mat* _image;
    int _frameSize;

    uchar meanColor(int i, int j, int channel);
    bool isInside(int y, int x);
public:
    explicit MedianFilter(const cv::Mat& image, int frameSize = 1);
    virtual ~MedianFilter();

    void setImage(Mat* image);
    void setFrameSize(int frameSize);

    void filter();
    void show();

    void save(const std::string& filename);
};


#endif //MEDIANFILTER_MEDIANFILTER_H
