#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

class SLList;

//struktura imitujaca pojedynczy element listy
struct SLListElement
{
	SLListElement *next;
	int value;
};

//klasa obslugujaca cala liste
class SLList {
	SLListElement *head;
	unsigned counterOfElem;
public:
	
	//konstruktor
	SLList() : head{ nullptr }, counterOfElem{0}
	{}

	//destruktor
	~SLList();

	void push(int number);		//funkcja pushujaca liczbe na poczatek listy
	void pop();					//funkcja zdejmujaca pierwszy element listy
	void showWholeList();		//funkcja pokazujaca wszystkie wartosci w liscie
	int size();					//funkcja zwracajaca liczbe elementow w danej chwilii w liscie
};



#endif // !SINGLYLINKEDLIST_H
