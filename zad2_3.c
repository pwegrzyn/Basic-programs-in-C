/*Patryk Wegrzyn
PI Laboratorium 2017*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //metoda Gausa
    int i, j, k, x, n;
    float A[20][20];
    float sum=0.0;
    float B[10];    //rozwazania
    int a;

    printf("Podaj rzad rownania: ");
    scanf("%d",&n);

    printf("\nPodaj elementy macierzy rzedami:\n");

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("A[%d][%d] : ", i,j);
            scanf("%f",&A[i][j]);
        }
    }

    printf("\nPodaj elemty kolumny wyrazow wolnych:\n");

    for(int i=1; i<=n; i++)
    {
        printf("B[%d] : ", i);
        scanf("%f", &A[i][n+1]);
    }

    //glowana czesc
    for(i=1; i<n+1; i++)
    {
        for(j=1; j<n+1; j++)
        {
            if(j>i)
            {
                a=A[j][i]/A[i][i];
                for(k=1; k<n+2; k++)
                {
                    x = A[i][k] * a;
                    A[j][k] -= x;
                }
            }
        }
    }

    B[n]=A[n][n+1]/A[n][n];

    for(j=n-1; j>0; j--)
    {
        sum=0;
        for(i=j+1; i<n+1; i++)
        {
            sum += A[j][i]*B[i];
        }
        B[j]= A[j][n+1] - sum;
        B[j] /= A[j][j];
    }

    printf("\nRozwiazanie: ");
    for(i=1; i<n+1; i++)
    {
        printf("\nx%d = %f", i ,B[i]);
    }
    printf("\n");

    return 0;
}
