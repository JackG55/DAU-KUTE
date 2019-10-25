#pragma once
#include "InSV.h"
#include "Menu.h"



void MakeMainMenu(List a);

void makeFrame();
void makeFrame_small(int width, int hight, int x, int y);
void input_the_information(List &sv, SV &a);
void make_menu_add_from_key_board(List a);
void save_or_not(List a, SV &b);
void luu();
void sua();
void xoa();

void make_menu_add_from_file(List a);
void input_information_from_file();


void writeFile(const char* Filename, List& l);
void write_new_File(const char* Filename, List& l);
void readFile(const char* Filename, List& l);



void enter_name(SV& sv);
void enter_masv(SV& sv);
void enter_malop(SV& sv);
void enter_birthday(SV& sv);
void enter_day(SV& sv);
void enter_month(SV& sv);
void enter_year(SV& sv);
void enter_result(SV& sv);

void right_name(char s[40]);
int wrong_name(char s[]);
void right_Malop(char s[15]);
int wrong_MaSV(char s[8]);
bool leapYear(date a);
int monthDays(date a);

void makeFrame()// x=80 , y=25
{
	Color(11);
	int i;
	for (i = 2; i < 25; i++)
	{
		gotoxy(1, i);  printf("%c", 186);//doc
		gotoxy(80, i); printf("%c", 186);
	}
	for (i = 2; i < 80; i++)
	{
		gotoxy(i, 1); printf("%c", 205);//ngang
		gotoxy(i, 25); printf("%c", 205);
	}
	gotoxy(1, 1); printf("%c", 201);//goc trai tren
	gotoxy(1, 25); printf("%c", 200);//goc trai duoi 
	gotoxy(80, 1); printf("%c", 187);//goc phai tren 
	gotoxy(80, 25); printf("%c", 188);//goc phai duoi
	for (int i = 23; i < 25; i++)
	{
		gotoxy(40, i);
		printf("%c", 186);
	}
	for (int i = 2; i < 40; i++)
	{
		gotoxy(i, 23);
		printf("%c", 205);
	}
	//gotoxy(1, 22); printf("%c", 201);//goc trai tren
	gotoxy(1, 25); printf("%c", 200);//goc trai duoi 
	gotoxy(40, 23); printf("%c", 187);//goc phai tren 
	gotoxy(40, 25); printf("%c", 188);//goc phai duoi
	gotoxy(2, 24);
	cout << "   Huong dan: Nhan Enter de nhap!!";
}

void makeFrame_small(int width, int hight, int x, int y)
{
	Color(14);
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
}

void make_menu_add_from_file(List a)
{
	makeFrame();
	Color(15);
	gotoxy(10, 10);
	cout << "File name: ";
	makeFrame_small(50, 2, 21, 9);
	gotoxy(0, 26);
	input_information_from_file();
}

void input_information_from_file()
{
	List a;
	init(a);
	char filename[100];
	showCursor();
	Color(15);
	gotoxy(22, 10);
	cin.getline(filename, 100);
	if (access(filename, 0) == -1)
	{
		Color(160);
		gotoxy(20, 20);
		cout << "  FILE ban nhap khong ton tai " << endl;
		gotoxy(20, 21);
		cout << "   Nhan ENTER de nhap lai     " << endl;
		hideCursor();
		Color(14);
		while (1)
		{
			if (_kbhit())
			{
				char key = _getch();
				if (key == enter())
				{
					delline(20, 20, 40);
					delline(20, 21, 40);
					delline(22, 10, 40);
					break;
				}
			}
		}
		input_information_from_file();
	}
	else
	{
		//readFile(filename, a);
		//writeFile(filename, a);
		Color(160);
		gotoxy(20, 20);
		cout << " Ban da nhap tu file thanh cong ";
		gotoxy(20, 21);
		cout << "Moi ban nhan backspace de thoat ";
		Color(15);
		while (1)
		{
			if (_kbhit())
			{
				char key = _getch();
				if (key == backspace())
				{
					system("cls");
					List m;
					init(m);
					MakeMainMenu(m);
					break;
				}
			}
		}
	}

	

}

