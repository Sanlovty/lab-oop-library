#include "library.h"

#include "printed_material_comporators.h"

namespace library
{
	void Library::_addBook(const author_t& author,
	                       const genre_t& genre,
	                       const binding_type_t& bindingType,
	                       const name_t& name,
	                       const page_amount_t& pageAmount,
	                       const publishing_house_t& publishingHouse
	)
	{
		_container.push_back(new Book(author, genre, bindingType, name, pageAmount, publishingHouse));
	}

	void Library::_addJournal(const id_t& id,
	                          const year_t& year,
	                          const website_url_t& websiteUrl,
	                          const name_t& name,
	                          const page_amount_t& pageAmount,
	                          const publishing_house_t& publishingHouse
	)

	{
		_container.push_back(new Journal(id, year, websiteUrl, name, pageAmount, publishingHouse));
	}

	vector<PrintedMaterial*> Library::_copyContainerMethod(const vector<PrintedMaterial*>& container) const
	{
		vector<PrintedMaterial*> toReturn;
		for (const auto it : container)
		{
			if (tryCastToBookPtr(it) != nullptr)
			{
				const Book* book = tryCastToBookPtr(it);
				toReturn.push_back(new Book(book->getAuthor(),
				                            book->getGenre(),
				                            book->getBindingType(),
				                            book->getName(),
				                            book->getPageAmount(),
				                            book->getPublishingHouse())
				);
			}
			else if (tryCastToJournalPtr(it) != nullptr)
			{
				const Journal* journal = tryCastToJournalPtr(it);
				toReturn.push_back(new Journal(journal->getId(),
				                               journal->getYear(),
				                               journal->getWebsiteUrl(),
				                               journal->getName(),
				                               journal->getPageAmount(),
				                               journal->getPublishingHouse())
				);
			}
			else
			{
				// Дальше должны строятся блоки else if для других детей, наследников PrintedMaterial
			}
		}
		return toReturn;
	}

	Library::Library()
		: _container(vector<PrintedMaterial*>()),
		  _name(string())
	{
	}

	Library::Library(const Library& other)
		: _container(_copyContainerMethod(other._container)),
		  _name(other._name)
	{
	}

	Library::~Library()
	{
		for (auto it : _container)
		{
			delete it;
		}
		_container.clear();
	}


	void Library::add(PrintedMaterial* printedMaterial)
	{
		_container.push_back(printedMaterial);
	}

	void Library::sortLibrary(const SORT_KEYS& key)
	{
		switch (key)
		{
		case SORT_KEYS::NAME:
			sort(_container.begin(), _container.end(), PrintedMaterialComporators::byName);
			break;
		case SORT_KEYS::PAGE_AMOUNT:
			sort(_container.begin(), _container.end(), PrintedMaterialComporators::byPageAmount);
			break;
		case SORT_KEYS::PUBLISHING_HOUSE:
			sort(_container.begin(), _container.end(), PrintedMaterialComporators::byPublishingHouse);
			break;
		}
	}

	void Library::fillFromFile(const string& filename)
	{
		auto file = ifstream(filename);
		if (!file.is_open())
		{
			throw exception("file not found");
		}
		while (file.good())
		{
			string type;
			file >> type;

			type = toLowerString(type);
			if (type != "book" && type != "journal")
			{
				throw exception("file incorrect");
			}

			name_t name;
			page_amount_t pageAmount;
			publishing_house_t publishingHouse;
			file >> name;
			file >> pageAmount;
			file >> publishingHouse;

			if (type == "book")
			{
				author_t author;
				genre_t genre;
				binding_type_t bindingType;
				file >> author;
				file >> genre;
				file >> bindingType;
				_addBook(author, genre, bindingType, name, pageAmount, publishingHouse);
			}
			else if (type == "journal")
			{
				id_t id;
				year_t year;
				website_url_t websiteUrl;
				file >> id;
				file >> year;
				file >> websiteUrl;
				_addJournal(id, year, websiteUrl, name, pageAmount, publishingHouse);
			}
			else
			{
				// Могут быть добалвлены блоки else if
			}
		}
	}

	void Library::printToConsole() const
	{
		for (auto it = _container.begin(); it != _container.end(); ++it)
		{
			cout << (*it)->toString() << (it + 1 == _container.end() ? "" : ",") << endl;
		}
	}

	void Library::printToFile(const string& filename) const
	{
		ofstream file(filename);
		for (auto it = _container.begin(); it != _container.end(); ++it)
		{
			file << (*it)->toString() << (it + 1 == _container.end() ? "" : ",") << endl;
		}
		file.close();
	}

	string Library::getName() const
	{
		return _name;
	}

	void Library::setName(const string& name)
	{
		_name = name;
	}

	vector<PrintedMaterial*> Library::getContainer() const
	{
		return _copyContainerMethod(_container);
	}
}
