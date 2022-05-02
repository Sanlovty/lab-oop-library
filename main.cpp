#include "library.h"
using namespace library;


int main()
{
	Library library;
	library.fillFromFile("input.txt");
	library.sortLibrary(SORT_KEYS::PAGE_AMOUNT);
	library.printToConsole();
	return 0;
}
