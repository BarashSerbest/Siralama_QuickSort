#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void takasEt(int* x, int* y) 
{
    int gecici = *x;
    *x = *y;
    *y = gecici;
}

int bolme(int dizi[], int sol, int sag) 
{
    int pivot = dizi[sag];
    int j, i = (sol - 1);

    for (j = sol; j <= sag - 1; j++) 
	{
        if (dizi[j] <= pivot)
		{
            i++;
            takasEt(&dizi[i], &dizi[j]);
        }
    }
    takasEt(&dizi[i + 1], &dizi[sag]);
    return (i + 1);
}

void quickSort(int dizi[], int sol, int sag) 
{
    if (sol < sag) 
	{
        int pi = bolme(dizi, sol, sag);
        quickSort(dizi, sol, pi - 1);
        quickSort(dizi, pi + 1, sag);
    }
}

int main() 
{
    int i, dizi[10000];

    srand(time(NULL));
    for (i = 0; i < 10000; i++) 
	{
        dizi[i] = rand() % 10000 + 1;
    }

    printf("Orijinal dizi: ");
    for (i = 0; i < 10000; i++) 
	{
        printf("%d ", dizi[i]);
    }

    quickSort(dizi, 0, 9999);

    printf("\n\nSiralanmis dizi:\n");
    for (i = 0; i < 10000; i++) 
	{
        printf("%d ", dizi[i]);
    }

    return 0;
}

