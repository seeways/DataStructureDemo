#include <stdio.h>
#include <stdlib.h>

void insert(int arr[], int temp[], int n)
{
    int first, final, k;
    first = 0; // 记录temp数组中最小值位置
    final = 0; // 记录temp数组中最大值位置
    temp[0] = arr[0];

    for (int i = 1; i < n; i ++)
    {
        // 待插入元素比最小的元素小
        if (arr[i] < temp[first])
        {
        	// 最小值的位置更新为数组末位, 如首次进入 7mod8=7
            first = (first - 1 + n) % n;
            // 待插入元素变为最小元素
            temp[first] = arr[i];
        }
        // 待插入元素比最大元素大
        else if (arr[i] > temp[final])
        {
        	// 最大值的位置更新为数组下一位，如首次进入 9mod8=1
            final = (final + 1 + n) % n;
            // 待插入元素变为最大元素
            temp[final] = arr[i];
        }
        // 插入元素比最小大，比最大小
        else
        {
        	// 最大值的位置更新到下一位
            k = (final + 1 + n) % n;
            //当插入值比当前值小时，需要移动当前值的位置
            while (temp[((k - 1) + n) % n] > arr[i])
            {
                temp[(k + n) % n] = temp[(k - 1 + n) % n];
                k = (k - 1 + n) % n;
            }
            //插入该值
            temp[(k + n) % n] = arr[i];
            //因为最大值的位置改变，所以需要实时更新final的位置
            final = (final + 1 + n) % n;
        }
    }
    // 将排序记录复制到原来的顺序表里
    for (k = 0; k < n; k ++)
    {
        arr[k] = temp[(first + k) % n];
    }
}


int main(int argc, char const *argv[])
{
    int arr[8] = {3, 1, 7, 5, 2, 4, 9, 6};
    int temp[8];
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    insert(arr, temp, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    getchar();
    return 0;
}