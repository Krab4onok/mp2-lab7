#define _CRT_SECURE_NO_WARNINGS

#include "scantable.h"
#include "sorttable.h"
#include "treetable.h"
#include"ArrayHash.h"
#include <string>

enum TTabMode { SCAN_TABLE = 1, SORT_TABLE = 2, TREE_TABLE = 3, HASH_TABLE = 4};
TTable* pTab = NULL;
int* pKeys = NULL;
string* pVals = NULL;
//int k;
//string v;
int DataCount = 0, MemSize;

void TableGenerator(TTabMode mode) {
	int  MaxKeyValue;
	char Line[100];
	cout << "Input the record's number - ";
	cin >> DataCount;
	//cout << "Input the Maximum Key Value - ";
	//cin >> MaxKeyValue;
	MemSize = DataCount + 10;
	switch (mode) {
	case SCAN_TABLE:
		pTab = new TScanTable(MemSize);
		break;
	case SORT_TABLE:
		pTab = new TSortTable(MemSize);
		break;
	case TREE_TABLE:
		pTab = new TTreeTable();
		break;
	case HASH_TABLE:
		pTab = new TArrayHashTable();
		break;
	}
	pKeys = new int[MemSize];
	pVals = new string[MemSize];
	for (int i = 0; i < DataCount; i++) {
		pKeys[i] = i;
		pVals[i] = "rec" + to_string(pKeys[i]);
		pTab->InsRecord(pKeys[i], pVals[i]);
	}
}

void TableProcessor(TTabMode mode) {
	int com;
	int key;
	string rec;
	while (1) {
		cout << "0-Exit, 1-Find, 2-Insert, 3-Delete, 4-Print - ";
		cin >> com;
		if (com == 0)
			break;
		if (com != 4) {
			cout << "Input the key of record - ";
			cin >> key;
			cout << "Input the record - ";
			cin >> rec;
		}
		if (com == 1) {
			pTab->ClearEfficiency();
			cout << " Find " << pTab->FindRecord(key) << endl;
			cout << " Efficiency  = " << pTab->GetEfficiency() << endl;
		}
		if (com == 2) {
			pTab->ClearEfficiency();
			if (DataCount >= MemSize)
				cout << "MemBuffer is full" << endl;
			else {
				pKeys[DataCount] = key;
				pVals[DataCount] = rec;
				//pVals[DataCount] = "rec" + to_string(key);
				pTab->InsRecord(key, pVals[DataCount]);
				DataCount++;
			}
		}
		if (com == 3) {
			pTab->ClearEfficiency();
			pTab->DelRecord(key);
		}
		if (com == 4)
		{
			pTab->ClearEfficiency();
			//if (mode != TREE_TABLE)
				cout << *pTab; // Table printing
			//else
			//	((TTreeTable*)pTab)->Draw();
		}
	}
}

int main() {
	int TableType;

	cout << "Test for the table" << endl;
	cout << "1-Scan, 2-Sort, 3-Tree, 4-Hash: ";
	cin >> TableType;
	//cout << *pTab;
	TableGenerator((TTabMode)TableType);
	//cout << *pTab;
	TableProcessor((TTabMode)TableType);
	//cout << *pTab;
}