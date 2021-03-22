#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "MyLib.h"
using namespace std;

class Linked_FQ;
class Node_fq
{
protected:
	string fq_id, message, answerKey;
	int link;
	Node_fq* next;
public:
	Node_fq() = default;
	Node_fq(string _fqId, int _link, string _message, string _answerKey);
	~Node_fq();
	friend class Linked_FQ;
};

class Linked_FQ
{
protected:
	Node_fq* head;
public:
	Linked_FQ();
	~Linked_FQ();
	void Search();
	void Insert_first(string _fqId, int _link, string _message, string _answerKey);
	void Insert_last(string _fqId, int _link, string _message, string _answerKey);
	void Output();
	int IsEmpty();
	int OutQuestion(string _fqId);
};