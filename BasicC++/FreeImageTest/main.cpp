#include <iostream>
#include <FreeImage.h>
#include <string>
#include <vector>
//#include <math.h>
//#include <cmath>
#include "VisualizationByOpenCV.h"

const int ExitLength = 10;
const int ThreholdPixel = 4;
const float Angel = 30;
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

//********************************************************************
//FUNCTION:
void computeSampleSet(const glm::vec2& vCurPos, int vSampleRadius, int vSampleAngle, std::vector<glm::vec2>& voSamplePointSet)
{
	for (double Angle = 0.0; Angle <= 90.0; Angle+=vSampleAngle)
	{
		double Radian = Angle * M_PI / 180.0f;
		voSamplePointSet.push_back(vCurPos + glm::vec2(vSampleRadius*std::cos(Radian), vSampleRadius*std::sin(Radian)));
	}
}

//********************************************************************
//FUNCTION:
RGBQUAD readPixelColor(FIBITMAP* vImage, const glm::vec2& vPixelPos)
{
	RGBQUAD Color;
	int ColorDepth = FreeImage_GetBPP(vImage);
	if (ColorDepth==16 || ColorDepth==24 || ColorDepth==32)
	{
		if (!FreeImage_GetPixelColor(vImage, vPixelPos.x, vPixelPos.y, &Color))
			std::cout << "read fail" << std::endl;
	}
	else if(ColorDepth==1 || ColorDepth==4 || ColorDepth==8)
	{
		BYTE Index;
		if (!FreeImage_GetPixelIndex(vImage, vPixelPos.x, vPixelPos.y, &Index))
			std::cout << "read fail" << std::endl;
		else
		{
			RGBQUAD* pPalette = (RGBQUAD*)FreeImage_GetPalette(vImage);
			Color = pPalette[Index];
		}
	}

	return Color;
}

//********************************************************************
//FUNCTION:
bool isEffectivePos(int vWidth, int vHeight, const glm::vec2& vPos)
{
	return vPos.x >=0 && vPos.x < vWidth && vPos.y >=0 && vPos.y < vHeight;
}

//********************************************************************
//FUNCTION:
bool isNecessary2ComputingSampleSet(FIBITMAP* vImage, const glm::vec2& vTargetPoint, const glm::vec3& vTargetPointColor)
{
	glm::vec2 LeftPoint = glm::vec2(vTargetPoint.x-1, vTargetPoint.y);
	glm::vec2 TopPoint  = glm::vec2(vTargetPoint.x, vTargetPoint.y-1);

	float Height = FreeImage_GetHeight(vImage);
	float Width  = FreeImage_GetWidth(vImage);
	if (isEffectivePos(Width, Height, LeftPoint))
	{
		RGBQUAD LeftPointColor = readPixelColor(vImage, LeftPoint);
		glm::vec3 LeftPointParsedColor = glm::vec3(LeftPointColor.rgbBlue, LeftPointColor.rgbGreen, LeftPointColor.rgbRed);
		if (vTargetPointColor == LeftPointParsedColor)
		{
			return false;
		}
	}

	if (isEffectivePos(Width, Height, TopPoint))
	{
		RGBQUAD TopPointColor = readPixelColor(vImage, TopPoint);
		glm::vec3 TopPointParsedColor = glm::vec3(TopPointColor.rgbBlue, TopPointColor.rgbGreen, TopPointColor.rgbRed);
		if (vTargetPointColor == TopPointParsedColor)
		{
			return false;
		}
	}

	return true;
}

std::vector<glm::vec2> ExitSet;

int main()
{
	std::string FileName = "../pic/pic-512-1.bmp";//test-pic-02;test-pic-05-8bits.bmp
	int Width, Height;
	FreeImage_Initialise(true);  //≥ı ºªØFreeImage

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

	cv::Scalar BackColor = cv::Scalar(0, 0, 0);
	hiveCrowdRendering::CVisualizationByOpenCV* pVisualize = new hiveCrowdRendering::CVisualizationByOpenCV(Width, Height, BackColor);

	for (int i=0; i<Width; ++i)
	{
		for (int k=0; k<Height; ++k)
		{
			RGBQUAD CurrentPixelColor = readPixelColor(pImage, glm::vec2(i, k));
			glm::vec3 CurrentPixelParsedColor = glm::vec3(CurrentPixelColor.rgbBlue, CurrentPixelColor.rgbGreen, CurrentPixelColor.rgbRed);
			if (CurrentPixelParsedColor == glm::vec3(255, 255, 255) || CurrentPixelParsedColor == glm::vec3(0, 0, 0))
			{
				pVisualize->drawPoint(glm::vec2(i, k), 1, CurrentPixelParsedColor, true);
			}
			else
			{
				//compute sample point set
				if (isNecessary2ComputingSampleSet(pImage, glm::vec2(i, k), CurrentPixelParsedColor))
				{
					std::vector<glm::vec2> SamplePointSet;
					computeSampleSet(glm::vec2(i, k), ExitLength, Angel, SamplePointSet);
					int NumEffectiveSamplePoint = 0;
					for (auto& SamplePoint : SamplePointSet)
					{
						RGBQUAD SamplePointColor = readPixelColor(pImage, SamplePoint);
						glm::vec3 ParsedColor = glm::vec3(SamplePointColor.rgbBlue, SamplePointColor.rgbGreen, SamplePointColor.rgbRed);
						if (ParsedColor == CurrentPixelParsedColor)
						{
							++NumEffectiveSamplePoint;
						}
					}
					if (NumEffectiveSamplePoint == ThreholdPixel)
					{
						ExitSet.push_back(glm::vec2(i, k));
					}
				}
				pVisualize->drawPoint(glm::vec2(i, k), 1, glm::vec3(0, 255, 255), true);
			}
		}
	}

	for (auto& Exit : ExitSet)
	{
		pVisualize->drawPoint(Exit, 1, glm::vec3(255, 255, 0), true);
	}
	pVisualize->display();

	FreeImage_Unload(pImage);
	FreeImage_DeInitialise();
	delete pVisualize;

	system("pause"); 
} 