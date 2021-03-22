#include "MyLib.h"
int MyLib::diChuyenPhim()
{
	char c = _getch();
	if ((int)c == -32) c = _getch();
	switch ((int)c) {
	case 80:
		return 1; //cout << "Xuong";
	case 72:
		return 2; //cout << "Len";
	case 77:
		return 3; //cout << "Phai";       
	case 75:
		return 4; //cout << "Trai";
	case 27:
		return 8; //Nut ESC thoat
	case 13:
		return 5; //Nut Enter
	default:
		return 0; //cout << "Sai";
	}
}

void MyLib::status(string str)
{
	for (int i = 30; i <= 81; i++)
	{
		MyLib::gotoxy(i, 4);
		wcout << L" ";
	}

	MyLib::gotoxy(32, 4); // 90
	wcout << MyLib::to_wstring(str);
}


wstring MyLib::to_wstring(string str)
{
	using convert_t = codecvt_utf8<wchar_t>;
	wstring_convert<convert_t, wchar_t> strconverter;
	return strconverter.from_bytes(str);
}

void MyLib::gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void MyLib::xoaKhungNoiDung()
{
	for (int j = 7; j <= 28; j++)
	{
		for (int i = 29; i < 93; i++)
		{
			MyLib::gotoxy(i, j);
			wcout << L" ";
		}
	}

}

void MyLib::EXP(int exp)
{
	for (int i = 82; i <= 90; i++)
	{
		MyLib::gotoxy(i, 4);
		wcout << L" ";
	}

	MyLib::gotoxy(82, 4); // 90
	wcout << L"EXP: " << exp;
}

string MyLib::to_string(wstring wstr)
{
	using convert_t = codecvt_utf8<wchar_t>;
	wstring_convert<convert_t, wchar_t> strconverter;
	return strconverter.to_bytes(wstr);
}

void MyLib::DeleteEXP()
{
	for (int i = 82; i <= 90; i++)
	{
		MyLib::gotoxy(i, 4);
		wcout << L" ";
	}
}