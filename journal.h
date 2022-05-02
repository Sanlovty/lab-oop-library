#pragma once
#include "printed_material.h"

namespace library
{
	// Журнал
	//
	// [_id] - номер
	// [_year] - год
	// [_websiteUrl] - вебсайт
	class Journal : public PrintedMaterial
	{
	protected:
		id_t _id;
		year_t _year;
		website_url_t _websiteUrl;
	public:
		~Journal() override = default;
		string toString() const override;

		Journal();
		Journal(const id_t& id,
		        const year_t& year,
		        const website_url_t& websiteUrl,
		        const name_t& name,
		        const page_amount_t& pageAmount,
		        const publishing_house_t& publishingHouse
		);

		id_t getId() const;
		year_t getYear() const;
		website_url_t getWebsiteUrl() const;

		void setId(const id_t& id);
		void setYear(const year_t& year);
		void setWebsiteUrl(const website_url_t& websiteUrl);
	};
}
