#include <iostream>
#include <vector>
#include "PlikiZUzytkownikami.h"
#include "Uzytkownik.h"



using namespace std;

class KsiazkaAdresowa
{
    PlikiZUzytkownikami pliki;
public:
    void wypiszZapisanych()
    {
        UzytkownikMenadzer menedzer;
        for(int i =0; i< menedzer.uzytkownicy.size(); i++)
        {
            cout<<menedzer.uzytkownicy[i].pobierzLogin()<<endl;
        }
    }
};
