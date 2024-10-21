#include "impls.h"


cv::Mat my_resize(const cv::Mat& input, float scale) {
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    int new_rows = input.rows * scale, new_cols = input.cols * scale;
    // IMPLEMENT YOUR CODE HERE
    cv::Mat output = cv::Mat::zeros(new_rows, new_cols, input.type());

    float invScale = 1.0f / scale;

    for (int x = 0; x < new_rows; x ++){
        for (int y = 0; y < new_cols; y ++){
            float x0 = x * invScale;
            float y0 = y * invScale;

            int x1 = std::floor(x0);
            int x2 = std::ceil(x0);
            int y1 = std::floor(y0);
            int y2 = std::ceil(y0);

            x1 = std::max(0, std::min(x1, input.rows - 1));
            x2 = std::max(0, std::min(x2, input.rows - 1));
            y1 = std::max(0, std::min(y1, input.cols - 1));
            y2 = std::max(0, std::min(y2, input.cols - 1));

            for (int k = 0; k < 3; k ++){
                float val11 = input.at<cv::Vec3b>(x1,y1)[k];
                float val12 = input.at<cv::Vec3b>(x1,y2)[k];
                float val21 = input.at<cv::Vec3b>(x2,y1)[k];
                float val22 = input.at<cv::Vec3b>(x2,y2)[k];

                float insV1 = val11 + (x0-x1) * (val21-val11);
                float insV2 = val12 + (x0-x1) * (val22-val12);
                float dstV = insV1 + (y0-y1) * (insV2-insV1);

                output.at<cv::Vec3b>(x, y)[k] = dstV;
            }
        }
    }

    return output;

}