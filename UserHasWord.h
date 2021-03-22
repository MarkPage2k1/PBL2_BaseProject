#pragma once
#include <ctime>
#include <iostream>
#include "MyLib.h"
using namespace std;

class Linked_UHW;
class Node_uhw
{
protected:
	string u_id, w_id;		// Id user, id cua tu vung
	int memoryLevel;		// Muc do nho cua tu vung (de on tap lai)
	time_t lastTimeLW;		// Lan cuoi hoc tu vung nay la bao nhieu gio tinh tu nam 1900
	int wordDiff;			// tu nay co can luu vo DS tu kho hay khong?
	time_t timeCheckBack;	// tu nay sao bao nhieu phut nua se on tap lai?
	Node_uhw* next;
public:
	Node_uhw() = default;
	Node_uhw(string _uId, string _wId, int _mLevl, time_t _lastTimeLW, bool _wordDiff, time_t _timeCB);
	~Node_uhw();
	friend class Linked_UHW;
	// ========= xem lai hai class ban nay
	friend class Node_wq;
	friend class Linked_WQ;
	// ================
	friend class Menu;
};

class Linked_UHW
{
private:
	int flags = 0;	// Co de kiem tra xem co hoc tu moi hay khong?
	int size = 0;	// Luu so tu da hoc;
protected:
	Node_uhw* head;
public:
	Linked_UHW();
	~Linked_UHW();
	int getSize();
	void setSize(int);
	int getFlags();
	void setFlags(int);
	void Output();
	Node_uhw* getUHW();
	void Insert_first(string _uId, string _wId, int _mLevl, time_t _lastTimeLW, bool _wordDiff, time_t _timeCB);
	void Insert_last(string _uId, string _wId, int _mLevl, time_t _lastTimeLW, bool _wordDiff, time_t _timeCB);
	void AddWordHadLearnt(string _wId, int _mLevl, time_t _lastTimeLW, bool _wordDiff, time_t _timeCB);
	void UpdateHadLearnt(string _wId, int _mLevl, time_t _lastTimeLW, bool _wordDiff, time_t _timeCB);
	int searchIDW(string str);
	int getTimeCheckBack(string);
	int getMemorylevel(string);
	//void AddDB(DBHelper&);
};
