#include "SinglyLinkedList.h"
#include "IncidenceList.h"
#include "libExceptions.h"
#include <iostream>
#include <fstream>
using namespace std;

void loadNumberOfVertexes(fstream& inFile, int& numberOfVertexes)
{
	int firstW{}, secW{}, numberOfEdges{};
	inFile >> numberOfEdges;

	for (int i = 0; i < numberOfEdges; i++)
	{
		inFile >> firstW >> secW;
		if (firstW > numberOfVertexes)
			numberOfVertexes = firstW;
		if (secW > numberOfVertexes)
			numberOfVertexes = secW;
	}

	inFile.seekg(0);
}

SLList ** createIncidenceList(int numberOfVertexes)
{
	SLList **list = nullptr;

	try
	{
		list = new SLList*[numberOfVertexes + 1];
	}
	catch (bad_alloc)
	{
		cout << "Nie udalo sie utworzyc listy o " << numberOfVertexes << " wierszach.";
		getchar();
		getchar();
		exit(0);
	}


	for (int i = 1; i <= numberOfVertexes; i++)
	{
		try
		{
			list[i] = new SLList;
		}
		catch (bad_alloc)
		{
			cout << "Nie udalo sie wstepnie zainicjowac tablicy.";
			getchar();
			getchar();
			exit(0);
		}
	}

	return list;
}

void fillIncidenceList(fstream & inFile, SLList **list)
{
	int firstW{}, secW{};
	int krawedzie{};
	inFile >> krawedzie;

	for (int i = 1; i <= krawedzie; i++)
	{
		try
		{
			inFile >> firstW >> secW;
			if (firstW <= 0 || secW <= 0)
				throw EXCEPTION_CODE::notNaturalNumber;

			list[firstW]->push(secW);
			list[secW]->push(firstW);
		}
		catch (EXCEPTION_CODE error)
		{
			seeExceptions(error);
			getchar();
			getchar();
			exit(0);
		}
	}


}

void showIncidenceList(SLList ** list, int numberOfVertexes)
{
	for (int i = 1; i <= numberOfVertexes; i++)
	{
		cout << i << " -> ";
		list[i]->showWholeList();
		cout << endl;
	}
}

void showDegreeOfVertexes(SLList ** list, int numberOfVertexes)
{
	for (int i = 1; i <= numberOfVertexes; i++)
	{
		cout << "Wierzcholek Nr" << i << " ->" << list[i]->size() << " stopien" << endl;
	}
}


