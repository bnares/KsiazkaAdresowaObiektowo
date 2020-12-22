#ifndef  PLIKIZUZYKOWNIKAMI_H
#define PLIKIZUZYKOWNIKAMI_H
#include <iostream>
#include <fstream>
#include <vector>
#include "UzytkownikMenedzer.h"
#include "MetodyPomocnicze.h"
#include "Uzytkownik.h"




using namespace std;


class PlikiZUzytkownikami
{

    const string nazwaPlikuZUzytkownikami;
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);


public:
    bool czyPlikJestPusty();
    PlikiZUzytkownikami():nazwaPlikuZUzytkownikami("Uzytkownicy.txt") {};
    string PobierzNazwePlikuUzytkownikow();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);
};


#endif
