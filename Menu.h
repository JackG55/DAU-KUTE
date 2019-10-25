#pragma once
#include "NhapSV.h"
#include "Sapxep.h"
#include "Timkiem.h"
#include "Thongke.h"

void MakeMainMenu(List a);

void addMenu(List a);

void printMenu(List a);

int arrangeMenu_1(List a);
void arrangeMenu_2(List a, int chon_1);

int searchMenu_1(List a);
void searchMenu_2(List a, int chon_1);


void statisticalMenu_1(List a);

void introduction();
void makeFrame_big(int width, int hight, int x, int y, int color);
void Thoat();

void make_menu_add_from_file(List a);
void make_menu_add_from_key_board(List a);
void writeFile(const char* Filename, List& l);
void readFile(const char* Filename, List& l);
void turn_page(List l, int x, int y);

void take_Infor_to_arr(SV a[], int& n);
void Take_infor_to_List(SV a[], List& l, int size);
void selection_sort(SV a[], int n, int p);
void insertion_sort(SV a[], int n, int p);
void buble_sort(SV a[], int n, int p);
void quick_sort(SV a[], int l, int r, int p);
void sort(int chon_1, int chon_2);


void MakeMainMenu(List a)
{
	hideCursor();
	string* menu;
	int MAX_LIST = 9;
	menu = new string[MAX_LIST];
	menu[0] = "-------------MainMenu--------------";
	menu[1] = "-----------------------------------";
	menu[2] = "| 1.Them moi ho so                |";
	menu[3] = "| 2.In danh sach                  |";
	menu[4] = "| 3.Sap xep                       |";
	menu[5] = "| 4.Tim kiem                      |";
	menu[6] = "| 5.Thong ke                      |";
	menu[7] = "| 0.Thoat                         |";
	menu[8] = "-----------------------------------";
	int pointer = 2;
	int thoat = 1;
	int n = 1;
	while (n == 1)
	{
		XoaManHinh();
		for (int i = 0; i < MAX_LIST; i++)
		{
			gotoxy(0, i);
			if (pointer == i && pointer != 0)
			{
				Color(12);
				cout << menu[i];
				Color(15);
			}
			else
				cout << menu[i];
		}
		introduction();
		while (n==1)
		{
			if (_kbhit())
			{
				char key = _getch();     // luu phim do lai de xu ly
				if (key == up())      // phim di len
				{
					if (pointer > 2)
						--pointer;
					else
						pointer = MAX_LIST - 2;
					break;
				}
				if (key == down())   // phim di xuong
				{
					if (pointer < MAX_LIST - 2)
						++pointer;
					else
						pointer = 2;
					break;
				}
				if (key == enter() || key == right())   // phim Enter
				{
					switch (pointer)
					{
					case 2://menu nhap
						addMenu(a);
						n = 0;
						break;
					case 3://menu in danh sach
						printMenu(a);
						n = 0;
						break;
					case 4://menu sap xep
						arrangeMenu_1(a);
						n = 0;
						break;
					case 5://menu tim kiem
						searchMenu_1(a);
						n = 0;
						break;
					case 6://menu thong ke
						statisticalMenu_1(a);
						n = 0;
						break;
					case 7://thoat
						Thoat();
						break;
					}
					break;
				}
			}
		}
	}
}



//ham tao menu cho lua chon 1:  Them moi ho so 
void addMenu(List a)
{
	hideCursor();
	string* addmenu;
	int MAX_LIST = 6;
	addmenu = new string[MAX_LIST];
	addmenu[0] = "----------THEM MOI HO SO-----------";
	addmenu[1] = "-----------------------------------";
	addmenu[2] = "| 1.Nhap tu ban phim              |";
	addmenu[3] = "| 2.Nhap tu file                  |";
	addmenu[4] = "| 0.Quay lai menu chinh           |";
	addmenu[5] = "-----------------------------------";
	int position = 2;
	int n = 1;
	while (n == 1)
	{
		for (int i = 0; i < MAX_LIST; i++)
		{
			gotoxy(35, i + 2);
			if (position == i && position != 0)
			{
				Color(12);
				cout << addmenu[i];
				Color(15);
			}
			else
				cout << addmenu[i];
		}
		while (n==1)
		{
			if (_kbhit())
			{
				char key = _getch();
				if (key == down())
				{
					if (position == MAX_LIST - 2)
						position = 2;
					else
						position++;
					break;
				}
				if (key == up())
				{
					if (position == 2)
						position = MAX_LIST - 2;
					else
						position--;
					break;
				}
				if (key == enter() || key == right())
				{
					switch (position)
					{
					case 2: //nhap tu ban phim
						system("cls");
						make_menu_add_from_key_board(a);
						n = 0;
						break;
					case 3: //nhap tu file
						system("cls");
						make_menu_add_from_file(a);
						n = 0;
						break;
					case 4:
						Xoa_man_hinh();
						n = 0;
						MakeMainMenu(a);
						break;
					}
					break;
				}
				if (key == left() || key == backspace())
				{
					Xoa_man_hinh();
					n=0;
					MakeMainMenu(a);
					break;
				}
			}
		}
	}
}


