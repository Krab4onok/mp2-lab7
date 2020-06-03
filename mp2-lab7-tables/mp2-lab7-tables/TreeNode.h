#pragma once
#ifndef _treenode_h
#define _treenode_h
#include "record.h"

class   TTreeNode;
typedef TTreeNode* PTTreeNode;

class TTreeNode : public TTabRecord
{
protected:
	PTTreeNode pLeft, pRight; 
public:
	TTreeNode(TKey k = 0, TValue pVal = 0, PTTreeNode pL = NULL, PTTreeNode pR = NULL) : TTabRecord(k, pVal) {
		pLeft = pL;
	    pRight = pL;
	}
	PTTreeNode GetLeft(void) const { return pLeft; }
	PTTreeNode GetRight(void) const { return pRight; }

	friend class TTreeTable;
};

#endif 