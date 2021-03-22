#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "MyLib.h"
using namespace std;

// ========== BEGIN: CLASS WORD ========== //
class Linked_WORD;
class Node_WORD
{
protected:
	string w_id, word, meaning, category, example;
	int pronounciation;  // ID SOUND
	int w_level;
	Node_WORD* next;
public:
	Node_WORD() = default;
	Node_WORD(string _wid, string _word, string _meaning, int _pronounciation, string _category, string _example, int _wlevel);
	~Node_WORD();
	friend class Linked_WORD;
	// =======================
	friend class Node_wq;
	friend class Linked_WQ;
};

class Linked_WORD
{
protected:
	Node_WORD* head;
	int size = 0;
public:
	Linked_WORD();
	~Linked_WORD();
	void Insert_first(string _wid, string _word, string _meaning, int _pronounciation, string _category, string _example, int _wlevel);
	void Insert_last(string _wid, string _word, string _meaning, int _pronounciation, string _category, string _example, int _wlevel);
	// void Search(Linked_WORD&);
	void Search();
	void Output();
	void SearchSound();
	int IsEmpty();
	int FindLevelWord(string);
	int getSize();
	void setSize(int);
	Node_WORD* getHeadWord();
};

// ========== END: CLASS WORD ========== //