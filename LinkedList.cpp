#include "LinkedList.h"
void LinkedList::insertNode(int data)
{
	Node* newNode = new Node(data);

	if (head == NULL) {
		head = newNode;
		return;
	}

	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

void LinkedList::printList()
{
	Node* temp = head;
	if (head == NULL)
	{
		cout << "No List" << endl;
		return;
	}

	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void LinkedList::deleteNode(int Offset)
{
	Node* temp1 = head, * temp2 = NULL;
	int ListLen = 0;
	if (head == NULL) {
		cout << "List empty." << endl;
		return;
	}
	//length
	while (temp1 != NULL) {
		temp1 = temp1->next;
		ListLen++;
	}
	if (ListLen < Offset) {
		cout << "Index out of range"
			<< endl;
		return;
	}
	temp1 = head;
	if (Offset == 1) {

		// Update head
		head = head->next;
		delete temp1;
		return;
}
	while (Offset-- > 1) {

		temp2 = temp1;
		temp1 = temp1->next;
	}
	temp2->next = temp1->next;
	delete temp1;
}

int LinkedList::getCurrentData()
{
	Node* temp = head;
	while (temp != NULL)
	{
		if (temp->next == NULL)
			return temp->data;
	}
}

int LinkedList::popHead()
{
	int temp = head->data;
	this->deleteNode(temp);
	return temp;
}

void LinkedList::WriteListToFile(string fileName)
{
	fstream file(fileName, ios::app);
	if (!file.is_open()) {
		return;
	}

	for (Node* curr = head; curr != NULL; curr = curr->next)
	{
		file << curr->data;
		file << " ";
	}

	file << endl;
}

int LinkedList::noBlack()
{
	int amount = 0;
	Node* temp = head;
	if (head == NULL)
	{
		return amount;
	}

	while (temp != NULL)
	{
		amount++;
		temp = temp->next;
	}
	return amount;
}

//void LinkedList::normalize(){
//	Node* temp = this->head;
//
//	int i = 0;
//
//	while (temp->next != NULL)
//	{
//		if (temp->data = -1)
//			break;
//		if(i=)
//	}
//}

void LinkedList::backToImage(int length)
{
	fstream image("RlcImage.pgm", ios::app);
	Node* temp = this->head;
	if (image.is_open())
	{
		int i = 0;
		for(int i=0; i<length; i++)
		{
			if (temp->data == -1)
			{
				image <<0;
				image << " ";
				continue;
			}
			if (temp->data == i)
			{
				image << 255;
				temp = temp->next;
				image << " ";
			}
			/*if (temp->data == i)
			{
				image << 255;
			}
			else if (temp->data != -1)
			{
				image << 0;
			}
			else if (temp->data == -1)
			{
				for (int j = i; j < length; j++) {
					image << 0;
				}
				break;
			}*/
		}
		image << endl;
	}
}

void LinkedList::toNegative(int length)
{
	fstream image("RlcNegativeImage.pgm", ios::app);
	Node* temp = this->head;
	if (image.is_open())
	{
		int i = 0;
		for (int i = 0; i < length; i++)
		{
			if (temp->data == -1)
			{
				image << 255;
				image << " ";
				continue;
			}
			if (temp->data == i)
			{
				image << 0;
				temp = temp->next;
				image << " ";
			}
		}
		image << endl;
	}
}