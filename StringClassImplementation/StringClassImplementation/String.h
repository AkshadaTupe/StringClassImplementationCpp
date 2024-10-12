#pragma once
#include "stdafx.h"

#ifndef STRING_H
#define STRING_H

class String
{
	char *m_strPtr;

public:
	//Default Constructor
	String() : m_strPtr(nullptr){}

	//from c-string
	String(const char* str);

	//Copy Constructor
	String(const String& str);

	//substring constructor
	String(const String& str, size_t pos, size_t len = npos);

	//from sequence
	String(const char* str, size_t n);

	//fill
	String(size_t n, char c);

	~String();

	friend ostream& operator<<(ostream& out, const String& str);

	static const size_t npos = -1;
};

#endif  // STRING_H