void printMenu(List a)
{
	hideCursor();
	string* printmenu;
	int MAX_LIST = 7;
	printmenu = new string[MAX_LIST];
	printmenu[0] = "----------In Danh Sach-------------";
	printmenu[1] = "-----------------------------------";
	printmenu[2] = "| 1.Theo thu tu sap xep           |";
	printmenu[3] = "| 2.Theo tim kiem                 |";
	printmenu[4] = "| 3.Toan bo danh sach             |";
	printmenu[5] = "| 0.Quay lai menu chinh           |";
	printmenu[6] = "-----------------------------------";
	int position = 2;
	int n = 1;
	while (n==1)
	{
		for (int i = 0; i < MAX_LIST; i++)
		{
			gotoxy(35, i + 3);
			if (position == i && position != 0)
			{
				Color(12);
				cout << printmenu[i];
				Color(15);
			}
			else
				cout << printmenu[i];
		}
		while (n==1)
		{
			if (_kbhit())
			{
				int key = _getch();
				if (key == up())
				{
					if (position == 2)
						position = MAX_LIST - 2;
					else
						position--;
					break;
				}
				if (key == down())
				{
					if (position == MAX_LIST - 2)
						position = 2;
					else
						position++;
					break;
				}
				if (key == enter() || key == right())
				{
					switch (position)
					{
					case 2: //theo thu tu sap xep
						List m;
						init(m);
						readFile("sort.dat", m);
						Xoa_man_hinh();
						turn_page(m, 0,5);
						n = 0;
						break;
					case 3: //theo tim kiem
						break;
					case 4: //toan bo danh sach
						List b;
						init(b);
						readFile("danhsachsinhvien.dat", b);
						Xoa_man_hinh();
						turn_page(b,0,5);
						n = 0;
						break;
					case 5: //ve menu chinh
						Xoa_man_hinh();
						n = 0;
						MakeMainMenu(a);
						break;
					}
					break;
				}
				if (key == left() || key == backspace())
				{
					Xoa_man_hinh();
					MakeMainMenu(a);
					break;
				}
			}
		}
	}

}



//Giao dien menu sap xep chon thuat toan sap xep
int arrangeMenu_1(List a)
{
	hideCursor();
	string* arrangemenu;
	int MAX_LIST = 9;
	arrangemenu = new string[MAX_LIST];
	arrangemenu[0] = "-------------Sap xep---------------";
	arrangemenu[1] = "-----------------------------------";
	arrangemenu[2] = "| Chon thuat toan sap xep:        |";
	arrangemenu[3] = "| 1.Selection Sort                |";
	arrangemenu[4] = "| 2.Insertion Sort                |";
	arrangemenu[5] = "| 3.Bubble Sort                   |";
	arrangemenu[6] = "| 4.Quick Sort                    |";
	arrangemenu[7] = "| 0.Quay lai menu chinh           |";
	arrangemenu[8] = "-----------------------------------";
	int position = 3;
	int n=1;
	while (n==1)
	{
		for (int i = 0; i < MAX_LIST; i++)
		{
			gotoxy(35, i + 4);
			if (position == i && position != 0)
			{
				Color(12);
				cout << arrangemenu[i];
				Color(15);
			}
			else
				cout << arrangemenu[i];
		}
		while (n==1)
		{
			if (_kbhit())
			{
				int key = _getch();
				if (key == up())
				{
					if (position == 3)
						position = MAX_LIST - 2;
					else
						position--;
					break;
				}
				if (key == down())
				{
					if (position == MAX_LIST - 2)
						position = 3;
					else
						position++;
					break;
				}
				if (key == enter() || key == right())
				{
					switch (position)
					{
					case 3: //selection sort
						arrangeMenu_2(a,3);
						n = 0;
						break;
					case 4: //insertion sort
						arrangeMenu_2(a, 4);
						n = 0;
						break;
					case 5: //bubble sort
						arrangeMenu_2(a, 5);
						n = 0;
						break;
					case 6:  //quicksort
						arrangeMenu_2(a, 6);
						n = 0;
						break;
					case 7:
						Xoa_man_hinh();
						MakeMainMenu(a);
						n = 0;
						break;
					}
					break;
					return position;
				}
				if (key == left() || key == backspace())
				{
					Xoa_man_hinh();
					MakeMainMenu(a);
					break;
				}
			}
		}
	}

}




