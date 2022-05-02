#pragma once

#include "header.h"

namespace library
{
	// Интерфейс контейнера.
	//
	// [printToFile] - метод для вывода всех элементов в файл
	// [printToConsole] - метод для вывода всех элементов в консоль
	// [fillFromFIle] - метод для заполнения из файла
	class IContainer
	{
	public:
		virtual ~IContainer() = default;

		virtual void printToFile(const string& filename) const = 0;
		virtual void printToConsole() const = 0;
		virtual void fillFromFile(const string& filename) = 0;
	};
}
