
#ifndef  UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H
#include <iostream>
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PlikiZUzytkownikami.h"
#include "Logowanie.h"
#include <vector>



using namespace std;

class UzytkownikMenadzer
{
    vector <Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika;
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);


public:
    UzytkownikMenadzer(): idZalogowanegoUzytkownika(0){};
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void rejestracjaUzytkownika();
    int pobierzIdUzytkownika();
    void ustawIdUzytkownika(int LiczbaId);
    void wypiszWszystkich(vector <Uzytkownik> &uzytkownicy);
    void zmianaHaslaZalogowanegoUzytkownika(vector <Uzytkownik> &uzytkownicy);
    void ustawIdZalogowanegoUzytkownika(int liczba);
    int pobierzIdZalogowanegoUzytkownika();

};


#endif
