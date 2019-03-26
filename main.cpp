#include <iostream>
#include "testy.cpp"
#include<fstream>
#include <iomanip>


int main(){
   int i, j;
   int ilosc_testow=100;
  double scalanie=0, szybkie=0, introspektywne=0;
  int ILOSC[5]={10000, 50000, 100000, 500000,1000000};

  ofstream plik;
  plik.open("Wyniki_testow.txt", ios::out | ios::app);

  plik.precision(6);
  plik.setf(ios::fixed);
  plik.setf(ios::showpoint);


  for(j=0; j<5; j++){
      int* tablica=new int [ILOSC[j]];
      plik<<endl<<"SORTOWANIE "<<ILOSC[j]<<" ELEMENTOW"<<endl;
      plik<<endl<<"LOSOWA"<<endl;
    for(i=0; i<ilosc_testow; i++){
      Losowa<int>(tablica, ILOSC[j]);
      Test<int>(tablica, ILOSC[j], scalanie,szybkie, introspektywne);
    }
    plik<<"SCALANIE: "<<scalanie<<endl;
    plik<<"SZYBKIE: "<<szybkie<<endl;
    plik<<"INTROSPEKTYWNE: "<<introspektywne<<endl;
    scalanie=0, szybkie=0,   introspektywne=0;

    plik<<endl<<"ODWROTNA"<<endl;
    for(i=0; i<ilosc_testow; i++){
      Odwrotnie_posortowana<int>(tablica, ILOSC[j]);
      Test<int>(tablica, ILOSC[j], scalanie, szybkie, introspektywne);
    }
    plik<<"SCALANIE: "<<scalanie<<endl;
    plik<<"SZYBKIE: "<<szybkie<<endl;
    plik<<"INTROSPEKTYWNE: "<<introspektywne<<endl;
    scalanie=0, szybkie=0,   introspektywne=0;

    plik<<endl<<"25% POSORTOWANA"<<endl;
    for(i=0; i<ilosc_testow; i++){
      Czesciowo_posortowana<int>(tablica, ILOSC[j],25);
      Test<int>(tablica, ILOSC[j], scalanie, szybkie, introspektywne);
    }
    plik<<"SCALANIE: "<<scalanie<<endl;
    plik<<"SZYBKIE: "<<szybkie<<endl;
    plik<<"INTROSPEKTYWNE: "<<introspektywne<<endl;
    scalanie=0, szybkie=0,   introspektywne=0;

    plik<<endl<<"50% POSORTOWANA"<<endl;
    for(i=0; i<ilosc_testow; i++){
    Czesciowo_posortowana<int>(tablica, ILOSC[j],50);
    Test<int>(tablica, ILOSC[j], scalanie, szybkie, introspektywne);
    }
    plik<<"SCALANIE: "<< scalanie<<endl;
    plik<<"SZYBKIE: "<< szybkie<<endl;
    plik<<"INTROSPEKTYWNE: "<< introspektywne<<endl;
    scalanie=0, szybkie=0,   introspektywne=0;

    plik<<endl<<"75% POSORTOWANA"<<endl;
    for(i=0; i<ilosc_testow; i++){
      Czesciowo_posortowana<int>(tablica, ILOSC[j],75);
      Test<int>(tablica, ILOSC[j], scalanie, szybkie, introspektywne);
    }
    plik<<"SCALANIE: "<< scalanie<<endl;
    plik<<"SZYBKIE: "<< szybkie<<endl;
    plik<<"INTROSPEKTYWNE: "<< introspektywne<<endl;
    scalanie=0, szybkie=0,   introspektywne=0;

    plik<<endl<<"95% POSORTOWANA"<<endl;
    for(i=0; i<ilosc_testow; i++){
      Czesciowo_posortowana<int>(tablica, ILOSC[j],95);
      Test<int>(tablica, ILOSC[j], scalanie, szybkie, introspektywne);
    }
    plik<<"SCALANIE: "<< scalanie<<endl;
    plik<<"SZYBKIE: "<< szybkie<<endl;
    plik<<"INTROSPEKTYWNE: "<< introspektywne<<endl;
    scalanie=0, szybkie=0,   introspektywne=0;

    plik<<endl<<"99% POSORTOWANA"<<endl;
    for(i=0; i<ilosc_testow; i++){
      Czesciowo_posortowana<int>(tablica, ILOSC[j],99);
      Test<int>(tablica, ILOSC[j], scalanie, szybkie, introspektywne);
    }
    plik<<"SCALANIE: "<< scalanie<<endl;
    plik<<"SZYBKIE: "<< szybkie<<endl;
    plik<<"INTROSPEKTYWNE: "<< introspektywne<<endl;
    scalanie=0, szybkie=0,   introspektywne=0;

    plik<<endl<<"99,7% POSORTOWANA"<<endl;
    for(i=0; i<ilosc_testow; i++){
      Czesciowo_posortowana<int>(tablica, ILOSC[j],99.7);
      Test<int>(tablica, ILOSC[j], scalanie, szybkie, introspektywne);
    }
    plik<<"SCALANIE: "<< scalanie<<endl;
    plik<<"SZYBKIE: "<< szybkie<<endl;
    plik<<"INTROSPEKTYWNE: "<< introspektywne<<endl;
    scalanie=0, szybkie=0,introspektywne=0;

    cout << "Etap " << j << " elo" << endl;
       delete [] tablica;
  };

    plik << endl;
    plik <<"----------------" << endl;
    plik << "KONIEC" <<endl<<endl;
    plik.close();

  return 0;
}
