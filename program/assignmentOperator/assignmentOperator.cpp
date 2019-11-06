#include "assignmentOperator.h"


CMyString::CMyString(char* pData )
{
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		unsigned int ilength = strlen(pData);
		m_pData = new char[ilength + 1];
		strcpy_s(m_pData, ilength + 1,pData);
		// strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str)
{
	unsigned int ilength = strlen(str.m_pData);
	m_pData = new char[ilength + 1];
	strcpy_s(m_pData,ilength+1, str.m_pData);
	// strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
	if (m_pData != nullptr)
	{
		delete[] m_pData;
		m_pData = nullptr;
	}
}

CMyString& CMyString::operator = (const CMyString& str)
{
	if (this == &str)
	{
		return *this;
	}
	delete [] m_pData;
	m_pData = nullptr;

	unsigned int ilength = strlen(str.m_pData);
	m_pData = new char[ilength + 1];
	strcpy_s(m_pData, ilength + 1, str.m_pData);	
	// strcpy(m_pData, str.m_pData);
	return *this;
}

void CMyString::Print()
{
	if (m_pData != nullptr)
	{
		std::cout << m_pData << std::endl;
	}
}
