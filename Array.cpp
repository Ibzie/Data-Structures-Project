#include "Array.h"

int Picture::image_number = 0;
Picture::Picture(int m, int n)
{
	cout << "OBJ MADE of " << m << " " << n << endl;
	image_number++;
	arr = new int* [m];
	for (int i = 0; i < m; i++) {

		// Declare a memory block
		// of size n
		arr[i] = new int[n];
	}

	size = 0;
	sum = 0;
	nBlack = 0;
	nWhite = 0;
	//this->size = m*n;
	height = m;
	Length = n;
	Negative = false;
	Normal = true;
	FilePath = " ";
}
void Picture::printArray()
{
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < Length; j++)
			{
				cout << arr[i][j];
			}
			cout << endl;
			cout << endl;
			cout << endl;
		}
}
void Picture::Save()
{
	/*
	P5
#apple-18.pgm
#converted PNM file
256 256
255*/
	string file_name = "Image.pgm";
	ofstream f(file_name, ios_base::out |ios_base::binary| ios_base::trunc);
	int maxColor = 255;
	f << "P5\n" << Length << " " << height << "\n" << maxColor << "\n";
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < Length; j++) {
			f << arr[i][j];
		}
	}
}
int Picture::getPixel(int length, int width)
{
	if(inRange(length, width))
		return arr[length][width];
	else
	{
		cout << "Incorrect Value Entered"<<endl;
		return -100000000;
	}
		

}
void Picture::setPixel(int length, int width, int value)
{
	if ((inRange(length, width)) && (value == 0 || value == 255)) 
		arr [length][width] = value;
	else cout << "Incorrect Value Entered" << endl;
}
long long Picture::getSize() {
	return size;
}
int Picture::noBlackPixels()
{
	return nBlack;
}
int Picture::noWhitePixels()
{
	return nWhite;
}
int* Picture::RowAverage()
{
	int* average = new int[height];

	for (int i = 0; i < height; i++) average[i] = 0;

	for (int i = 0; i < height; i++)
	{
		
		for (int j = 0; j < Length; j++)
		{
			if (arr[i][j] == 255)
				average[i]++;
		}
	}

	for (int i = 0; i < height; i++) average[i]/=Length;

	return average;
}