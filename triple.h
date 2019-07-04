#pragma once
#ifndef triple

#include<stdio.h>

#define MAXSIZE 10000
#define MAXRC 10000
#define ElemType int

//结构体
typedef struct {
	int i, j;//行标i，列标j
	ElemType data;//元素值
}triple;

//三元组矩阵的结构表示
typedef struct {
	triple data[MAXSIZE];//存储该矩阵中所有非0元素的三元组
	int n, m, num;//n和m分别记录矩阵的行数和列数，num记录矩阵中所有的非0元素的个数
}TSMatrix;
void TSMatrixOut();// 三元组数据输出


//行逻辑连接的结构表示
typedef struct
{
	triple  data[MAXSIZE];
	int rpos[MAXRC];//每行第一个非零元素在data数组中的位置
	int mu, nu, tu;//行数，列数，元素个数
}RLSMatrix;
void RLSMatrixOut();// 行逻辑连接的数据输出



// 矩阵（稀疏矩阵）的转置算法
TSMatrix transposeMatrix(TSMatrix M, TSMatrix T);
void transposeOut();

// 矩阵的快速转置算法
void fastTransposeMatrixOut();


#endif // !triple
