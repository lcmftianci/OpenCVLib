#pragma once
#include<stack>
#include "MyMutex.h"

//œﬂ≥Ã’ª
class CMyThread ;
class CMyStack
{
public:
	CMyStack(void);
	~CMyStack(void);
public:
	CMyThread* pop();
	bool push(CMyThread*);
	int getSize();
	bool isEmpty();
	bool clear();
private:
	std::stack<CMyThread*> m_stack;
	CMyMutex m_mutext;
};

