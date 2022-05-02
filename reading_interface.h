#pragma once
#include "header.h"

namespace library
{
	// Интерфейс читабельного документа.
	//
	// toString() - метод для получения информации о сущности в формате string
	class IReading
	{
	public:
		virtual ~IReading() = default;
		virtual string toString() const = 0;
	};
}
