#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS //trying to resolve a time error
#include"Queue.h"
#include"Stack.h"
#include<iomanip>
#include<fstream>
#include<cstring>
#include<cstdlib> //Only for Clear Screen
#include "Hash.h"
#include <sys/types.h>
#include <sys/stat.h>
#include<sstream>
#include <filesystem>
#include<string>
#include <Windows.h>
#include <tchar.h>
#include<stdlib.h>
#include<vector>
#include<conio.h>
LinkedList RLC(int height, int width, Picture P, LinkedList Li)
{
	int temp = 0;
	int counter = 0;
	for (int i = 0; i < width; i++) 
	{
		counter = i;
		if (P.getPixel(height, i) == 255) {
				Li.insertNode(i);
		}
	}
	Li.insertNode(-1);
	return Li;
}

int main()
{
	/*auto t = std::time(nullptr);
	auto tm = *std::localtime_s(&t);*/
	//put_time(&tm, "%d-%m-%Y %H-%M-%S");
	struct tm newtime;
	time_t t = time(NULL);
	localtime_s(&newtime, &t);
	string log = "Log" + localtime_s(&newtime, &t);
	ofstream logFile;
	logFile.open(log);
	
	logFile << "Log file started at process time: " << localtime_s(&newtime, &t) << endl;
	//prompt
PROMPT:
	string path = "apple-18.pgm", input = " ";
	cout << "Enter File name (for testing use apple-18.pgm):  " << endl;
	cin >> path;
	try
	{
		ifstream file(path);
		if (file)
		{
			cout << "File found..." << endl;
			file.close();
		}
		else
			throw(path);
	}
	catch (string Incorrectpath)
	{
		cout << "Incorrect File Name" << endl;
		goto PROMPT;
	}
	int height, length=0;
	ifstream file;
	file.open(path);
	cout << "Reading File..." << endl;
	for (int i = 0; i < 7; i++) {

		file >> input;
		if (i == 7 - 1)
		{
			length = stoi(input);//stoo -> string to integer func
		}
		else if (i == 7 - 2)//      ^
		{
			height = stoi(input);
		}		
	} //reading file for dimensions
	file.close();

	logFile << "Piucture made at time: " << localtime_s(&newtime, &t) << endl;
	Picture pic(length, height);
	pic.Read(path);

	//Everything above is for  implementation of the questoins.
	//The file to be manipulated will be asked for first, then we will extract size
	//Read it and retrurn as the opject "pic"

	int QuestionNumber = 0;
	char QuestionPart = ' ';
LABEL:
	logFile << "terminal started at: " << localtime_s(&newtime, &t) << endl;
	system("CLS");
	cout << "Welcome to 21i_1679's AKA Ibrahim Akhtars(Mine) Implementatino of Assignment Module 1" << endl;
	cout << "1: Statistics of the Image.\n2: Component Extraction from Queue.\n3: Component Extraction from Stack.\n"
		 << "4 RLC stuff\n5\n6\n"<< endl;
	cout << "Enter the question number you wish to view (1-6): Please only enter integer values" << endl;
	cin >> QuestionNumber;
	try
	{
		if (QuestionNumber<=6 && QuestionNumber>0)
		{
			goto Switch_Case;
		}
		else
			throw(QuestionNumber);
	}
	catch (int IncorrectQuestionNumber)
	{
		cout << "Incorrect Question Number" << endl;
		goto PROMPT;
	}
	Switch_Case:
	switch (QuestionNumber)
	{
	//Question 1
	//done
	case 1:
	{

		logFile << "Question 1: " << localtime_s(&newtime, &t) << endl;
		cout << "a) Mean pixel value by adding all the pixel values and dividing it by the no. of pixels\n"
			<< "b) The number of blackand no.of white pixels.\n"
			<< "c) The average no.of black pixels in each row.\n"
			<< "d) Convert image to its negative thru the image class method." << endl;
		cout << "Enter option (a,b,c,d): " << endl;
		cin >> QuestionPart;
		switch (QuestionPart)
		{
		case 'A':
		{
			
		}
		case 'a':
		{

			logFile << "Question1 part a: " << localtime_s(&newtime, &t) << endl;
			cout << pic.mean();
			system("pause");
			break;
		}
		case 'B':
		{
			
		}
		case 'b':
		{
	
			logFile << "Question1 part b: " << localtime_s(&newtime, &t) << endl;
			cout << "No. of Balck Pixels: " << pic.noBlackPixels()<< endl;
			cout << "No. of WHite Pixels: " << pic.noWhitePixels() << endl;
			system("pause");
			break;
		}
		case 'C':
		{

		}
		case 'c':
		{

			logFile << "Question1 part c: " << localtime_s(&newtime, &t) << endl;
			int * Average = pic.RowAverage();
			for (int i = 0; i < height; i++)
				cout << Average[i] << endl;
			system("pause");
			break;
		}
		case 'D':
		{

		}
		case 'd':
		{
			logFile << "Question1 part d: " << localtime_s(&newtime, &t) << endl;
			Picture* NegativePic = pic.ConvertToNegative();
			cout << "Object of type ptr->Picture named NegativePic has been made containing the Negative of " << path << " ." << endl;
			system("pause");
			break;
		}
		default:
		{

			logFile << "Incorrect option entered: " << localtime_s(&newtime, &t) << endl;
			cout << "Incorrect option number: " << endl;
			goto LABEL;
		}
		}
		
	}
	goto LABEL;
	//Question 2
	//not done
	case 2:
	{;
		logFile << "Question2: " << localtime_s(&newtime, &t) << endl;
		cout << "Main Implementation of this code is currently in development\n"
			<< "However Queue.cpp and Queue.h is in the code as of now and functional"
			<<"The entire image can be found enqueued in the queue named 'q'"
			<<"NOTE: IT IS NOW DONE." << endl;
		system("pause");
		break;
	}
	goto LABEL;
	//Question 3
	//not done
	case 3:
	{
		logFile << "Question3: " << localtime_s(&newtime, &t) << endl;
			cout << "Main Implementation of this code is currently in development\n"
			<< "However Stack.cpp and Queue.h is in the code as of now and functional"
			<< "The entire image can be found pushed in the stack named 's'" 
			<< "NOTE: IT IS NOW DONE. Nope not done nvm" << endl;
			system("pause");
		break;
	}
	goto LABEL;
	//Question 4
	//done
	case 4:
	{
		logFile << "Question4: " << localtime_s(&newtime, &t) << endl;
		logFile << "RLC performed: " << localtime_s(&newtime, &t) << endl;
		cout << "RLC on the image." << endl;
		LinkedList* list = new LinkedList[height+1];
		list[0].insertNode(height);
		list[0].insertNode(length);
		list[0].printList();
		//RLC STUff
		for (int i = 1; i < height; i++) {
			list[i] = RLC(i, length, pic, list[i]);
			cout << endl;
		}
		//List has been made
		//void Write_List_To_File(int width, LinkedList Li, fstream file)
		logFile << "List written to Disk: " << localtime_s(&newtime, &t) << endl;
		fstream file("RLCLIST.txt");
		file.close();
		for (int i = 0; i <= length; i++)
		{
			list[i].WriteListToFile("RLCLIST.txt");
			cout << " List " << i << " written successfully" << endl;
		}
		logFile << "Black Pixels Calcualted: " << localtime_s(&newtime, &t) << endl;
		int totalBlack = 0;
		for (int i = 0; i <= length; i++) {
			totalBlack += list[i].noBlack();
		}
		cout << "Total number of black pixels in selected image are: " << totalBlack << endl;
		
		logFile << "Image from RLC written to Disk: " << localtime_s(&newtime, &t) << endl;
		for (int i = 1; i < length; i++)
			list[i].backToImage(length);

		logFile << "Negative of Image: " << localtime_s(&newtime, &t) << endl;
		for (int i = 1; i < length; i++)
			list[i].toNegative(length);

		system("pause");
		break;
	}
	goto LABEL;
	//Question 5
	//not done
	case 5:
	{

		logFile << "Question5: " << localtime_s(&newtime, &t) << endl;
		cout << "Main Implementation of this code is currently in development\n" << endl;
		system("pause");
		break;
	}
	goto LABEL;
	//Question 6
	//not done
	case 6:
	{
		Hash H(401);
		/*string str1 = "D:\\Assignments\\Assignment Module 1\\Image database\\image";
		string number = "001";

		string image = str1 + number;
		string extension = ".pgm";
		image = image + extension;
		ifstream imageFile(number);


		if (imageFile.is_open())
			cout << "Yes" << endl;
		else
			cout << image << endl;*/
		logFile << "Question6: " << localtime_s(&newtime, &t) << endl;
		cout << "Main Implementation of this code is currently in development\n" << endl;

		//READING IMAGES FROM DIR USING SYSTEM(DIR) AS WELL AS VECTOR ITERATION ALOGN WITH WIN32 API DID NOT WORK
		//WHICH IS WHY IM SELECTING 5 RANDOM PICTURES TO VERIFY THAT THE SYSTEM WORKS

		fstream image1("image001.pgm");
		fstream image2("image002.pgm");
		fstream image3("image003.pgm");
		fstream image4("image004.pgm");
		fstream image5("image005.pgm");
		string i1 = " ", i2 = " ", i3 = " ", i4 = " ", i5 = " ";
		int hashImagesLength[5];
		int hashImagesHeight[5];

		for (int i = 0; i < 7; i++) {

			//part 1:
			image1 >> i1;
			if (i == 7 - 1)
			{
				length = stoi(i1);//stoo -> string to integer func
			}
			else if (i == 7 - 2)//      ^
			{
				height = stoi(i1);
			}

			//part 2:
			image2 >> i2;
			if (i == 7 - 1)
			{
				length = stoi(i2);//stoo -> string to integer func
			}
			else if (i == 7 - 2)//      ^
			{
				height = stoi(i2);
			}

			//part 3:
			image3 >> i3;
			if (i == 7 - 1)
			{
				length = stoi(i3);//stoo -> string to integer func
			}
			else if (i == 7 - 2)//      ^
			{
				height = stoi(i3);
			}

			//part 4:
			image4 >> i4;
			if (i == 7 - 1)
			{
				length = stoi(i4);//stoo -> string to integer func
			}
			else if (i == 7 - 2)//      ^
			{
				height = stoi(i4);
			}

			//part 5:
			image5 >> i5;
			if (i == 7 - 1)
			{
				length = stoi(i5);//stoo -> string to integer func
			}
			else if (i == 7 - 2)//      ^
			{
				height = stoi(i5);
			}
		} //reading file for dimensions
		image1.close();
		image2.close();
		image3.close();
		image4.close();
		image5.close();

		logFile << "Hash question made at time: " << localtime_s(&newtime, &t) << endl;

		Picture HashPic1(hashImagesLength[0], hashImagesHeight[0]);
		Picture HashPic2(hashImagesLength[1], hashImagesHeight[1]);
		Picture HashPic3(hashImagesLength[2], hashImagesHeight[2]);
		Picture HashPic4(hashImagesLength[3], hashImagesHeight[3]);
		Picture HashPic5(hashImagesLength[4], hashImagesHeight[4]);

		HashPic1.Read("image001.pgm");
		HashPic2.Read("image002.pgm");
		HashPic3.Read("image003.pgm");
		HashPic4.Read("image004.pgm");
		HashPic5.Read("image005.pgm");


		H.Question6(HashPic1);
		H.Question6(HashPic2);
		H.Question6(HashPic3);
		H.Question6(HashPic4);
		H.Question6(HashPic5);

		cout << "Task performed successfully" << endl;
		system("pause");
		break;
	}
	goto LABEL;
	//Question Number Incorrect

	default:
	{

		logFile << "Incorrect question number: " << localtime_s(&newtime, &t) << endl;
		cout << "Kindly enter a valid question number." << endl;
		system("pause");
		goto LABEL;
	}
	}
	goto LABEL;
}


