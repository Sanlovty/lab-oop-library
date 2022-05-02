#include "journal.h"

namespace library
{
	string Journal::toString() const
	{
		return "[" + thisToString(this) + "] is Journal instance with values: {\n"
			+ "	name: " + _name + ",\n"
			+ "	page_amount: " + to_string(_pageAmount) + ",\n"
			+ "	publishingHouse: " + _publishingHouse + ",\n"
			+ "	id: " + to_string(_id) + ",\n"
			+ "	year: " + to_string(_year) + ",\n"
			+ "	website_url: " + _websiteUrl
			+ "\n}";
	}

	Journal::Journal() :
		_id(id_t()),
		_year(year_t()),
		_websiteUrl(website_url_t())
	{
	}


	Journal::Journal(const id_t& id,
	                 const year_t& year,
	                 const website_url_t& websiteUrl,
	                 const name_t& name,
	                 const page_amount_t& pageAmount,
	                 const publishing_house_t& publishingHouse
	) :
		PrintedMaterial(name,
		                pageAmount,
		                publishingHouse
		),
		_id(id),
		_year(year),
		_websiteUrl(websiteUrl)
	{
	}

	id_t Journal::getId() const
	{
		return _id;
	}

	year_t Journal::getYear() const
	{
		return _year;
	}

	website_url_t Journal::getWebsiteUrl() const
	{
		return _websiteUrl;
	}

	void Journal::setId(const id_t& id)
	{
		_id = id;
	}

	void Journal::setYear(const year_t& year)
	{
		_year = year;
	}

	void Journal::setWebsiteUrl(const website_url_t& websiteUrl)
	{
		_websiteUrl = websiteUrl;
	}
}
