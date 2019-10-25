#pragma once
#include "List.h"
#include "NhapSV.h"
#include <vector>
#define rowPage 15
#define posOfNumPage 15

void readFile(const char* Filename, List& l);
void makeFrame_small(int width, int hight, int x, int y);
void makeFrame_big(int width, int hight, int x, int y, int color);
void makeFrame_small_thin(int width, int hight, int x, int y);
void MakeMainMenu(List a);
int partition_i(SV arr[], int low, int high, int key);
void recursiveQuickSort(SV arr[], int low, int high, int key);

void giao_dien_tim_kiem(int x, int y);
void delSceen();
void printStudent(int row, int i, SV a);
void printSearch(List& L, vector<int> setColor, int key);
void makeOutputConsoleFrame(int lenght);
void delLine(int x, int y, int length);
int listToArray(SV arr[1000], List& L);
void arrToList(SV arr[1000], List& L, int size);
int checkDiem(char a[]);
int check(char value[]);
int check(char value[]);
int compareWithKeyword(SV sv, char keyword[], int key);
int searchKey(char source[], char Key[]);
int searchToMid(SV Arr[], int size, char keyword[], int key);
void searchUp(SV Arr[], int size, char keyword[], int key, int mid, vector<int>& setColor);
void searchType(int Key, int key, List& L, int type);


void delSceen() {//xoa man hinh tai vung vi tri 
	for (int i = 0; i <= (posOfNumPage * 2); i++) {
		delLine(5, 6 + i, 90);
	}
}

void printStudent(int row, int i, SV a)
{
	showCursor();
	gotoxy(12, (row +8) + row - 1); cout << (i + 1);
	gotoxy(19, (row + 8)+ row - 1); cout << a.MaLop;
	gotoxy(33, (row + 8) + row - 1); cout << a.MaSV;
	gotoxy(47, (row + 8) + row - 1); cout << a.Name;
	gotoxy(74, (row + 8) + row - 1); printf("%2d/%2d/%4d", a.birthday.day, a.birthday.month, a.birthday.year);
	gotoxy(93, (row + 8) + row - 1); cout << a.diemTB;
}

void printSearch(List& L, vector<int> setColor, int key)
{
	SV arr[1000];
	int size = listToArray(arr, L);
	hideCursor();
	int sizeofList = lenghtList(L);
	vector<int> lenPage;
	while (sizeofList > 0)
	{
		if (sizeofList >= rowPage) lenPage.push_back(rowPage);
		else
		{
			lenPage.push_back(sizeofList);
			break;
		}
		sizeofList = sizeofList - rowPage;
	}
	int i = 2;
	int pos = -rowPage;
	int page = -1;
	while (1)
	{
		switch (i)
		{
		case 1:
		{
			delSceen();
			page = page - 1;
			if (page == -1) page = lenPage.size() - 1;
			pos = pos - rowPage;
			if (pos == -rowPage) pos = (lenPage.size() - 1) * rowPage;
			makeOutputConsoleFrame(lenPage.at(page));
			if (key != 1)
			{
				delLine(80, 2, 15);
				Color(14);
				gotoxy(80, 3);
				cout << "Exit: ESC";
			}
			Color(15);
			int row = 0;
			for (int i = pos; i < (pos + rowPage); i++)
			{
				if (setColor.at(i) == 0)
				{
					Color(15);
					printStudent(row, i, arr[i]);
				}
				if (setColor.at(i) == 1)
				{
					Color(10);
					printStudent(row, i, arr[i]);
				}
				if (i > size - 2)
					break;
				row++;
			}
			Color(15);
			hideCursor();
			gotoxy(105, 6 + posOfNumPage * 2); cout << "            ";
			gotoxy(100, 6 + posOfNumPage * 2); cout << "Page ";
			gotoxy(105, 6 + posOfNumPage * 2); cout << page + 1 << " / " << lenPage.size();
		}
		break;
		case 2:
		{
			delSceen();
			page = page + 1;
			if (page == lenPage.size()) page = 0;
			pos = pos + rowPage;
			if (pos == lenPage.size() * rowPage) pos = 0;
			makeOutputConsoleFrame(lenPage.at(page));
			if (key != 1)
			{
				delLine(80, 2, 15);
				Color(14);
				gotoxy(80, 3);
				cout << "Exit: ESC";
			}
			Color(15);
			int row = 0;
			for (int i = pos; i < (pos + rowPage); i++)
			{
				if (setColor.at(i) == 0)
				{
					Color(15);
					printStudent(row, i, arr[i]);
				}
				if (setColor.at(i) == 1)
				{
					Color(10);
					printStudent(row, i, arr[i]);
				}
				if (i > size - 2) break;
				row++;
			}
			Color(15);
			hideCursor();
			gotoxy(105, 6 + posOfNumPage * 2); cout << "                  ";
			gotoxy(100, 6 + posOfNumPage * 2); cout << "Page ";
			gotoxy(105, 6 + posOfNumPage * 2); cout << page + 1 << " / " << lenPage.size();
		}
		break;
		default: break;
		}
		char i = _getch();
		if (i == esc() || i == left())
		{
			system("cls");
			break;
		}
	}
}

