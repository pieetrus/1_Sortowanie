#include "Testy.hh"
#include "scalanie.cpp"
#include "quicksort.cpp"
#include "introspektywne.cpp"
#include <cstdlib>
#include <ctime>
#include <fstream>

template <class typ>
void wyswietl_tablice(typ *tablica, int dlugosc)
{
    for(int i =0; i< dlugosc; i++)
        cout << tablica[i] << endl;
}

template <class typ>
void Odwrotnie_posortowana(typ *tablica, int dlugosc)
{
    for(int i =0; i< dlugosc; i++)
        tablica[i] = dlugosc - i;
}

template <class typ>
void Posortowana(typ *tablica, int dlugosc)
{
    for(int i =0; i< dlugosc; i++)
        tablica[i] = i;
}

template <class typ>
void Czesciowo_posortowana(typ *tablica, const int dlugosc, double procent)
{
    srand(time(NULL));
    int indeks;

    procent = procent/100;
    indeks = dlugosc*procent;

    for(int i =0; i< indeks; i++)
        tablica[i] = i;

    for(int i = indeks; i<dlugosc; i++)
        tablica[i] = (rand())/2 +5;
}

template <class typ>
void Losowa(typ *tablica, int dlugosc)
{
    srand(time(NULL));

    for(int i=0; i<dlugosc; i++)
        tablica[i] = (rand())/2+5;
}

template <class typ>
bool Sprawdz_czy_posortowano(typ *tablica, int dlugosc)
{
    for(int i=0; i<dlugosc-1; i++)
        if(tablica[i+1] < tablica[i])
            return false;
    return true;
}


template <class typ>
void Test(typ *tablica, int dlugosc, double &scalanie, double &szybkie, double &introspektywne)
{
    clock_t start, stop;
    double roznica;
    int i;
    typ* pom=new typ [dlugosc];

    for(int i=0; i<dlugosc; i++)
        tablica[i] = pom[i];

    start=clock(); // mierzymy czas dzialania sortowania przez scalanie
    sortowanie_scalanie<typ>(pom, 0, dlugosc-1);
    stop=clock();
    if(!Sprawdz_czy_posortowano(pom, dlugosc))
    {
        cout<<"ERROR!";
        return;
    }
    roznica=(stop-start)/(double)CLOCKS_PER_SEC;
    scalanie=scalanie+roznica;

    for(int i=0; i<dlugosc; i++)
        tablica[i] = pom[i];

    start=clock(); // mierzymy czas dzialania sortowania przez scalanie
    sortowanie_szybkie<typ>(pom, 0, dlugosc-1);
    if(!Sprawdz_czy_posortowano(pom, dlugosc))
    {
        cout<<"ERROR!";
        return;
    }
    stop=clock();
    // if(!Sprawdz_czy_posortowano(pom, dlugosc)){cout<<"ERROR!"; return;}
    roznica=(stop-start)/(double)CLOCKS_PER_SEC;
    szybkie=szybkie+roznica;

    for(int i=0; i<dlugosc; i++)
        tablica[i] = pom[i];

    start=clock(); // mierzymy czas dzialania sortowania przez scalanie

    sortowanie_introspektywne<typ>(pom, dlugosc);
    if(!Sprawdz_czy_posortowano(pom, dlugosc))
    {
        cout<<"ERROR!";
        return;
    }
    stop=clock();
    // if(!Sprawdz_czy_posortowano(pom, dlugosc)){cout<<"ERROR!"; return;}
    roznica=(stop-start)/(double)CLOCKS_PER_SEC;
    introspektywne=introspektywne+roznica;

    delete [] pom;

}


