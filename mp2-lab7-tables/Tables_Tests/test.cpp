#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <string>
using namespace std;
TEST(TTable, CAN_CREATE_TABLE) 
{
	ASSERT_NO_THROW(TTable * pTab);
}
TEST(TScanTable, CAN_GET_DATACOUNT_AND_EFFICINCY)
{
	TScanTable* pTab;
	pTab = new TScanTable;
	ASSERT_NO_THROW((*pTab).GetDataCount());
	ASSERT_NO_THROW((*pTab).GetEfficiency());
}
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


TEST(TSortTable, CAN_INSERT_RECORD)
{
	string str;
	TSortTable* tab;
	tab = new TSortTable;
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
}

TEST(TTreeTable, CAN_INSERT_RECORD)
{
	string str;
	str = "rec";
	TTreeTable* tab;
	tab = new TTreeTable;
	tab->InsRecord(3, str);
}
TEST(TTreeTable, CAN_FIND_RECORD)
{
	string str;
	str = "rec";
	TTreeTable* tab;
	tab = new TTreeTable;
	tab->InsRecord(3, str);
	tab->FindRecord(3);
}
TEST(TTreeTable, CAN_DELETE_RECORD)
{
	string str;
	str = "rec";
	TTreeTable* tab;
	tab = new TTreeTable;
	tab->InsRecord(3, str);
	tab->DelRecord(3);
}
TEST(TArrayHashTable, CAN_INSERT_RECORD)
{
	string str;
	str = "rec";
	TArrayHashTable* tab;
	tab = new TArrayHashTable;
	tab->InsRecord(3, str);
}
TEST(TArrayHashTable, CAN_FIND_RECORD)
{
	string str;
	str = "rec";
	TArrayHashTable* tab;
	tab = new TArrayHashTable;
	tab->InsRecord(3, str);
	tab->FindRecord(3);
}
TEST(TArrayHashTable, CAN_DELETE_RECORD)
{
	string str;
	str = "rec";
	TArrayHashTable* tab;
	tab = new TArrayHashTable;
	tab->InsRecord(3, str);
	tab->DelRecord(3);
}