void makeOutputConsoleFrame(int lenght)
{
	HANDLE hconsolepos;
	hconsolepos = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize;
	bufferSize = { 100,100 };
	SetConsoleScreenBufferSize(hconsolepos, bufferSize);
	Color(15);

	int pos_y = 6;
	for (int i = 5; i < 2 * lenght + pos_y; i++)
	{
		gotoxy(9, i);
		printf("%c", 179);
		gotoxy(15, i);
		printf("%c", 179);
		gotoxy(29, i);
		printf("%c", 179);
		gotoxy(44, i);
		printf("%c", 179);
		gotoxy(69, i);
		printf("%c", 179);
		gotoxy(89, i);
		printf("%c", 179);
		gotoxy(99, i);
		printf("%c", 179);
	}
	for (int i = 10; i < 99; i++)
	{
		gotoxy(i, 4);
		printf("%c", 196);
		gotoxy(i, 6);
		printf("%c", 196);
		for (int j = 1; j <= lenght; j++)
		{
			gotoxy(i, 2 * j + pos_y);
			printf("%c", 196);
		}
	}
	gotoxy(9, 4);
	printf("%c", 218);
	gotoxy(99, 4);
	printf("%c", 191);
	gotoxy(9, 2 * lenght + pos_y);
	printf("%c", 192);
	gotoxy(99, 2 * lenght + pos_y);
	printf("%c", 217);
	gotoxy(15, 4);
	printf("%c", 194);
	gotoxy(15, 2 * lenght + pos_y);
	printf("%c", 193);
	gotoxy(29, 4);
	printf("%c", 194);
	gotoxy(29, 2 * lenght + pos_y);
	printf("%c", 193);
	gotoxy(44, 4);
	printf("%c", 194);
	gotoxy(44, 2 * lenght + pos_y);
	printf("%c", 193);
	gotoxy(69, 4);
	printf("%c", 194);
	gotoxy(69, 2 * lenght + pos_y);
	printf("%c", 193);
	gotoxy(89, 4);
	printf("%c", 194);
	gotoxy(89, 2 * lenght + pos_y);
	printf("%c", 193);
	for (int i = 1; i <= lenght; i++)
	{
		gotoxy(9, 2 * (i - 1) + pos_y);
		printf("%c", 195);
		gotoxy(15, 2 * (i - 1) + pos_y);
		printf("%c", 197);
		gotoxy(99, 2 * (i - 1) + pos_y);
		printf("%c", 180);
		gotoxy(29, 2 * (i - 1) + pos_y);
		printf("%c", 197);
		gotoxy(44, 2 * (i - 1) + pos_y);
		printf("%c", 197);
		gotoxy(69, 2 * (i - 1) + pos_y);
		printf("%c", 197);
		gotoxy(89, 2 * (i - 1) + pos_y);
		printf("%c", 197);

	}
	gotoxy(40, 1);
	Color(12);
	cout << "_~IN DANH SACH SINH VIEN~_";
	Color(14);
	gotoxy(80, 2);
	cout << "Enter: continue!";
	Color(11);
	gotoxy(11, 5);
	cout << "STT";
	gotoxy(19, 5);
	cout << "Ma Lop";
	gotoxy(34, 5);
	cout << "Ma SV";
	gotoxy(52, 5);
	cout << "Ho Va Ten";
	gotoxy(75, 5);
	cout << "Ngay Sinh";
	gotoxy(92, 5);
	cout << "Diem TB";
	gotoxy(2, 7);
	Color(15);
}

