#pragma once
#include "Header.h"
#include "List.h"
#include "InSV.h"
#include  "NhapSV.h"

void in_cot_ngang(int color, int size, int x, int y);
void in_cot_doc(int color, int size, int x, int y);
void ve_do_thi(int x, int y, int cot_doc, int cot_ngang, int length);
void do_thi_lop(int x, int y);
void do_thi_hoc_luc(int x, int y);

void in_cot_ngang(int color, int size, int x, int y)
{
	Color(color);
	gotoxy(x, y);
	for (int i = 0; i < size; i++)
	{
		printf("%c", 219);
	}
}

void in_cot_doc(int color, int size, int x, int y)
{
	Color(color);
	for (int i = 0; i < size; i++)
	{
		gotoxy(x, y - i);
		printf("%c", 219);
		gotoxy(x + 1, y - i);
		printf("%c", 219);
	}
	Color(15);
}

void ve_do_thi(int x, int y, int cot_doc, int cot_ngang, int length)
{
	int do_dai_cot_doc = cot_doc * 5;
	int do_dai_cot_ngang = cot_ngang * 10;

	//ve diem goc
	gotoxy(x, y);
	printf("%c", 192);   //goc trai duoi

	//ve truc toa do Oxy
	for (int i = 1; i < do_dai_cot_doc; i++)   //ve cot doc
	{
		gotoxy(x, y - i);
		printf("%c", 179);   //doc
	}


	for (int i = 1; i < do_dai_cot_ngang; i++)  //ve cot ngang
	{
		gotoxy(x + i, y);
		printf("%c", 196);   //ngang
	}

	//vach diem
	for (int i = 1; i < cot_doc; i++)
	{
		gotoxy(x, i * 5);
		printf("%c", 180);   //ngang
	}

	for (int i = 1; i <= cot_ngang; i++)
	{
		gotoxy(x + i * 10, y);
		printf("%c", 194);
	}


	//dien chi so
	int sohs = length;
	int chiso = length / (cot_doc - 1);
	for (int i = 1; i < cot_doc; i++)
	{
		gotoxy(x - 2, y - i * 5);
		cout << chiso * i;
	}



}

void do_thi_lop(int x, int y)
{
	system("cls");
	List l;
	init(l);
	readFile("danhsachsinhvien.dat", l);
	int bd53=0;
	int cntt1=0; 
	int cntt2=0; 
	int an53=0;
	int dth=0;

	Node* temp = l.first;
	while (temp != NULL)
	{
		char x[15];
		strcpy(x, temp->sv.MaLop);
		if (strcmpi(x, "BD53")==0)
		{
			bd53++;
		}
		else if (strcmpi(x, "CNTT1")==0)
		{
			cntt1++;
		}
		else if (strcmpi(x, "CNTT2")==0)
		{
			cntt2++;
		}
		else if (strcmpi(x, "ATTT53")==0)
		{
			an53++;
		}
		else if (strcmpi(x, "DTH")==0)
		{
			dth++;
		}

		temp = temp->next;
	}
	int a[5];
	a[0] = bd53;
	a[1] = cntt1;
	a[2] = cntt2;
	a[3] = an53;
	a[4] = dth;
	
	int max = a[0];
	for (int i = 0; i <= 4; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}

	y = 6 * 5;

	ve_do_thi(x, y , 6, 5, max+3);
	//dien ten lop
	gotoxy(x + 9, y+1);
	cout << "BD53";

	gotoxy(x + 10 * 2 - 1, y + 1);
	cout << "CNTT2";

	gotoxy(x + 10 * 3 - 1, y + 1);
	cout << "CNTT1";

	gotoxy(x + 10 * 4 - 1, y + 1);
	cout << "ATTT53";

	gotoxy(x + 10 * 5 - 1, y + 1);
	cout << "DTH";


	int chiso = (max+3) / (6 - 1);

	//chen cot 
	in_cot_doc(12, (bd53/chiso)*5, x+9, y-1);
	gotoxy(x + 9, y - (bd53 / chiso) * 5 - 1);
	cout << bd53;

	in_cot_doc(11, (cntt1 / chiso) * 5, x + 2*10-1, y - 1);
	gotoxy(x + 2 * 10 - 1, y - (cntt1 / chiso) * 5 - 1);
	cout << cntt1;

	in_cot_doc(10, (cntt2 / chiso) * 5, x + 3*10-1, y - 1);
	gotoxy(x + 3*10-1, y - (cntt2/ chiso) * 5 - 1);
	cout << cntt2;

	in_cot_doc(9, (an53 / chiso) * 5, x + 4*10-1, y - 1);
	gotoxy(x + 4*10-1, y - (an53 / chiso) * 5 - 1);
	cout << an53;

	in_cot_doc(12, (dth / chiso) * 5, x+5*10-1, y - 1);
	gotoxy(x + 5*10-1, y - (dth / chiso) * 5 - 1);
	cout << dth;

	gotoxy(40, 40);
}


