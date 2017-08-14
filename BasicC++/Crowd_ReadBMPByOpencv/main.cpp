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
	/* ��ȡ�ļ� */  
	FILE * fp = fopen(bmpPath.c_str(), "rb");  
	assert(fp != NULL);  

	/* �����ļ�ͷ */  
	fseek(fp, sizeof(BITMAPFILEHEADER),0);  

	/* ��ȡ��Ϣͷ */  
	fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1,fp);  

	int bmpWidth = infoHeader.biWidth;  
	int bmpHeight = infoHeader.biHeight;  
	int biBitCount = infoHeader.biBitCount;               
	int lineByte=(bmpWidth * biBitCount/8+3)/4*4;       /* �������������ͼ��ÿ��������ռ���ֽ�����������4�ı�����*/  

	/* �Ҷ�ͼ������ɫ������ɫ�����Ϊ256���ؼ� */  
	RGBQUAD* pColorTable;  
	if(biBitCount==8)  
	{  

		//������ɫ������Ҫ�Ŀռ䣬����ɫ����ڴ�  

		pColorTable=new RGBQUAD[256];  

		fread(pColorTable,sizeof(RGBQUAD),256,fp);  

	}  
	//����λͼ��������Ҫ�Ŀռ䣬��λͼ���ݽ��ڴ�  
	unsigned char* pBmpBuf=new unsigned char[lineByte * bmpHeight];  

	fread(pBmpBuf,1,lineByte * bmpHeight,fp);  

	fclose(fp);//�ر��ļ�  


	IplImage* pImg = cvCreateImage(cvSize(bmpWidth, bmpHeight), 8, 1);  

	assert(pImg != NULL);  

	/* ����ͼ�����ݵ�opencv���ݽṹ�ܲ���ʾ */  
	memcpy(pImg->imageData, pBmpBuf, lineByte * bmpHeight *   
		sizeof(unsigned char));  
	/* ֱ�ӿ���ͼƬ���ݵ�OpenCV�ṹ��Ļ���Ҫ��ת */  
	cvFlip(pImg, NULL, 0);  

	cvShowImage("pImg", pImg);  
	cvWaitKey(0);  
	free(pBmpBuf);  
}  