#include "User.h"

User::User()
{
	this->u_id = "US0000";
	this->username = "UserEmpty";
	this->password = "1234";
	this->nickname = "Empty";
	this->goal = 0;
	this->exp = 0;
	this->l_id = "L0000";
}
User::User(string uId, string UserName, string PassWord, string NickName, int Goal, int Exp, string lId)
	:u_id(uId), username(UserName), password(PassWord), nickname(NickName), goal(Goal), exp(Exp), l_id(lId)
{

}
User::~User()
{

}
void User::SetInfor(string uId, string UserName, string PassWord, string NickName, int Goal, int Exp, string lId)
{
	this->u_id = uId;
	this->username = UserName;
	this->password = PassWord;
	this->nickname = NickName;
	this->goal = Goal;
	this->exp = Exp;
	this->l_id = lId;
}
void User::ShowInfor()
{
	MyLib mylib;
	wcout << L"===== DISPLAY USER INFORMATION =======" << endl;
	wcout << L"ID: " << mylib.to_wstring(this->u_id) << endl
		 << L"User Name: " << mylib.to_wstring(this->username) << endl
		 << L"Pass Word: " << mylib.to_wstring(this->password) << endl
		 << L"Nick Name: " << mylib.to_wstring(this->nickname) << endl
		 << L"Goal: " << this->goal << endl
		 << L"Experience: " << this->exp << endl
		 << L"Level ID: " << mylib.to_wstring(this->l_id) << endl;
}
string User::GetID()
{
	return this->u_id;
}

int User::GetEXP()
{
	return this->exp;
}

void User::SetEXP(int exP)
{
	this->exp = exP;
}

string User::GetLevel()
{
	return this->l_id;
}

void User::SetLevel(string level)
{
	this->l_id = level;
}

int User::GetGoal()
{
	return this->goal;
}

void User::SetGoal(int goal)
{
	this->goal = goal;
}

string User::GetPass()
{
	return this->password;
}


void User::SetPass(string PassW)
{
	this->password = PassW;
}


string User::GetNickName()
{
	return this->nickname;
}

void User::SetNickName(string nickN)
{
	this->nickname = nickN;
}

