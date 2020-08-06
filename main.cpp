#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include "MedianFilter.h"

using namespace std;

int main()
{
    std::string image_path = samples::findFile("noisy.png");
    Mat img = imread(image_path, IMREAD_COLOR);
    MedianFilter filter(img, 2);
    filter.filter();
    filter.show();
    return 0;
}