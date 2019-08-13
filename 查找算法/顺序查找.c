#include <stdio.h>
#include <stdlib.h>


// 查找函数
int Search(int arr[], int n, int key)
{
	while(key != arr[n-1])
		n--;
	return n;
}


int main(int argc, char const *argv[])
{
	// 一个顺序表
	int arr[7] = {1,2,3,4,5,6,7};
	for (int i = 0; i < 7; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	// 输入一个要查询的关键字
	int key;
	printf("input key:\n");
	scanf("%d", &key);

	// 查找关键字在数组中的下标
	int location = Search(arr,7,key);

	if (location < 0)
	{
		printf("Search Failed! \n");
	}
	else{
		printf("array index: %d\n", n);
	}
	
	system("pause");
	return 0;
}

