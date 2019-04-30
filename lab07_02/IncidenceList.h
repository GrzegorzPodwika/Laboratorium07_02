#ifndef INCIDENCELIST_H
#define INCIDENCELIST_H
#include <fstream>

/*
Funkcja pomocnicza poszukujaca najwiekszej wartosci wierzcholka w pliku
@param inFile plik, w ktorym znajduja sie definicje krawedzi grafy nieskierowanego
@param numberOfVertexes maksymalna liczba wierzcholkow do uzupelnienia, poprzez referencje
*/
void loadNumberOfVertexes(std::fstream& inFile, int& numberOfVertexes);

/*
Funkcja tworzaca tablice wskaznikow do obiektow typu lista wraz ze wstepna inicjalizacja
@param numberOfVertexes liczba wierzcholkow; ilosc wierszy
@return tablice wskaznikow do obiektow typu lista
*/
SLList** createIncidenceList(int numberOfVertexes);

/*
Funkcja wypelniajaca tablice list incydencji wartosciami z pliku
@param inFile plik, w ktorym znajduja sie definicje krawedzi grafy nieskierowanego
@param list tablica wskaznikow do obiektow typu lista
*/
void fillIncidenceList(std::fstream &inFile, SLList **list);

/*
Funkcja pokazujaca na ekran liste incydencji wierzcholkow
@param list tablica list incydencji
@param numberOfVertexes liczba wierzcholkow; ilosc wierszy
*/
void showIncidenceList(SLList **list, int numberOfVertexes);

/*
Funkcja pokazujaca na ekran stopnie danych wierzcholkow
@param list tablica list incydencji
@param numberOfVertexes liczba wierzcholkow; ilosc wierszy
*/
void showDegreeOfVertexes(SLList **list, int numberOfVertexes);


#endif // !INCIDENCELIST_H

