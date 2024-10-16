#include <opencv2/opencv.hpp>
 
#include <iostream>
 
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    VideoCapture vid(0);

    Size frame_size(static_cast<int>(vid.get(3)), static_cast<int>(vid.get(4)));
    VideoWriter output("video.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 24, frame_size);

    bool take = false;
    int count = 0;
    while (vid.isOpened())
    {
        Mat frame;
        bool success = vid.read(frame);


        if (take)
        {
            if (success)
            {
                if (count++ == 120)
                    break;
                output.write(frame);
            }
            else
            {
                cout << "Video camera is disconnected" << endl;
                break;
            }
        }
        else if (waitKey(500) == ' ')
            take = true;
        else
            imshow("Preview", frame);
        
    }
    vid.release();
    output.release();

    return 0;
}