#pragma once

#include "header.h"

namespace library
{
	// ��������� ����������.
	//
	// [printToFile] - ����� ��� ������ ���� ��������� � ����
	// [printToConsole] - ����� ��� ������ ���� ��������� � �������
	// [fillFromFIle] - ����� ��� ���������� �� �����
	class IContainer
	{
	public:
		virtual ~IContainer() = default;

		virtual void printToFile(const string& filename) const = 0;
		virtual void printToConsole() const = 0;
		virtual void fillFromFile(const string& filename) = 0;
	};
}
