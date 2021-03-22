#pragma once
#include <iostream>
#include "MyLib.h"
using namespace std;

// ========== BEGIN: CLASS WORD ========== //
class Linked_RANK;
class Node_RANK
{
protected:
	string u_id, nickname;
	int exp = 0;
	Node_RANK* next;
public:
	Node_RANK() = default;
	Node_RANK(string, string, int);
	~Node_RANK();
	friend class Linked_RANK;
};

class Linked_RANK
{
protected:
	Node_RANK* head;
	int size = 0;
public:
	Linked_RANK();
	~Linked_RANK();
	void Insert_first(string, string, int);
	void SapXepGiam();
	void SetEXP(string, int);
	int FindID_EXP(string);
	void Output();
};

// ========== END: CLASS WORD ========== //
