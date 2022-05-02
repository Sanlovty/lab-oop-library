#pragma once

#include "printed_material.h"

namespace library
{
	// ����� ��� ������������
	class PrintedMaterialComporators
	{
	public:
		static bool byName(const PrintedMaterial* first, const PrintedMaterial* second);
		static bool byPageAmount(const PrintedMaterial* first, const PrintedMaterial* second);
		static bool byPublishingHouse(const PrintedMaterial* first, const PrintedMaterial* second);
	};
}
