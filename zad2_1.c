/*Patryk Wegrzyn
PI Laboratorium 2017*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 10

void fillArray(int A[N][N], int n);
int sumDiag(int A[N][N], int n);
int sumUnderDiag(int A[N][N], int n);
int sumArray(int A[N][N], int n);
void matrixProduct(int t1[N][N], int t2[N][N], int t3[N][N], int n);
void printArray(int A[N][N], int n);

int main(void)
{
        int t1[N][N];
        int t2[N][N];
        int t3[N][N];

        fillArray(t1, N);
        fillArray(t2, N);

        printf("Pierwsza tablica: \n");
        printArray(t1, N);

        printf("\n");

        printf("Druga tablica: \n");
        printArray(t2, N);

        printf("\nSuma na przekatnej pierwszej tablicy: %d\n\n", sumDiag(t1, N));
        printf("Suma pod przekatna pierwszej tablicy: %d\n\n", sumUnderDiag(t1, N));
        printf("Suma wszystkich elementow pierwszej talicy: %d\n\n", sumArray(t1, N));

        matrixProduct(t1, t2, t3, N);

        printf("Iloczyn macierzy: \n");
        printArray(t3, N);

        return 0;
}

void fillArray(int A[N][N], int n)
{
        for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                        A[i][j] = (rand()%33) + 12;
        return;
}

int sumDiag(int A[N][N], int n)
{
        int sum = 0;
        for(int i=0; i<n; i++)
                sum += A[i][i];
        return sum;
}

int sumUnderDiag(int A[N][N], int n)
{
        int sum = 0;
        int counter = n;
        for(int i=0; i<n; i++){
                for(int j=0; j<(n - counter); j++){
                        sum += A[i][j];
                }
                counter--;
        }
        return sum;
}

int sumArray(int A[N][N], int n)
{
        int sum = 0;
        for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                        sum += A[i][j];
        return sum;
}

void matrixProduct(int t1[N][N], int t2[N][N], int t3[N][N], int n)
{
        //fill output array with zeros
        for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                        t3[i][j] = 0;

        //matrix product
        for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                        for(int k=0; k<n; k++)
                                t3[i][j] += t1[i][k] * t2[k][j];
        return;
}

void printArray(int A[N][N], int n)
{
        for(int i=0; i<n; i++){
                for(int j=0; j<n; j++)
                        printf("%d ", A[i][j]);
                 printf("\n");
        }
}
