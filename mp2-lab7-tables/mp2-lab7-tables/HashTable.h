#pragma once
//таблицы - базовый класс с таблицами с вычислимым входом//HashTables
#ifndef _HASHTAB_H_
#define _HASHTAB_H_
#include "Table.h"
#define TabMaxSize 25

class HashTable : public TTable
{
protected:
	virtual unsigned int HashFunck(const TKey key);
public:
	HashTable():TTable(){}
};
#endif