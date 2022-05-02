#pragma once

#include "container_interface.h"
#include "printed_material.h"
#include "utils_cast.cpp"

namespace library
{
	class Library : public IContainer
	{
	protected:
		vector<PrintedMaterial*> _container;
		string _name;

		void _addBook(const author_t& author,
		              const genre_t& genre,
		              const binding_type_t& bindingType,
		              const name_t& name,
		              const page_amount_t& page_amount,
		              const publishing_house_t& publishingHouse
		);
		void _addJournal(const id_t& id,
		                 const year_t& year,
		                 const website_url_t& websiteUrl,
		                 const name_t& name,
		                 const page_amount_t& pageAmount,
		                 const publishing_house_t& publishingHouse);
		vector<PrintedMaterial*> _copyContainerMethod(const vector<PrintedMaterial*>& container) const;
	public:
		Library();
		Library(const Library& other);
		~Library() override;

		void add(PrintedMaterial* printedMaterial);
		void sortLibrary(const SORT_KEYS& key);

		string getName() const;
		void setName(const string& name);

		vector<PrintedMaterial*> getContainer() const;

		void fillFromFile(const string& filename) override;
		void printToConsole() const override;
		void printToFile(const string& filename) const override;
	};
}
