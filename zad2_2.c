/*Patryk Wegrzyn
PI Laboratorium 2017*/

#include <stdio.h>
#include <stdlib.h>

int distOk(int i, int j, int k, int l, int r);

int main(void)
{
    int r, n;

    //read first line
    scanf("%d", &n);
    scanf("%d", &r);

    //dynamically alocate 2D array size n
    int *F[n];
    for (int i=0; i<n; i++)
         F[i] = (int *)malloc(n * sizeof(int));

    int *W[n];
    for (int i=0; i<n; i++)
         W[i] = (int *)malloc(n * sizeof(int));

    //read 2D array from the input
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            scanf("%d", &(F[i][j]));
    }

    //filling the W output array with zeros
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            W[i][j] = 0;
        }
    }

    //filling the W table according to the algorithm
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                for(int l=0; l<n; l++)
                {
                    if(distOk(i, j, k, l, r) == 1) W[i][j] += F[k][l];
                }
            }
        }
    }

    //print array
    printf("\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ", W[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int distOk(int i, int j, int i2, int j2, int r)
{
    int a = abs(i - i2);
    int b = abs(j - j2);
    int dist = (a>b) ? a : b;
    if(dist <= r) return 1;
    else return 0;
}


