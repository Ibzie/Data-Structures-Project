#include<iostream>
#include<fstream>
#include<cstring>
#include<sstream>
using namespace std;
class Picture{
public:
	int **arr;
	long long size;
	int sum;
	long height;
	long Length;
	int nBlack, nWhite;
	bool Negative, Normal;
	string FilePath;
	static int image_number;
	bool inRange(int l, int w) {
		if ((l > Length || l < 0) && (w > height || w < 0))
			return false;
		else
			return true;
	}
	Picture(int, int);
	void printArray();
	Picture* Read(string file_Path)
	{
		ifstream file;
		string garbage; //temp for storing useless lines
		char ch;
		file.open(file_Path);

		//Skipping Useless Lines
		for (int i = 0; i < 8; i++)
			file >> garbage;
		
		/*-842150451*/
		int temp;
		//Reading File
		int m = height, n = Length;
		if (file.is_open())
		{
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < Length; j++)
				{
					file >> ch;
					temp = int(ch);
					if (temp == 'ÿ') {
						arr[i][j] = 255;
						nBlack++;
					}
					else {
						arr[i][j] = 0;
						nWhite++;
					}
					size++;
					sum += arr[i][j];
				}
			}
		}
		else {
			cout << "File not found" << endl;
			return this;
		}
		cout << "File Successfully Read" << endl;
		//Display check
		//for (int i = 0; i < m; i++) {
		//	for (int j = 0; j < Length; j++)
		//	{
		//		cout << arr[i][j];
		//	}
		//	cout << endl;
		//	cout << endl;
		//	cout << endl;
		//}


		file.close();
		return this;
	}
	void Save();
	int getLen()
	{
		return Length;
	}
	int getHeight()
	{
		return height;
	}
	int getPixel(int length, int width);
	void setPixel(int length, int width, int value);
	long long getSize();
	Picture* ConvertToNegative()
	{
		if(!Negative)
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < Length; j++) {
				if (getPixel(i, j) == 0)
					setPixel(i, j, 255);
				else
					setPixel(i, j, 0);
			}
		}

		else
			cout<<"It is already a negative image"<<endl;

		return this;
	}
	Picture* Normalize()
	{
		if (!Negative)
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < Length; j++) {
					if (getPixel(i, j) == 255)
						setPixel(i, j, 0);
					else
						setPixel(i, j, 255);
				}
			}

		else
			cout << "It is already a already a normal image" << endl;

		return this;

	}
	float mean()
	{
		return sum/size;
	}
	int noBlackPixels();
	int noWhitePixels();
	int* RowAverage();
};


