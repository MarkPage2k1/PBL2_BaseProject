#include "MultiQuestion.h"
#include <windows.h>
#include "mmsystem.h"
#include <string>
Node_mq::Node_mq(string _mqId, string _mqContent, string _answerKey, string _answerA, string _answerB, string _answerC, string _answerD)
	: mq_id(_mqId), mq_content(_mqContent), answerKey(_answerKey), answerA(_answerA), answerB(_answerB), answerC(_answerC), answerD(_answerD)
{}

Node_mq::~Node_mq()
{
	delete next;
}

Linked_MQ::Linked_MQ()
{
	head = NULL;
}
Linked_MQ::~Linked_MQ()
{

}

void Linked_MQ:: Search()
{
	Node_mq* P;
	P = this->head;
	string _mqId;
	cin.ignore();
	cout << "Nhap id tu ban muon tim: ";
	getline(cin, _mqId);
	while (P != NULL && P->mq_id != _mqId)
	{
		P = P->next;
	}
	if (P == NULL) cout << "Khong co tu can tim!!!\n";
	else cout << "Da tim thay tu ban can tim!!! \n";
}
void Linked_MQ::Insert_first(string _mqId, string _mqContent, string _answerKey, string _answerA, string _answerB, string _answerC, string _answerD)
{
	Node_mq* P;
	P = new Node_mq;
	P->mq_id = _mqId;
	P->mq_content = _mqContent;
	P->answerKey = _answerKey;
	P->answerA = _answerA;
	P->answerB = _answerB;
	P->answerC = _answerC;
	P->answerD = _answerD;
	P->next = head;
	head = P;
}

void Linked_MQ::Insert_last(string _mqId, string _mqContent, string _answerKey, string _answerA, string _answerB, string _answerC, string _answerD)
{
	Node_mq* P;
	Node_mq* temp;
	P = new Node_mq;
	P->mq_id = _mqId;
	P->mq_content = _mqContent;
	P->answerKey = _answerKey;
	P->answerA = _answerA;
	P->answerB = _answerB;
	P->answerC = _answerC;
	P->answerD = _answerD;
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
void Linked_MQ::Output()
{
	Node_mq* P;
	P = head;
	while (P != NULL)
	{
		cout << "\nMutil Question ID: " << P->mq_id;
		cout << "\nContent:  " << P->mq_content;
		cout << "\nPhuong an 1: " << P->answerA;
		cout << "\nPhuong an 2: " << P->answerB;
		cout << "\nPhuong an 3: " << P->answerC;
		cout << "\nPhuong an 4: " << P->answerD;
		cout << "\nDap an: " << P->answerKey;
		cout << "\n\n";
		P = P->next;
	}
	wcout << endl;
}
int Linked_MQ::IsEmpty()
{
	return (this->head == NULL);
}

int Linked_MQ::OutQuestion(string _mqId)
{
	Node_mq* P;
	P = this->head;
	char answer;
	string temp;
	MyLib mylib;
	vector<wstring> menu;
	while (P != NULL && P->mq_id != _mqId)
	{
		P = P->next;
	}
	if (P == NULL) cout << "Khong co cau hoi!!!\n";
	else
	{
		/*
		wcout << mylib.to_wstring(P->mq_content) << endl;
		wcout << L"==============================" << endl
			 << L"A: " << mylib.to_wstring(P->answerA) << endl
			 << L"B: " << mylib.to_wstring(P->answerB) << endl
			 << L"C: " << mylib.to_wstring(P->answerC) << endl
			 << L"D: " << mylib.to_wstring(P->answerD) << endl;
		cout << L"Cau tra loi: ";
		*/
		// ==============================
		//vector<wstring> menu = { L"PHƯƠNG ÁN A", L"ÔN TẬP", L"TỪ ĐIỂN",L"THOÁT" };
		menu.clear();
		mylib.status(P->mq_content);
		menu.push_back(mylib.to_wstring(P->answerA));
		menu.push_back(mylib.to_wstring(P->answerB));
		menu.push_back(mylib.to_wstring(P->answerC));
		menu.push_back(mylib.to_wstring(P->answerD));
		//menu[0] = mylib.to_wstring(P->answerA);
		//menu[1] = mylib.to_wstring(P->answerB);
		//menu[2] = mylib.to_wstring(P->answerC);
		//menu[3] = mylib.to_wstring(P->answerD);
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
						//mylib.xoaKhungNoiDung();
						//::hoctuLV(WQ, MQ, FQ, UHW, WORD, US, US.GetLevel());
						temp = "a";
						if (temp == P->answerKey)
						{
							//cout << "Gioi qua!\n"; 
							PlaySound(MAKEINTRESOURCE(9091), GetModuleHandle(NULL), SND_RESOURCE);
							return 1;
						}
						else
						{
							PlaySound(MAKEINTRESOURCE(9092), GetModuleHandle(NULL), SND_RESOURCE);
							//cout << "Sai mat roi!\n\n";
							return 0;
						}
						break;
					}
					case 1:
					{
						//mylib.xoaKhungNoiDung();
						//::hoctuLV(WQ, MQ, FQ, UHW, WORD, US, US.GetLevel());
						temp = "b";
						if (temp == P->answerKey)
						{
							//cout << "Gioi qua!\n"; 
							PlaySound(MAKEINTRESOURCE(9091), GetModuleHandle(NULL), SND_RESOURCE);
							return 1;
						}
						else
						{
							PlaySound(MAKEINTRESOURCE(9092), GetModuleHandle(NULL), SND_RESOURCE);
							//cout << "Sai mat roi!\n\n";
							return 0;
						}
						break;
					}
					case 2:
					{
						//mylib.xoaKhungNoiDung();
						//::hoctuLV(WQ, MQ, FQ, UHW, WORD, US, US.GetLevel());
						temp = "c";
						if (temp == P->answerKey)
						{
							//cout << "Gioi qua!\n"; 
							PlaySound(MAKEINTRESOURCE(9091), GetModuleHandle(NULL), SND_RESOURCE);
							return 1;
						}
						else
						{
							PlaySound(MAKEINTRESOURCE(9092), GetModuleHandle(NULL), SND_RESOURCE);
							//cout << "Sai mat roi!\n\n";
							return 0;
						}
						break;
					}
					case 3:
					{
						//mylib.xoaKhungNoiDung();
						//::hoctuLV(WQ, MQ, FQ, UHW, WORD, US, US.GetLevel());
						temp = "d";
						if (temp == P->answerKey)
						{
							//cout << "Gioi qua!\n"; 
							PlaySound(MAKEINTRESOURCE(9091), GetModuleHandle(NULL), SND_RESOURCE);
							return 1;
						}
						else
						{
							PlaySound(MAKEINTRESOURCE(9092), GetModuleHandle(NULL), SND_RESOURCE);
							//cout << "Sai mat roi!\n\n";
							return 0;
						}
						break;
					}

					}
					break;
					//return;
				}

				default:
					break;
				}

			}

		}

		/*
		// ==============================
		// wcin >> mylib.to_wstring(answer);
		if (answer >= 65 && answer <= 90) answer += 32;
		temp = answer;
		if (temp == P->answerKey)
		{
			//cout << "Gioi qua!\n"; 
			PlaySound(MAKEINTRESOURCE(9091), GetModuleHandle(NULL), SND_RESOURCE);
			return 1;
		}
		else
		{
			PlaySound(MAKEINTRESOURCE(9092), GetModuleHandle(NULL), SND_RESOURCE);
			//cout << "Sai mat roi!\n\n";
			return 0;
		}
		*/
		
	}
}