void make_menu_add_from_key_board(List a)
{
	SV b;
	string* addmenu;
	int MAX_LIST = 6;
	addmenu = new string[MAX_LIST];
	addmenu[0] = "Ho va ten ";
	addmenu[1] = "Ma lop ";
	addmenu[2] = "Ma sinh vien ";
	addmenu[3] = "Ngay sinh ";
	addmenu[4] = "Diem trung binh ";
	int j = 0;
	makeFrame();//tao khung ngoai
	for (int i = 5; i < 20; i += 3) // i tuong trung cho chi so y
	{
		Color(15);
		gotoxy(5, i);
		cout << addmenu[j];//them vao menu thu tu j
		j++;
		Color(14);
		if (i == 14)//nam o hang ngay sinh
		{
			makeFrame_small(7, 2, 25, i - 1);  //toa do (25,13)
			gotoxy(34, i - 1 + 1);
			printf("%c", 186);
			makeFrame_small(7, 2, 36, i - 1);  //toa do (36,13)
			gotoxy(45, i - 1 + 1);
			printf("%c", 186);
			makeFrame_small(12, 2, 47, i - 1); //toa do (47,13)

		}
		else
			makeFrame_small(50, 2, 25, i - 1);//tao khung be ben trong toa do (25),(4,7,11,14,17,20)
	}
	input_the_information(a,b);  //them a vao cuoi list
	
	save_or_not(a,b);              // co thi giu nguyen,   khong thi xoa a khoi day

}

void input_the_information(List& listsv, SV &a)
{
	showCursor();
	enter_name(a);
	fflush(stdin);
	enter_malop(a);
	fflush(stdin);
	enter_masv(a);
	fflush(stdin);
	enter_birthday(a);
	enter_result(a);
	Xoa_man_hinh();
	make_a_table_of_information(2,0,0);
	center(1, 5, 5, 1);
    cout << "1";
	insert_information_to_add_table(a,0, 5);
}


void luu()
{
	center(38, 47, 13, 4);
	cout << "LUU";
}

void sua()
{
	center(50, 59, 13, 4);
	cout << "SUA";
}

void xoa()
{
	center(62, 71, 13, 4);
	cout << "XOA";
}



void save_or_not(List a, SV &b)
{
	int MAX_LIST = 2;
	int position = 0;
	int n = 1;
	while (n==1)
	{
		hideCursor();
		makeFrame_small_thin(38, 6, 35, 10);//khuong to
		makeFrame_small_thin(10, 2, 37, 12);//luu
		makeFrame_small_thin(10, 2, 49, 12);//sua
		makeFrame_small_thin(10, 2, 61, 12);//xoa
		if (position == 0)
		{
			Color(160);
			luu();
			Color(15);
			sua();
			xoa();
		}
		if (position == 1)
		{
			Color(160);
			sua();
			Color(15);
			luu();
			xoa();
		}
		if (position == 2)
		{
			Color(160);
			xoa();
			Color(15);
			luu();
			sua();
		}
		while (n==1)
		{
			if (_kbhit())
			{
				int key = _getch();
				if (key == left())
				{
					if (position == 0)
						position = MAX_LIST;
					else
						position--;
					break;
				}
				if (key == right())
				{
					if (position == MAX_LIST)
						position = 0;
					else
						position++;
					break;
				}
				if (key == enter())
				{
					switch (position)
					{
					case 0:            //luu
						insertAtLast(a, b);
						writeFile("danhsachsinhvien.dat", a);
						Xoa_man_hinh();
						MakeMainMenu(a);
						n = 0;
						break;
					case 1:            //sua
						break; 
					case 2:
						Xoa_man_hinh();
						MakeMainMenu(a);
						n = 0;
						break;         //xoa
					}
				}
			}
		}
	}
}




//------------------------------------------------------------------------------------------//
void enter_name(SV& sv)
{
	showCursor();
	gotoxy(26, 5);
	cin.getline(sv.Name, 40);
	int check = wrong_name(sv.Name);
	if (check != 0)
	{
		Color(160);
		gotoxy(20, 20);
		cout << "  Ban nhap ten khong hop le " << endl;
		gotoxy(20, 21);
		cout << "   Nhan ENTER de nhap lai   " << endl;
		hideCursor();
		Color(14);
		while (1)
		{
			if (_kbhit())
			{
				char key = _getch();
				if (key == enter())
				{
					delline(20, 20, 40);
					delline(20, 21, 40);
					delline(26, 5, 40);
					break;
				}
			}
		}
		enter_name(sv);
	}
	else
	{
		right_name(sv.Name); // chuan hoa ten
		delline(26, 5, 45);
		gotoxy(26, 5);
		cout << sv.Name;
	}

}

