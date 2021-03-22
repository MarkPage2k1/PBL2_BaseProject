#include "Menu.h"
void Menu::menu()
{
	int chon;
	do
	{
		cout << "===== Chao mung ban den voi Learn Word With SASUKE =======\n";
		cout << "\nChuc nang gom co:\n";
		cout << "1. Hoc tu vung." << endl;
		cout << "2. On lai tu vung." << endl;
		cout << "3. Hoc lai tu kho." << endl;
		cout << "4. Tra tu dien." << endl;
		cout << "0. Thoat." << endl;
		cout << "Moi ban chon:";
		cin >> chon;
		switch (chon)
		{
		case 1:
		{
			system("cls");
			cout << "==== Ban da chon chu nang hoc tu vung ==== \n";
		}
		break;
		case 2:
		{

		}
		break;
		case 3:
		{

		}
		break;
		case 4:
		{

		}
		break;
		case 0:
		{

		}
		break;
		default: break;
		}
	} while (chon != 0);
	
}

void Menu::hocTu(Linked_WQ& WQ, Linked_MQ& MQ, Linked_FQ& FQ, Linked_UHW& UHW, User& US)
{
	srand(time(NULL));
	int chon = 1;
	while (chon)
	{
		WQ.LearnWord(MQ, FQ, UHW, US);
		//WORD.SearchSound();
		cout << "Ban co muon tiep tuc?\n1. co\t0. khong\n" << endl;
		cin >> chon;
	}
	
	//WQ.Test(MQ, FQ, UHW);
	//UHW.Output();
	
}
void Menu::onTap(Linked_WQ& WQ, Linked_MQ& MQ, Linked_FQ& FQ, Linked_UHW& UHW, User& US)
{
	srand(time(NULL));
	WQ.Exercise(MQ, FQ, UHW, US);
}

void Menu::tuDien(Linked_WORD& WORD)
{
	//int chon = 1;
	//while (chon)
	//{
		WORD.SearchSound();
		//cout << "Ban co muon tiep tuc?\n1. co\t0. khong\n" << endl;
		//cin >> chon;
	//}
}

void Menu::hoctuLV(Linked_WQ& WQ, Linked_MQ& MQ, Linked_FQ& FQ, Linked_UHW& UHW, Linked_WORD& WORD, User& US, string level)
{
	srand(time(NULL));
	WQ.LearnWordLevel(MQ, FQ, UHW, WORD, US, level);
}
void Menu::Test(Linked_WQ& WQ, Linked_MQ& MQ, Linked_FQ& FQ, Linked_WORD& WORD, User& US)
{
	srand(time(NULL));
	WQ.Test(MQ, FQ, WORD, US);
}


void Menu::AddUHWDB(Linked_UHW& UHW, DBHelper& db)
{
	if (UHW.getFlags() == 1)
	{
		Node_uhw* P;
		P = UHW.getUHW();
		int i = 1;
		while (P != NULL)
		{
			if (i > UHW.getSize())
			{
				// .... xu li add vo data base
				db.InserUHW(P->w_id, P->wordDiff, P->lastTimeLW);
			}
			i++;
			P = P->next;
		}
	}
}

void Menu::UpdateUHWDB(Linked_UHW& UHW, DBHelper& db)
{

	Node_uhw* P;
	P = UHW.getUHW();
	while (P != NULL)
	{
		db.UpdateUHW(P->w_id, P->memoryLevel, P->lastTimeLW, P->wordDiff, P->timeCheckBack);
		P = P->next;
	}
}

