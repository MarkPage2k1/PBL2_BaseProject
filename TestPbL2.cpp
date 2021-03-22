#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <string>
#include <sqltypes.h>
#include <sql.h>
#include <sstream>
#include "DBHelper.h"
#include "Menu.h"
#include <io.h>
#include <fcntl.h>"
using namespace std;
int main()
{
	Menu mn;
	DBHelper database;
	
	_setmode(_fileno(stdout), _O_WTEXT); //needed for output
	_setmode(_fileno(stdin), _O_WTEXT); //needed for input
	database.init();
	User US;
	Linked_WQ WQ;
	Linked_FQ FQ;
	Linked_MQ MQ;
	Linked_WORD WORD;
	Linked_UHW UHW;
	Linked_RANK RANK;
	database.select_USER(US);
	database.select_WQ(WQ);
	database.select_FQ(FQ);
	database.select_MQ(MQ);
	database.select_WORD(WORD);
	database.select_USERHASWORD(UHW);
	database.select_RANK(RANK);
	// =============================
	
	mn.VeKhung();
	mn.menudong(WQ, MQ, FQ, UHW, WORD, RANK, US);
	mn.gotoxy(0, 30);
	system("pause");
	system("cls");
	
	//system("pause");
	mn.AddUHWDB(UHW, database);
	database.UpdateUS(US.GetID(), US.GetPass(), US.GetNickName(), US.GetGoal(), US.GetEXP(), US.GetLevel());
	if (UHW.getSize() > 0) mn.UpdateUHWDB(UHW, database);
	
	database.close();
	
	return 0;
}