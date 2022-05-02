#include "header.h"

// ¬озвращает указатель в виде строки
template <typename _Ty>
static string thisToString(const _Ty& thisPointer)
{
	stringstream ss;
	ss << &thisPointer;

	return ss.str();
}


// ¬озвращает строку в нижнем регистре
static string toLowerString(const string& str)
{
	string result = str;
	for (size_t i = 0; i < str.length(); i++)
	{
		result[i] = tolower(str[i]);
	}

	return result;
}
