/* Patryk Wegrzyn, PI 2017*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 101

int main()
{
    //tworzenie tablicy i wypelnianie losowymi liczbami
    double t1[N];
    srand(time(NULL));
    for(int i=0; i<N; i++){
        t1[i]=((float)rand()/(float)(RAND_MAX)*(112-55));
        t1[i]+=55;
    }

    //tworzenie drugiej tablicy i wypelnienie jej srednimi
    double t2[(N+1)/2];
    int j=0;
    for(int i=0; i<(N+1)/2; i++){
        t2[i]=(t1[j]+t1[j+1])/2;
        j+=2;
    }
    if(N%2==1) t2[((N+1)/2)-1]=t1[N-1];   //jesli N nieprzyste to przepisz ostatni element

    //wypisanie tablic
    for(int i=0; i<N; i++){
        printf("%f", t1[i]);
        printf("\n");
    }
    printf("\n\n");
    for(int i=0; i<(N+1)/2; i++){
        printf("%f", t2[i]);
        printf("\n");
    }

    return 0;
}
