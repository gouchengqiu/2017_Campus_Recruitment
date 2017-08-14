//#include <string>
//#include <iostream>
////#include "opencv2/core/core.hpp"
//#include "opencv2/highgui/highgui.hpp"
#include <glm/glm.hpp>

//void video2Image(const std::string& vVideo)
//{
//	cv::VideoCapture Capture(vVideo);
//	if (Capture.isOpened())
//	{
//		std::cout << "Open video error." << std::endl;
//	}
//
//	int Frame_Number = Capture.get(CV_CAP_PROP_FRAME_COUNT);
//	int Frame_Width  = Capture.get(CV_CAP_PROP_FRAME_WIDTH);
//	int Frame_Height = Capture.get(CV_CAP_PROP_FRAME_HEIGHT);
//	float Frame_FPS  = Capture.get(CV_CAP_PROP_FPS);
//	
//	std::cout << "Frame_Width is " << Frame_Width << std::endl;
//	std::cout << "Frame_Height is " << Frame_Height << std::endl;
//	std::cout << "Frame_FPS is " << Frame_FPS << std::endl;
//
//	int Num = 0;
//	cv::Mat Image;
//	std::string ImgName;
//	char ImageName[20];
//	cv::namedWindow("VideoTest", CV_WINDOW_AUTOSIZE);
//	while (true)
//	{
//		cv::Mat Frame;
//		bool Success = Capture.read(Image); //从视频中读取一帧
//		if (!Success)
//		{
//			std::cout << "不能从视频文件读取帧." << std::endl;
//		}
//		imshow("VideoTest", Frame); //从窗口显示当前帧
//		sprintf(ImageName, "%s%d%s", Image, ++Num, ".jpg");
//		ImgName = ImageName;
//		imwrite(ImgName, Frame);
//
//		if (cv::waitKey(30) == 27 || Num == Frame_Number)
//		{
//			std::cout << "按下ESC键" << std::endl;
//			break;
//		}
//	}
//
//	Capture.release();
//}

int main()
{
	float Test = glm::distance(glm::vec2(189, 108), glm::vec2(206, 112));

	/*std::string VideoName = "TestVideo.avi";
	video2Image(VideoName);*/
}