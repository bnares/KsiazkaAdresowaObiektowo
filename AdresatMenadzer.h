#ifndef  ADRESATMENADZER_H

#define ADRESATMENADZER_H
#include <vector>
#include <iostream>
#include "Adresaci.h"
#include "PlikiZAdresatami.h"
#include "MetodyPomocnicze.h"
#include "Uzytkownik.h"
#include "PlikiZUzytkownikami.h"
#include <fstream>


using namespace std;


class AdresatMenadzer
{
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);

    public:
    int dodajAdresata(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void dopiszAdresataDoPliku(Adresat adresat);
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> &adresaci, UzytkownikMenadzer menadzer);
};


#endif

