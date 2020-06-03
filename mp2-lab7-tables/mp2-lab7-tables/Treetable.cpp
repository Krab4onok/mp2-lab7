#include "treetable.h"

int TTreeTable::IsFull() const 
{
	PTTreeNode pNode = new TTreeNode();
	int temp = pNode == NULL;
	delete pNode;
	return temp;
} 

bool TTreeTable::FindRecord(TKey k) 
{
	PTTreeNode pNode = pRoot;
	ppRef = &pRoot; 
	Efficiency = 0;
	while (pNode != NULL)
	{
		Efficiency++;
		if (pNode->Key == k)
			break;
		if (pNode->Key < k)
			ppRef = &pNode->pRight;
		else
			ppRef = &pNode->pLeft;
		pNode = *ppRef;
	}
	if (pNode == NULL) {
		return TabNoRec;
	}
	else {
		return TabOK;
	}
	return (pNode == NULL) ? false : true;
} 

int TTreeTable::InsRecord(TKey k, TValue pVal) 
{
	if (IsFull()) {
		return TabFull;
	}
	else if (FindRecord(k) != NULL) {
		return TabRecDbl;
	}
	else
	{
		*ppRef = new TTreeNode(k, pVal);
		DataCount++;
	}
} 

int TTreeTable::DelRecord(TKey k) 
{
	if (FindRecord(k) == NULL) {
		return TabNoRec;
	}
	else
	{
		PTTreeNode pNode = *ppRef;
		if (pNode->pRight == NULL)
			*ppRef = pNode->pLeft; 
		else if (pNode->pLeft == NULL)
			*ppRef = pNode->pRight; 
		else 
		{
			PTTreeNode pN = pNode->pLeft, * ppR = &pNode->pLeft;
			while (pN->pRight != NULL)
			{
				ppR = &pN->pRight;
				pN = *ppR;
			} 
			pNode->pValue = pN->pValue;  
			pNode->Key = pN->Key;
			pNode = pN;
			*ppR = pN->pLeft; 
		}
		delete pNode;
	}                                                              
} 


TKey TTreeTable::GetKey(void) const 
{
	return (pCurrent == NULL) ? 0 : pCurrent->Key;
} 

TValue TTreeTable::GetValue(void) const 
{
	return (pCurrent == NULL) ? NULL : pCurrent->pValue;
} 

int TTreeTable::Reset(void)
{
	PTTreeNode pNode = pCurrent = pRoot;
	while (!St.empty())
		St.pop(); 
	CurrPos = 0;
	while (pNode != NULL) 
	{
		St.push(pNode);
		pCurrent = pNode;
		pNode = pNode->GetLeft();
	}
	return IsTabEnded();
} 

int TTreeTable::IsTabEnded(void) const
{
	return CurrPos >= DataCount;
} 

int TTreeTable::GoNext(void) 
{
	if (!IsTabEnded() && (pCurrent != NULL))                          
	{
		PTTreeNode pNode = pCurrent = pCurrent->GetRight(); 
		St.pop();
		while (pNode != NULL) 
		{
			St.push(pNode);
			pCurrent = pNode;
			pNode = pNode->GetLeft();
		}
		
		if ((pCurrent == NULL) && !St.empty())
			pCurrent = St.top();
		CurrPos++;
	}
	return IsTabEnded();                                              
} 


ostream& operator<<(ostream& os, TTreeTable& tab)
{
	cout << "Table printing" << endl;
	tab.PrintTreeTable(os, tab.pRoot);
	return os;
} 

void TTreeTable::Draw(void) 
{
	cout << "Table printing" << endl;
	DrawTreeTable(pRoot, 0);
} 


void TTreeTable::PutValues(PTTreeNode pNode, int Level)
{
	if ((pNode != NULL) && (pos < 20))
	{
		PutValues(pNode->pLeft, Level + 1);
		tk[pos] = pNode->Key;
		tl[pos] = Level;
		pos++;
		PutValues(pNode->pRight, Level + 1);
	}
} 

void TTreeTable::Show(void) 
{
	int maxl = 0, i, j, k, pn;
	pos = 0;
	PutValues(pRoot, 0);
	for (i = 0; i < pos; i++)
		if (maxl < tl[i])
			maxl = tl[i];

	cout << "Table visualization" << endl;
	for (i = 0; i < maxl + 1; i++) 
	{
		pn = 0;
		for (j = 0; j < pos; j++) 
		{
			if (tl[j] == i)
			{
				for (k = 0; k < 2 * (j - pn); k++)
					cout << " ";
				cout << tk[j];
				pn = j + 1;
			}
		}
		cout << endl;
	}
} 


void TTreeTable::PrintTreeTable(ostream& os, PTTreeNode pNode)
{
	if (pNode != NULL) 
	{
		PrintTreeTable(os, pNode->pLeft);
		pNode->Print(os);
		os << endl;
		PrintTreeTable(os, pNode->pRight);
	}
} 

void TTreeTable::DrawTreeTable(PTTreeNode pNode, int Level)
{
	if (pNode != NULL) 
	{
		DrawTreeTable(pNode->pRight, Level + 1);
		for (int i = 0; i < 2 * Level; i++)
			cout << " ";
		pNode->Print(cout);
		cout << endl;
		DrawTreeTable(pNode->pLeft, Level + 1);
	}
} 

void TTreeTable::DeleteTreeTable(PTTreeNode pNode)
{
	if (pNode != NULL) 
	{
		DeleteTreeTable(pNode->pLeft);
		DeleteTreeTable(pNode->pRight);
		delete pNode;
	}
} 