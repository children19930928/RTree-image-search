// LoadImage.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "atlimage.h"
#include <fstream>
#include <cmath>
using namespace std;

#define dimI 4	
#define dimJ 2	
#define dimK 2	

//RGB颜色直方图（维度dimI*dimJ*dimK）
void RGB_Color_Histogram(char* name, CImage image, char* buffer)
{
	int iHeight, iWidth;
	BYTE byteR, byteG, byteB;
	int Histogram[dimI][dimJ][dimK] = {};
	int result[dimI][dimJ][dimK];
	char temp[16];
	iHeight = image.GetHeight();
	iWidth = image.GetWidth();

	for ( int iRow=0; iRow<iWidth; iRow++)
		for ( int iCol=0; iCol<iHeight; iCol++ )
		{
			COLORREF colorref = image.GetPixel( iRow, iCol );
			byteR =  GetRValue( colorref );
			byteG =  GetGValue( colorref );
			byteB =  GetBValue( colorref );

			Histogram[(byteR*dimI)>>8][(byteG*dimJ)>>8][(byteB*dimK)>>8]++;		
		}
	//strcat(buffer, "rect ");	
	strcat(buffer, name);	
	strcat(buffer, ": \n");	
	for (int i = 0; i < dimI; i++)
	{
		for (int j = 0; j < dimJ; j++)
		{
			for (int k = 0; k < dimK; k++)
			{
				result[i][j][k] = 100000 * (1.0 * Histogram[i][j][k] / iHeight / iWidth);
				sprintf(temp, "%d ", result[i][j][k]);
				strcat(buffer, temp);
			}
		}
	}
	strcat(buffer, "\n");
}
int* RGB_Color_Histogram(CImage image)
{
	int ijk = 0;
	int re[dimI*dimJ*dimK] = {};//返回结果
	int iHeight, iWidth;
	BYTE byteR, byteG, byteB;
	int Histogram[dimI][dimJ][dimK] = {};
	int result[dimI][dimJ][dimK];
	char temp[16];
	iHeight = image.GetHeight();
	iWidth = image.GetWidth();

	for ( int iRow=0; iRow<iWidth; iRow++)
		for ( int iCol=0; iCol<iHeight; iCol++ )
		{
			COLORREF colorref = image.GetPixel( iRow, iCol );
			byteR =  GetRValue( colorref );
			byteG =  GetGValue( colorref );
			byteB =  GetBValue( colorref );
			
			Histogram[(byteR*dimI)>>8][(byteG*dimJ)>>8][(byteB*dimK)>>8]++;		
		}
	//strcat(buffer, "rect ");	
	//strcat(buffer, name);	
	//strcat(buffer, ": \n");	
	for (int i = 0; i < dimI; i++)
	{
		for (int j = 0; j < dimJ; j++)
		{
			for (int k = 0; k < dimK; k++)
			{
				result[i][j][k] = 100000 * (1.0 * Histogram[i][j][k] / iHeight / iWidth);
				re[ijk++] = result[i][j][k];
				//sprintf(temp, "%d ", result[i][j][k]);
				//strcat(buffer, temp);
			}
		}
	}
	return re;
	//strcat(buffer, "\n");
}

