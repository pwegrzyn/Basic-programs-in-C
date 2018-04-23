/* Patryk Wegrzyn, PI 2017*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

//Declarations
bool checkIfNarc(int, int);
int countDigits(int);
int changeBase(int, int);
int power(int, int);

int main()
{
    int b=10;
    int x=1;
    int y=INT_MAX;
    do
    {
        printf("Podaj podstawe systemu (mozliwe 2-10): \n");
        scanf("%d", &b);
    }while(b>10 || b<2);

    do
    {
        printf("Podaj lewy koniec przedzialu (minimum 1): ");
        scanf("%d", &x);
    }while(x<1);

    do
    {
        printf("Podaj prawy koniec przedzialu (maksimum ok 2 miliardy): ");
        scanf("%d", &y);
    }while(y<1);

    printf("W zadanym przedziale znaleziono nastepujace liczby Armstronga w danym systemie: \n");
    for(int i=x; i<y; i++)
    {
        if(checkIfNarc(i, b)) printf("%d\n", i);
    }

    return 0;
}

//checks if the passed number n in an narcisstic number in base b
bool checkIfNarc(int n, int b)
{
    int newNum = changeBase(n, b);
    int d=countDigits(newNum);
    int sum=0;
    int a=0;
    while(newNum > 0)
    {
        a=newNum%10;
        sum+=power(a, d);
        newNum/=10;
    }
    if(sum == n) return true;
    return false;
}

//returns the number of digits in a given number n
int countDigits(int n)
{
    int counter=0;
    while(n>0)
    {
        n/=10;
        counter++;
    }
    return counter;
}

//converts the passed number n from decimal to base b
//(only works for base2 - base10
int changeBase(int n, int b)
{
    int remainder;
    int res = 0, i = 1;
    while(n != 0)
    {
        remainder = n%b;
        n = n/b;
        res = res + (remainder*i);
        i = i*10;
    }
    return res;
}

//basic power function, return a^d
int power(int a, int d)
{
    int res = 1;
    while(d>0)
    {
        res*=a;
        d--;
    }
    return res;
}
