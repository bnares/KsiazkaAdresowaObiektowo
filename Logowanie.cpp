#include <iostream>
#include "Logowanie.h"



using namespace std;


int Logowanie:: logowanieUzytkownika(vector <Uzytkownik> &dane)
{
    Uzytkownik uzytkownik;
    UzytkownikMenadzer menadzer;
    MetodyPomocznicze metoda;

    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = metoda.wczytajLinie();

    vector <Uzytkownik> pobranaBazaUzytkownikow = dane;
    vector <Uzytkownik>::iterator itr = pobranaBazaUzytkownikow.begin();

    while (itr != pobranaBazaUzytkownikow.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = metoda.wczytajLinie();

                if (itr -> pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return itr -> pobierzID();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}
