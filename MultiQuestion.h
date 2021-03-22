#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "MyLib.h"
using namespace std;

class Linked_MQ;
class Node_mq
{
protected:
	string mq_id, mq_content, answerKey, answerA, answerB, answerC, answerD;
	Node_mq* next;
public:
	Node_mq() = default;
	Node_mq(string _mqId, string _mqContent, string _answerKey, string _answerA, string _answerB, string _answerC, string _answerD);
	~Node_mq();
	friend class Linked_MQ;
};

class Linked_MQ
{
protected:
	Node_mq* head;
public:
	Linked_MQ();
	~Linked_MQ();
	void Search();
	void Insert_first(string _mqId, string _mqContent, string _answerKey, string _answerA, string _answerB, string _answerC, string _answerD);
	void Insert_last(string _mqId, string _mqContent, string _answerKey, string _answerA, string _answerB, string _answerC, string _answerD);
	void Output();
	int IsEmpty();
	int OutQuestion(string _mqId);
};