void delLine(int x, int y, int length)
{
	gotoxy(x, y);
	for (int i = 1; i <= length; i++)
	{
		cout << "  ";
	}
	gotoxy(x, y);
}

int listToArray(SV arr[1000], List& L)
{
	int size = 0;
	Node* temp = L.first;
	while (temp != NULL)
	{
		arr[size] = temp->sv;
		size++;
		temp = temp->next;
	}
	return size;
}

void arrToList(SV arr[1000], List& L, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		insertAtFirst(L, arr[i]);
	}
}

void giao_dien_tim_kiem(int x, int y)
{
	makeFrame_big(50, 2, 2, 3, 10);
	makeFrame_small_thin(20, 2, 16, 0);
	center(16, 16 + 20, 1, 8);
	cout << "Tim kiem";
	Color(8);
	gotoxy(3, 4);
	cout << "Nhap thu ban muon tim";
	Color(15);
	gotoxy(0, 15);
	char s[100];
	
}

int checkDiem(char a[])// kiem tra diem co dung hay ko
{
	int k = 0;
	for (int i = 0; i < strlen(a); i++) {
		if (int(a[i]) < 46 || int(a[i]) > 57) return 0;
		if (int(a[i]) == 47) return 0;
		if (int(a[i]) == 46) k++;
		if (k > 1) return 0;
	}
	return 1;
}

int check(char value[])
{
	for (int i = 0; i < strlen(value); i++)
	{
		if ((int)value[i] < 48 || (int)value[i]>57) return 1;
	}
	return 0;
}

int compareWithKeyword(SV sv, char keyword[], int key)
{
	switch (key)
	{
	case 1:// so sanh voi ma lop
	{
		if (strcmpi(sv.MaLop, keyword) == 0) return 0;
		else if (strcmpi(sv.MaLop, keyword) > 0) return 1;
		else return -1;
	}
	break;
	case 2:
	{
		if (strcmpi(sv.MaSV, keyword) == 0) return 0;
		else if (strcmpi(sv.MaSV, keyword) > 0) return 1;
		else return -1;
	}
	break;
	case 3:
	{
		if (strcmpi(sv.Name, keyword) == 0) return 0;
		else if (strcmpi(sv.Name, keyword) > 0) return 1;
		else return -1;
	}
	break;
	case 5:
	{
		float temp = atof(keyword);
		if (sv.diemTB == temp) return 0;
		else if (sv.diemTB < temp) return 1;
		else return -1;
	}
	}
}

int searchKey(char source[], char Key[])
{
	char* ret;
	ret = strstr(source, Key);
	if (ret == NULL) return 0;
	else return 1;
}

int searchToMid(SV Arr[], int size, char keyword[], int key)
{
	int low = 0;
	int high = size - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (compareWithKeyword(Arr[mid], keyword, key) == 0)
			return mid;
		else
		{
			if (compareWithKeyword(Arr[mid], keyword, key) == -1)
				low = low + 1;
			else high = high - 1;
		}
	}
}

void searchUp(SV Arr[], int size, char keyword[], int key, int mid, vector<int>& setColor)
{
	for (int i = mid; i >= 0; i--)
	{
		if (compareWithKeyword(Arr[i], keyword, key) == 0)
			setColor.at(i) = 1;
	}
}

void searchDown(SV Arr[], int size, char keyword[], int key, int mid, vector<int>& setColor)
{
	for (int i = mid; i < size; i++)
	{
		if (compareWithKeyword(Arr[i], keyword, key) == 0)
			setColor.at(i) = 1;
	}
}

