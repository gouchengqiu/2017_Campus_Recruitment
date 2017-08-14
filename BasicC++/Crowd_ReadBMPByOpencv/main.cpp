#include <windows.h>
#include <string>
#include <iostream>
#include "highgui.h"

using namespace std;
typedef struct tagBITMAPFILEHEADER{
	WORD  bfType;
	DWORD bfSize;
	WORD  bfReserved1;
	WORD  bfReserved2;
	DWORD bfOffBits;
}BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER{
	DWORD  biSize;
	LONG   biWidth;
	LONG   biHeight;
	WORD   biPlanes;
	WORD   biBitCount;
	DWORD  biCompression;
	DWORD  biSizeImage;
	LONG   biXPelsPerMeter;
	LONG   biYPelsPerMeter;
	DWORD  biClrUsed;
	DWORD  biClrImportant;
} BITMAPINFOHEADER;

static BITMAPFILEHEADER fileHeader;
static BITMAPINFOHEADER infoHeader;

void ReadBmp(const string& bmpPath)  
{  
	/* 读取文件 */  
	FILE * fp = fopen(bmpPath.c_str(), "rb");  
	assert(fp != NULL);  

	/* 跳过文件头 */  
	fseek(fp, sizeof(BITMAPFILEHEADER),0);  

	/* 读取信息头 */  
	fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1,fp);  

	int bmpWidth = infoHeader.biWidth;  
	int bmpHeight = infoHeader.biHeight;  
	int biBitCount = infoHeader.biBitCount;               
	int lineByte=(bmpWidth * biBitCount/8+3)/4*4;       /* 定义变量，计算图像每行像素所占的字节数（必须是4的倍数）*/  

	/* 灰度图像有颜色表，且颜色表表项为256，关键 */  
	RGBQUAD* pColorTable;  
	if(biBitCount==8)  
	{  

		//申请颜色表所需要的空间，读颜色表进内存  

		pColorTable=new RGBQUAD[256];  

		fread(pColorTable,sizeof(RGBQUAD),256,fp);  

	}  
	//申请位图数据所需要的空间，读位图数据进内存  
	unsigned char* pBmpBuf=new unsigned char[lineByte * bmpHeight];  

	fread(pBmpBuf,1,lineByte * bmpHeight,fp);  

	fclose(fp);//关闭文件  


	IplImage* pImg = cvCreateImage(cvSize(bmpWidth, bmpHeight), 8, 1);  

	assert(pImg != NULL);  

	/* 复制图像数据到opencv数据结构总并显示 */  
	memcpy(pImg->imageData, pBmpBuf, lineByte * bmpHeight *   
		sizeof(unsigned char));  
	/* 直接拷贝图片数据到OpenCV结构里的话需要翻转 */  
	cvFlip(pImg, NULL, 0);  

	cvShowImage("pImg", pImg);  
	cvWaitKey(0);  
	free(pBmpBuf);  
}  