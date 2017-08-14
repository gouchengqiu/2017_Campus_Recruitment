#include <iostream>
#include <FreeImage.h>
#include <string>
#include "VisualizationByOpenCV.h"

int main()
{
	std::string FileName = "test-pic-05-8bits.bmp";//test-pic-02;test-pic-05-8bits.bmp
	int Width, Height;
	FreeImage_Initialise(true);  //≥ı ºªØFreeImage
	//FreeImage_Allocate();

	FREE_IMAGE_FORMAT Fif = FreeImage_GetFIFFromFilename(FileName.c_str());
	if (Fif == FIF_UNKNOWN)
	{
		return 0;
	}
	FIBITMAP* pImage = FreeImage_Load(FIF_BMP, FileName.c_str(), BMP_DEFAULT);
	Width = FreeImage_GetWidth(pImage);
	Height = FreeImage_GetHeight(pImage);
	BYTE* pPixelData = FreeImage_GetBits(pImage);
	if (pPixelData == NULL)
	{
		return 0;
	}

	int ColorDepth = FreeImage_GetBPP(pImage);
	bool HighColorDepth = (ColorDepth==16 || ColorDepth==24 || ColorDepth==32) ? true : false;

	cv::Scalar BackColor = cv::Scalar(0, 0, 0);
	hiveCrowdRendering::CVisualizationByOpenCV* pVisualize = new hiveCrowdRendering::CVisualizationByOpenCV(Width, Height, BackColor);
	RGBQUAD Color; //b,g,r

	for (int i=0; i<Width; ++i)
	{
		for (int k=0; k<Height; ++k)
		{
			//freehyan add
			//int ColorDepth = FreeImage_GetBPP(pImage);
			//if (ColorDepth==16 || ColorDepth==24 || ColorDepth==32)
			//{
			//	if (!FreeImage_GetPixelColor(pImage, i, k, &Color))
			//		std::cout << "read fail" << std::endl;
			//}
			//else if(ColorDepth==1 || ColorDepth==4 || ColorDepth==8)
			//{
			//	BYTE Index;
			//	if (!FreeImage_GetPixelIndex(pImage, i, k, &Index))
			//		std::cout << "read fail" << std::endl;
			//	else
			//	{
			//		 RGBQUAD* pPalette = (RGBQUAD*)FreeImage_GetPalette(pImage);
			//		 Color = pPalette[Index];
			//	}
			//}

			if (HighColorDepth)
			{
				if (!FreeImage_GetPixelColor(pImage, i, k, &Color));
				{
					std::cout << "FreeImage_GetPixelColor fail" << std::endl;
				}
			}
			else
			{
				BYTE Index;
				if (!FreeImage_GetPixelIndex(pImage, i, k, &Index))
				{
					std::cout << "FreeImage_GetPixelIndex fail" << std::endl;
				}
				else
				{
					RGBQUAD* pPalette = (RGBQUAD*)FreeImage_GetPalette(pImage);
					Color = pPalette[Index];
				}
			}

			//RGBQUAD Color; //b,g,r
			//FreeImage_GetPixelColor(pImage, i, k, &Color);
			glm::vec3 TempColor = glm::vec3(Color.rgbBlue, Color.rgbGreen, Color.rgbRed);
			//std::cout << Color.rgbBlue << ", " << Color.rgbGreen << ", " << Color.rgbRed << std::endl;
			//std::cout << TempColor.x << ", " << TempColor.y << ", " << TempColor.z << std::endl;
			if (TempColor == glm::vec3(255, 255, 255) || TempColor == glm::vec3(0, 0, 0))
			{
				pVisualize->drawPoint(glm::vec2(i, k), 1, TempColor, true);
			}
			else
			{
				pVisualize->drawPoint(glm::vec2(i, k), 1, glm::vec3(0, 255, 255), true);
			}
		}
	}

	pVisualize->display();

	FreeImage_Unload(pImage);
	FreeImage_DeInitialise();
	delete pVisualize;

	system("pause"); 
} 