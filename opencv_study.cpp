#include <opencv2/opencv.hpp>
#include <iostream> 
#include <cstdlib>
#include <ctime>

int main(){
    int rad = 100; 
    cv::Mat frame; 
    cv::VideoCapture cap(0);
    int value = 50;

    if(!cap.isOpened()){
        std::cerr << "Error: Unable to open camera" << std::endl;
        return 1;
    }
    std::srand(time(0));
    
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    while(true){
        bool ret = cap.read(frame);
        int column = frame.cols;
        int row = frame.rows;
        int channel = frame.channels();

        std::cout << row << " " << column << " " << channel << std::endl;

        cv::Vec3b pixel = frame.at<cv::Vec3b>(100, 100);

        cv::Scalar bright(value, value, value);

        cv::Mat frame_value;
        cv::add(frame, value, frame_value);
        value++;
        if(value > 100)
            value = 50;

        // ROI 
        cv::Rect roi(0, 0, 100, 100);
        cv::Mat frame_roi = frame(roi);

        // cvtColor()
        cv::Mat frame_hsv;
        cv::cvtColor(frame, frame_hsv, cv::COLOR_BGR2HSV);

        // inRange color tracking (blue)
        cv::Scalar upper(140, 255, 255);
        cv::Scalar lower(100, 100, 100);
        cv::Mat frame_mask;
        cv::inRange(frame_hsv, lower, upper, frame_mask);

        if(!ret){
            std::cerr << "Error: image read fail" << std::endl;
            return 1;
        }
        rad = std::rand() % 100;
        cv::circle(frame, cv::Point(100, 100), rad, cv::Scalar(0, 0, 255), 5);
        cv::imshow("win", frame);
        cv::imshow("roi", frame_roi);
        cv::imshow("value", frame_mask);
        if(cv::waitKey(1) == 'q'){
            break;
        };
    }
    cap.release();
    cv::destroyAllWindows();
    return 0;
}