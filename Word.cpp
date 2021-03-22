#include <iostream>
#include <string>
#include <windows.h>
#include "mmsystem.h"
#include "Word.h"
#pragma comment(lib, "winmm.lib")
using namespace std;


// ========== BEGIN: CLASS WORD ========== //
Node_WORD::Node_WORD(string _wid, string _word, string _meaning, int _pronounciation, string _category, string _example, int _wlevel)
	: w_id(_wid), word(_word), meaning(_meaning), pronounciation(_pronounciation), category(_category), example(_example), w_level(_wlevel)
{
	// ...
}

Node_WORD::~Node_WORD()
{
	delete next;
}

Linked_WORD::Linked_WORD()
{
	head = NULL;
}

Linked_WORD::~Linked_WORD()
{
	// ...
}

// void Linked_WORD::Search(Linked_WORD& WORD)
void Linked_WORD::Search()
{
	Node_WORD* P;
	P = this->head;
	//P = WORD.head;
	string _wid;
	cin.ignore();
	cout << "Nhap id tu ban muon tim: ";
	getline(cin, _wid);
	while (P != NULL && P->w_id != _wid)
	{
		P = P->next;
	}
	if (P == NULL) cout << "Khong co tu can tim!!!\n";
	else cout << "Da tim thay tu ban can tim!!! \n";
}

void Linked_WORD::Output()
{
	Node_WORD* P;
	P = head;
	while (P != NULL)
	{
		cout << "\nID:  " << P->w_id;
		cout << "\nWord:  " << P->word;
		cout << "\nMeaning:  " << P->meaning;
		cout << "\nPronounciation:  " << P->pronounciation;
		cout << "\nTu loai:  " << P->category;
		cout << "\nVi du: " << P->example;
		cout << "\nDo kho cua tu: " << P->w_level;
		cout << "\n\n";
		P = P->next;
	}
	wcout << endl;
}

int Linked_WORD::IsEmpty()
{
	return (head == NULL);
}

void Linked_WORD::Insert_first(string _wid, string _word, string _meaning, int _pronounciation, string _category, string _example, int _wlevel)
{
	Node_WORD* P;
	P = new Node_WORD;
	P->w_id = _wid;
	P->word = _word;
	P->meaning = _meaning;
	P->pronounciation = _pronounciation;
	P->category = _category;
	P->example = _example;
	P->w_level = _wlevel;
	P->next = head;
	head = P;
}

void Linked_WORD::Insert_last(string _wid, string _word, string _meaning, int _pronounciation, string _category, string _example, int _wlevel)
{
	Node_WORD* P;
	Node_WORD* temp;
	P = new Node_WORD;
	P->w_id = _wid;
	P->word = _word;
	P->meaning = _meaning;
	P->pronounciation = _pronounciation;
	P->category = _category;
	P->example = _example;
	P->w_level = _wlevel;
	if (head == NULL)
	{
		head = P;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = P;
	}
}

