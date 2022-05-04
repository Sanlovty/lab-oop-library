#include "library.h"
#include <map>
#include <set>
using namespace library;

void task(const Library& library, const size_t& year)
{
	std::map<string, size_t> publishHouses;
	for (auto it = library.begin(); it != library.end(); ++it)
	{
		auto tmp = dynamic_cast<Journal*>(*it);
		if (tmp != nullptr && tmp->getYear() == year)
		{
			publishHouses[tmp->getPublishingHouse()]++;
		}
	}
	std::set<std::pair<size_t, string>> sorted;
	for (const auto& it : publishHouses)
	{
		sorted.emplace(it.second, it.first);
	}
	auto it = sorted.rbegin();
	while (it != sorted.rend() && (*it).first == (*sorted.rbegin()).first)
	{
		cout << "PublishingHouse = " << it->second << ", amount of journals per (" << year << " year) is " << it->first
			<< endl;
		++it;
	}
}

int main()
{
	Library library;
	library.fillFromFile("input.txt");

	size_t year;
	cout << "Enter year: ";
	std::cin >> year;

	task(library, year);
	return 0;
}
