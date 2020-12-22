#include <iostream>
#include "UzytkownikMenedzer.h"
#include "PlikiZUzytkownikami.h"
#include <fstream>


using namespace std;




vector <Uzytkownik> UzytkownikMenadzer:: wczytajUzytkownikowZPliku()
{
    Uzytkownik uzytkownik;
    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";
    PlikiZUzytkownikami plik;
    fstream plikTekstowy;
    plikTekstowy.open(plik.PobierzNazwePlikuUzytkownikow().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami))
        {
            uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            uzytkownicy.push_back(uzytkownik);
        }

    }

    else
    {
        cout<<"Brak pliku"<<endl;
    }
    plikTekstowy.close();
    return uzytkownicy;
}



Uzytkownik UzytkownikMenadzer:: pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    Uzytkownik uzytkownik;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejUzytkownika)
            {
            case 1:
                uzytkownik.ustawID(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }

    return uzytkownik;

}


void UzytkownikMenadzer:: wypiszWszystkich(vector <Uzytkownik> &uzytkownicy)
{
    Uzytkownik a;
    vector <Uzytkownik>::iterator it = uzytkownicy.begin();
    cout<<"TWOI UZYTKOWNICY: "<<endl;
    for(int i =0; i<uzytkownicy.size(); i++)
    {
        cout<<uzytkownicy[i].pobierzLogin()<<endl;
    }
    system("pause");

}

int UzytkownikMenadzer:: pobierzIdUzytkownika()
{
    return idZalogowanegoUzytkownika;
}


void UzytkownikMenadzer:: rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();
    PlikiZUzytkownikami pliki;

    uzytkownicy.push_back(uzytkownik);
    cout<<"Dodane uzytkownik - rejestracja uzytkownika: \n"<<uzytkownicy.back().pobierzID()<<" "<<uzytkownicy.back().pobierzLogin()<<" "<<uzytkownik.pobierzHaslo()<<endl;
    pliki.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}



Uzytkownik UzytkownikMenadzer:: podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    MetodyPomocznicze pomoc;

    uzytkownik.ustawID(pobierzIdNowegoUzytkownika());
    cout<<"Dodane id do pliku bedzie wynosic: "<<uzytkownik.pobierzID()<<endl;

    do
    {
        cout << endl << "Podaj login: ";
        uzytkownik.ustawLogin(pomoc.wczytajLinie());
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    uzytkownik.ustawHaslo(pomoc.wczytajLinie());

    return uzytkownik;
}




int UzytkownikMenadzer:: pobierzIdNowegoUzytkownika()
{

    if (uzytkownicy.empty() == true)
        return 1;
    else
        cout<<"Ostatnie id wynosi: "<<uzytkownicy.back().pobierzID()<<endl;
        return uzytkownicy.back().pobierzID() + 1;
}



bool UzytkownikMenadzer:: czyIstniejeLogin(string login)
{


    for(int i =0; i< uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin()==login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;

}





void UzytkownikMenadzer::ustawIdUzytkownika(int liczbaId)
{
    idZalogowanegoUzytkownika = liczbaId;
}



void UzytkownikMenadzer:: zmianaHaslaZalogowanegoUzytkownika(vector <Uzytkownik> &uzytkownicy)
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    MetodyPomocznicze metoda;
    noweHaslo = metoda.wczytajLinie();

    for(int i =0; i< uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzID()== UzytkownikMenadzer:: idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }

    PlikiZUzytkownikami plik;
    plik.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}



void UzytkownikMenadzer:: ustawIdZalogowanegoUzytkownika(int liczba)
{
    idZalogowanegoUzytkownika = liczba;
}

int UzytkownikMenadzer:: pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