void Menu::VeKhung()
{
	//Menu::gotoxy(0, 0);
	system("cls");
	wcout << L"  ╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n";
	wcout << L"  ║                                                                                                                  ║\n";
	wcout << L"  ║══════════════════════════════════════════════════════════════════════════════════════════════════════════════════║\n";
	wcout << L"  ║                         ║                                                                ║                       ║\n";
	wcout << L"  ║ User:                   ║                                                                ║     Bảng xếp hạng     ║\n";
	wcout << L"  ║ Level:                  ║                                                                ║                       ║\n";
	wcout << L"  ║ EXP:                    ║════════════════════════════════════════════════════════════════║═══════════════════════║\n";
	wcout << L"  ║ Goal:                   ║                                                                ║ 1  NO NAME            ║\n";
	wcout << L"  ║                         ║                                                                ║ 2  NO NAME            ║\n";
	wcout << L"  ║                         ║                                                                ║ 3  NO NAME            ║\n";
	wcout << L"  ║                         ║                                                                ║ 4  NO NAME            ║\n";
	wcout << L"  ║                         ║                                                                ║ 5  NO NAME            ║\n";
	wcout << L"  ║                         ║                                                                ║ 6  NO NAME            ║\n";
	wcout << L"  ║                         ║                                                                ║ 7  NO NAME            ║\n";
	wcout << L"  ║                         ║                                                                ║ 8  NO NAME            ║\n";
	wcout << L"  ║                         ║                                                                ║ 9  NO NAME            ║\n";
	wcout << L"  ║                         ║                                                                ║ 10 NO NAME            ║\n";
	wcout << L"  ║                         ║                                                                ║                       ║\n";
	wcout << L"  ║                         ║                                                                ║       Loading ...     ║\n";
	wcout << L"  ║  Bạn đang cảm thấy:     ║                                                                ║                       ║\n";
	wcout << L"  ║                         ║                                                                ║                       ║\n";
	wcout << L"  ║       (Vui vẻ)          ║                                                                ║                       ║\n";
	wcout << L"  ║                         ║                                                                ║                       ║\n";
	wcout << L"  ║     (^_^)(^_^)          ║                                                                ║                       ║\n";
	wcout << L"  ║     (^_^)  (^_^)        ║                                                                ║                       ║\n";
	wcout << L"  ║     (^_^) (^_^)         ║                                                                ║                       ║\n";
	wcout << L"  ║     (^_^)               ║                                                                ║                       ║\n";
	wcout << L"  ║     (^_^)               ║                                                                ║                       ║\n";
	wcout << L"  ║     (^_^)               ║                                                                ║                       ║\n";
	wcout << L"  ╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";

	int a = 3;
	int b = 100;
	while (a <= 43)
	{
		for (int j = 3; j <= a; j++)
		{
			Menu::gotoxy(j, 1);
			wcout << " ";
		}
		Menu::gotoxy(a, 1); // cot, hang
		wcout << "Hoc tu vung cung ";
		a++;
		for (int j = 110; j >= b; j--)
		{
			Menu::gotoxy(j, 1);
			wcout << " ";
		}

		Menu::gotoxy(b, 1); // cot, hang
		wcout << "LEARN WORD";
		b--;
		Sleep(20);
	}
	time_t baygio = time(0);
	tm* ltm = localtime(&baygio);
	Menu::gotoxy(85, 1);
	if (ltm->tm_wday == 0) wcout << L"Chu nhat, ";
	if (ltm->tm_wday == 1) wcout << L"Thu hai, ";
	if (ltm->tm_wday == 2) wcout << L"Thu ba, ";
	if (ltm->tm_wday == 3) wcout << L"Thu tu, ";
	if (ltm->tm_wday == 4) wcout << L"Thu nam, ";
	if (ltm->tm_wday == 5) wcout << L"Thu sau, ";
	if (ltm->tm_wday == 6) wcout << L"Thu bay, ";
	wcout << L"ngay " << ltm->tm_mday << L" - " << 1 + ltm->tm_mon << L" - " << 1900 + ltm->tm_year;
	//Menu::gotoxy(0, 30);
	//Menu::gotoxy(100, 100);
	Menu::status("Moi ban choi chuc nang (*_*)");

}

