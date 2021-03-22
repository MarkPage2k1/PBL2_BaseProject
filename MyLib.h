#pragma once
#include <iostream>
#include <conio.h>
#include <codecvt>
#include <windows.h>
using namespace std;

class MyLib
{
public:
	void gotoxy(int, int);
	int diChuyenPhim();
	void status(string);
	wstring to_wstring(string);
	void xoaKhungNoiDung();
	void EXP(int);
	void DeleteEXP();
	string to_string(wstring);
};

