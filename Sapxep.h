#pragma once
#include "List.h"
#include "NhapSV.h"

void swap(SV& a, SV& b);
void selection_sort(SV a[], int n, int p);
void insertion_sort(SV a[], int n, int p);
void buble_sort(SV a[], int n, int p);
int partition_i(SV arr[], int low, int high, int key);
void recursiveQuickSort(SV arr[], int low, int high, int key);

void take_Infor_to_arr(SV a[], int& n);
void Take_infor_to_List(SV a[], List& l, int size);

int ssMaSV(SV a, SV b);
void split_name(char* name, char* b);
int ssHovaTen(SV a, SV b);
int ssMaLop(SV a, SV b);
int ssNgaysinh(SV a, SV b);
int ssDiemTrungbinh(SV a, SV b);
int ss(SV a, SV b, int p);

void sort(int chon_1, int chon_2);

void swap(SV& a, SV& b)
{
	SV temp;
	temp = a;
	a = b;
	b = temp;
}

void selection_sort(SV a[], int n, int p)
{
	int min;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (ss(a[j], a[min], p)==-1)
			{
				min = j;
			}
		}
		if (min != i)
			swap(a[i], a[min]);
	}

	List m;
	init(m);
	Take_infor_to_List(a, m, n);
	write_new_File("sort.dat", m);
	turn_page(m, 0, 5);
	
	
}

void insertion_sort(SV a[], int n, int p)
{
	SV temp;
	int j;
	for (int i = 1; i < n; i++)
	{
		j = i - 1;
		temp = a[i];
		while (ss(temp , a[j], p)==-1 && j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}

	List m;
	init(m);
	Take_infor_to_List(a, m, n);
	write_new_File("sort.dat", m);
	turn_page(m, 0, 5);
}

void buble_sort(SV a[], int n, int p)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (ss(a[j] , a[j - 1],p)==-1)
				swap(a[j - 1], a[j]);
		}
	}

	List m;
	init(m);
	Take_infor_to_List(a, m, n);
	write_new_File("sort.dat", m);
	turn_page(m, 0, 5);
}

int partition_i(SV arr[], int low, int high, int key) {
	SV pivot_element = arr[high];
	int small_i = low - 1;
	for (int i = low; i < high; i++) {
		if (ss(pivot_element, arr[i],key) == 1) {
			small_i += 1;
			swap(arr[i], arr[small_i]);
		}
	}
	small_i += 1;
	swap(arr[small_i], arr[high]);
	return small_i;
}
// dùng cho quick sort
void recursiveQuickSort(SV arr[], int low, int high, int key) {
	if (low <= high) {
		int pivot = partition_i(arr, low, high, key);
		recursiveQuickSort(arr, low, pivot - 1, key);
		recursiveQuickSort(arr, pivot + 1, high, key);
	}

	List m;
	init(m);
	Take_infor_to_List(arr, m, high+1);
	write_new_File("sort.dat", m);
	turn_page(m, 0, 5);
}


void take_Infor_to_arr(SV a[], int &n)
{
	List l;
	init(l);
	readFile("danhsachsinhvien.dat", l);
	n = 0;
	Node* temp = l.first;
	while (temp != NULL)
	{
		a[n] = temp->sv;
		n+=1;
		temp = temp->next;
	}

}

void Take_infor_to_List(SV a[], List &l, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		insertAtLast(l, a[i]);
	}
}

int ssMaSV(SV a, SV b)
{
	if (strcmp(a.MaSV, b.MaSV) > 0) return 1;
	else if (strcmp(a.MaSV, b.MaSV) < 0) return -1;
}

int ssHovaTen(SV a, SV b)
{
	char name_1[40];
	char name_2[40];
	split_name(a.Name, name_1);
	split_name(b.Name, name_2);
	if (strcmp(name_1, name_2)>0)
	{
		return 1;
	}
	else if (strcmp(name_1, name_2) <0)
	{
		return -1;
	}
	else if (strcmp(name_1, name_2) == 0)
	{
		if (strcmp(a.Name, b.Name) > 0) return 1;
		else if (strcmp(a.Name, b.Name) < 0) return -1;
		return ssMaSV(a, b);
	}
}

void split_name(char *name,char *b)
{
	int i,j,k=0;
	for(i=strlen(name)-1;i>=0;i--)
	{
		if(name[i]==' ')
		{
			j=i+1;
			while(name[j] != '\0')
			{
				b[k] = name[j];
				k++;
				j++;	
			}
			b[k] = name[j];
			break;
		}
	}
}

int ssNgaysinh(SV a, SV b)
{
	date i = a.birthday;
	date j = b.birthday;
	if (i.year > j.year)
		return 1;
	else if (i.year < j.year)
		return -1;
	else
	{
		if (i.month > j.month)
			return 1;
		else if (i.month < j.month)
			return -1;
		else
		{
			if (i.day > j.day)
				return 1;
			else if (i.day < j.day)
				return -1;
			else
				return ssMaSV(a, b);
		}
	}
}

int ssDiemTrungbinh(SV a, SV b)
{
	float i = a.diemTB;
	float j = b.diemTB;
	if (i > j)
		return 1;
	else if (i < j)
		return -1;
	else
		return 0;
}

int ssMaLop(SV a, SV b)
{
	if (strcmp(a.MaLop, b.MaLop) > 0)
	{
		return 1;
	}
	else if (strcmp(a.MaLop, b.MaLop) < 0)
	{
		return -1;
	}
	else if (strcmp(a.MaLop, b.MaLop) == 0)
	{
		return ssHovaTen(a, b);
	}
}

int ss(SV a, SV b, int p)
{
	switch (p)
	{
	case 1: return ssMaSV(a, b); break;
	case 2: return ssHovaTen(a, b); break;
	case 3: return ssNgaysinh(a, b); break;
	case 4: return ssDiemTrungbinh(a, b); break;
	case 5: return ssMaLop(a, b); break;
	}
}

void sort(int chon_1, int chon_2)
{
	int size = 0;
	SV temp[10000];
	take_Infor_to_arr(temp, size);
	switch (chon_1)
	{
	case 3:
		selection_sort(temp, size, chon_2);
		break;
	case 4:
		insertion_sort(temp, size, chon_2);
		break;
	case 5:
		buble_sort(temp, size, chon_2);
		break;
	case 6:
		recursiveQuickSort(temp, 0, size - 1, chon_2);
		break;
	}

}

