#include "book.h"

namespace library
{
	string Book::toString() const
	{
		return "[" + thisToString(this) + "] is Book instance with values: {\n"
			+ "	name: " + _name + ",\n"
			+ "	page_amount: " + to_string(_pageAmount) + ",\n"
			+ "	publishingHouse: " + _publishingHouse + ",\n"
			+ "	author: " + _author + ",\n"
			+ "	genre: " + _genre + ",\n"
			+ "	binding_type: " + _bindingType
			+ "\n}";
	}

	Book::Book() :
		_author(author_t()),
		_genre(genre_t()),
		_bindingType(binding_type_t())
	{
	}


	Book::Book(const author_t& author,
	           const genre_t& genre,
	           const binding_type_t& bindingType,
	           const name_t& name,
	           const page_amount_t& pageAmount,
	           const publishing_house_t& publishingHouse
	) :
		PrintedMaterial(name,
		                pageAmount,
		                publishingHouse
		),
		_author(author),
		_genre(genre),
		_bindingType(bindingType)
	{
	}

	author_t Book::getAuthor() const
	{
		return _author;
	}

	genre_t Book::getGenre() const
	{
		return _genre;
	}

	binding_type_t Book::getBindingType() const
	{
		return _bindingType;
	}

	void Book::setAuthor(const author_t& author)
	{
		_author = author;
	}

	void Book::setGenre(const genre_t& genre)
	{
		_genre = genre;
	}

	void Book::setBindingType(const binding_type_t& bindingType)
	{
		_bindingType = bindingType;
	}
}
