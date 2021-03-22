#include <codecvt>
#include <locale>
#include "DBHelper.h"
#include <iostream>
#include <string>
#include <sstream>
#include "WordQuestion.h"
#include <string.h>
#include <stdio.h>

using namespace std;
void DBHelper::init()
{
	//initializations
	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;
	//allocations
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
		close();
	if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		close();
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
		close();
	//output
	do
	{
		wcout << L"Project: Lean vocabulary English with LEARN WORD \n";
		wcout << L"Member:\n";
		wcout << L"1. Dong Minh Phu\n";
		wcout << L"2. Tran Phuoc Thien\n";
	} while (wcin.get() != '\n');
	wcout << L"\nLoading and connect to Student DB...";

	//connect to SQL Server	
	//I am using a trusted connection and port 14808
	//it does not matter if you are using default or named instance
	//just make sure you define the server name and the port
	//You have the option to use a username/password instead of a trusted connection
	//but is more secure to use a trusted connection
	switch (SQLDriverConnect(sqlConnHandle,
		NULL,
		(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=DESKTOP-KEVP32V;DATABASE=DBPBL2;",
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT)) {

	case SQL_SUCCESS:
		cout << "Done\n";
		cout << "\n";
		break;

	case SQL_SUCCESS_WITH_INFO:
		do {
			wcout << L"Connect successfully";
			wcout << L"\n";
		} while (wcin.get() != '\n');
		break;

	case SQL_INVALID_HANDLE:
		wcout << L"Could not connect to SQL Server";
		wcout << L"\n";
		close();
		break;

	case SQL_ERROR:
		wcout << L"Could not connect to SQL Server";
		wcout << L"\n";
		close();
		break;

	default:
		break;
	}


	//if there is a problem connecting then exit application
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
		close();
}

/*string to_string(wstring wstr)
{
	using convert_t = codecvt_utf8<wchar_t>;
	wstring_convert<convert_t, wchar_t> strconverter;
	return strconverter.to_bytes(wstr);
}
*/

wstring to_wstring(string str)
{
	using convert_t = codecvt_utf8<wchar_t>;
	wstring_convert<convert_t, wchar_t> strconverter;
	return strconverter.from_bytes(str);
}

void DBHelper::select_WQ(Linked_WQ& WQ)
{
	//cout << "Da vao select";
	wstring sqlStr = L"SELECT * FROM WORDQUESTION";
	SQLRETURN retcode;
	//output buffers
	char wq_id[11];
	char w_id[11];
	char fq_id[11];
	char mq_id[11];

	//stringstream parser;
	//string _wqId;
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	retcode = SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)sqlStr.c_str(), SQL_NTS);
	SQLBindCol(sqlStmtHandle, 1, SQL_C_CHAR, wq_id, 11, NULL);
	SQLBindCol(sqlStmtHandle, 2, SQL_C_CHAR, w_id, 11, NULL);
	SQLBindCol(sqlStmtHandle, 3, SQL_C_CHAR, fq_id, 11, NULL);
	SQLBindCol(sqlStmtHandle, 4, SQL_C_CHAR, mq_id, 11, NULL);

	for (retcode = SQLFetch(sqlStmtHandle);
		retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO;
		retcode = SQLFetch(sqlStmtHandle))
	{
		//string s_wqId(wq_id),
		//	s_wId(w_id),
		//	s_fqId(fq_id),
		//	s_mqId(mq_id);
		//parser.str(w_id);
		//parser >> _wqId;
		WQ.Insert_last(wq_id, w_id, fq_id, mq_id);
	}
	SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);

}

