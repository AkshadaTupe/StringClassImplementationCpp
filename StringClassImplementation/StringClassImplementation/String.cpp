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

String & String::append(const String & str)
{
	if (this->m_strPtr != nullptr)
	{
		size_t newLength = strlen(this->m_strPtr) + strlen(str.m_strPtr);
		strcat_s(this->m_strPtr, newLength + 1, str.m_strPtr);
	}
	else
	{
		this->m_strPtr = new char[strlen(str.m_strPtr) + 1];
		strcpy_s(this->m_strPtr, strlen(str.m_strPtr) + 1, str.m_strPtr);
	}
	return *this;

}

String & String::append(const String & str, size_t subpos, size_t sublen)
{
	size_t strLength = strlen(str.m_strPtr);

	// If the subpos is out of bounds, return the original string
	if (subpos >= strLength)
	{
		return *this;
	}

	// Adjust the sublen if it's npos or longer than the remaining string
	if (sublen == npos || sublen > (strLength - subpos))
	{
		sublen = strlen(str.m_strPtr) - subpos;
	}

	char* newStrPtr = new char[strlen(this->m_strPtr) + sublen + 1];

	strcpy_s(newStrPtr, strlen(this->m_strPtr) + sublen + 1, this->m_strPtr);
	strncat_s(newStrPtr, strlen(this->m_strPtr)+sublen+1, str.m_strPtr + subpos, sublen);

	delete[] this->m_strPtr;

	this->m_strPtr = newStrPtr;

	return *this;
}

String & String::append(const char * s, size_t n)
{
	char* newStr;
	if (this->m_strPtr == nullptr)
	{
		size_t newLength = n+1;
		newStr = new char[newLength];
		strcpy_s(newStr, newLength, s);
	}
	else
	{
		size_t newLength = strlen(this->m_strPtr) + n + 1;
		newStr = new char[newLength];
		strcpy_s(newStr, newLength, this->m_strPtr);
		strncat_s(newStr, newLength, s, n);
	}
	delete[] this->m_strPtr;
	this->m_strPtr = newStr;
	return *this;
}

String & String::append(const char * s)
{
	char* newStr;
	if (this->m_strPtr == nullptr)
	{
		size_t newLength =  strlen(s) + 1;
		newStr = new char[newLength];
		strcpy_s(newStr, newLength, s);
	}
	else
	{
		size_t newLength = strlen(this->m_strPtr) + strlen(s) + 1;
		newStr = new char[newLength];
		strcpy_s(newStr, newLength, this->m_strPtr);
		strcat_s(newStr, newLength , s);
	}
	delete[] this->m_strPtr;
	this->m_strPtr = newStr;
	return *this;
}

String & String::append(size_t n, char c)
{

		char* newStr = new char[n + 1];
		for (int i = 0; i < n; i++)
			newStr[i] = c;
		newStr[n] = '\0';
	    
		char* str;
		if (this->m_strPtr == nullptr)
		{
		    str = new char[n + 1];
			strcpy_s(str, n + 1, newStr);
		}
		else
		{
			str = new char[strlen(this->m_strPtr)+n + 1];
			strcpy_s(str, strlen(this->m_strPtr) + n + 1, this->m_strPtr);
			strcat_s(str, strlen(this->m_strPtr) + n + 1, newStr);
		}
		delete[] newStr;
		delete[] this->m_strPtr;
		this->m_strPtr = str;
		return *this;
}
