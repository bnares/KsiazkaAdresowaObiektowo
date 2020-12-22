#ifndef PLIKIZADRESATAMI_H

#define PLIKIZADRESATAMI_H

#include <iostream>
#include"MetodyPomocnicze.h"
#include "Adresaci.h"
#include <fstream>
#include <vector>
#include "UzytkownikMenedzer.h"


using namespace std;


class PlikiZAdresatami
{


public:

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    const string nazwaPlikuZAdresatami;
    PlikiZAdresatami(): nazwaPlikuZAdresatami("Adresaci.txt"){};
};


#endif
