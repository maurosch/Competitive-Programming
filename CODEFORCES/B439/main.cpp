#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void merge(long long* a, long long n);
void mergesort(long long* a, long long n);

int main()
{
  unsigned long long MinimasHoras = 0;
  long long n;
  long long* MateriasConSusHoras;
  long long x;
  cin >> n >> x;
  MateriasConSusHoras = new long long[n];
  for (long long i = 0; i < n; i++)
  {
    cin >> MateriasConSusHoras[i];
  }

  mergesort(MateriasConSusHoras, n);
  long long indice = 0;
  while( indice < n)
  {
    MinimasHoras += MateriasConSusHoras[indice] * x;
    if (x > 1)
    {
      x--;
    }
    indice++;
  }
  delete[] MateriasConSusHoras;
  std::cout << MinimasHoras;
  return 0;
}


void merge(long long* a, long long n)
{
  long long* b = a + n/2;
  long long c[n];
  long long m = n - n/2;
  long long i = 0, j = 0;
   while(i < n/2 && j < m) {
     if(a[i] > b[j]) {
       c[i+j] = b[j];
       j++;
     }
     else {
       c[i+j] = a[i];
       i++;
     }
   }
   for(; i < n/2; i++) c[i+j] = a[i];
   for(; j < m; j++) c[i+j] = b[j];
   for(i = 0; i < n; i++) a[i] = c[i];
}

void mergesort(long long* a, long long n) {
  if(n > 10) {
    mergesort(a, n/2);
    mergesort(a + n/2, n - n/2);
    merge(a, n);
  }
  else {
    // Insertion.
    for(long long i = 0; i < n; i++) {
      for(long long j = i; j > 0 && a[j] < a[j-1]; j--) {
        long long aux = a[j];
        a[j] = a[j-1];
        a[j-1] = aux;
      }
    }
  }
}
