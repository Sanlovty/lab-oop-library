#include "book.h"
#include "journal.h"

namespace library
{
	static PrintedMaterial* tryCastToPrintedMaterialPtr(IReading* readingObject)
	{
		return dynamic_cast<PrintedMaterial*>(readingObject);
	}

	static Book* tryCastToBookPtr(IReading* readingObject)
	{
		PrintedMaterial* printedMaterial = tryCastToPrintedMaterialPtr(readingObject);
		return printedMaterial == nullptr ? nullptr : dynamic_cast<Book*>(printedMaterial);
	}

	static Journal* tryCastToJournalPtr(IReading* readingObject)
	{
		PrintedMaterial* printedMaterial = tryCastToPrintedMaterialPtr(readingObject);
		return printedMaterial == nullptr ? nullptr : dynamic_cast<Journal*>(printedMaterial);
	}
}
