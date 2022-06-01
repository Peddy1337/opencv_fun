#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

int main()
{
    VideoCapture capture;
    bool run = true, hsv = false, blurring = false;
    Size filterSize = Size(10, 10);
    capture.open(0);
    while (run)
    {
        Mat frame;
        capture >> frame;

        if (frame.empty())
        {
            break;
        }

        if (hsv)
        {
            // converts the image of the frame to hsv
            cvtColor(frame, frame, COLOR_BGR2HSV);
        }

        if (blurring)
        {
            blur(frame, frame, filterSize);
        }

        imshow("Testfeed", frame);

        switch (waitKey(5))
        {
        case 'h':
            hsv = !hsv;
            break;
        case 'b':
            blurring = !blurring;
            break;
        case '+':
            filterSize = Size(filterSize.width + 1, filterSize.height + 1);
            break;
        case '-':
            if (filterSize.height > 1)
            {
                filterSize = Size(filterSize.width - 1, filterSize.height - 1);
            }
            break;
        case 27:
            run = false;
            break;
        }
    }
    capture.release();
    return 0;
}
