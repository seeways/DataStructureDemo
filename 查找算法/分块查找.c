#include <stdio.h>
#include <stdlib.h>


struct index//定义块的结构
{
    int key; // 定义最大值
    int start; // 定义开始位置
} newIndex[3];



int cmp(const void *a, const void *b)
{
    return (*(struct index *)a).key > (*(struct index *)b).key ? 1 : -1;
}

// 查找函数
int Search(int arr[], int key)
{
    int i = 0;
    int startValue = 0;

    while (i < 3 && key > newIndex[i].key) //确定在哪个块中，遍历每个块，确定key 在哪个块中
    {
        i++;
    }
    if (i >= 3) //大于分得的块数，则返回-1
    {
        return -1;
    }

    startValue = newIndex[i].start; //startValue 等于块范围的起始值
    while (startValue < startValue + 5 && arr[startValue] != key)
    {
        startValue++;
    }
    if (startValue > startValue + 5) //如果大于块范围的结束值，则说明没有要查找的数
    {
        return -1;
    }

    return startValue;
}


int main(int argc, char const *argv[])
{
    // int arr[3][5] = {{11,2,5,8,9},{17,16,18,22,33},{99,66,77,88,55}};
    int arr [15] = {11, 2, 5, 8, 9, 22, 33, 99, 66, 77, 17, 16, 18, 88, 55};
    for (int i = 0; i < 15; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");


    int start = 0;
    //确认模块的起始值和最大值
    for (int i = 0; i < 3; ++i)
    {
        newIndex[i].start = start;
        start += 5;
        for (int j = newIndex[i].start;  j <= start; ++j)
        {
            if (newIndex[i].key < arr[j])
            {
                newIndex[i].key = arr[j];
            }
        }
    }

    //对结构体按照key 值进行排序
    qsort(newIndex, 3, sizeof(newIndex[0]), cmp);

    // 输入一个要查询的关键字
    int key;
    printf("input key:\n");
    scanf("%d", &key);

    // 查找关键字在数组中的下标
    int location = Search(arr, key);

    if (location < 0)
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