void DBHelper::select_FQ(Linked_FQ& FQ)
{
	//cout << "Da vao select";
	wstring sqlStr = L"SELECT * FROM FILLQUESTION";
	SQLRETURN retcode;
	//output buffers
	char fq_id[11];
	int link;
	char message[51];
	char answerKey[51];

	//stringstream parser;
	//string _fqId;
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	retcode = SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)sqlStr.c_str(), SQL_NTS);
	SQLBindCol(sqlStmtHandle, 1, SQL_C_CHAR, fq_id, 11, NULL);
	SQLBindCol(sqlStmtHandle, 2, SQL_C_LONG, &link, 4, NULL);
	SQLBindCol(sqlStmtHandle, 3, SQL_C_CHAR, message, 51, NULL);
	SQLBindCol(sqlStmtHandle, 4, SQL_C_CHAR, answerKey, 51, NULL);

	for (retcode = SQLFetch(sqlStmtHandle);
		retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO;
		retcode = SQLFetch(sqlStmtHandle))
	{
		//string s_fqId(fq_id),
		//	s_link(link),
		//	s_answerKey(answerKey);
		//parser.str(fq_id);
		//parser >> _fqId;
		FQ.Insert_last(fq_id, link, message, answerKey);
	}
	SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
}

void DBHelper::select_MQ(Linked_MQ& MQ)
{
	//cout << "Da vao select";
	wstring sqlStr = L"SELECT * FROM MULTIQUESTION";
	SQLRETURN retcode;
	//output buffers
	char mq_id[11];
	char mq_content[51];
	char answerKey[6];
	char answerA[51];
	char answerB[51];
	char answerC[51];
	char answerD[51];

	//stringstream parser;
	//string _mqId;
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	retcode = SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)sqlStr.c_str(), SQL_NTS);
	SQLBindCol(sqlStmtHandle, 1, SQL_C_CHAR, mq_id, 11, NULL);
	SQLBindCol(sqlStmtHandle, 2, SQL_C_CHAR, mq_content, 51, NULL);
	SQLBindCol(sqlStmtHandle, 3, SQL_C_CHAR, answerKey, 6, NULL);
	SQLBindCol(sqlStmtHandle, 4, SQL_C_CHAR, answerA, 51, NULL);
	SQLBindCol(sqlStmtHandle, 5, SQL_C_CHAR, answerB, 51, NULL);
	SQLBindCol(sqlStmtHandle, 6, SQL_C_CHAR, answerC, 51, NULL);
	SQLBindCol(sqlStmtHandle, 7, SQL_C_CHAR, answerD, 51, NULL);

	for (retcode = SQLFetch(sqlStmtHandle);
		retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO;
		retcode = SQLFetch(sqlStmtHandle))
	{
		//string s_mqId(mq_id),
		//	s_mqContent(mq_content),
		//	s_answerKey(answerKey),
		//	s_answerA(answerA),
		//	s_answerB(answerB),
		//	s_answerC(answerC),
		//	s_answerD(answerD);
		//parser.str(mq_id);
		//parser >> _mqId;
		MQ.Insert_last(mq_id, mq_content, answerKey, answerA, answerB, answerC, answerD);
	}
	SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
}

void DBHelper::select_WORD(Linked_WORD& WORD)
{

	//cout << "Da vao select";
	wstring sqlStr = L"SELECT * FROM WORD";
	SQLRETURN retcode;
	//output buffers
	char w_id[11];
	char word[21];
	char meaning[51];
	char category[51];
	char example[101];
	int pronounciation;
	int w_level;

	stringstream parser;
	string _wid;
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	retcode = SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)sqlStr.c_str(), SQL_NTS);
	SQLBindCol(sqlStmtHandle, 1, SQL_C_CHAR, w_id, 11, NULL);
	SQLBindCol(sqlStmtHandle, 2, SQL_C_CHAR, word, 51, NULL);
	SQLBindCol(sqlStmtHandle, 3, SQL_C_CHAR, meaning, 51, NULL);
	SQLBindCol(sqlStmtHandle, 4, SQL_C_LONG, &pronounciation, 4, NULL);
	SQLBindCol(sqlStmtHandle, 5, SQL_C_CHAR, category, 51, NULL);
	SQLBindCol(sqlStmtHandle, 6, SQL_C_CHAR, example, 101, NULL);
	SQLBindCol(sqlStmtHandle, 7, SQL_C_LONG, &w_level, 4, NULL);
	for (retcode = SQLFetch(sqlStmtHandle);
		retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO;
		retcode = SQLFetch(sqlStmtHandle))
	{
		//string s_wid(w_id),
		//	s_word(word),
		//	s_meaning(meaning),
		//	s_category(category),
		//	s_example(example);
		//parser.str(w_id);
		//parser >> _wid;
		//StandardizeTheString(s_word);
		
		WORD.Insert_last (w_id, word, meaning, pronounciation, category, example, w_level);
		WORD.setSize(WORD.getSize() + 1);
	}
	SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
}