void do_thi_hoc_luc(int x, int y)
{
	system("cls");
	List l;
	init(l);
	readFile("danhsachsinhvien.dat", l);
	int xuat_sac = 0;
	int gioi = 0;
	int kha = 0;
	int tb = 0;
	int yeu = 0;

	Node* temp = l.first;
	while(temp != NULL)
	{
		float x = temp->sv.diemTB;
		if (x >= 3.5)
		{
			xuat_sac++;
		}
		else if (x >= 3.2 && x < 3.5)
		{
			gioi++;
		}
		else if (x >= 2.5 && x < 3.2)
		{
			kha++;
		}
		else if (x >= 2.0 && x < 2.5)
		{
			tb++;
		}
		else if (x < 2.0)
		{
			yeu++;
		}
		temp = temp->next;
	}


	int a[5];
	a[0] = xuat_sac;
	a[1] = gioi;
	a[2] = kha;
	a[3] = tb;
	a[4] = yeu;

	int max = a[0];
	for (int i = 0; i <= 4; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}

	y = 6 * 5;

	ve_do_thi(x, y, 6, 5, max + 3);
	//dien ten lop
	gotoxy(x + 7, y + 1);
	cout << "Xuat sac";

	gotoxy(x + 10 * 2 - 1, y + 1);
	cout << "Gioi";

	gotoxy(x + 10 * 3 - 1, y + 1);
	cout << "Kha";

	gotoxy(x + 10 * 4 - 3, y + 1);
	cout << "Trung binh";

	gotoxy(x + 10 * 5 - 1, y + 1);
	cout << "Yeu";



	int chiso = (max + 3) / (6 - 1);

	//chen cot 
	in_cot_doc(12, (xuat_sac / chiso) * 5, x + 9, y - 1);
	gotoxy(x + 9, y - (xuat_sac / chiso) * 5 - 1);
	cout << xuat_sac;

	in_cot_doc(11, (gioi / chiso) * 5, x + 2 * 10 - 1, y - 1);
	gotoxy(x + 2 * 10 - 1, y - (gioi / chiso) * 5 - 1);
	cout << gioi;

	in_cot_doc(10, (kha / chiso) * 5, x + 3 * 10 - 1, y - 1);
	gotoxy(x + 3 * 10 - 1, y - (kha / chiso) * 5 - 1);
	cout << kha;

	in_cot_doc(9, (tb / chiso) * 5, x + 4 * 10 - 1, y - 1);
	gotoxy(x + 4 * 10 - 1, y - (tb / chiso) * 5 - 1);
	cout << tb;

	in_cot_doc(12, (yeu / chiso) * 5, x + 5 * 10 - 1, y - 1);
	gotoxy(x + 5 * 10 - 1, y - (yeu / chiso) * 5 - 1);
	cout << yeu;

	gotoxy(40, 40);
}