void enter_malop(SV& sv)
{
	gotoxy(26, 8);
	cin.getline(sv.MaLop, 15);
	right_Malop(sv.MaLop); // chuan hoa ma lop
	delline(26, 8, 45);
	gotoxy(26, 8);
	cout << sv.MaLop;
}

void enter_masv(SV& sv)
{
	showCursor();
	gotoxy(26, 11);
	cin.getline(sv.MaSV, 20);
	int check = wrong_MaSV(sv.MaSV);
	if (check != 0)
	{
		Color(160);
		if (check == 1)
		{
			gotoxy(20, 20);
			cout << "Ban phai nhap so co 8 chu so" << endl;
		}
		else if (check == 2)
		{
			gotoxy(20, 20);
			cout << "  Ban phai nhap cac chu so  " << endl;
		}
		else if (check == 3)
		{
			gotoxy(20, 20);
			cout << "   Ma sinh vien da ton tai  " << endl;
		}
		gotoxy(20, 21);
		    cout << "   Nhan ENTER de nhap lai   " << endl;
		hideCursor();
		Color(14);
		while (1)
		{
			if (_kbhit())
			{
				char key = _getch();
				if (key == enter())
				{
					delline(20, 20, 40);
					delline(20, 21, 40);
					delline(26, 11, 40);
					
					break;
				}
			}
		}
		enter_masv(sv);
	}
	else
	{
		return;
	}
}

void enter_day(SV& sv)
{
	showCursor();
	gotoxy(27, 14);
	cin >> sv.birthday.day;
	if (sv.birthday.day > 31 || sv.birthday.day < 1)
	{
		Color(160);
		gotoxy(20, 20);
		cout << "  Ban nhap khong dung ngay  " << endl;
		gotoxy(20, 21);
		cout << "   Nhan ENTER de nhap lai   " << endl;
		hideCursor();
		Color(14);
		while (1)
		{
			if (_kbhit())
			{
				char key = _getch();
				if (key == enter())
				{
					delline(20, 20, 40);
					delline(20, 21, 40);
					delline(27, 14, 3);
					enter_day(sv);
					break;
				}
			}
		}
	}
}

void enter_month(SV& sv)
{
	showCursor();
	gotoxy(38, 14);
	cin >> sv.birthday.month;
	if (sv.birthday.month > 12 || sv.birthday.month < 1)
	{
		Color(160);
		gotoxy(20, 20);
		cout << "  Ban nhap khong dung thang  " << endl;
		gotoxy(20, 21);
		cout << "   Nhan ENTER de nhap lai    " << endl;
		hideCursor();
		Color(14);
		while (1)
		{
			if (_kbhit())
			{
				char key = _getch();
				if (key == enter())
				{
					delline(20, 20, 40);
					delline(20, 21, 40);
					delline(38, 14, 3);
					enter_month(sv);
					break;
				}
			}
		}
	}
}

void enter_year(SV& sv)
{
	showCursor();
	gotoxy(49, 14);
	cin >> sv.birthday.year;
	if (sv.birthday.day >= monthDays(sv.birthday))
	{
		Color(160);
		gotoxy(20, 20);
		cout << "  Ban nhap thoi gian khong hop le  " << endl;
		gotoxy(20, 21);
		cout << "       Nhan ENTER de nhap lai      " << endl;
		hideCursor();
		Color(14);
		while (1)
		{
			if (_kbhit())
			{
				char key = _getch();
				if (key == enter())
				{
					delline(20, 20, 40);
					delline(20, 21, 40);
					delline(27, 14, 3);
					delline(38, 14, 3);
					delline(49, 14, 5);
					enter_birthday(sv);
					break;
				}
			}
		}
	}

}

void enter_birthday(SV& sv)
{
	enter_day(sv);
	enter_month(sv);
	enter_year(sv);

}

void enter_result(SV& sv)
{
	gotoxy(26, 17);
	cin >> sv.diemTB;
	if (sv.diemTB > 10 || sv.diemTB < 0)
	{
		Color(160);
		gotoxy(20, 20);
		cout << "Diem phai nam trong thang diem muoi" << endl;
		gotoxy(20, 21);
		cout << "       Nhan ENTER de nhap lai      " << endl;
		hideCursor();
		Color(14);
		while (1)
		{
			if (_kbhit())
			{
				char key = _getch();
				if (key == enter())
				{
					delline(20, 20, 40);
					delline(20, 21, 40);
					delline(26, 17, 30);
					enter_result(sv);
					break;
				}
			}
		}
	}
}

