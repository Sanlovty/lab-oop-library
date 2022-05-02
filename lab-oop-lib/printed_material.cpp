#include "printed_material.h"

namespace library
{
	PrintedMaterial::PrintedMaterial() :
		_name(name_t()),
		_pageAmount(page_amount_t()),
		_publishingHouse(publishing_house_t())
	{
	}

	PrintedMaterial::PrintedMaterial(
		const name_t& name,
		const page_amount_t& pageAmount,
		const publishing_house_t& publishingHouse
	) :
		_name(name),
		_pageAmount(pageAmount),
		_publishingHouse(publishingHouse)
	{
	}

	string PrintedMaterial::toString() const
	{
		return "[" + thisToString(this) + "] is PrintedMaterial instance with values: {\n"
			+ "	name: " + _name + ",\n"
			+ "	page_amount: " + to_string(_pageAmount) + ",\n"
			+ "	publishingHouse: " + _publishingHouse
			+ "\n}";
	}

	name_t PrintedMaterial::getName() const
	{
		return _name;
	}

	page_amount_t PrintedMaterial::getPageAmount() const
	{
		return _pageAmount;
	}

	publishing_house_t PrintedMaterial::getPublishingHouse() const
	{
		return _publishingHouse;
	}

	void PrintedMaterial::setName(const name_t& name)
	{
		_name = name;
	}

	void PrintedMaterial::setPageAmount(const page_amount_t& pageAmount)
	{
		_pageAmount = pageAmount;
	}

	void PrintedMaterial::setPublishingHouse(const publishing_house_t& publishingHouse)
	{
		_publishingHouse = publishingHouse;
	}
}
