#pragma once
#ifndef _sorttable_h
#define _sorttable_h
#include "scantable.h"

enum TSortMethod { INSERT_SORT = 1, MERGE_SORT, QUICK_SORT };

class TSortTable : public TScanTable {
protected:

	TTabRecord* pBuff; //буфер для сортировки слиянием
	TSortMethod SortMethod; //индекс метода сортировки
	void SortData(void);   //сортировка данных
	void InsertSort(TTabRecord* pMem, int DataCount); //сортировка вставками
	void MergeSort(TTabRecord* pMem, int DataCount); //сортировка слиянием
	void MergeSorter(TTabRecord*& pData, TTabRecord*& pBuff, int Size);
	void MergeData(TTabRecord*& pData, TTabRecord*& pBuff, int n1, int n2);
	void QuickSort(TTabRecord* pMem, int DataCount); //ьыстрая сортировка
	void QuickSplit(TTabRecord* pData, int Size, int& Pivot);
public:
	TSortTable(int Size = TabMaxSize) : TScanTable(Size) {
		pBuff = new TTabRecord[DataCount];
	};
	~TSortTable()
	{
		delete[] pBuff;
	}
	TSortTable(const TScanTable& tab) { *this = tab; }
	TSortTable& operator=(const TScanTable& tab);
	TSortMethod GetSortMethod(void) { return SortMethod; }
	void SetSortMethod(TSortMethod sm) { SortMethod = sm; }

	//базовые методы
	virtual bool FindRecord(TKey k);
	virtual int InsRecord(TKey k, TValue pVal);
	virtual int DelRecord(TKey k);
};

#endif 