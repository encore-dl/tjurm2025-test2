#include "impls.h"


std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用findCountours函数找出输入图像（彩色图像）中的矩形轮廓，并且返回它的外接矩形，以及
     * 最小面积外接矩形。所需要的函数自行查找。
     * 
     * 通过条件：
     * 运行测试点，你找到的矩形跟答案一样就行。
    */
    std::pair<cv::Rect, cv::RotatedRect> res;
    // IMPLEMENT YOUR CODE HERE
    cv::Mat gray, thresh;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::cvtColor(input, gray, cv::COLOR_RGB2GRAY);
    cv::threshold(gray, thresh, 50, 255, cv::THRESH_BINARY);
    cv::findContours(thresh, contours, hierarchy, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);
    cv::Rect rect = cv::boundingRect(contours[0]);
    cv::RotatedRect rrect = cv::minAreaRect(contours[0]);
    res = std::make_pair(rect, rrect);

    return res;

}