void DBHelper::select_USER(User& US)
{
	wstring sqlStr = L"SELECT * FROM USERLW WHERE username = 'minhphu' AND password = '7890'";
	SQLRETURN retcode;
	//output buffers
	char u_id[11];
	char username[16];
	char password[16];
	char nickname[16];
	char l_id[11];
	int goal;
	int exp;

	stringstream parser;
	string _wid;

	retcode = SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	retcode = SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)sqlStr.c_str(), SQL_NTS);
	SQLBindCol(sqlStmtHandle, 1, SQL_C_CHAR, u_id, 11, NULL);
	SQLBindCol(sqlStmtHandle, 2, SQL_C_CHAR, username, 16, NULL);
	SQLBindCol(sqlStmtHandle, 3, SQL_C_CHAR, password, 16, NULL);
	SQLBindCol(sqlStmtHandle, 4, SQL_C_CHAR, nickname, 16, NULL);
	SQLBindCol(sqlStmtHandle, 5, SQL_C_LONG, &goal, 4, NULL);
	SQLBindCol(sqlStmtHandle, 6, SQL_C_LONG, &exp, 4, NULL);
	SQLBindCol(sqlStmtHandle, 7, SQL_C_CHAR, l_id, 11, NULL);
	for (retcode = SQLFetch(sqlStmtHandle);
		retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO;
		retcode = SQLFetch(sqlStmtHandle))
	{
		US.SetInfor(u_id, username, password, nickname, goal, exp, l_id);
	}
	SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
}

void DBHelper::select_USERHASWORD(Linked_UHW& UHW)
{
	//cout << "Da vao select";
	wstring sqlStr = L"SELECT * FROM USERHASWORD WHERE u_id = 'US0001'";
	SQLRETURN retcode;
	//output buffers
	char u_id[11];
	char w_id[11];
	int memoryLevel;
	int lastTimeLW;
	int wordDiff;
	int timeCheckBack;

	retcode = SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	retcode = SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)sqlStr.c_str(), SQL_NTS);
	SQLBindCol(sqlStmtHandle, 1, SQL_C_CHAR, u_id, 11, NULL);
	SQLBindCol(sqlStmtHandle, 2, SQL_C_CHAR, w_id, 11, NULL);
	SQLBindCol(sqlStmtHandle, 3, SQL_C_LONG, &memoryLevel, 4, NULL);
	SQLBindCol(sqlStmtHandle, 4, SQL_C_LONG, &lastTimeLW, 8, NULL);
	SQLBindCol(sqlStmtHandle, 5, SQL_C_LONG, &wordDiff, 1, NULL);
	SQLBindCol(sqlStmtHandle, 6, SQL_C_LONG, &timeCheckBack, 8, NULL);
	for (retcode = SQLFetch(sqlStmtHandle);
		retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO;
		retcode = SQLFetch(sqlStmtHandle))
	{
		//string s_wid(w_id),
		//	s_word(word),
		//	s_meaning(meaning),
		//	s_category(category),
		//	s_example(example);
		//parser.str(w_id);
		//parser >> _wid;
		//StandardizeTheString(s_word);

		UHW.Insert_last(u_id, w_id, memoryLevel, lastTimeLW, wordDiff, timeCheckBack);
		UHW.setSize(UHW.getSize() + 1);
	}
	SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
}

void DBHelper::close()
{
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
	//getchar();
	exit(0);
}

