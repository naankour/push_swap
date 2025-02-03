#include <stdio.h>
#include <stdlib.h>

// Fonction pour trouver la médiane
static int	find_median(int	*arr, int size)
{
	return (arr[size / 2]);
}

// Fonction pour trier un tableau (Bubble Sort pour la simplicité)
void bubble_sort(int *arr, int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fonction pour afficher le tableau
void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Programme principal pour tester find_median
int main()
{
    int arr[] = {2, 1, 4, 5, 7, 3, 0}; // Liste non triée
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Tableau avant tri : ");
    print_array(arr, size);

    // Trier avant de trouver la médiane
    bubble_sort(arr, size);

    printf("Tableau après tri : ");
    print_array(arr, size);

    // Trouver la médiane
    int median = find_median(arr, size);
    printf("Médiane trouvée : %d\n", median);

    return 0;
}
