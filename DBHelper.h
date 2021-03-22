#pragma once

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <string>
#include "WordQuestion.h"
#include "FillQuestion.h"
#include "MultiQuestion.h"
#include "Word.h"
#include "User.h"
#include "UserHasWord.h"
#include "rank.h"

using namespace std;

void StandardizeTheString(string&);
class DBHelper
{
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1024
	//define handles and variables
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
	friend void StandardizeTheString(string&);
public:
	void init();
	void select_WQ(Linked_WQ&);
	void select_FQ(Linked_FQ&);
	void select_MQ(Linked_MQ&);
	void select_WORD(Linked_WORD&);
	void select_USER(User&);
	void select_USERHASWORD(Linked_UHW&);
	void select_RANK(Linked_RANK&);
	void InserUHW(string, int, int);
	void UpdateUHW(string, int, int, int, int);
	void UpdateUS(string, string, string, int, int, string);
	void close();
};