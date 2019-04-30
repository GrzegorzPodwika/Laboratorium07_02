#include <iostream>
#include "SinglyLinkedList.h"
#include "IncidenceList.h"
#include "libFiles.h"
using namespace std;

int main()
{
	int numberOfVertexes{};
	fstream inFile = createInputFile();
	loadNumberOfVertexes(inFile, numberOfVertexes);

	SLList **incidenceList = createIncidenceList(numberOfVertexes);
	fillIncidenceList(inFile, incidenceList);

	showIncidenceList(incidenceList, numberOfVertexes);
	showDegreeOfVertexes(incidenceList, numberOfVertexes);

	inFile.close();
	getchar();
	getchar();
	return 0;
}