//------------------------------------------------------------------------------------------//
//cac ham chuan hoa//
/*chuan hoa ten thoa man:   +Chu cai dau moi tu viet hoa
							+Cac tu cach dung 1 dau cach
							+Chuan phien am tieng viet (???)*/
							//kiem tra ten sai 
int wrong_name(char s[])
{
	int m = 0;
	if (strlen(s) == 0)
	{
		return 1;
	}
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122 || s[i] == 32)
		{
			int m = 0;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

//sua ten thanh ten hop le
void right_name(char s[40])
{
	int length = strlen(s);
	//chuan hoa dau cach
	for (int i = 0; i < length; i++)
	{
		if (s[i] == 32)
		{
			while (s[i + 1] == 32)
			{
				for (int j = i + 1; j < length; j++)
				{
					s[j] = s[j + 1];
				}
				length--;
			}
		}
	}
	//chuan hoa tu viet hoa
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[0] >=97&&s[0]<=122)
		{
			s[0] = int(s[0]) - 32;
		}
		if (s[i] == 32)
		{
			if (s[i + 1] >=97  && s[i + 1]<=122)
			{
				s[i + 1] = int(s[i + 1]) - 32;
			}
		}
	}
}

//sua ma lop thanh ma lop hop le   +chuyen cac chu cai thuong thanh chu in hoa
void right_Malop(char s[15])
{
	for (int i = 0; i < strlen(s); i++)
	{
			if (s[i] >= 97 && s[i] <= 122)
			{
				s[i] = int(s[i]) - 32;
			}
	}
}

//chuan hoa ma sinh vien:   +gom 8 chu so
                          //+ma sinh vien khong duoc trung
int wrong_MaSV(char s[8])
{
	int length = strlen(s);
	if (length != 8)
	{
		return 1;   //loi ma sinh vien phai co 8 chu so 
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			if (s[i] < 48 || s[i]>57)  // ma ascii cua cac chu so 
			{
				return 2;   //loi ma sinh vien chi chua chu so 
			}
		}
	}
	List test;
	init(test);
	readFile("danhsachsinhvien.dat", test);
	Node* temp = NULL;
	temp = test.first;
	while (temp != NULL)
	{
		if (strcmp(temp->sv.MaSV, s)==0)
		{
			return 3;    //ma sinh vien bi trung
		}
		temp = temp->next;
	}
	return 0;    //ma sinh vien hop le

}

int already_exist_maSV(char s[8])
{
	List test;
	init(test);
	readFile("danhsachsinhvien.dat", test);
	Node* temp = NULL;
	temp = test.first;
	while (temp != NULL)
	{
		if (temp->sv.MaSV == s)
		{
			return 3;    //ma sinh vien bi trung
		}
		temp = temp->next;
	}
	return 0;    //ma sinh vien hop le
}

bool leapYear(date a)  //kiem tra nam nhuan
{
	if (a.year % 4 == 0)
	{
		if (a.year % 100 == 0)
		{
			if (a.year % 400 == 0)
				return true;
			else
				return false;
		}
		else {
			return true;
		}
	}
	else
		return false;
}

int monthDays(date a)  //kiem tra ngay cua thang
{
	if (a.month == 1 || a.month == 3 || a.month == 5 || a.month == 7 || a.month == 8 || a.month == 10 || a.month == 12)
	{
		return 31;
	}
	else if (a.month == 2)
	{
		if (leapYear(a))
		{
			return 29;
		}
		else
			return 28;
	}
	else
		return 30;
}

void writeFile(const char* Filename, List& l)
{
	Node* temp = l.first;
	SV x;
	FILE* out;
	out = fopen(Filename, "ab");
	while (temp != NULL)
	{
		x = temp->sv;
		fwrite(&x, sizeof(x), 1, out);
		temp = temp->next;
	}
	fclose(out);
}

void write_new_File(const char* Filename, List& l)
{
	Node* temp = l.first;
	SV x;
	FILE* out;
	out = fopen(Filename, "wb");
	while (temp != NULL)
	{
		x = temp->sv;
		fwrite(&x, sizeof(x), 1, out);
		temp = temp->next;
	}
	fclose(out);
}

void readFile(const char* Filename, List& l)
{
	SV x;
	FILE* in;
	in = fopen(Filename, "rb");
	fread(&x, sizeof(x), 1, in);
	do
	{
		insertAtLast(l, x);
		fread(&x, sizeof(x), 1, in);
	} while (!feof(in));
	fclose(in);
}