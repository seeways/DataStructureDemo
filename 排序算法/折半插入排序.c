#include <stdio.h>

void BInsertSort(int arr[], int n)
{
    int low = 0, high = 0, mid;
    int temp = 0;
    for (int i = 1; i < n; i++)
    {
        low = 0;
        high = i - 1;
        temp = arr[i];

        //采用折半查找法判断插入位置，最终变量 low 表示插入位置
        while (low <= high)
        {
            mid = (low + high) / 2; // 取上
            // 中位 > 顺序位，则取低位，反之取高位
            if (arr[mid] > temp)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        //有序表中插入位置后的元素统一后移
        for (int j = i; j > low; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[low] = temp; //插入元素

        // 打印排序后的数组
        printf("%d: ", i);
        for(int k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

}


int main(int argc, char const *argv[])
{
    int arr[8] = {3, 1, 7, 5, 2, 4, 9, 6};
    BInsertSort(arr, 8);
    getchar();
    return 0;
}

