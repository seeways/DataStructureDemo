#include <stdio.h>
#include <stdlib.h>

typedef struct BitNode
{
    int data;
    struct BiTNode *lchild, *rchild;

} BitNode, *BiTree;

int i;
int min;
int dw;


//创建次优查找树， arr 数组为查找表， sw 数组为存储的各关键字的概率（权值）， low 和 high 表示的 sw 数组中的权值的范围
void SecondOptimal(BiTree T, int arr[], float sw[], int low, int high)
{
    //由有序表R[low...high]及其累计权值表sw（其中sw[0]==0）递归构造次优查找树
    i = low;
    min = abs(sw[high] - sw[low]); // 绝对值
    dw = sw[high] + sw[low - 1];
    //选择最小的△Pi 值
    for (int j = low + 1; j <= high; j++)
    {
        if (abs(dw - sw[j] - sw[j - 1]) < min)
        {
            i = j;
            min = abs(dw - sw[j] - sw[j - 1]);
        }
    }
    T = (BiTree)malloc(sizeof(BiTNode));
    T->data = arr[i];//生成结点（第一次生成根）
    if (i == low) T->lchild = NULL;//左子树空
    else SecondOptimal(T->lchild, arr, sw, low, i - 1);//构造左子树
    if (i == high) T->rchild = NULL;//右子树空
    else SecondOptimal(T->rchild, arr, sw, i + 1, high);//构造右子树
}