//HSV颜色直方图（维度dimI*dimJ*dimK）
void HSV_Color_Histogram(char* name, CImage image, char* buffer)
{
	int iHeight, iWidth, x, y, z ;
	BYTE byteR, byteG, byteB, maxRGB, minRGB;
	double doubleH, doubleS, doubleV;
	int Histogram[dimI][dimJ][dimK] = {};
	int result[dimI][dimJ][dimK];
	char temp[16];
	iHeight = image.GetHeight();
	iWidth = image.GetWidth();
	for ( int iRow=0; iRow<iWidth; iRow++)
	{
		for ( int iCol=0; iCol<iHeight; iCol++ )
		{
			COLORREF colorref = image.GetPixel( iRow, iCol );
			byteR =  GetRValue( colorref );
			byteG =  GetGValue( colorref );
			byteB =  GetBValue( colorref );
			maxRGB = max(max(byteR, byteG),byteB);
			minRGB = min(min(byteR, byteG),byteB);

			//H
			if(maxRGB == minRGB)
				doubleH = 0;
			else if(byteR == maxRGB)
			{
				doubleH = 60*(byteG-byteB)/(maxRGB-minRGB);
				if(byteG<byteB)	doubleH += 360;
			}
			else if(byteG == maxRGB)
				doubleH = 120+60*(byteB-byteR)/(maxRGB-minRGB);
			else if(byteB == maxRGB)
				doubleH = 240+60*(byteR-byteG)/(maxRGB-minRGB);
			//S
			if(maxRGB != 0)
				doubleS = 1.0*(maxRGB-minRGB)/maxRGB;
			else
				doubleS = 0;
			//V
			doubleV = 1.0*maxRGB/255;

			if(doubleH == 360)
				x = dimI - 1;
			else
				x = doubleH/(360/dimI);//doubleH>180?1:0;;//（0~360）
			if(doubleS == 1)
				y = dimJ - 1;
			else
				y = doubleS/(1/dimJ);//>0.5?1:0;//（0~1）
			if(doubleV == 1)
				z = dimK - 1;
			else
				z = doubleV/(1/dimK);//>0.5?1:0;//（0~1）

			Histogram[x][y][z]++;		
		}
	}
	//strcat(buffer, "rect ");	
	strcat(buffer, name);	
	strcat(buffer, ": \n");	
	for (int i = 0; i < dimI; i++)
	{
		for (int j = 0; j < dimJ; j++)
		{
			for (int k = 0; k < dimK; k++)
			{
				result[i][j][k] = 100000 * (1.0 * Histogram[i][j][k] / iHeight / iWidth);
				//cout << result[i][j][k] << " ";
				sprintf(temp, "%d ", result[i][j][k]);
				strcat(buffer, temp);
			}
		}
	}
	//cout << endl;
	strcat(buffer, "\n");
}
int* HSV_Color_Histogram(CImage image)
{
	int ijk = 0;
	int re[dimI*dimJ*dimK] = {};//返回结果

	int iHeight, iWidth, x, y, z ;
	BYTE byteR, byteG, byteB, maxRGB, minRGB;
	double doubleH, doubleS, doubleV;
	int Histogram[dimI][dimJ][dimK] = {};
	int result[dimI][dimJ][dimK];
	char temp[16];
	iHeight = image.GetHeight();
	iWidth = image.GetWidth();
	for ( int iRow=0; iRow<iWidth; iRow++)
	{
		for ( int iCol=0; iCol<iHeight; iCol++ )
		{
			COLORREF colorref = image.GetPixel( iRow, iCol );
			byteR =  GetRValue( colorref );
			byteG =  GetGValue( colorref );
			byteB =  GetBValue( colorref );
			maxRGB = max(max(byteR, byteG),byteB);
			minRGB = min(min(byteR, byteG),byteB);

			//H
			if(maxRGB == minRGB)
				doubleH = 0;
			else if(byteR == maxRGB)
			{
				doubleH = 60*(byteG-byteB)/(maxRGB-minRGB);
				if(byteG<byteB)	doubleH += 360;
			}
			else if(byteG == maxRGB)
				doubleH = 120+60*(byteB-byteR)/(maxRGB-minRGB);
			else if(byteB == maxRGB)
				doubleH = 240+60*(byteR-byteG)/(maxRGB-minRGB);
			//S
			if(maxRGB != 0)
				doubleS = 1.0*(maxRGB-minRGB)/maxRGB;
			else
				doubleS = 0;
			//V
			doubleV = 1.0*maxRGB/255;

			if(doubleH == 360)
				x = dimI - 1;
			else
				x = doubleH/(360/dimI);//doubleH>180?1:0;;//（0~360）
			if(doubleS == 1)
				y = dimJ - 1;
			else
				y = doubleS/(1/dimJ);//>0.5?1:0;//（0~1）
			if(doubleV == 1)
				z = dimK - 1;
			else
				z = doubleV/(1/dimK);//>0.5?1:0;//（0~1）

			Histogram[x][y][z]++;		
		}
	}

	for (int i = 0; i < dimI; i++)
	{
		for (int j = 0; j < dimJ; j++)
		{
			for (int k = 0; k < dimK; k++)
			{
				result[i][j][k] = 100000 * (1.0 * Histogram[i][j][k] / iHeight / iWidth);
				re[ijk++] = result[i][j][k];
			}
		}
	}
	return re;
}