void Menu::gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void Menu::showInForUS(User& US)
{
	Menu::gotoxy(12, 4);
	wcout << Menu::to_wstring(US.GetNickName());
	Menu::gotoxy(12, 5);
	wcout << Menu::to_wstring(US.GetLevel());
	Menu::gotoxy(12, 6);
	wcout << US.GetEXP();
	Menu::gotoxy(12, 7);
	wcout << US.GetGoal();
}

wstring Menu::to_wstring(string str)
{
	using convert_t = codecvt_utf8<wchar_t>;
	wstring_convert<convert_t, wchar_t> strconverter;
	return strconverter.from_bytes(str);
}

void Menu::status(string str)
{
	for (int i = 30; i <= 90; i++)
	{
		Menu::gotoxy(i, 4);
		wcout << L" ";
	}
	
	Menu::gotoxy(32, 4); // 90
	wcout << Menu::to_wstring(str);
}

int Menu::diChuyenPhim()
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


void Menu::menudong(Linked_WQ& WQ, Linked_MQ& MQ, Linked_FQ& FQ, Linked_UHW& UHW, Linked_WORD& WORD, Linked_RANK& RANK, User& US)
{
	vector<wstring> menu = { L"HỌC TỪ", L"ÔN TẬP", L"TỪ ĐIỂN",L"THOÁT"};
	int pointer = 0;

	Menu* m = new Menu();
	RANK.SapXepGiam();
	Menu::showRank(RANK, US);
	while (true)
	{
		Menu::status("Moi ban choi chuc nang (*_*)");
		Menu::showInForUS(US);
		fflush(stdin);
		Menu::gotoxy(35, 8);
		wcout << L"";
		//system("cls");
		for (int i = 0; i < menu.size(); ++i)
		{
			if (i == pointer)
			{
				// di chuyen toi noi chon
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				wcout << L"\n\t\t\t\t\t    ╔══════════════════════════════╗";
				wcout << L"\n\t\t\t\t\t    ║" << right << setw(10) << L">>  " << left << setw(20) << menu[i] << right << setw(0) << L'║';
				wcout << L"\n\t\t\t\t\t    ╚══════════════════════════════╝";
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				wcout << L"\n\t\t\t\t\t    ╔══════════════════════════════╗";
				wcout << L"\n\t\t\t\t\t    ║" << right << setw(10) << L"    " << left << setw(20) << menu[i] << right << setw(0) << L'║';
				wcout << L"\n\t\t\t\t\t    ╚══════════════════════════════╝";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		}

		int x;
		bool thoat = false;


		if (_kbhit)
		{
			x = m->diChuyenPhim();
			switch (x)
			{
			case 1:
			case 3: {
				pointer += 1;
				if (pointer == menu.size())
					pointer = 0;
				thoat = true;
				break; }
			case 2:
			case 4: {
				pointer -= 1;
				if (pointer == -1)
					pointer = menu.size() - 1;
				thoat = true;
				break; }
			case 5:
			{
				switch (pointer)
				{
				case 0:
				{
					Menu::xoaKhungNoiDung();
					//

					if (US.GetEXP() == 0)
					{
						
						//
						vector<wstring> menu1 = { L"KIỂM TRA TRÌNH ĐỘ", L"HỌC TỪ ĐẦU" };
						int pointer1 = 0;

						Menu* m1 = new Menu();

						while (true)
						{
							Menu::showInForUS(US);
							fflush(stdin);
							Menu::gotoxy(35, 8);
							wcout << L"";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							for (int i = 0; i < menu1.size(); ++i)
							{
								if (i == pointer1)
								{

									// di chuyen toi noi chon
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
									wcout << L"\n\t\t\t\t\t    ╔══════════════════════════════╗";
									wcout << L"\n\t\t\t\t\t    ║" << right << setw(10) << L">>  " << left << setw(20) << menu1[i] << right << setw(0) << L'║';
									wcout << L"\n\t\t\t\t\t    ╚══════════════════════════════╝";
								}
								else
								{
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
									wcout << L"\n\t\t\t\t\t    ╔══════════════════════════════╗";
									wcout << L"\n\t\t\t\t\t    ║" << right << setw(10) << L"    " << left << setw(20) << menu1[i] << right << setw(0) << L'║';
									wcout << L"\n\t\t\t\t\t    ╚══════════════════════════════╝";
								}
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

							}

							int x1;
							bool thoat1 = false;
							int checkKT = 0;


							if (_kbhit) {
								x1 = m1->diChuyenPhim();
								switch (x1)
								{
								case 1:
								case 3: {
									pointer1 += 1;
									if (pointer1 == menu1.size())
										pointer1 = 0;
									thoat1 = true;
									break; }
								case 2:
								case 4: {
									pointer1 -= 1;
									if (pointer1 == -1)
										pointer1 = menu1.size() - 1;
									thoat1 = true;
									break; }
								case 5: 
								{
									switch (pointer1) 
									{
										case 0: 
										{
											Menu::Test(WQ, MQ, FQ, WORD, US);
											Menu::showInForUS(US);
											Menu::showRank(RANK, US);
											checkKT = 1;
											break;
										}
										case 1:
										{
											Menu::menuHocTheoLV(WQ, MQ, FQ, UHW, WORD, RANK, US);
											checkKT = 1;
											break;
										}
										default:
											break;
									}
									thoat1 = true;
									break;
								}

								default:
									break;
								}

							}
							if (checkKT == 1) break;

						}

						//
						//Menu::hoctuLV(WQ, MQ, FQ, UHW, WORD, US, US.GetLevel());
						//Menu::showInForUS(US);
						//Menu::xoaKhungNoiDung();
						break;
					}
					else
					{
						Menu::menuHocTheoLV(WQ, MQ, FQ, UHW, WORD, RANK, US);
						break;
					}
				}
				case 1:
				{
					Menu::xoaKhungNoiDung();
					Menu::onTap(WQ, MQ, FQ, UHW, US);
					Menu::showRank(RANK, US);
					//Menu::xoaKhungNoiDung();
					break;
				}
				case 2:
				{
					Menu::xoaKhungNoiDung();
					Menu::tuDien(WORD);
					Menu::xoaKhungNoiDung();
					break;
				}
				case 3:
				{
					Menu::status("GOODBYE AND SEE YOU AGAIN !!!");
					return;
				}
				}

			default:
				break;
			}

			}

		}
	}
}

void Menu::xoaKhungNoiDung()
{
	for (int j = 7; j <= 28; j++)
	{
		for (int i = 29; i < 93; i++)
		{
			Menu::gotoxy(i, j);
			wcout << L" ";
		}
	}
	
}

void Menu::menuHocTheoLV(Linked_WQ& WQ, Linked_MQ& MQ, Linked_FQ& FQ, Linked_UHW& UHW, Linked_WORD& WORD, Linked_RANK& RANK, User& US)
{
	vector<wstring> menu = { L"HỌC TỪ LEVEL 1", L"HỌC TỪ LEVEL 2", L"HỌC TỪ LEVEL 3",L"HỌC TỪ LEVEL 4", L"HỌC TỪ LEVEL 5", L"QUAY LẠI" };
	int pointer = 0;

	Menu* m = new Menu();
	while (true)
	{
		Menu::status("Moi ban chon level de hoc!!!");
		Menu::showInForUS(US);
		fflush(stdin);
		Menu::gotoxy(35, 8);
		wcout << L"";
		//system("cls");
		for (int i = 0; i < menu.size(); ++i)
		{
			if (i == pointer)
			{
				// di chuyen toi noi chon
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				wcout << L"\n\t\t\t\t\t    ╔══════════════════════════════╗";
				wcout << L"\n\t\t\t\t\t    ║" << right << setw(10) << L">>  " << left << setw(20) << menu[i] << right << setw(0) << L'║';
				wcout << L"\n\t\t\t\t\t    ╚══════════════════════════════╝";
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				wcout << L"\n\t\t\t\t\t    ╔══════════════════════════════╗";
				wcout << L"\n\t\t\t\t\t    ║" << right << setw(10) << L"    " << left << setw(20) << menu[i] << right << setw(0) << L'║';
				wcout << L"\n\t\t\t\t\t    ╚══════════════════════════════╝";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		}

		int x;
		bool thoat = false;


		if (_kbhit)
		{
			x = m->diChuyenPhim();
			switch (x)
			{
			case 1:
			case 3: {
				pointer += 1;
				if (pointer == menu.size())
					pointer = 0;
				thoat = true;
				break; }
			case 2:
			case 4: {
				pointer -= 1;
				if (pointer == -1)
					pointer = menu.size() - 1;
				thoat = true;
				break; }
			case 5:
			{
				switch (pointer)
				{
					case 0:
					{
						Menu::xoaKhungNoiDung();
						Menu::hoctuLV(WQ, MQ, FQ, UHW, WORD, US, "L0001");
						Menu::showInForUS(US);
						Menu::showRank(RANK, US);
						//Menu::xoaKhungNoiDung();
						break;
					}
					case 1:
					{
						if (US.GetLevel() >= "L0002")
						{
							Menu::xoaKhungNoiDung();
							Menu::hoctuLV(WQ, MQ, FQ, UHW, WORD, US, "L0002");
							Menu::showInForUS(US);
							Menu::showRank(RANK, US);
						}
						else
						{
							Menu::status("Hien tai ban chua the hoc o level nay!!!");
							Menu::gotoxy(0, 30);
							system("pause");
						}
						//Menu::xoaKhungNoiDung();
						break;
					}
					case 2:
					{
						if (US.GetLevel() >= "L0003")
						{
							Menu::xoaKhungNoiDung();
							Menu::hoctuLV(WQ, MQ, FQ, UHW, WORD, US, "L0003");
							Menu::showInForUS(US);
							Menu::showRank(RANK, US);
						}
						else
						{
							Menu::status("Hien tai ban chua the hoc o level nay!!!");
							Menu::gotoxy(0, 30);
							system("pause");
						}
						//Menu::xoaKhungNoiDung();
						break;;
					}
					case 3:
					{
						if (US.GetLevel() >= "L0004")
						{
							Menu::xoaKhungNoiDung();
							Menu::hoctuLV(WQ, MQ, FQ, UHW, WORD, US, "L0004");
							Menu::showInForUS(US);
							Menu::showRank(RANK, US);
						}
						else
						{
							Menu::status("Hien tai ban chua the hoc o level nay!!!");
							Menu::gotoxy(0, 30);
							system("pause");
						}
						//Menu::xoaKhungNoiDung();
						break;;
					}
					case 4:
					{
						if (US.GetLevel() >= "L0005")
						{
							Menu::xoaKhungNoiDung();
							Menu::hoctuLV(WQ, MQ, FQ, UHW, WORD, US, "L0005");
							Menu::showInForUS(US);
							Menu::showRank(RANK, US);
						}
						else
						{
							Menu::status("Hien tai ban chua the hoc o level nay!!!");
							Menu::gotoxy(0, 30);
							system("pause");
						}
						//Menu::xoaKhungNoiDung();
						break;
					}
					case 5:
					{
						Menu::xoaKhungNoiDung();
						return;
					}
				}

			default:
				break;
			}

			}

		}
	}
}

void Menu::showRank(Linked_RANK& RANK, User& US)
{
	if (US.GetEXP() != RANK.FindID_EXP(US.GetID()))
	{
		RANK.SetEXP(US.GetID(), US.GetEXP());
		RANK.SapXepGiam();
	}
	RANK.Output();
}