#include <stdio.h>
#include <stdlib.h>


// 二分查找函数
int BST(int arr[], int n, int key)
{
	int low = 0;
	int high = n-1;
	int mid = 0;
	while(low <= high)
	{
		mid = (low+high)/2;
		if (arr[mid] == key) // mid == key已经找到了
		 {
		 	return mid;
		 } 
		 else if(arr[mid]>key) // mid大于key，说明在低区，high = mid-1;
		 {
		 	
		 	high = mid-1;
		 }
		 else // 反之，说明在高区，low = mid+1;
		 {
		 	low = mid+1;
		 }
		
	}
	return 0;
}


int main(int argc, char const *argv[])
{
	// 一个顺序表
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	// 输入一个要查询的关键字
	int key;
	printf("input key:\n");
	scanf("%d", &key);

	// 查找关键字在数组中的下标
	int location = BST(arr,10,key);
	if (location == 0)
	{
		printf("Search Failed! \n");
	}
	else
	{
		printf("array index: %d\n", location);
	}
	
	system("pause");
	return 0;
}