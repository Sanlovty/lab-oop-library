#include "printed_material_comporators.h"

namespace library
{
	bool PrintedMaterialComporators::byName(const PrintedMaterial* first, const PrintedMaterial* second)
	{
		return first->getName() >= second->getName();
	}

	bool PrintedMaterialComporators::byPageAmount(const PrintedMaterial* first, const PrintedMaterial* second)
	{
		return first->getPageAmount() >= second->getPageAmount();
	}

	bool PrintedMaterialComporators::byPublishingHouse(const PrintedMaterial* first, const PrintedMaterial* second)
	{
		return first->getPublishingHouse() >= second->getPublishingHouse();
	}
}
