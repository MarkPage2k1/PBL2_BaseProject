#pragma once
#include <iostream>
#include "MyLib.h"
using namespace std;

class User
{
protected:
	string u_id, username, password, nickname, l_id;
	int goal, exp;
public:
	User();
	User(string uId, string UserName, string PassWord, string NickName, int Goal, int Exp, string lId);
	~User();
	void SetInfor(string uId, string UserName, string PassWord, string NickName, int Goal, int Exp, string lId);
	string GetID();
	void ShowInfor();
	string GetLevel();
	void SetLevel(string);
	int GetEXP();
	void SetEXP(int);
	int GetGoal();
	void SetGoal(int);
	string GetPass();
	void SetPass(string);
	string GetNickName();
	void SetNickName(string);
};