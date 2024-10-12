#include "stdafx.h"
#include "String.h"

ostream& operator<<(ostream& out, const String& str)
{
	if (str.m_strPtr != nullptr)
	{
		out << str.m_strPtr;
	}
	return out;
}

String::String(const char* str)
{
	m_strPtr = new char[strlen(str) + 1];
	strcpy_s(m_strPtr, strlen(str) + 1, str);
}

String::String(const String& str)
{
	m_strPtr = new char[strlen(str.m_strPtr) + 1];
	strcpy_s(m_strPtr, strlen(str.m_strPtr) + 1, str.m_strPtr);
}

String::String(const String& str, size_t pos, size_t len)
{
	size_t strLength = strlen(str.m_strPtr);

	if (pos >= strLength)
	{
		m_strPtr = nullptr;
	}
	else
	{
		if (len == npos || len > (strLength - pos))
		{
			len = strLength - pos;
		}
		m_strPtr = new char[len + 1];
		strncpy_s(m_strPtr, len+1, str.m_strPtr + pos, len);
	}

}

String::String(const char* str, size_t n)
{
	m_strPtr = new char[n+1];
	strncpy_s(m_strPtr, n+1, str, n);
}

String::String(size_t n, char c)
{
	m_strPtr = new char[n+1];
	for (int i = 0; i < n; i++)
		m_strPtr[i] = c;

	m_strPtr[n] = '\0';

}

String::~String()
{
	delete[] m_strPtr;
	m_strPtr = nullptr;
}
