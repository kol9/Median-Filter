//
// Created by Nikolay Yarlychenko on 05.08.2020.
//
#include "MedianFilter.h"

MedianFilter::MedianFilter(const Mat& image, int frameSize)
{
    _image = new Mat(image);
    _changedImage = new Mat(image);
    _frameSize = frameSize;
}
MedianFilter::~MedianFilter()
{
    delete _changedImage;
}
void MedianFilter::setImage(Mat* image)
{
    _image = image;
    delete _changedImage;
    _changedImage = new Mat(*image);
}
void MedianFilter::setFrameSize(int frameSize)
{
    _frameSize = frameSize;
}
void MedianFilter::filter()
{
    const int channels = _image->channels();

    switch (channels)
    {
        case 1:
        {
            for (int y = 0; y < _image->rows; ++y)
            {
                for (int x = 0; x < _image->cols; ++x)
                {
                    _changedImage->at<uchar>(y, x) = meanColor(y, x, -1);
                }
            }
            break;
        }
        case 3:
        {
            for (int y = 0; y < _image->rows; ++y)
            {
                for (int x = 0; x < _image->cols; ++x)
                {
                    for (int c = 0; c < channels; ++c)
                    {
                        _changedImage->ptr(y, x)[c] = meanColor(y, x, c);
                    }
                }
            }
            break;
        }
    }
}
uchar MedianFilter::meanColor(int i, int j, int channel)
{
    std::vector<double> colors;

    for (int y = i - _frameSize; y <= i + _frameSize; ++y)
    {
        for (int x = j - _frameSize; x <= j + _frameSize; ++x)
        {

            if (isInside(y, x))
            {
                if (channel == -1)
                {
                    colors.push_back(_image->at<uchar>(y, x));
                }
                else
                {
                    colors.push_back(_image->ptr(y, x)[channel]);
                }
            }
        }
    }
    std::sort(colors.begin(), colors.end());
    return colors[colors.size() / 2];
}
bool MedianFilter::isInside(int y, int x)
{
    return (y >= 0 && y < _image->rows && x >= 0 && x < _image->cols);
}
void MedianFilter::show()
{
    imshow("Filtered image", *_changedImage);
    cv::waitKey(0);
}
void MedianFilter::save(const std::string& filepath)
{
    imwrite(filepath, *_changedImage);
}
