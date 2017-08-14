#include <iostream>
#include "FreeImage.h"
#include "VisualizationByOpenCV.h"

FIBITMAP* pBitmap;

void load(const std::string& vFile)
{
	FreeImage_Initialise(TRUE);//º”‘ÿFreeImageø‚
	pBitmap = FreeImage_Load(FIF_BMP, vFile.c_str(), BMP_DEFAULT);
	pBitmap    = FreeImage_ConvertTo8Bits(pBitmap);
	int Width  = FreeImage_GetWidth(pBitmap);
	int Height = FreeImage_GetHeight(pBitmap);
	bool* pBuffer = (bool *)malloc(sizeof(bool) * Width * Height);
	memcpy(pBuffer, FreeImage_GetBits(pBitmap), Width * Height);

// 	cv::Scalar BackColor = cv::Scalar(0, 0, 0);
// 	hiveCrowdRendering::CVisualizationByOpenCV* pRendering = new hiveCrowdRendering::CVisualizationByOpenCV(512, 512, BackColor);

	for (unsigned int i=0; i<Height; ++i)
	{
		for (unsigned int k=0; k<Width; ++k)
		{
			bool A = pBuffer[i*Width+k];
			if (A)
			{
				//pRendering->drawPoint(glm::vec2(i, k), 1, glm::vec3(0, 255, 0), true);
				std::cout << "1 ";
			}
			else
			{
				//pRendering->drawPoint(glm::vec2(i, k), 1, glm::vec3(255, 255, 255), true);
				std::cout << "0 ";
			}

			if (i==10 && k==256)
			{
				bool Test = A;
				std::cout << "Out : " << Test << std::endl;
			}
		}
		std::cout << std::endl;
	}

	//pRendering->display();
	FreeImage_DeInitialise();// Õ∑≈FreeImageø‚
	free(pBuffer);
	//delete pRendering;
}
//
int main()
{
	load("test-pic-02.bmp");
	system("pause");
}