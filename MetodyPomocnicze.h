#ifndef METODYPOMOCNICZE_H

#define METODYPOMOCNICZE_H
#include <sstream>
#include "MetodyPomocnicze.h"
#include <fstream>
#include <algorithm>

using namespace std;

class MetodyPomocznicze
{
    public:
        char wczytajZnak();
        string wczytajLinie();
        string konwerjsaIntNaString(int liczba);
        int konwersjaStringNaInt(string liczba);
        string pobierzLiczbe(string tekst, int pozycjaZnaku);
        string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);

};



#endif
