#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

SLList::~SLList()
{
	SLListElement *tmp = nullptr;

	while (head != nullptr)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
}

void SLList::push(int number)
{
	SLListElement *nElem = new SLListElement;
	nElem->value = number;

	nElem->next = head;
	head = nElem;
	counterOfElem++;
}

void SLList::pop()
{
	if (head != nullptr)
	{
		SLListElement *tmp = head;
		head = tmp->next;
		delete tmp;
		counterOfElem--;
	}
	else
	{
		cout << "Lista jest pusta!" << endl;
	}

}

void SLList::showWholeList()
{
	SLListElement *tmp = head;
	while (tmp != nullptr)
	{
		cout << tmp->value << "  ";
		tmp = tmp->next;
	}
}

int SLList::size()
{
	return counterOfElem;
}
