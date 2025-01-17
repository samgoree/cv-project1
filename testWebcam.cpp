#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace std;

using namespace cv;

Mat photo;
VideoCapture cap;

int main(int argc, char** argv)
{
	// this should work
	cap = VideoCapture(0);

	/* if it doesn't, use this code to choose a custom camera device/api
	int deviceID = 0;             // 0 = open default camera
    int apiID = cv::CAP_ANY;      // 0 = autodetect default API
    // open selected camera using selected API
    cap.open(deviceID, apiID);
	*/
	if (!cap.isOpened()) {
		cout << "cannot open camera";
	}

	Mat image;
	namedWindow("Webcam");
	namedWindow("Photo");
	int k;
	// infinite loop
	while (true) {
		// get a camera frame
		cap.read(image);
		// show it
		imshow("Webcam", image);
		// wait 25ms for a keypress and save its integer value
		k = waitKey(25); 
		if (k % 256 == 32) { // space bar
			imshow("Photo", image);
		}
		else if (k % 256 == 27) { // backspace
			break;
		}
	}
	cap.release();
	destroyAllWindows();
	return 0;

}