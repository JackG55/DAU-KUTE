#pragma once
#include "Header.h"

struct date
{
	int day = 1;
	int month = 1;
	int year = 1900;
};

struct SV
{
	char Name[40];
	char MaLop[15];
	char MaSV[8];
	date birthday;
	float diemTB = 0;
};

struct Node {
	SV sv;
	Node* next;
};

struct List {
	Node* first;
};

void init(List& l);
bool isEmpty(List l);
Node* createNode(SV x);
void insertAtFirst(List& l, SV x);
void insertAtLast(List& l, SV x);
void insertAtPos(List& l, int pos, SV x);
Node* lastitem(List l);
void deleteAtFirst(List& l);
void deleteAtLast(List& l);
void deleteAtPos(List& l, int pos);
void makeEmpty(List& l);
int lenghtList(List L);

void init(List& l)
{
	l.first = NULL;
}

bool isEmpty(List l)
{
	return (l.first == NULL);
}

int size(List l)
{
	int count = 0;
	while (l.first != NULL)
	{
		l.first = l.first->next;
		count++;
	}
	return count;
}

Node* createNode(SV x)
{
	Node* temp = new Node;
	temp->sv = x;
	temp->next = NULL;
	return temp;
}

void insertAtFirst(List& l, SV x)
{
	Node* temp = createNode(x);
	if (isEmpty(l))
	{
		l.first = temp;
	}
	else
	{
		temp->next = l.first;
		l.first = temp;
	}
}

void insertAtLast(List& l, SV x)
{
	Node* temp = createNode(x);
	if (isEmpty(l))
	{
		l.first = temp;
	}
	else
	{
		Node* curr = l.first;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = temp;
	}
}

void insertAtPos(List& l, int pos, SV x)
{

	Node* temp = createNode(x);
	if (isEmpty(l))
	{
		l.first = temp;
	}
	else if (pos<1 || pos>size(l) + 1)
	{
		printf("Nhap lai pos");
		return;
	}
	else if (pos == 1)
		insertAtFirst(l, x);
	else if (pos == (size(l) + 1))
		insertAtLast(l, x);
	else {
		Node* curr = l.first;
		for (int i = 1; i < pos - 1; i++)
		{
			curr = curr->next;
		}
		temp->next = curr->next;
		curr->next = temp;
	}
}

Node* lastitem(List l)
{
	Node* temp = l.first;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return temp;
}

void deleteAtFirst(List& l)
{
	if (isEmpty(l))
	{
		printf("Khong co du lieu");
		return;
	}
	else
	{
		Node* temp = l.first;
		l.first = l.first->next;
		free(temp);
	}
}

void deleteAtLast(List& l)
{
	if (isEmpty(l))
	{
		printf("Khong co du lieu");
	}
	else
	{
		Node* curr = l.first;
		while (curr->next->next != NULL)
		{
			curr = curr->next;
		}
		Node* temp = curr->next;
		curr->next = NULL;
		free(temp);
	}
}

void deleteAtPos(List& l, int pos)
{
	if (isEmpty(l))
	{
		printf("Khong co du lieu");
	}
	else if (pos<1 || pos>size(l))
	{
		printf("Nhap lai pos");
		return;
	}
	else if (pos == 1)
		deleteAtFirst(l);
	else if (pos == size(l))
		deleteAtLast(l);
	else {
		Node* curr = l.first;
		Node* temp = l.first;
		for (int i = 1; i < pos - 1; i++)
		{
			temp = temp->next;
		}
		curr = temp->next;
		temp->next = curr->next;
		free(curr);

	}
}

void makeEmpty(List& l)
{
	while (!isEmpty(l))
	{
		deleteAtFirst(l);
	}
}

int lenghtList(List L)
{
	int lenght = 0;
	Node* p = L.first;
	while (p != NULL)
	{
		lenght++;
		p = p->next;
	}
	return lenght;
}
