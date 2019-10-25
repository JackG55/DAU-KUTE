#pragma once
#include "List.h"
#include "Menu.h"

void MakeMainMenu(List a);

void makeFrame_big(int width, int hight, int x, int y, int color);
void makeFrame_small_thin(int width, int hight, int x, int y);

void print_collum(int hight, int x, int y);      // in cac cot
void print_row(int n,int x, int y);   //n la so hang
void print_middle(int n, int x, int y);   // in cac diem giua
void complete(int n, int x, int y);    //hoan thien bang, dien tu, dien chu

void make_a_table_of_information(int n,int x,int y);
void insert_information_to_add_table(SV a,int x, int y);

void introduction_for_print();
void turn_page(List l, int x, int y);
void print_from_to(List l, int start, int end);



void makeFrame_big(int width, int hight, int x, int y, int color)
{
	Color(color);
	int i;
	for (i = y + 1; i < y + hight; i++)
	{
		gotoxy(x, i);  printf("%c", 186);//doc
		gotoxy(x + width, i); printf("%c", 186);
	}
	for (i = x + 1; i < x + width; i++)
	{
		gotoxy(i, y); printf("%c", 205);//ngang
		gotoxy(i, y + hight); printf("%c", 205);
	}
	gotoxy(x, y); printf("%c", 201);//goc trai tren
	gotoxy(x, y + hight); printf("%c", 200);//goc trai duoi 
	gotoxy(x + width, y); printf("%c", 187);//goc phai tren 
	gotoxy(x + width, y + hight); printf("%c", 188);//goc phai duoi
	Color(15);
}

void makeFrame_small_thin(int width, int hight, int x, int y)
{
	Color(15);
	int i;
	for (i = y + 1; i < y + hight; i++)
	{
		gotoxy(x, i);  printf("%c", 179);//doc
		gotoxy(x + width, i); printf("%c", 179);
	}
	for (i = x + 1; i < x + width; i++)
	{
		gotoxy(i, y); printf("%c", 196);//ngang
		gotoxy(i, y + hight); printf("%c", 196);
	}
	gotoxy(x, y); printf("%c", 218);//goc trai tren
	gotoxy(x, y + hight); printf("%c", 192);//goc trai duoi 
	gotoxy(x + width, y); printf("%c", 191);//goc phai tren 
	gotoxy(x + width, y + hight); printf("%c", 217);//goc phai duoi
}

void print_collum(int hight, int x, int y)
{

	gotoxy(5 + x, y);
	cout << (char)194;   //phan o giua huong xuong
	gotoxy(44 + x, y);
	cout << (char)194;
	gotoxy(60 + x, y);
	cout << (char)194;
	gotoxy(75 + x, y);
	cout << (char)194;
	gotoxy(95 + x, y);
	cout << (char)194;

	gotoxy(5 + x, hight + y);         //phan o giua huong len
	cout << (char)193;
	gotoxy(44 + x, hight + y);
	cout << (char)193;
	gotoxy(60 + x, hight + y);
	cout << (char)193;
	gotoxy(75 + x, hight + y);
	cout << (char)193;
	gotoxy(95 + x, hight + y);
	cout << (char)193;
}

void print_row(int n, int x, int y)
{
	for (int i = 1; i < n; i++)
	{
		gotoxy(x, 5 * i - 2 + y);            //phan ben trai huong sang phai
		cout << (char)195;
	}
	for (int i = 1; i < n; i++)
	{
		gotoxy(x + 107, 5 * i - 2 + y);           //phan ben phai huong sang trai
		cout << (char)180;
	}
}

void print_middle(int n, int x, int y)
{
	for (int i = 1; i < n; i++)
	{
		gotoxy(5 + x, i * 5 - 2 + y);
		cout << (char)197;
		gotoxy(44 + x, i * 5 - 2 + y);
		cout << (char)197;
		gotoxy(60 + x, i * 5 - 2 + y);
		cout << (char)197;
		gotoxy(75 + x, i * 5 - 2 + y);
		cout << (char)197;
		gotoxy(95 + x, i * 5 - 2 + y);
		cout << (char)197;
	}
}

	void complete(int n, int x, int y)
	{
		Color(9);
		gotoxy(1 + x, 1 + y);
		cout << "STT";
		gotoxy(20 + x, 1 + y);
		cout << "Ho va ten";
		gotoxy(50 + x, 1 + y);
		cout << "Ma lop";
		gotoxy(66 + x, 1 + y);
		cout << "Ma sv";
		gotoxy(82 + x, 1 + y);
		cout << "Ngay sinh";
		gotoxy(98 + x, 1 + y);
		cout << "Diem TB";

		Color(15);
		for (int i = 1; i < n * 5 - 2; i++)
		{
			if ((i + 2) % 5 != 0)
			{
				gotoxy(5 + x, i + y);
				cout << (char)179;
				gotoxy(44 + x, i + y);
				cout << (char)179;
				gotoxy(60 + x, i + y);
				cout << (char)179;
				gotoxy(75 + x, i + y);
				cout << (char)179;
				gotoxy(95 + x, i + y);
				cout << (char)179;
			}
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < 107; j++)
			{
				if (j != 5 && j != 44 && j != 60 && j != 75 && j != 95)
				{
					gotoxy(j + x, i * 5 - 2 + y);
					cout << (char)196;
				}
			}
		}
	}