void searchType(int Key, int key, List& L, int type)
{
	giao_dien_tim_kiem(0, 0);
	while (1)
	{
		if (kbhit())
		{
			char key = getch();
			if (key == enter())
			{
				delline(3, 4, 30);
				showCursor();
				break;
			}
		}
	}
	init(L);
	readFile("danhsachsinhvien.dat", L);
	SV Arr[1000];
	int size;
	size = listToArray(Arr, L);
	makeEmpty(L);
	vector<int> setColor;
	setColor.clear();
	int valueOfKey = 0;
	char temp[40] = " ";
	switch (Key)
	{
	case 1://tim kiem tuan tu
	{
		if (key == 1 || key == 2 || key == 3 || key == 5)
		{
			showCursor();
			gotoxy(3,4);
			cin.getline(temp, 40);
			fflush(stdin);
			for (int i = 0; i < size; i++)
			{
				if (key == 1)
				{
					strupr(temp);
					if (searchKey(Arr[i].MaLop, temp) == 1)
					{
						setColor.push_back(1);
						valueOfKey++;
					}
					else setColor.push_back(0);
				}
				if (key == 2)
				{
					strupr(temp);
					if (searchKey(Arr[i].MaSV, temp) == 1)
					{
						setColor.push_back(1);
						valueOfKey++;
					}
					else setColor.push_back(0);
				}
				if (key == 3)
				{
					char temp3[40] = "";
					strcpy(temp3, Arr[i].Name);
					strlwr(temp3);
					if (searchKey(temp3, temp) == 1)
					{
						setColor.push_back(1);
						valueOfKey++;
					}
					else setColor.push_back(0);
				}
				if (key == 5)
				{
					do
					{
						if (checkDiem(temp) == 1)
						{
							float temp1 = atof(temp);
							if (temp1 == Arr[i].diemTB)
							{
								setColor.push_back(1);
								valueOfKey++;
							}
							else setColor.push_back(0);
							break;
						}
						else
						{
							Color(15);
							gotoxy(57, 23);
							cout << "                   ";
							gotoxy(57, 23);
							cin >> temp;
						}
					} while (1);
				}
			}
		}
		if (key == 4)
		{
			if (type == 1 || type == 2 || type == 3)
			{
				showCursor();
				gotoxy(3,4);
				cin >> temp;
				fflush(stdin);
				for (int i = 0; i < size; i++)
				{
					do
					{
						if (check(temp) == 0)
						{
							int temp1 = atof(temp);
							if (type == 1)
							{
								if (temp1 == Arr[i].birthday.day)
								{
									setColor.push_back(1);
									valueOfKey++;
								}
								else setColor.push_back(0);
							}
							if (type == 2)
							{
								if (temp1 == Arr[i].birthday.month)
								{
									setColor.push_back(1);
									valueOfKey++;
								}
								else setColor.push_back(0);
							}
							if (type == 3)
							{
								if (temp1 == Arr[i].birthday.year)
								{
									setColor.push_back(1);
									valueOfKey++;
								}
								else setColor.push_back(0);
							}
							break;
						}
						else
						{
							gotoxy(57, 23);
							cout << "           ";
							gotoxy(57, 23);
							cin >> temp;
						}
					} while (1);
				}
			}
			if (type == 4)
			{
				char temp1[20] = " ", temp2[20] = " ", temp3[20] = " ";
				gotoxy(57, 23);
				cout << "   /   /    ";
				showCursor(); 
				gotoxy(57, 23); 
				cin >> temp1;
				fflush(stdin);
				gotoxy(61, 23); 
				showCursor(); 
				cin >> temp2; 
				fflush(stdin);
				gotoxy(65, 23); 
				showCursor(); 
				cin >> temp3;
				fflush(stdin);
				int ng = atof(temp1);
				int th = atof(temp2);
				int na = atof(temp3);
				for (int i = 0; i < size; i++)
				{
					if (ng == Arr[i].birthday.day && th == Arr[i].birthday.month && na == Arr[i].birthday.year)
					{
						setColor.push_back(1);
						valueOfKey++;
					}
					else setColor.push_back(0);
				}
			}
		}
		system("cls");
		if (valueOfKey == 0)
		{

			gotoxy(30, 5);
			Color(11);
			cout << "Don't find the keyword. Press enter to back!";
			hideCursor();
			if (getch() == 13)
			{
				Color(15);
				system("cls");
				List L;
				init(L);
				MakeMainMenu(L);
			}
		}
		else
		{
			Color(15);
			system("cls");
			char nameOfSearch[][50] = { "Tim Kiem Tuan Tu - MaLop",
									   "Tim Kiem Tuan Tu - MaSV",
									   "Tim Kiem Tuan Tu - HoTen",
									   "Tim Kiem Tuan Tu - NgaySinh",
									   "Tim Kiem Tuan Tu - DiemTB" };
			gotoxy(1, 1); Color(12); cout << "Key    : " << temp; Color(15);
			gotoxy(1, 2); Color(12); cout << "Value  : " << valueOfKey; Color(15);
			gotoxy(1, 3); Color(12); cout << nameOfSearch[key - 1]; Color(15);
			char temp_1[50] = "";
			strcpy(temp_1, nameOfSearch[key - 1]);
			List DL;
			init(DL);
			arrToList(Arr, DL, size);
			printSearch(DL, setColor, 2);
			MakeMainMenu(L);
		}
		break;
	}
	case 2:// tim kiem nhi phan
	{
		for (int i = 0; i < size; i++)
		{
			setColor.push_back(0);
		}
		if (key == 1 || key == 2 || key == 3 || key == 5)
		{
			showCursor();
			gotoxy(3,4);
			cin.getline(temp, 40);
			fflush(stdin);
			if (key == 1)
			{
				strupr(temp);
				recursiveQuickSort(Arr, 0, size - 1, 1);
				int mid = searchToMid(Arr, size, temp, 1);
				searchUp(Arr, size, temp, 1, mid, setColor);
				searchDown(Arr, size, temp, 1, mid, setColor);
			}
			if (key == 2)
			{
				strupr(temp);
				recursiveQuickSort(Arr, 0, size - 1, 2);
				int mid = searchToMid(Arr, size, temp, 2);
				searchUp(Arr, size, temp, 2, mid, setColor);
				searchDown(Arr, size, temp, 2, mid, setColor);
			}
			if (key == 3)
			{
				recursiveQuickSort(Arr, 0, size - 1, 3);
				int mid = searchToMid(Arr, size, temp, 3);
				searchUp(Arr, size, temp, 3, mid, setColor);
				searchDown(Arr, size, temp, 3, mid, setColor);
			}
			if (key == 5)
			{
				do
				{
					if (checkDiem(temp) == 1)
					{
						recursiveQuickSort(Arr, 0, size - 1, 5);
						int mid = searchToMid(Arr, size, temp, 5);
						searchUp(Arr, size, temp, 5, mid, setColor);
						searchDown(Arr, size, temp, 5, mid, setColor);
						break;
					}
					else
					{
						gotoxy(57, 23);
						cout << "                      ";
						gotoxy(57, 23);
						cin >> temp;
					}
				} while (1);
			}
		}
		if (key == 4)
		{
			char temp1[20] = " ", temp2[20] = " ", temp3[20] = " ";
			gotoxy(57, 23);
			cout << "   /   /    ";
			showCursor(); gotoxy(57, 23); cin >> temp1; fflush(stdin);
			gotoxy(61, 23); showCursor(); cin >> temp2; fflush(stdin);
			gotoxy(65, 23); showCursor(); cin >> temp3; fflush(stdin);
			int ng = atof(temp1);
			int th = atof(temp2);
			int na = atof(temp3);
			recursiveQuickSort(Arr, 0, size - 1, 4);
			int mid = searchToMid(Arr, size, temp, 4);
			searchUp(Arr, size, temp, 4, mid, setColor);
			searchDown(Arr, size, temp, 4, mid, setColor);
		}
		system("cls");
		int valueOfKey = 0;
		for (int i = 0; i < setColor.size(); i++)
		{
			if (setColor.at(i) == 1)
				valueOfKey++;
		}
		if (valueOfKey == 0)
		{
			gotoxy(30, 5);
			Color(11);
			cout << "Don't find the keyword. Press enter to back!";
			showCursor();
			if (getch() == 13)
			{
				Color(15);
				system("cls");
				List L;
				init(L);
				MakeMainMenu(L);
			}
		}
		else
		{
			char nameOfSearch[][50] = { "Tim kiem Nhi Phan - MaLop",
										"Tim Kiem Nhi Phan - MaSV",
										"Tim Kiem Nhi Phan - HoTen",
										"Tim Kiem Nhi Phan - NgaySinh",
										"Tim Kiem Nhi Phan - DiemTB" };
			gotoxy(1, 1); Color(12); 	cout << "Key   : " << temp;			Color(15);
			gotoxy(1, 2); Color(12);	cout << "Value : " << valueOfKey;	Color(15);
			gotoxy(1, 3); Color(12);    cout << nameOfSearch[key - 1];         Color(15);
			char temp_1[50] = "";
			strcpy(temp_1, nameOfSearch[key - 1]);
			List DL;
			init(DL);
			arrToList(Arr, DL, size);
			printSearch(DL, setColor, 2);
			MakeMainMenu(DL);
		}
		break;
	}
	}
}

