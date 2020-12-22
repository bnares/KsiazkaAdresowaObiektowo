
#include <iostream>
#include "Uzytkownik.h"
#include "PlikiZAdresatami.h"


using namespace std;






int PlikiZAdresatami:: pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    MetodyPomocznicze metoda;


    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = metoda.konwersjaStringNaInt(metoda.pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}




int PlikiZAdresatami:: pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    MetodyPomocznicze metoda;
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = metoda.konwersjaStringNaInt(metoda.pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}













