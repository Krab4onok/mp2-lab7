#pragma once
#ifndef _ARRAYHASH_
#define _ARRAYHASH_
#include"HashTable.h"
#define TabHashStep 7
class TArrayHashTable : public HashTable
{
protected:
	TTabRecord* pRecs;// ������ ��� �������// table memory
	int TabSize;//����������� ��������� ������ �������// max table memory
	int HashStep;//��� ���������� �������������
	int FreePos;//������ ���������� ������, ������������ ��� ������// the first serched free line 
	int CurrPos;//������ ������ ��� ���������� ������ // the line of the end of searching
	TTabRecord Mark;//������ ��� ��������� ����� � ��������� ��������// mark of lines without notes
	TTabRecord Empty;//������ ��� ��������� �� ������� ����� // mark of free lines
	int GetNextPos(int pos) { return (pos + HashStep) % TabSize; }// ������� ��������� ������������
public:
	TArrayHashTable(int size = TabMaxSize, int step = TabHashStep);
	virtual ~TArrayHashTable();
	virtual bool IsFull() const { return DataCount >= TabSize; };//���������?//Is Full?
	//�������� ������// basick methods
	virtual bool FindRecord(TKey k);
	virtual int InsRecord(TKey k, TValue val);
	virtual int DelRecord(TKey k);
	//���������//navigation
	virtual int Reset(void);
	virtual int IsTabEnded(void) const;
	virtual int GoNext(void);
	//������//access
	virtual TKey GetKey(void) const;
	virtual TValue GetValue(void) const;
};
#endif
