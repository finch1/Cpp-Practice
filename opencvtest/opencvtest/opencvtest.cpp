#include <iostream>
#include <random>
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>

using namespace cv;
using namespace std;

void colorReduce(cv::Mat image, int div = 64) {
	int nr = image.rows; //number of lines
	//total number of elements per line
	int nc = image.cols * image.channels();

	for (int r = 0; r < nr; r++) {
		//get the address of row j
		uchar* data = image.ptr<uchar>(r);

		for (int c = 0; c < nc; c++) {
			//process each pixel -------
			data[c] = data[c] / div*div + div/2;
			//end of pixel processing--

		}
	}
}

int main() {

	Mat	image = imread("color.jpg", IMREAD_COLOR);
	colorReduce(image, 64);
	imshow("image", image);
	waitKey(0);

}