#include <iostream>
#include "Adresaci.h"


using namespace std;

void Adresat:: ustawIdAdresata(int numer)
{
    idAdresata = numer;
}


void Adresat:: ustawIdUzytkownika(int numer)
{
    idUzytkownika = numer;
}


void Adresat:: ustawImie(string noweImie)
{
    imie = noweImie;
}


void Adresat:: ustawNazwisko(string noweNazwisko)
{
    nazwisko = noweNazwisko;
}


void Adresat:: ustawTelefon(string nowyTelefon)
{
        telefon = nowyTelefon;
}


void Adresat:: ustawEmail(string nowyEmail)
{
    email = nowyEmail;
}


void Adresat:: ustawAdres(string nowyAdres)
{
    adres = nowyAdres;
}



int Adresat:: pobierzIdAdresata()
{
    return idAdresata;
}

int Adresat:: pobierzIdUzytkownika()
{
    return idUzytkownika;
}

string Adresat:: pobierzImie()
{
    return imie;
}

string Adresat:: pobierzNazwisko()
{
    return nazwisko;

}

string Adresat:: pobierzTelefon()
{
    return telefon;
}


string Adresat:: pobierzEmail()
{
    return email;
}


string Adresat:: pobierzAdres()
{
    return adres;
}



