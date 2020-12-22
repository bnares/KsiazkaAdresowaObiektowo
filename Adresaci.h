#ifndef  ADRESACI_H

#define ADRESACI_H
#include <iostream>
#include <vector>
#include "MetodyPomocnicze.h"
#include "PlikiZAdresatami.h"

using namespace std;

class Adresat
{
    int idAdresata;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string telefon;
    string email;
    string adres;


public:
    void ustawIdAdresata(int numer);
    void ustawIdUzytkownika(int numer);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawTelefon(string nowyTelefon);
    void ustawEmail(string nowyEmail);
    void ustawAdres(string nowyAdres);

    int pobierzIdAdresata();
    int pobierzIdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzTelefon();
    string pobierzEmail();
    string pobierzAdres();



};





#endif