void arrangeMenu_2(List a, int chon_1)
{
	hideCursor();
	string* arrangemenu;
	int MAX_LIST = 10;
	arrangemenu = new string[MAX_LIST];
	arrangemenu[0] = "-------------Sap xep---------------";
	arrangemenu[1] = "-----------------------------------";
	arrangemenu[2] = "| Chon tu khoa sap xep:           |";
	arrangemenu[3] = "| 1.Ma Sinh Vien                  |";
	arrangemenu[4] = "| 2.Ho va ten                     |";
	arrangemenu[5] = "| 3.Ngay sinh                     |";
	arrangemenu[6] = "| 4.Diem trung binh tich luy      |";
	arrangemenu[7] = "| 5.Ma Lop                        |";
	arrangemenu[8] = "| 0.Quay lai menu chinh           |";
	arrangemenu[9] = "-----------------------------------";
	int position = 3;
	int n = 1;
	while (n==1)
	{
		for (int i = 0; i < MAX_LIST; i++)
		{
			gotoxy(35 * 2, i + 4);
			if (position == i && position != 0)
			{
				Color(12);
				cout << arrangemenu[i];
				Color(15);
			}
			else
				cout << arrangemenu[i];
		}
		while (n==1)
		{
			if (_kbhit())
			{
				int key = _getch();
				if (key == up())
				{
					if (position == 3)
						position = MAX_LIST - 2;
					else
						position--;
					break;
				}
				if (key == down())
				{
					if (position == MAX_LIST - 2)
						position = 3;
					else
						position++;
					break;
				}
				if (key == enter() || key == right())
				{
					switch (position)
					{
					case 3: //ma sinh vien
						sort(chon_1, 1);
						makeFrame_big(38, 2, 109, 10, 9);
						Color(10);
						center(109, 109 + 38, 11, 9);
						cout << "THEO HO TEN";
						n = 0;
						break;
					case 4: //ho va ten
						sort(chon_1, 2);
						n = 0;
						break;
					case 5: //ngay sinh
						sort(chon_1, 3);
						n = 0;
						break;
					case 6:  //diem trung binh
						sort(chon_1, 4);
						n = 0;
						break;
					case 7:  //ma lop
						sort(chon_1, 5);
						n = 0;
						break;
					case 8://quay lai menu chinh
						Xoa_man_hinh();
						MakeMainMenu(a);
						break;
					}
					break;
				}
				if (key == left() || key == backspace())
				{
					Xoa_man_hinh();
					MakeMainMenu(a);
					break;
				}
			}
		}
	}

}




int searchMenu_1(List a)
{
	hideCursor();
	string* searchmenu;
	int MAX_LIST = 7;
	searchmenu = new string[MAX_LIST];
	searchmenu[0] = "-------------Tim kiem--------------";
	searchmenu[1] = "-----------------------------------";
	searchmenu[2] = "| Chon thuat toan tim kiem:       |";
	searchmenu[3] = "| 1.Tuan tu                       |";
	searchmenu[4] = "| 2.Nhi phan                      |";
	searchmenu[5] = "| 0.Quay lai menu chinh           |";
	searchmenu[6] = "-----------------------------------";
	int position = 3;
	int n = 1;
	while (n==1)
	{
		for (int i = 0; i < MAX_LIST; i++)
		{
			gotoxy(35, i + 5);
			if (position == i && position != 0)
			{
				Color(12);
				cout << searchmenu[i];
				Color(15);
			}
			else
				cout << searchmenu[i];
		}
		while (n==1)
		{
			if (_kbhit())
			{
				int key = _getch();
				if (key == up())
				{
					if (position == 3)
						position = MAX_LIST - 2;
					else
						position--;
					break;
				}
				if (key == down())
				{
					if (position == MAX_LIST - 2)
						position = 3;
					else
						position++;
					break;
				}
				if (key == enter() || key == right())
				{
					switch (position)
					{
					case 3: //tim kiem tuan tu
						searchMenu_2(a,1);
						n = 0;
						break;
					case 4: //tim kiem nhi phan
						searchMenu_2(a,2);
						n = 0;
						break;
					case 5: //thoat
						Xoa_man_hinh();
						MakeMainMenu(a);
						break;
					}
					return position;
				}
				if (key == left() || key == backspace())
				{
					Xoa_man_hinh();
					MakeMainMenu(a);
					break;
				}
			}
		}
	}

}



