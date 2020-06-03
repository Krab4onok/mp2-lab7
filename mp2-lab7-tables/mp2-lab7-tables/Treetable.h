#pragma once
#ifndef _treetable_h
#define _treetable_h
#include <stack>
#include "table.h"
#include "treenode.h"

class TTreeTable : public TTable
{
protected:
	PTTreeNode  pRoot;    
	PTTreeNode* ppRef;    
	PTTreeNode  pCurrent;
	int CurrPos;          
	stack<PTTreeNode> St; 

	void PrintTreeTable(ostream& os, PTTreeNode pNode);
	void DrawTreeTable(PTTreeNode pNode, int Level);   
	void DeleteTreeTable(PTTreeNode pNode); 
	string tk[20];
	int tl[20], pos;
	void PutValues(PTTreeNode pNode, int Level);
public:
	TTreeTable() : TTable()
	{
		CurrPos = 0; pRoot = pCurrent = NULL; ppRef = NULL;
	}
	~TTreeTable() { DeleteTreeTable(pRoot); }
	
	virtual int IsFull() const;               

	virtual bool FindRecord(TKey k); 
	virtual int  InsRecord(TKey k, TValue pVal); 
	virtual int  DelRecord(TKey k); 
	
	virtual int Reset(void);      
	virtual int IsTabEnded(void) const; 
	virtual int GoNext(void);       
	
	virtual TKey GetKey(void) const;    
	virtual TValue GetValue(void) const; 
	
	friend ostream& operator<<(ostream& os, TTreeTable& tab);
	void Draw(void);
	void Show(void); 
};

#endif 