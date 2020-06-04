#pragma once
#ifndef _ARRAYHASH_
#define _ARRAYHASH_
#include"HashTable.h"
#define TabHashStep 7
class TArrayHashTable : public HashTable
{
protected:
	TTabRecord* pRecs;// память для таблицы// table memory
	int TabSize;//максимально возможный размер таблицы// max table memory
	int HashStep;//шаг вторичного перемешивания
	int FreePos;//первая свободнаяя строка, обнаруженная при поиске// the first serched free line 
	int CurrPos;//строка памяти при завершении поиска // the line of the end of searching
	TTabRecord Mark;//маркер для индикации строк с удалёнными записями// mark of lines without notes
	TTabRecord Empty;//маркер для индикации не занятых строк // mark of free lines
	int GetNextPos(int pos) { return (pos + HashStep) % TabSize; }// функция открытого пермешивания
public:
	TArrayHashTable(int size = TabMaxSize, int step = TabHashStep);
	virtual ~TArrayHashTable();
	virtual bool IsFull() const { return DataCount >= TabSize; };//заполнена?//Is Full?
	//основные методы// basick methods
	virtual bool FindRecord(TKey k);
	virtual int InsRecord(TKey k, TValue val);
	virtual int DelRecord(TKey k);
	//навигация//navigation
	virtual int Reset(void);
	virtual int IsTabEnded(void) const;
	virtual int GoNext(void);
	//доступ//access
	virtual TKey GetKey(void) const;
	virtual TValue GetValue(void) const;
};
#endif
