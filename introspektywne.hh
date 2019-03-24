#include <cmath>

template <class typ>
void sortowanie_introspektywne (typ *tablica, int dlugosc);

template <class typ>
void IntroSort (typ *tablica, int N, int M);

template <class typ>
int Partition (typ *tablica, int L, int R);

template <class typ>
void MedianOfThree (typ *tablica, int &L, int &R);

template <class typ>
void Exchange (typ *tablica, int i, int j);

template <class typ>
void Heap_Sort (typ *tablica, int N);

template <class typ>
void Heapify (typ *tablica, int i, int N);

template <class typ>
void Insertion_Sort (typ *tablica, int N);
