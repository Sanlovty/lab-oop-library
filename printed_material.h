#pragma once

#include "reading_interface.h"
#include "utils_misc.cpp"

namespace library
{
	// Печатное издание
	//
	// [_name] - наименование
	// [_pageAmount] - количество страниц
	// [_publishingHouse] - издательство
	class PrintedMaterial : public IReading
	{
	protected:
		name_t _name;
		page_amount_t _pageAmount;
		publishing_house_t _publishingHouse;
	public:
		PrintedMaterial();
		PrintedMaterial(const name_t& name,
		                const page_amount_t& pageAmount,
		                const publishing_house_t& publishingHouse
		);
		~PrintedMaterial() override = default;
		string toString() const override;

		name_t getName() const;
		page_amount_t getPageAmount() const;
		publishing_house_t getPublishingHouse() const;

		void setName(const name_t& name);
		void setPageAmount(const page_amount_t& pageAmount);
		void setPublishingHouse(const publishing_house_t& publishingouse);
	};
}