void searchMenu_2(List a, int chon_1)
{
	hideCursor();
	string* searchmenu;
	int MAX_LIST = 10;
	searchmenu = new string[MAX_LIST];
	searchmenu[0] = "-------------Tim kiem---------------";
	searchmenu[1] = "-----------------------------------";
	searchmenu[2] = "| Chon tu khoa tim kiem:          |";
	searchmenu[3] = "| 1.Ma Lop                        |";
	searchmenu[4] = "| 2.Ma Sinh Vien                  |";
	searchmenu[5] = "| 3.Ho va ten                     |";
	searchmenu[6] = "| 4.Ngay sinh                     |";
	searchmenu[7] = "| 5.Diem trung binh tich luy      |";
	searchmenu[8] = "| 0.Quay lai menu chinh           |";
	searchmenu[9] = "-----------------------------------";
	int position = 3;
	int n = 1;
	while (n==1)
	{
		for (int i = 0; i < MAX_LIST; i++)
		{
			gotoxy(35 * 2, i + 5);
			if (position == i && position != 0)
			{
				Color(12);
				cout << searchmenu[i];
				Color(15);
			}
			else
				cout << searchmenu[i];
		}
		while (n==1)
		{
			if (_kbhit())
			{
				int key = _getch();
				if (key == up())
				{
					if (position == 3)
						position = MAX_LIST - 2;
					else
						position--;
					break;
				}
				if (key == down())
				{
					if (position == MAX_LIST - 2)
						position = 3;
					else
						position++;
					break;
				}
				if (key == enter() || key == right())
				{
					switch (position)
					{
					case 3:   //tim kiem theo ma lop
						system("cls");
						searchType(chon_1, 1, a, 0);
						break;
					case 4: //tim kiem theo ma sinh vien
						system("cls");
						searchType(chon_1, 2, a, 0);
						break;
					case 5: //tim kiem theo ho va ten
						system("cls");
						searchType(chon_1, 3, a, 0);
						break;
					case 6: //tim kiem theo ngay sinh
						break;
					case 7: //tim kiem theo diem trung binh tich luy
						system("cls");
						searchType(chon_1, 5, a, 0);
						break;
					case 8:
						Xoa_man_hinh();
						MakeMainMenu(a);
						break;
					}
					break;
				}
				if (key == left() || key == backspace())
				{
					Xoa_man_hinh();
					MakeMainMenu(a);
					break;
				}
			}
		}
	}


}

void statisticalMenu_1(List a)
{
	hideCursor();
	string* statisticalmenu;
	int MAX_LIST = 6;
	statisticalmenu = new string[MAX_LIST];
	statisticalmenu[0] = "------------THONG KE---------------";
	statisticalmenu[1] = "-----------------------------------";
	statisticalmenu[2] = "| 1.Theo lop                      |";
	statisticalmenu[3] = "| 2.Theo hoc luc                  |";
	statisticalmenu[4] = "| 0.Quay lai menu chinh           |";
	statisticalmenu[5] = "-----------------------------------";
	int position = 2;
	int n = 1;
	while (n==1)
	{
		for (int i = 0; i < MAX_LIST; i++)
		{
			gotoxy(35, i + 6);
			if (position == i && position != 0)
			{
				Color(12);
				cout << statisticalmenu[i];
				Color(15);
			}
			else
				cout << statisticalmenu[i];
		}
		while (n==1)
		{
			if (_kbhit())
			{
				int key = _getch();
				if (key == up())
				{
					if (position == 2)
						position = MAX_LIST - 2;
					else
						position--;
					break;
				}
				if (key == down())
				{
					if (position == MAX_LIST - 2)
						position = 2;
					else
						position++;
					break;
				}
				if (key == enter() || key == right())
				{
					switch (position)
					{
					case 2: //thong ke theo lop
						system("cls");
						do_thi_lop(5, 30);
						n = 0;
						break;
					case 3: //thong ke theo hoc luc
						system("cls");
						do_thi_hoc_luc(5, 30);
						n = 0;
						break;
					case 4:
						Xoa_man_hinh();
						MakeMainMenu(a);
						break;
					}
					break;
				}
				if (key == left() || key == backspace())
				{
					Xoa_man_hinh();
					MakeMainMenu(a);
					break;
				}
			}
		}
	}

}


void introduction()
{
	hideCursor();
	string* intromenu;
	int MAX_LIST = 5;
	intromenu = new string[MAX_LIST];
	intromenu[0] = "------------HUONG DAN--------------";
	intromenu[1] = "| move: arrow down or arrow up    |";
	intromenu[2] = "| choose: enter or arrow right    |";
	intromenu[3] = "| return: backspace or arrow lefr |";
	intromenu[4] = "-----------------------------------";
	for (int i = 0; i < MAX_LIST; i++)
	{
		gotoxy(0, i + 20);
		cout << intromenu[i];

	}
}

void Thoat()
{
	int msgboxID = MessageBox(NULL, "Do you want to exit the program?", "Confirm", MB_OKCANCEL);
	switch (msgboxID)
	{
	case IDCANCEL:
		break;
	case IDOK:
		exit(0);
	}
}

