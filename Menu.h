#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "Word.h"
#include "WordQuestion.h"
#include "MultiQuestion.h"
#include "MultiQuestion.h"
#include "UserHasWord.h"
#include "User.h"
#include "DBHelper.h"
//
#include <codecvt>
#include <conio.h>
#include <vector>
#include <locale>
#include <string>
#include <fstream>
#include <windows.h>
#include <iomanip>
//#include <locale>
//#include <iostream>
//#include <string>
//#include <sstream>
class Menu
{
public:
	void menu();
	void hocTu(Linked_WQ&, Linked_MQ&, Linked_FQ&, Linked_UHW&, User&);
	void hoctuLV(Linked_WQ&, Linked_MQ&, Linked_FQ&, Linked_UHW&, Linked_WORD&, User&, string);
	void onTap(Linked_WQ&, Linked_MQ&, Linked_FQ&, Linked_UHW&, User&);
	void Test(Linked_WQ& , Linked_MQ&, Linked_FQ&, Linked_WORD&, User&);
	//void onTap();
	void tuDien(Linked_WORD&);
	void AddUHWDB(Linked_UHW&, DBHelper&);
	void UpdateUHWDB(Linked_UHW&, DBHelper&);
	void VeKhung();
	void gotoxy(int, int);
	void showInForUS(User&);
	wstring to_wstring(string);
	void status(string);
	int diChuyenPhim();
	void menudong(Linked_WQ&, Linked_MQ&, Linked_FQ&, Linked_UHW&, Linked_WORD&, Linked_RANK&, User&);
	void menuHocTheoLV(Linked_WQ&, Linked_MQ&, Linked_FQ&, Linked_UHW&, Linked_WORD&, Linked_RANK&, User&);
	void xoaKhungNoiDung();
	void showRank(Linked_RANK&, User&);
};

