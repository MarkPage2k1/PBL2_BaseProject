#pragma once
#include <iostream>
#include <sstream>
#include "MultiQuestion.h"
#include "FillQuestion.h"
#include "UserHasWord.h"
#include "Word.h"
#include "User.h"
#include "MyLib.h"
using namespace std;

// ========== BEGIN: CLASS WORD QUESTION ========== //
class Linked_WQ;
class Node_wq
{
protected:
	string wq_id, w_id, fq_id, mq_id;
	Node_wq* next;
public:
	Node_wq() = default;
	Node_wq(string _wqId, string _wId, string _fqId, string _mqId);
	~Node_wq();
	friend class Linked_WQ;
};

class Linked_WQ
{
protected:
	Node_wq* head;
public:
	Linked_WQ();
	~Linked_WQ();
	void Search();
	void Insert_first(string _wqId, string _wId, string _fqId, string _mqId);
	void Insert_last(string _wqId, string _wId, string _fqId, string _mqId);
	void Output();
	int IsEmpty();
	void LearnWord(Linked_MQ&, Linked_FQ&, Linked_UHW&, User&);	// Hoc theo level
	void Exercise(Linked_MQ&, Linked_FQ&, Linked_UHW&, User&);
	void Test(Linked_MQ&, Linked_FQ&, Linked_WORD&, User&);
	void LearnWordLevel(Linked_MQ&, Linked_FQ&, Linked_UHW&, Linked_WORD& , User&, string);
};
// ========== END: CLASS WORD QUESTION ========== //