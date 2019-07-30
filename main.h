#ifndef main
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW 3
#define UNDERFLOW 4

typedef int Status; //Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int Boolean; //Boolean是布尔类型,其值是TRUE或FALSE
typedef int ElemType;

// 线性表
#include "shunxubiao.h"
#include "lianbiao.h"
#include "jingtaibiao.h"
#include "JosephRing.h"
#include "doubleLink.h"
#include "roulette.h"

// 栈和队列
#include "SequenceStack.h"
#include "LinkStack.h"
#include "LinkQueue.h"
#include "SequenceQueue.h"

// 字符串
#include "blockLinkStorage.h"
#include "sequenceArray.h"

// 数组和广义表
#include "triple.h"
#include "orthogonalList.h"
#include "GYLink.h"

// 二叉树
#include "BiTree.h"
#include "ThreadBinaryTree.h"
#include "SaveTree.h"
#include "HuffmanTree.h"
#include "BackTrackAlgorithm.h"

// 图
#include "SequenceGraph.h"
#include "DFS.h"

#endif // !main
