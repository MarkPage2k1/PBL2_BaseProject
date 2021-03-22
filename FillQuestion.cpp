#include "FillQuestion.h"
#include <string>
#include <windows.h>
#include "mmsystem.h"

Node_fq::Node_fq(string _fqId, int _link, string _message, string _answerKey)
	:fq_id(_fqId), link(_link), message(_message), answerKey(_answerKey)
{

}
Node_fq::~Node_fq()
{
	delete next;
}

Linked_FQ::Linked_FQ()
{
	head = NULL;
}
Linked_FQ:: ~Linked_FQ()
{

}
void Linked_FQ::Search()
{
	Node_fq* P;
	P = this->head;
	string _fqId;
	cin.ignore();
	cout << "Nhap id tu ban muon tim: ";
	getline(cin, _fqId);
	while (P != NULL && P->fq_id != _fqId)
	{
		P = P->next;
	}
	if (P == NULL) cout << "Khong co cau hoi can tim!!!\n";
	else cout << "Da tim thay cau hoi ban can tim!!! \n";
}
void Linked_FQ::Insert_first(string _fqId, int _link, string _message, string _answerKey)
{
	Node_fq* P;
	P = new Node_fq;
	P->fq_id = _fqId;
	P->link = _link;
	P->message = _message;
	P->answerKey = _answerKey;
	P->next = head;
	head = P;
}

void Linked_FQ::Insert_last(string _fqId, int _link, string _message, string _answerKey)
{
	Node_fq* P;
	Node_fq* temp;
	P = new Node_fq;
	P->fq_id = _fqId;
	P->link = _link;
	P->message = _message;
	P->answerKey = _answerKey;
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
void Linked_FQ::Output()
{
	Node_fq* P;
	P = head;
	while (P != NULL)
	{
		cout << "\nFill Question ID: " << P->fq_id;
		cout << "\nLink:  " << P->link;
		cout << "\nAnswerKey: " << P->answerKey;
		cout << "\n\n";
		P = P->next;
	}
	wcout << endl;
}
int Linked_FQ::IsEmpty()
{
	return (this->head == NULL);
}

int Linked_FQ::OutQuestion(string _fqId)
{
	MyLib mylib;
	Node_fq* P;
	P = this->head;
	while (P != NULL && P->fq_id != _fqId)
	{
		P = P->next;
	}
	if (P == NULL) wcout << L"Khong co cau hoi FQ!!!\n";
	else
	{
		string str;
		//int chon = 1;
		//cout << P->message << endl;
		mylib.status(P->message);
		mylib.xoaKhungNoiDung();
		//while (chon == 1)
		//{
			PlaySound(MAKEINTRESOURCE(P->link), GetModuleHandle(NULL), SND_RESOURCE);
			//cout << "1. Nghe lai.\t2. Tra loi.\n";
			//cin >> chon;
			vector<wstring> menu = { L"NGHE LẠI", L"TRẢ LỜI"};
			int pointer = 0;

			MyLib* m = new MyLib();
			while (true)
			{
				fflush(stdin);
				mylib.gotoxy(35, 8);
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
					case 5: {
						switch (pointer)
						{
						case 0:
						{
							PlaySound(MAKEINTRESOURCE(P->link), GetModuleHandle(NULL), SND_RESOURCE);
							break;
						}
						case 1:
						{
							mylib.gotoxy(35, 15);
							wcout << L"\n\t\t\t\t\t    ╔══════════════════════════════╗";
							wcout << L"\n\t\t\t\t\t    ║                              ║";
							wcout << L"\n\t\t\t\t\t    ╚══════════════════════════════╝";
							mylib.gotoxy(48, 17);
							wstring wstr;
							wcin >> wstr;
							string str = mylib.to_string(wstr);
							for (int i = 0; i < str.length(); i++)
							{
								if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
							}
							if (str == P->answerKey)
							{
								PlaySound(MAKEINTRESOURCE(9091), GetModuleHandle(NULL), SND_RESOURCE);
								//cout << "Gioi qua!\n";
								return 1;
							}
							else
							{
								PlaySound(MAKEINTRESOURCE(9092), GetModuleHandle(NULL), SND_RESOURCE);
								//cout << "Ban sai roi!!!\n";
								//cout << "Dap an: " << P->answerKey << endl;
								mylib.status("Dap an: " + P->answerKey);
								mylib.gotoxy(0, 30);
								system("pause");
								return 0;
							}
							break;
						}
						}
						//return;
						break;
					}

					default:
						break;
					}

				}

			}
		}
		/*
		cout << "Tra loi: ";
		cin.ignore();
		cin >> str;
		//cout << "Dap an vua nhap: " << str << endl;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
		}
		//cout << "Dap an ban vua nhap: " << str << endl;
		if (str == P->answerKey)
		{
			PlaySound(MAKEINTRESOURCE(9091), GetModuleHandle(NULL), SND_RESOURCE);
			//cout << "Gioi qua!\n";
			return 1;
		}
		else
		{
			PlaySound(MAKEINTRESOURCE(9092), GetModuleHandle(NULL), SND_RESOURCE);
			//cout << "Ban sai roi!!!\n";
			cout << "Dap an: " << P->answerKey << endl;
			return 0;
		}*/
	//}
}