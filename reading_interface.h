#pragma once
#include "header.h"

namespace library
{
	// ��������� ������������ ���������.
	//
	// toString() - ����� ��� ��������� ���������� � �������� � ������� string
	class IReading
	{
	public:
		virtual ~IReading() = default;
		virtual string toString() const = 0;
	};
}
