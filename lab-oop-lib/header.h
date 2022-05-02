#pragma once

// ���������
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

// ����� ������
using std::stringstream;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::exception;
using std::sort;
using std::to_string;
using std::cout;
using std::endl;

// ������ ��� [PrintedMaterial] 
using name_t = string;
using page_amount_t = size_t;
using publishing_house_t = string;

// ������ ��� [Book] 
using author_t = string;
using genre_t = string;
using binding_type_t = string;

// ������ ��� [Journal] 
using id_t = size_t;
using year_t = size_t;
using website_url_t = string;

// ������ ��� [IContainer] 
using id_t = size_t;
using year_t = size_t;
using website_url_t = string;


// Enums
namespace library
{
	enum class SORT_KEYS
	{
		NAME,
		PAGE_AMOUNT,
		PUBLISHING_HOUSE
	};
}
