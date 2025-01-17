#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace std;

using namespace cv;

Mat photo;
VideoCapture cap;

Mat processFrame(Mat photo) {
	/*
	Processing function for each frame of video
	*/
	
}

Mat processPhoto(Mat photo) {
	/*
	Processing function for each photo
	*/
}

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

	Mat frame, photo;
	namedWindow("Webcam");
	namedWindow("Photo");
	int k;
	// infinite loop
	while (true) {
		// get a camera frame
		cap.read(frame);
		// show it
		frame = processFrame(frame);
		imshow("Webcam", frame);
		// wait 25ms for a keypress and save its integer value
		k = waitKey(25); 
		if (k % 256 == 32) { // space bar
			photo = frame.clone();
			photo = processPhoto(photo);
			imshow("Photo", photo);
		}
		else if (k % 256 == 27) { // backspace
			break;
		}
	}
	cap.release();
	destroyAllWindows();
	return 0;

}