#include "UserHasWord.h"

Node_uhw::Node_uhw(string _uId, string _wId, int _mLevl, time_t _lastTimeLW, bool _wordDiff, time_t _timeCB)
	: u_id(_uId), w_id(_wId), memoryLevel(_mLevl), lastTimeLW(_lastTimeLW), wordDiff(_wordDiff), timeCheckBack(_timeCB)
{}

Node_uhw::~Node_uhw()
{
	delete next;
}

Linked_UHW::Linked_UHW()
{
	this->head = NULL;
}

Linked_UHW::~Linked_UHW()
{
	// ...
}

int Linked_UHW::getSize()
{
	return this->size;
}

void Linked_UHW::setSize(int Size)
{
	this->size = Size;
}

int Linked_UHW::getFlags()
{
	return this->flags;
}

void Linked_UHW::setFlags(int flag)
{
	this->flags = flag;
}

void Linked_UHW::Output()
{
	MyLib mylib;
	Node_uhw* P;
	P = head;
	while (P != NULL)
	{
		wcout << L"\nUser ID: " << mylib.to_wstring( P->u_id);
		wcout << L"\nWord ID:  " << mylib.to_wstring(P->w_id);
		wcout << L"\nMemory level: " << P->memoryLevel;
		wcout << L"\nLast time learn word: " << P->lastTimeLW;
		wcout << L"\nWord difficulty: " << P->wordDiff;
		wcout << L"\nTime to check back: " << P->timeCheckBack;
		wcout << L"\n\n";
		P = P->next;
	}
	wcout << endl;
}

void Linked_UHW::Insert_first(string _uId, string _wId, int _mLevl, time_t _lastTimeLW, bool _wordDiff, time_t _timeCB)
{
	Node_uhw* P;
	P = new Node_uhw;
	P->u_id = _uId;
	P->w_id = _wId;
	P->memoryLevel = _mLevl;
	P->lastTimeLW = _lastTimeLW;
	P->wordDiff = _wordDiff;
	P->timeCheckBack = _timeCB;
	P->next = head;
	head = P;
}

void Linked_UHW::Insert_last(string _uId, string _wId, int _mLevl, time_t _lastTimeLW, bool _wordDiff, time_t _timeCB)
{
	Node_uhw* P;
	Node_uhw* temp;
	P = new Node_uhw;
	P->u_id = _uId;
	P->w_id = _wId;
	P->memoryLevel = _mLevl;
	P->lastTimeLW = _lastTimeLW;
	P->wordDiff = _wordDiff;
	P->timeCheckBack = _timeCB;
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
void Linked_UHW::AddWordHadLearnt(string _wId, int _mLevl, time_t _lastTimeLW, bool _wordDiff, time_t _timeCB)
{
	Node_uhw* P;
	Node_uhw* temp;
	P = new Node_uhw;
	P->w_id = _wId;
	P->memoryLevel = _mLevl;
	P->lastTimeLW = _lastTimeLW;
	P->wordDiff = _wordDiff;
	P->timeCheckBack = _timeCB;
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

Node_uhw* Linked_UHW::getUHW()
{
	return head;
}

int Linked_UHW::searchIDW(string str)
{
	Node_uhw* P;
	P = head;
	while (P != NULL)
	{
		if (P->w_id == str) return 1;
		P = P->next;
	}
	return 0;
}

void Linked_UHW::UpdateHadLearnt(string _wId, int _mLevl, time_t _lastTimeLW, bool _wordDiff, time_t _timeCB)
{
	Node_uhw* P;
	P = this->head;
	while (P != NULL)
	{
		if (P->w_id == _wId)
		{
			P->memoryLevel = _mLevl;
			P->lastTimeLW = _lastTimeLW;
			P->wordDiff = _wordDiff;
			P->timeCheckBack = _timeCB;
			break;
		}
		else P = P->next;
	}
}

int Linked_UHW::getTimeCheckBack(string _wId)
{
	Node_uhw* P;
	P = this->head;
	while (P != NULL)
	{
		if (P->w_id == _wId)
		{
			return P->timeCheckBack;
		}
		else P = P->next;
	}
}
int Linked_UHW::getMemorylevel(string _wId)
{
	Node_uhw* P;
	P = this->head;
	while (P != NULL)
	{
		if (P->w_id == _wId)
		{
			return P->memoryLevel;
		}
		else P = P->next;
	}
}