void DBHelper::select_RANK(Linked_RANK& RANK)
{
		wstring sqlStr = L"SELECT u_id, nickname, exp FROM USERLW";
		SQLRETURN retcode;
		char u_id[11];
		char nickname[16];
		int exp;

		retcode = SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		retcode = SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)sqlStr.c_str(), SQL_NTS);
		SQLBindCol(sqlStmtHandle, 1, SQL_C_CHAR, u_id, 11, NULL);
		SQLBindCol(sqlStmtHandle, 2, SQL_C_CHAR, nickname, 16, NULL);
		SQLBindCol(sqlStmtHandle, 3, SQL_C_LONG, &exp, 4, NULL);
		for (retcode = SQLFetch(sqlStmtHandle);
			retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO;
			retcode = SQLFetch(sqlStmtHandle))
		{
			RANK.Insert_first(u_id, nickname, exp);
		}
		SQLFreeStmt(sqlStmtHandle, SQL_CLOSE);
}

void StandardizeTheString(string& str)
{
	while (str.length() > 0 && str[(str.length() - 1)] == ' ')
	{
		str = str.substr(0, str.size() - 1);
	}
}

void DBHelper::InserUHW(string wId, int wordDiff, int lastTimeLW)
{
	int number1 = wordDiff, number2 = lastTimeLW;
	string result1, result2;
	ostringstream convert1, convert2;
	convert1 << number1;
	convert2 << number2;
	result1 = convert1.str() + ", 5)";
	result2 = convert2.str() + ", ";
	// insert into USERHASWORD values('US0002', 'W1001', 1, 402831, 0, 0)
	string s = "INSERT INTO USERHASWORD VALUES('US0001', '";
	//string s1 = "W1001',";
	string convert3 = wId;
	s = s + convert3 + "', 1, " + result2 + result1;

	char m[100];
	int i;
	for (i = 0; i < s.length(); i++)
	{
		m[i] = s[i];
	}
	m[i] = '\0';


	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)m, SQL_NTS)) {

		wcout << L"\n";
		wcout << L"Error querying SQL Server";
		wcout << L"\n";
		close();
	}
	else {

		wcout << L"\nINSERT SUCCESS";
		return;
	}
}


void DBHelper::UpdateUHW(string _wId, int mmlevel, int lastTimeLw, int wordDiff, int timeCB)
{

	string str1, str2, str3, str4;
	ostringstream convert1, convert2, convert3, convert4;
	convert1 << mmlevel;
	convert2 << lastTimeLw;
	convert3 << wordDiff;
	convert4 << timeCB;
	str1 = convert1.str() + ", lastTimeLW = ";
	str2 = convert2.str() + ", wordDiff = ";
	str3 = convert3.str() + ", timeCheckBack = ";
	str4 = convert4.str() + " where w_id = '";
	string s = "UPDATE USERHASWORD SET memoryLevel = ";
	s = s + str1 + str2 + str3 + str4 + _wId + "'";
	char m[150];
	int i;
	for (i = 0; i < s.length(); i++)
	{
		m[i] = s[i];
		//cout << m[i];
	}
	m[i] = '\0';
	//cout << m << endl;

	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)m, SQL_NTS)) {
		wcout << L"\n";
		wcout << L"Error querying SQL Server";
		wcout << L"\n";
		close();
	}
	else {

		wcout << L"\nUPDATE SUCCESS";
		return;
	}
}

void DBHelper::UpdateUS(string _uID, string passW, string nickName, int goal, int exp, string L_id)
{
	string str1, str2;
	ostringstream convert1, convert2;
	convert1 << goal;
	convert2 << exp;
	str1 = convert1.str() + ", exp = ";
	str2 = convert2.str() + ", l_id = ";
	// update USERLW set password = '4321', nickname = 'ABC', goal = 2000, exp = 0, l_id = 'L0002' where u_id = 'US0001'
	string s = "UPDATE USERLW SET password = ";
	s = s + "'" + passW + "', nickname = " + "'" + nickName + "'" + ", goal = " + str1 + str2 + "'" + L_id + "'" + " where u_id = " + "'" + _uID + "'";
	char m[150];
	int i;
	for (i = 0; i < s.length(); i++)
	{
		m[i] = s[i];
	}
	m[i] = '\0';
	
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)m, SQL_NTS)) {
		wcout << L"\n";
		wcout << L"Error querying SQL Server";
		wcout << L"\n";
		close();
	}
	else {

		wcout << L"\nUPDATE USER SUCCESS";
		return;
	}
	
}