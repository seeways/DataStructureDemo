#include <stdio.h>


void bubleSort(int arr[], int n)
{
    int i, j, flag;
    int temp;
    for (i = n - 1; i > 0; --i)
    {
        flag = 0;
        for (j = 1; j <= i; ++j)
        {
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) return;
    }
}

int main(int argc, char const *argv[])
{
    int arr[7] = {2, 3, 4, 1, 7, 5, 6};
    bubleSort(arr, 7);

    for (int i = 0; i < 7; ++i)
    {
        printf("%d ", arr[i]);
    }
    getchar();
    return 0;
}