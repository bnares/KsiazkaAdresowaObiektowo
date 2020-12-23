#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include "UzytkownikMenedzer.h"
#include "Menu.h"
#include "Adresaci.h"
#include "PlikiZAdresatami.h"
#include "AdresatMenadzer.h"

/* MADE WITH LOVE */

using namespace std;

int main()
{
    UzytkownikMenadzer menadzer;
    Menu menu;
    vector <Uzytkownik> uzytkownicy = menadzer.wczytajUzytkownikowZPliku();
    vector <Adresat> adresaci;
    int IdOstatniegoAdresata=0;
    char wybor = {0};
    while(true)
    {

        if(menadzer.pobierzIdZalogowanegoUzytkownika()==0)
        {
            wybor = menu.wybierzOpcjeZMenuGlownego();
            switch(wybor)
            {
            case '1':
                {
                    menadzer.rejestracjaUzytkownika();
                    break;
                }
            case '2':
                {

                    Logowanie loguj;
                    menadzer.ustawIdZalogowanegoUzytkownika(loguj.logowanieUzytkownika(uzytkownicy));
                    break;
                }
            case '9':
                {
                    exit(0);
                }
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }

        }

        else
        {
            AdresatMenadzer dane;
            IdOstatniegoAdresata = dane.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci,menadzer);
            char wybor =menu.wybierzOpcjeZMenuUzytkownika();


            switch(wybor)
            {


            case '1':
                {

                    AdresatMenadzer adresat;
                    IdOstatniegoAdresata = adresat.dodajAdresata(adresaci, menadzer.pobierzIdUzytkownika(), IdOstatniegoAdresata);
                    break;
                }
            case '7':
                {

                    menadzer.zmianaHaslaZalogowanegoUzytkownika(uzytkownicy);
                    break;
                }
            case '8':
                {
                    menadzer.ustawIdZalogowanegoUzytkownika(0);
                }

            }

        }

    }


    return 0;

}

