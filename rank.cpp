#include "rank.h"


// ========== BEGIN: CLASS WORD ========== //
Node_RANK::Node_RANK(string u_Id, string nickname, int exp)
	:u_id(u_Id), nickname(nickname), exp(exp)
{
	// ...
}

Node_RANK::~Node_RANK()
{
	delete next;
}

Linked_RANK::Linked_RANK()
{
	head = NULL;
}

Linked_RANK::~Linked_RANK()
{
	// ...
}


void Linked_RANK::Output()
{
	MyLib mylib;
	Node_RANK* P;
	P = head;
	int dem = 0;
	int i = 7;
	while (P != NULL)
	{
		for (int j = i; j < 27; j++)
		{
			mylib.gotoxy(90 + j, i);
			wcout << L" ";
		}
		
		mylib.gotoxy(98, i);
		wcout << mylib.to_wstring(P->nickname);
		//mylib.gotoxy(120, i);
		//wcout << P->exp;
		i++;
		P = P->next;
		dem++;
		if (dem >= 10) break;
	}
	wcout << endl;
}


void Linked_RANK::Insert_first(string u_id, string nickname, int exp)
{
	Node_RANK* P;
	P = new Node_RANK;
	P->u_id = u_id;
	P->nickname = nickname;
	P->exp = exp;
	P->next = head;
	head = P;
}

void Linked_RANK::SapXepGiam()
{
	Node_RANK* P;
	Node_RANK* P1;
	for (P = head; P != NULL; P = P->next)
	{
		for (P1 = P->next; P1 != NULL; P1 = P1->next)
		{
			if (P->exp < P1->exp)
			{
				int tmp = P->exp;
				P->exp = P1->exp;
				P1->exp = tmp;
				// =======
				string strtmp = P->nickname;
				P->nickname = P1->nickname;
				P1->nickname = strtmp;

				// ============
				strtmp = P->u_id;
				P->u_id = P1->u_id;
				P1->u_id = strtmp;
			}
		}
	}
}
void Linked_RANK::SetEXP(string us, int exp)
{
	Node_RANK* P;
	P = this->head;
	while (P != NULL && P->u_id != us)
	{
		P = P->next;
	}
	if (P != NULL) P->exp = exp;
}

int Linked_RANK::FindID_EXP(string us)
{
	MyLib mylib;
	Node_RANK* P;
	P = this->head;
	while (P != NULL && P->u_id != us)
	{
		P = P->next;
	}
	if (P != NULL)
	{
		return P->exp;
	}
	
}
// ========== END: CLASS WORD ========== //