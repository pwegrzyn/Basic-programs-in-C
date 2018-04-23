/*Patryk Wegrzyn
 * Programowanie Imperatywne*/

//-----KOMPILACJA: gcc -std=c99 zad1.c -o zad1 -lm --------

#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//struktura odpowiadaja liczbie zespolonej
typedef struct complex{
    double re;
    double im;
};

//deklaracje
double getModulus(struct complex);
double power(double, int);
int compare(const void*, const void*);

//main
int main(void){

    //wczytaj rozmiar tablicy, wiekszy od 0
    int n;
    do{
        printf("Podaj rozmiar tablicy n: ");
        scanf("%d", &n);
    }while(n <= 0);
    
    //zaalokuj dynamicznie tablice o wczytanym rozmiarze
    struct complex* A = (struct complex*)malloc(n * (sizeof(struct complex)));
    if(A == NULL){
        printf("Memory error.\n");
        return 1;
    }
    
    //uzupelnij tablice losowymi liczbami zespolonymi z przedzialu (-10,10)
    srand48(time(NULL));
    for(int i=0; i<n; i++){
        (A[i]).re = (drand48() - drand48()) * 10.0;
        (A[i]).im = (drand48() - drand48()) * 10.0;
    }
    
    printf("\nPrzed posortowaniem: ");
    for(int i=0; i<n; i++)
        printf("\n%d. re = %f, im = %f, mod = %f", i, A[i].re, A[i].im, getModulus(A[i]));
    
    qsort(A, n, sizeof(struct complex), compare);
    
    printf("\nPo posortowaniu: ");
    for(int i=0; i<n; i++)
        printf("\n%d. re = %f, im = %f, mod = %f", i, A[i].re, A[i].im, getModulus(A[i]));
    printf("\n");
    
    //zwolnij pamiec
    free(A);
    return 0;

}


//funkacja zwraca modul liczby zespolonej
double getModulus(struct complex num){
    return sqrt(power(num.re, 2) + power(num.im, 2));
}

//funkcja liczy naturalna potege liczby
double power(double a, int b){
    double pow = 1.0;
    while(b > 0){
        pow *= a;
        b--;
    }
    return pow;
}

//komparator do qsorta
int compare(const void* a, const void* b){
    struct complex* c = (struct complex*)a;
    struct complex* d = (struct complex*)b;
    double eps = 1e-6;
    if(fabs(getModulus(*c) - getModulus(*d)) < eps) return 0;
    else if(getModulus(*c) < getModulus(*d)) return -1;
    else return 1;
}