void make_a_table_of_information(int n, int x, int y)
{
	Color(15);
	makeFrame_small_thin(107, n * 5 - 2, x, y);
	print_collum(n * 5 - 2, x, y);
	print_row(n,x,y);
	print_middle(n,x,y);
	complete(n,x,y);
	//insert_information_to_add_table(a,5);
}

void insert_information_to_add_table(SV sv,int x, int y)
{
	//gotoxy(2, 5);
	//center(1, 5, y, 1);
	//cout << "1";
	int length = strlen(sv.Name);
	//gotoxy(18, 5);
	center(6, 44, y, length);
	cout << sv.Name;

	length = strlen(sv.MaLop);
	center(45, 60, y, length);
	//gotoxy(47, 5);
	cout << sv.MaLop;

	length = 8;
	center(61, 75, y, length);
	//gotoxy(62, 5);
	cout << sv.MaSV;

	length = 10;
	center(76, 95, y, length);
	//gotoxy(82, 5);
	cout << sv.birthday.day << "/" << sv.birthday.month << "/" << sv.birthday.year;

	length = 3;
	center(96, 107, y, length);
	//gotoxy(100, 5);
	cout << sv.diemTB;
}

void printList(List l)
{
	system("mode 150");
	makeFrame_big(40, 2, 34, 1, 11);
	center(35, 73, 2, 19);
		cout << "DANH SACH SINH VIEN";
	Node* temp = l.first;
	Node* temp2 = l.first;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	int y = 5;     //khoang cach tinh tu dau
	make_a_table_of_information(count+1, 0, y);
	for (int i = 1; i <= count; i++)
	{
		SV b = temp2->sv;
		center(1, 5, 5 * i+y, 1);
		cout << i;
		insert_information_to_add_table(b,0, 5 * i+y);
		temp2 = temp2->next;
	}
	gotoxy(51,51);
}

void print_from_to(List l, int start, int end)
{
	Node* temp = l.first;
	int count = 0;
	int i = 1;
	while (temp != NULL)
	{
		count++;
		if (count >= start && count <= end)
		{
			SV b = temp->sv;
			insert_information_to_add_table(b, 0, 5 * i + 5);
			i++;
		}
		if (count == end)
		{
			break;
		}
		temp = temp->next;
	}
}

void introduction_for_print()
{
	makeFrame_big(38, 2, 109, 12, 9);
	Color(10);
	center(109, 109 + 38, 13, 9);
		cout << "HUONG DAN";

	makeFrame_big(38,4, 109, 15, 9);
	Color(10);
	gotoxy(110, 16);
	cout << "Arrow right: Next page";
	gotoxy(110, 17);
	cout << "Arrow left : Previous page";
	gotoxy(110, 18);
	cout << "Backspace or ecs: Return to mainmenu";
	Color(15);
}

void turn_page(List l, int x, int y)
{
	system("mode 150");
	int count = 0;
	Node* temp = l.first;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	int so_trang;
	int thuong;
	thuong = count / 10;
	int so_du;
	so_du = count % 10;
	if (so_du == 0)
	{
		so_trang = thuong;
	}
	else
	{
		so_trang = thuong + 1;
	}
	int pos = 1;
	// count = 25;   thuong = 2   du = 5    so_trang = 3;
	 // pos =  1 thi in tu 1 den 10   
	// pos = 2 thi in tu 11 den 20
	// pos = 3 thi in tu 21 den 25     
	int n = 1;
	while (n==1)
	{
		//phan in ra bang
		Xoa_man_hinh();
		introduction_for_print();

		makeFrame_big(40, 2, 34, 1, 11);
		center(35, 73, 2, 19);
		cout << "DANH SACH SINH VIEN";

		Color(11);
		gotoxy(108, 4);
		cout << "Trang " << pos << "/" << so_trang << endl;
		Color(15);

		Node* temp2 = l.first;
		if (pos * 10 > count)                  // chay tu  thuong*10+1 ->  thuong * 10 + du  
		{
			make_a_table_of_information(so_du+1, 0, 5);
			int j = thuong * 10 + 1;
			for (int i = 1; i <= so_du; i++)
			{
				center(1, 5, 5 * i + 5, 2);
				cout << j;
				j++;
			}
			print_from_to(l, thuong * 10 + 1, thuong * 10 + so_du);
		}
		else
		{
			make_a_table_of_information(11, 0, 5);
			int j = (pos - 1) * 10 + 1;
			for (int i = 1; i <= pos*10; i++)
			{
				center(1, 5, 5 * i + 5, 2);
				cout << j;
				j++;
			}
			print_from_to(l, (pos - 1) * 10 + 1, pos * 10);
		}

		while (n==1)   //phan chuyen bang
		{
			if (_kbhit())
			{
				char x = _getch();
				if (x == right())
				{
					if (pos == so_trang)
					{
						pos = 1;
					}
					else
						pos++;
					break;
				}
				if (x == left())
				{
					if (pos == 1)
					{
						pos = so_trang;
					}
					else
						pos--;
					break;
				}
				if (x == esc() || x == backspace())
				{
					Xoa_man_hinh();
					n = 0;
					List k;
					init(k);
					MakeMainMenu(k);
					break;
				}
			}
		}
	}
}