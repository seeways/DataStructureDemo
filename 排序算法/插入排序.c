#include <stdio.h>

void insertSort(int arr[], int n)
{
	int temp, i, j;
	for (i = 1; i < n; ++i)
	{
		temp = arr[i];
		j = i-1;
		while(j>=0&&temp<arr[j])
		{
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1] = temp;

	}
}

int main(int argc, char const *argv[])
{
	int arr[7] = {2,3,4,1,7,5,6};
	insertSort(arr, 7);

	for (int i = 0; i < 7; ++i)
	{
		printf("%d ", arr[i]);
	}
	getchar();
	return 0;
}