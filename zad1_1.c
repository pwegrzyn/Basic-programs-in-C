/* Patryk Wegrzyn, PI 2017*/

#include<stdio.h>
#include<string.h>
#define N 100

void swap (char*, char*);

int main()
{
    // deklaracja danych
    int y,x,z, r, t;
    char num1[N];
    char num2[N];
    int t1[N]={0};
    int t2[N]={0};
    int t3[N]={0};

    printf("Podaj pierwsza liczbe: ");
    gets(num1);
    printf("Podaj druga liczbe: ");
    gets(num2);

    swap (num1, num2);  //zamieni jesli konieczne

    t=strlen(num1); //pobierz dlugosci
    r=strlen(num2);


    for(int i=0; i<num1[i]; i++)  //zamiana ze znaku na inta
    {
        t1[i]=num1[--t];
		t1[i]-='0';
    }

    for(int i=0; i<num2[i]; i++)    //zamiana ze znaku na inta
    {
        t2[i]=num2[--r];
		t2[i]-='0';
    }

    t=strlen(num1); //pobierz dlugosci
    r=strlen(num2);


    for(int i=0; i<=r; i++) //Glowny zestaw instrukcji odpowiedzialny za obliczenie iloczynu
    {
        z=0;
        x=0;
        for(int j=i; j<=(2*t-1); j++)
        {
            y=t3[j]+t2[i]*t1[x];
            y+=z;
            t3[j]=y%10;
            z=y/10; //przeniesienie
            x++;
        }
    }

    printf("\nIloczyn wczytanych liczb wynosi: ");

    for(int i=(2*t-1); i>=0; i--)    //wypisanie wyniku
    {
        if(i>t)
        {
            if(t3[i]==0)
            //idz dalej bez wypisania bo zero bez znaczenia
            continue;
        }
        printf("%d",t3[i]);
    }
    printf("\n");
}

void swap (char A[], char B[])
{
    int r=strlen(A);
    int t=strlen(B);
    char temp[N];

    if(t>r)    //sprawdza ktora z liczb jest wieksza
    {
        strcpy(temp,A);
        strcpy(A,B);
        strcpy(B,temp);
    }
}
