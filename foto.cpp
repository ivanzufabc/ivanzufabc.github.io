#include <opencv2/opencv.hpp>
 
#include <iostream>
 
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    string files[] = {"foto1.jpg", "foto2.jpg", "foto3.jpg", "foto4.jpg", "foto5.jpg"};
    VideoCapture vid(0);

    bool take = false;
    int count = 0;
    while (vid.isOpened())
    {
        Mat frame;
        bool success = vid.read(frame);

        imshow("Frame", frame);
        if (waitKey(500) == ' ')
            take = true;
        if (take)
        {
            imwrite(files[count], frame);
            if (++count == 5)
            {
                break;
            }
        }
        
    }
    vid.release();

    return 0;
}