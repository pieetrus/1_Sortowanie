#include"introspektywne.hh"

template <class typ>
void sortowanie_introspektywne(typ *tablica, int dlugosc)
{
  IntroSort(tablica,dlugosc,(int)floor(2*log(dlugosc)/M_LN2));
  Insertion_Sort(tablica,dlugosc);
}

template <class typ>
void IntroSort (typ *tablica, int N, int M)
{
  int i;
  if (M<=0)
  {
    Heap_Sort(tablica,N);
    return;
  }
  i=Partition(tablica,0,N);
  if (i>9)
    IntroSort(tablica,i,M-1);
  if (N-1-i>9)
    IntroSort(tablica+i+1,N-1-i,M-1);
}

template <class typ>
int Partition (typ *tablica, int L, int R)
{
  int i, j;
  if (R>=3)
    MedianOfThree(tablica,L,R);
  for (i=L, j=R-2; ; )
  {
    for ( ; tablica[i]<tablica[R-1]; ++i);
    for ( ; j>=L && tablica[j]>tablica[R-1]; --j);
    if (i<j)
      Exchange(tablica,i++,j--);
    else break;
  }
  Exchange(tablica,i,R-1);
  return i;
}

template <class typ>
void MedianOfThree (typ *tablica, int &L, int &R)
{
  if (tablica[++L-1]>tablica[--R])
    Exchange(tablica,L-1,R);
  if (tablica[L-1]>tablica[R/2])
    Exchange(tablica,L-1,R/2);
  if (tablica[R/2]>tablica[R])
    Exchange(tablica,R/2,R);
  Exchange(tablica,R/2,R-1);
}

template <class typ>
void Exchange (typ *tablica, int i, int j)
{
  typ temp;
  temp=tablica[i];
  tablica[i]=tablica[j];
  tablica[j]=temp;
}

template <class typ>
void Heap_Sort (typ *tablica, int N)
{
  int i;
  for (i=N/2; i>0; --i)
    Heapify(tablica-1,i,N);
  for (i=N-1; i>0; --i)
  {
    Exchange(tablica,0,i);
    Heapify(tablica-1,1,i);
  }
}

template <class typ>
void Heapify (typ *tablica, int i, int N)
{
  int j;
  while (i<=N/2)
  {
    j=2*i;
    if (j+1<=N && tablica[j+1]>tablica[j])
      j=j+1;
    if (tablica[i]<tablica[j])
      Exchange(tablica,i,j);
    else break;
    i=j;
  }
}

template <class typ>
void Insertion_Sort (typ *tablica, int N)
{
  int i, j;
  typ temp;
  for (i=1; i<N; ++i)
  {
    temp=tablica[i];
    for (j=i; j>0 && temp<tablica[j-1]; --j)
      tablica[j]=tablica[j-1];
    tablica[j]=temp;
  }
}
