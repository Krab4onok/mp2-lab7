#pragma once
//������� - ������� ����� � ��������� � ���������� ������//HashTables
#ifndef _HASHTAB_H_
#define _HASHTAB_H_
#include "Table.h"

class HashTable : public TTable
{
protected:
	virtual unsigned int HashFunck(const TKey key);
public:
	HashTable():TTable(){}
};
#endif