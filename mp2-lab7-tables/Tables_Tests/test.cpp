#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <string>
using namespace std;
TEST(TTable, CAN_CREATE_TABLE) 
{
	ASSERT_NO_THROW(TTable * pTab);
}
/*TEST(TTable, CAN_GET_DATACOUNT_AND_EFFICINCY)
{
	int s = 10;
	TTable* pTab;
	pTab = new TSortTable(s);
	ASSERT_NO_THROW((*pTab).GetDataCount());
	ASSERT_NO_THROW((*pTab).GetEfficiency());
}*/
TEST(TArrayTable, CAN_CREATE_ARRTABLE)
{
	ASSERT_NO_THROW(TArrayTable* tab);
}
TEST(TScanTable, CAN_CREATE_SCANTABLE)
{
	ASSERT_NO_THROW(TScanTable * tab);
}
TEST(TSortTable, CAN_CREATE_SCORTTABLE)
{
	ASSERT_NO_THROW(TSortTable * tab);
}
TEST(TTreeTable, CAN_CREATE_TREETABLE)
{
	ASSERT_NO_THROW(TTreeTable * tab);
}
TEST(TArrayHashTable, CAN_CREATE_TARRAYHASHTABLE)
{
	ASSERT_NO_THROW(TArrayHashTable * tab);
}

TEST(TScanTable, CAN_INSERT_RECORD)
{
	int s = 15;
	string str;
	TTable *tab;
	tab = new TScanTable(s);
	str = "rec";
	for(int i = 0; i < s; i++)
    tab->InsRecord(1,str);
}
/*TEST(TScanTable, CAN_FIND_RECORD)
{
	string str;
	TScanTable* tab;
	str = "rec";
	ASSERT_NO_THROW(tab->InsRecord(1, str));
	ASSERT_NO_THROW(tab->FindRecord(1));
}
TEST(TScanTable, CAN_DELETE_RECORD)
{
	string str;
	TScanTable* tab;
	str = "rec";
	ASSERT_NO_THROW(tab->InsRecord(1, str));
	ASSERT_NO_THROW(tab->DelRecord(1));
}
TEST(TSortTable, CAN_INSERT_RECORD)
{
	string str;
	TSortTable* tab;
	str = "rec";
	ASSERT_NO_THROW(tab->InsRecord(1, str));
}
TEST(TSortTable, CAN_FIND_RECORD)
{
	string str;
	TSortTable* tab;
	str = "rec";
	ASSERT_NO_THROW(tab->InsRecord(1, str));
	ASSERT_NO_THROW(tab->FindRecord(1));
}
TEST(TSortTable, CAN_DELETE_RECORD)
{
	string str;
	TSortTable* tab;
	str = "rec";
	ASSERT_NO_THROW(tab->InsRecord(1, str));
	ASSERT_NO_THROW(tab->DelRecord(1));
}*/


