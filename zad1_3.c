/* Patryk Wegrzyn, PI 2017*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N1 10000
#define N2 15000

void zamiana(int *a, int *b);
void odwroc(int*, int);
void bubbleSort(int*, int);
int one_two(int*, int, int*, int, int*);
void wymien_tablice(int*, int*, int);
int deleteDuplicates(int*, int);

int main()
{
    int t1[N1]; //deklaracje tablic
    int t2[N2];
    int t3[N1+N2];
    srand(time(NULL));

    for(int i=0; i<N1; i++) //wypelnianie tablic losowymi wartosciami z przedzialu od 1 do 10
        t1[i]=(rand()%10)+1;
    for(int i=0; i<N2; i++)
        t2[i]=(rand()%10)+1;
    for(int i=0; i<N1+N2; i++)
        t3[i]=0;

    int a = 5;      //testowanie funkcji zamiana
    int b = 6;
    printf("a= %d", a);
    printf("\n");
    printf("b= %d", b);
    printf("\n");
    int*x=&a;
    int*y=&b;
    zamiana(x,y);
    printf("Zamiana...\n");
    printf("a= %d", a);
    printf("\n");
    printf("b= %d", b);
    printf("\n");
    printf("\n");

    bubbleSort(t1, N1);     //sortujemy tablice
    bubbleSort(t2, N2);

    //testowanie funkcji one_two
    printf("Pierwsza tablica: \n");
    for(int i=0; i<N1; i++)
    {
        printf("%d", t1[i]);
        printf("\n");
    }
    printf("\n");
    printf("Druga tablica: \n");
    for(int i=0; i<N2; i++)
    {
        printf("%d", t2[i]);
        printf("\n");
    }

    int first=deleteDuplicates(t1,N1);
    int second=deleteDuplicates(t2,N2);
    int val = one_two(t1, first, t2, second, t3);

    printf("\n");

    printf("Scalona tablica: \n");
    for(int i=0; i<val; i++)
    {
        printf("%d", t3[i]);
        printf("\n");
    }

    return 0;
}

void  zamiana(int *a, int *b)   //zamienia wartosci argumentow
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void odwroc(int A[], int n) //odwraca tablice
{
    int end = n - 1;
    for(int i=0; i< n/2; i++)
    {
        int *x=&A[i];
        int *y=&A[end];
        zamiana(x, y);
        end--;
    }
}

void bubbleSort(int A[], int n)
{
 int temp;
  for (int i = 0 ; i < ( n - 1 ); i++)
  {
    for (int j = 0 ; j < n - i - 1; j++)
    {
      if (A[j] > A[j+1])
      {
        //zamieniamy
        temp=A[j];
        A[j]=A[j+1];
        A[j+1] = temp;
      }
    }
  }
}

int one_two(int t1[], int n1, int t2[], int n2, int t3[]) {     //scala tablice pozbywajac sie duplikatow

  int i=0;
  int j=0;
  int k=0;

  while(i < n1 + n2) {
    if (j < n1 && k < n2) {
      if (t1[j] < t2[k]) {
        t3[i] = t1[j];
        j++;
      }
      else {
        t3[i] = t2[k];
        k++;
      }
      i++;
    }
    else if (j == n1) {
      while ( i < n1 + n2) {
        t3[i] = t2[k];
        k++;
        i++;
      }
    }
    else {
      while ( i < n1 + n2) {
        t3[i] = t1[j];
        j++;
        i++;
      }
    }
  }

  int ret=deleteDuplicates(t3, n1+n2);
  return ret;
}


void wymien_tablice(int A1[], int A2[], int n)      //wymienia zawartosciami dwie tablice o tym samym rozmiarze
{
    int tmp;
    for(int i=0; i<n; i++)
    {
        tmp=A1[i];
        A1[i]=A2[i];
        A2[i]=tmp;
    }
}

int deleteDuplicates(int A[], int n)    //zwraca dlugosc tablicy po usunieciu duplikatow
{
     for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n;) {
         if (A[j] == A[i]) {
            for (int k = j; k < n; k++) {
                A[k] = A[k + 1];    //przesuwamy
            }
            n--;
         } else
            j++;
      }
   }
   return n;
}
