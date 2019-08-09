#include <stdio.h>

void selectSort(int arr[], int n)
{
	int i,j,k;
	int temp;
	for (i = 0; i < n; ++i)
	{
		k = i;
		for (j = i+1; j < n; ++j)
		{
			if (arr[k]>arr[j])
			{
				k=j;
			}
		}
		temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
	}

}


int main(int argc, char const *argv[])
{
	int n = 7;
	int arr[7] = {2,3,4,1,7,5,6};
	selectSort(arr, n);

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	getchar();
	return 0;
}