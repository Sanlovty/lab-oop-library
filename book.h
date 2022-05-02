#pragma once

#include "printed_material.h"

namespace library
{
	// Книга
	//
	// [_author] - автор
	// [_genre] - жанр
	// [_bindingType] - тип переплёта
	class Book : public PrintedMaterial
	{
	protected:
		author_t _author;
		genre_t _genre;
		binding_type_t _bindingType;
	public:
		~Book() override = default;
		string toString() const override;

		Book();
		Book(const author_t& author,
		     const genre_t& genre,
		     const binding_type_t& bindingType,
		     const name_t& name,
		     const page_amount_t& pageAmount,
		     const publishing_house_t& publishingHouse
		);

		author_t getAuthor() const;
		genre_t getGenre() const;
		binding_type_t getBindingType() const;

		void setAuthor(const author_t& author);
		void setGenre(const genre_t& genre);
		void setBindingType(const binding_type_t& bindingType);
	};
}
