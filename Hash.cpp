#include "Hash.h"
#include <sstream>
#include<cstring>
Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new Node * [b];
	for (int i = 0; i < b; i++)
		table[i] = NULL;
}
int Hash::hashing(int key)//for getting index
{
	return key % BUCKET;
}
void Hash::Display_Hash()
{
	for (int i = 0; i < BUCKET; i++)
	{
		Node* temp = table[i]; //getting individual lists
		cout << "Index " << i << ": ";
		while (temp != NULL)
		{
			cout << temp->data << " | ";
			temp = temp->next;
		}
		cout << endl;
	}
}
void Hash::insert(int key)
{
	int index = hashing(key);//getting index
	Node* temp = table[index];
	while (temp != NULL)
	{
		if (temp->data == key) return;
		temp = temp->next;
	}
	temp = new Node;
	temp->data = key;
	temp->next = table[index];
	table[index] = temp;
}

void Hash::Question6(Picture P)
{
	int* horizontalProjection = new int[P.Length];
	int* verticalProjection = new int[P.height];
	int temp = 0;
	long sumHorizontal=0, sumVertical=0;
	for (int i = 0; i < P.height; i++)
	{
		temp = 0;
		for (int j = 0; i < P.Length; i++)
		{
			if (P.arr[i][j] == 255)
			{
				temp++;
			}
			horizontalProjection[i] = temp;
			sumHorizontal += temp;
		}
	}

	for (int i = 0; i < P.Length; i++)
	{
		temp = 0;
		for (int j = 0; i < P.height; i++)
		{
			if (P.arr[i][j] == 255)
			{
				temp++;
			}
			verticalProjection[i] = temp;
			sumVertical += temp;
		}
	}


	long sum = sumHorizontal + sumVertical;
	
	insert(sum);
	/*std::string str1, str2, value;
	for (int i =0 ; i< sizeof(verticalProjection); i++)
		str1 += to_string(verticalProjection[i]);

	for (int i = 0; i < sizeof(horizontalProjection); i++)
		str2 += to_string(horizontalProjection[i]);

	value = str1 + str2;*/
	
	/*stringstream s(value);*/

	/*string** fourVal = new string*[value.length()/4];

	for (int i = 0; i < value.length(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fourVal[i][j] = value[i * j];
		}
	}*/
	//convert fourVal[i] to integer and sum it up
	//insert it into hash
}

bool Hash::find(Picture P)
{
	int* horizontalProjection = new int[P.Length];
	int* verticalProjection = new int[P.height];
	int temp = 0;
	long sumHorizontal =0, sumVertical=0;
	for (int i = 0; i < P.height; i++)
	{
		temp = 0;
		for (int j = 0; i < P.Length; i++)
		{
			if (P.arr[i][j] == 255)
			{
				temp++;
			}
			horizontalProjection[i] = temp;
			sumHorizontal += temp;
		}
	}

	for (int i = 0; i < P.Length; i++)
	{
		temp = 0;
		for (int j = 0; i < P.height; i++)
		{
			if (P.arr[i][j] == 255)
			{
				temp++;
			}
			verticalProjection[i] = temp;
			sumVertical += temp;
		}
	}


	long sum = sumHorizontal + sumVertical;

	bool status = false;
	for (int i = 0; i < BUCKET; i++)
	{
		Node* temp = table[i]; //getting individual list
		while (temp != NULL)
		{
			if (temp->data == (sum % 401)) {
				status = true;
				return status;
			}
			temp = temp->next;
		}
	}
	return status;
}
