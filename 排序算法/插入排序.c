#include <stdio.h>

void insertSort(int arr[], int n)
{
    int temp, i, j;
    for (i = 1; i < n; ++i)
    {
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;
        for (int i = 0; i < n; ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int arr[8] = {3, 1, 7, 5, 2, 4, 9, 6};
    insertSort(arr, 8);
    getchar();
    return 0;
}