void Linked_WORD::SearchSound()
{
	MyLib mylib;
	Node_WORD* P;
	P = this->head;
	//P = WORD.head;
	string _word;

	//cin.ignore();
	fflush(stdin);
	mylib.status("Nhap tu ban muon tim: ");
	//cout << "Nhap tu ban muon tim: ";
	//getline(cin, _word);
	mylib.gotoxy(35, 8);
	wcout << L"\n\t\t\t\t\t    ╔══════════════════════════════╗";
	wcout << L"\n\t\t\t\t\t    ║                              ║";
	wcout << L"\n\t\t\t\t\t    ╚══════════════════════════════╝";
	mylib.gotoxy(47, 10);
	wstring wstr;
	wcin >> wstr;
	_word = mylib.to_string(wstr);

	while (P != NULL && P->word != _word)
	{
		P = P->next;
	}
	if (P == NULL)
	{
		mylib.status("Khong co tu can tim!!!");
		mylib.gotoxy(0, 30);
		system("pause");
		Linked_WORD::SearchSound();
		return;
	}
	else
	{

		mylib.gotoxy(35, 12);
		wcout << L"\n\t\t\t\t╔═════════════════════════════════════════════════════════╗";
		wcout << L"\n\t\t\t\t║  TỪ:                                                    ║";
		wcout << L"\n\t\t\t\t║                                                         ║";
		wcout << L"\n\t\t\t\t║  NGHĨA:                                                 ║";
		wcout << L"\n\t\t\t\t║                                                         ║";
		wcout << L"\n\t\t\t\t║  TỪ LOẠI:                                               ║";
		wcout << L"\n\t\t\t\t║                                                         ║";
		wcout << L"\n\t\t\t\t║  VÍ DỤ:                                                 ║";
		wcout << L"\n\t\t\t\t║                                                         ║";
		wcout << L"\n\t\t\t\t╚═════════════════════════════════════════════════════════╝";
		int choice;
		mylib.status("Da tim thay tu ban can tim!!!");
		mylib.gotoxy(41, 14);	wcout << mylib.to_wstring(P->word);
		mylib.gotoxy(43, 16);	wcout << mylib.to_wstring(P->meaning);
		mylib.gotoxy(44, 18);	wcout << mylib.to_wstring(P->category);
		mylib.gotoxy(43, 20);	wcout << mylib.to_wstring(P->example);

		// =================
		vector<wstring> menu = { L"PHÁT ÂM", L"TRA TỪ MỚI",L"THOÁT" };
		int pointer = 0;

		MyLib* m = new MyLib();
		while (true)
		{
			fflush(stdin);
			//mylib.gotoxy(51, 23);
			//wcout << L" ";
			//system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			for (int i = 0; i < menu.size(); ++i)
			{
				if (i == pointer)
				{
					// di chuyen toi noi chon
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					if (i == 0)
					{
						mylib.gotoxy(31, 23); wcout << L"╔════════════════╗";
						mylib.gotoxy(31, 24); wcout << L"║" << right << setw(0) << L">>  " << left << setw(12) << menu[i] << right << setw(0) << L'║';
						mylib.gotoxy(31, 25); wcout << L"╚════════════════╝";
					}
					if (i == 1)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
						mylib.gotoxy(51, 23); wcout << L"╔════════════════╗";
						mylib.gotoxy(51, 24); wcout << L"║" << right << setw(0) << L">>  " << left << setw(12) << menu[i] << right << setw(0) << L'║';
						mylib.gotoxy(51, 25); wcout << L"╚════════════════╝";

					}
					if (i == 2)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
						mylib.gotoxy(71, 23); wcout << L"╔════════════════╗";
						mylib.gotoxy(71, 24); wcout << L"║" << right << setw(0) << L">>  " << left << setw(12) << menu[i] << right << setw(0) << L'║';
						mylib.gotoxy(71, 25); wcout << L"╚════════════════╝";

					}

				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					if (i == 0)
					{
						mylib.gotoxy(31, 23); wcout << L"╔════════════════╗";
						mylib.gotoxy(31, 24); wcout << L"║" << right << setw(0) << L"    " << left << setw(12) << menu[i] << right << setw(0) << L'║';
						mylib.gotoxy(31, 25); wcout << L"╚════════════════╝";
					}
					if (i == 1)
					{
						mylib.gotoxy(51, 23); wcout << L"╔════════════════╗";
						mylib.gotoxy(51, 24); wcout << L"║" << right << setw(0) << L"    " << left << setw(12) << menu[i] << right << setw(0) << L'║';
						mylib.gotoxy(51, 25); wcout << L"╚════════════════╝";
					}
					if (i == 2)
					{
						mylib.gotoxy(71, 23); wcout << L"╔════════════════╗";
						mylib.gotoxy(71, 24); wcout << L"║" << right << setw(0) << L"    " << left << setw(12) << menu[i] << right << setw(0) << L'║';
						mylib.gotoxy(71, 25); wcout << L"╚════════════════╝";
					}

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
					case 3:
					{
						pointer += 1;
						if (pointer == menu.size())
							pointer = 0;
						thoat = true;
						break;
					}
					case 2:
					case 4:
					{
						pointer -= 1;
						if (pointer == -1)
							pointer = menu.size() - 1;
						thoat = true;
						break;
					}
					case 5:
					{
						switch (pointer)
						{
							case 0:
							{
								PlaySound(MAKEINTRESOURCE(P->pronounciation), GetModuleHandle(NULL), SND_RESOURCE);
								break;
							}
							case 1:
							{
								Linked_WORD::SearchSound();
								return;
							}
							case 2:
							{
								return;
							}
						}
					}

					default:
						break;
				}

			}
		}
	}
}

int Linked_WORD::FindLevelWord(string _wId)
{
	Node_WORD* P;
	P = this->head;
	while (P != NULL && P->w_id != _wId)
	{
		P = P->next;
	}
	if (P == NULL) cout << "Khong co tu can tim!!!\n";
	else return P->w_level;
}

int Linked_WORD::getSize()
{
	return this->size;
}

void Linked_WORD::setSize(int size)
{
	this->size = size;
}

Node_WORD* Linked_WORD::getHeadWord()
{
	return head;
}
// ========== END: CLASS WORD ========== //