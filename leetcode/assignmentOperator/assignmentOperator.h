#pragma once
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class CMyString
{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);

	CMyString& operator = (const CMyString& str);
	void Print();

private:
	char* m_pData;
};
