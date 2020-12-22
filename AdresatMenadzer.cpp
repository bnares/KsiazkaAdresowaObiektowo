#include <iostream>
#include "AdresatMenadzer.h"


using namespace std;


int AdresatMenadzer:: dodajAdresata(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;
    AdresatMenadzer menadzer;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);

    adresaci.push_back(adresat);

    menadzer.dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;
}




Adresat AdresatMenadzer:: podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;
    MetodyPomocznicze metoda;

    adresat.ustawIdAdresata(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    adresat.ustawImie(metoda.wczytajLinie());
    adresat.ustawImie(metoda.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(metoda.wczytajLinie());
    adresat.ustawNazwisko(metoda.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawTelefon(metoda.wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(metoda.wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(metoda.wczytajLinie());

    return adresat;
}





Adresat AdresatMenadzer:: pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawIdAdresata(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawTelefon(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}



string AdresatMenadzer:: zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    MetodyPomocznicze metoda;

    liniaZDanymiAdresata += metoda.konwerjsaIntNaString(adresat.pobierzIdAdresata()) + '|';
    liniaZDanymiAdresata += metoda.konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzTelefon() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}



void AdresatMenadzer:: dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    PlikiZAdresatami plik;
    PlikiZUzytkownikami uzytkownikPlik;
    plikTekstowy.open(plik.nazwaPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);  //TUTAJ JESTES

        if (uzytkownikPlik.czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    plikTekstowy.close();
    system("pause");

}




int AdresatMenadzer:: wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> &adresaci, UzytkownikMenadzer menadzer)
{
    Adresat adresat;
    PlikiZAdresatami plik;
    int idZalogowanego = menadzer.pobierzIdZalogowanegoUzytkownika();
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(plik.nazwaPlikuZAdresatami.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            int liczba = plik.pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami);
            if(menadzer.pobierzIdZalogowanegoUzytkownika() == liczba)
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);

                adresaci.push_back(adresat);
            }
                daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        }



    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "")
    {

        idOstatniegoAdresata = plik.pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        return idOstatniegoAdresata;
    }

    else
        return 0;

}