//灰度共生矩阵(固定4*5=20维)
void Gray(int *p[], CImage image)
{
	int iHeight, iWidth;
	BYTE byteR, byteG, byteB;
	int g;
	iHeight = image.GetHeight();
	iWidth = image.GetWidth();
	for ( int iRow=0; iRow<iWidth; iRow++)
	{
		for ( int iCol=0; iCol<iHeight; iCol++ )
		{
			COLORREF colorref = image.GetPixel( iRow, iCol );
			byteR =  GetRValue( colorref );
			byteG =  GetGValue( colorref );
			byteB =  GetBValue( colorref );
			g = 0.229*byteR + 0.587*byteG + 0.114*byteB;
			p[iCol][iRow] = g>>4;
		}
	}
}
void Cooccurrence_Matrix(double (*P)[16], int *p[], int flag, int iHight, int iWidth)
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			P[i][j] = 0;
		}
	}
	if (flag == 1)
	{
		for (int i = 0; i < iHight; i++)
		{
			for (int j = 0; j < iWidth-1; j++)
			{
				P[p[i][j]][p[i][j+1]]++;
				P[p[i][j+1]][p[i][j]]++;
			}
		}
	}
	else if (flag == 2)
	{
		for (int i = 0; i < iHight-1; i++)
		{
			for (int j = 0; j < iWidth-1; j++)
			{
				P[p[i][j]][p[i+1][j+1]]++;
				P[p[i+1][j+1]][p[i][j]]++;
			}
		}
	}
	else if (flag == 3)
	{
		for (int i = 0; i < iHight-1; i++)
		{
			for (int j = 0; j < iWidth; j++)
			{
				P[p[i][j]][p[i+1][j]]++;
				P[p[i+1][j]][p[i][j]]++;
			}
		}
	}
	else if (flag == 4)
	{
		for (int i = 1; i < iHight; i++)
		{
			for (int j = 0; j < iWidth-1; j++)
			{
				P[p[i][j]][p[i-1][j+1]]++;
				P[p[i-1][j+1]][p[i][j]]++;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			sum += P[i][j];
		}
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			P[i][j] = 1.0 * P[i][j] / sum;
		}
	}
}
double E(double (*P)[16])
{
	double result = 0;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			result += (P[i][j]*P[i][j]);
		}
	}
	return result;
}
double H(double (*P)[16])
{
	double result = 0;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (P[i][j] != 0)
			{
				result += P[i][j]*log(P[i][j]);
			}
		}
	}
	return -result;
}
double I(double (*P)[16])
{
	double result = 0;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			result += P[i][j]*(i-j)*(i-j);
		}
	}
	return result;
}
double C(double (*P)[16])
{
	double result = 0;
	double mux = 0, muy = 0,sigmax = 0, sigmay = 0;
	double temp = 0;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			temp += P[i][j];
		}
		mux += i * temp;
		temp = 0;
	}
	for (int j = 0; j < 16; j++)
	{
		for (int i = 0; i < 16; i++)
		{
			temp += P[i][j];
		}
		muy += j * temp;
		temp = 0;
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			temp += P[i][j];
		}
		sigmax += (i-mux)*(i-mux) * temp;
		temp = 0;
	}
	for (int j = 0; j < 16; j++)
	{
		for (int i = 0; i < 16; i++)
		{
			temp += P[i][j];
		}
		sigmay += (j-muy)*(j-muy) * temp;
		temp = 0;
	}
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (P[i][j] != 0)
			{
				result += P[i][j]*(i-mux)*(j-muy);
			}	
		}
	}
	result = result / sqrt(sigmax) /sqrt(sigmay);
	return result;
}
double L(double (*P)[16])
{
	double result = 0;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			result += P[i][j] / (1 + (i - j) * (i - j));
		}
	}
	return result;
}
void GrayLevel_Cooccurrence_Matrix(char* name, CImage image, char* buffer)
{
	int **p;
	char temp[128];
	int iHeight, iWidth;
	iHeight = image.GetHeight();
	iWidth = image.GetWidth();

	int  result;
	double P[16][16] = {};
	p = new int *[iHeight];
	for (int i = 0; i < iHeight; i++)
		p[i] = new int[iWidth];
	//strcat(buffer, "rect ");
	strcat(buffer, name);
	strcat(buffer, ": \n");
	Gray(p, image);
	Cooccurrence_Matrix(P, p, 1, iHeight, iWidth);
	result = E(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	result = H(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	result = I(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	result = C(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	result = L(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	Cooccurrence_Matrix(P, p, 2, iHeight, iWidth);
	result = E(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	result = H(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	result = I(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	result = C(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	result = L(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	Cooccurrence_Matrix(P, p, 3, iHeight, iWidth);
	result = E(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	result = H(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	result = I(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	result = C(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	result = L(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	Cooccurrence_Matrix(P, p, 4, iHeight, iWidth);
	result = E(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	result = H(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	result = I(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	result = C(P) * 10000;
	sprintf(temp, "%d ", result);
	strcat(buffer, temp);
	result = L(P) * 10000;
	sprintf(temp, "%d\n", result);
	strcat(buffer, temp);
	for (int i = 0; i < iHeight; i++)
		delete []p[i];
}

void getfeature(char* name, char* buffer, int flag)
{
	CImage image;
	char sname[100] = "image/";
	strcat(sname, name);
	image.Load(sname);

	if (flag == 0)
		RGB_Color_Histogram(name, image, buffer);
	else if (flag == 1)
		HSV_Color_Histogram(name, image, buffer);
	else if (flag == 2)
		GrayLevel_Cooccurrence_Matrix(name, image, buffer);

	image.GetBits();
	image.Destroy();
}


void main()
{
	char charArray[100];
	char buffer[1024] = "\0";
	
	int flag = 0;	
	while(flag != -1)
	{
		cout<<"请输入特征提取方法："<<endl;
		cout<<"0 代表RGB颜色直方图；" << "1 代表HSV颜色直方图；" << "2 代表灰度共生矩阵。（输入-1退出程序）"<<endl;
		cin>>flag;
		if (flag == 0)
		{
			ofstream outFile("data_color_RGB.txt", ios::out);
			int i= 0;
			ifstream inFile("imagelist.txt", ios::in);
			//inFile.seekg(ios::beg);
			while(!inFile.eof())
			{
				inFile.getline(charArray, 100);
				cout<<flag<<"正在提取第"<<++i<<"幅图像(" << charArray << ")特征"<<endl;
				getfeature(charArray, buffer, flag);
				cout << buffer;
				outFile<<buffer;
				buffer[0] = '\0';
			}
		}
		else if(flag == 1)
		{
			ofstream outFile("data_color_HSV_422.txt", ios::out);
			int i= 0;
			ifstream inFile("imagelist.txt", ios::in);
			while(!inFile.eof())
			{
				inFile.getline(charArray, 100);
				cout<<flag<<"正在提取第"<<++i<<"幅图像(" << charArray << ")特征"<<endl;
				getfeature(charArray, buffer, flag);
				outFile<<buffer;
				buffer[0] = '\0';
			}
		}
		else if(flag == 2)
		{
			ofstream outFile("data_tex_GLCM.txt", ios::out);
			int i= 0;
			ifstream inFile("imagelist.txt", ios::in);
			while(!inFile.eof())
			{
				inFile.getline(charArray, 100);
				cout<<flag<<"正在提取第"<<++i<<"幅图像(" << charArray << ")特征"<<endl;
				getfeature(charArray, buffer, flag);
				outFile<<buffer;
				buffer[0] = '\0';
			}
			flag = 
		}
		else
		{
			cout<<"输入错误"<<endl;
		}
	}
}
