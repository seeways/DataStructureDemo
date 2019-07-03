#pragma once
// 数组的顺序存储
#ifndef sequenceArray
#include<stdarg.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h> // atoi()
#include<io.h> // eof()
#include<math.h>

#define TRUE 1 
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1 // 不可行
#define OVERFLOW 3 // 溢出
#define UNDERFLOW 4 // 下溢出

typedef int Status; //Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int Boolean; //Boolean是布尔类型,其值是TRUE或FALSE
typedef int ElemType;
#define MAX_ARRAY_DIM 8 //假设数组维数的最大值为8

typedef struct
{
	ElemType* base; //数组元素基址，由InitSequenceArray分配
	int dim; //数组维数 dimension
	int* bounds; //数组维界基址，由InitSequenceArray分配
	int* constants; // 数组映象函数常量基址，由InitSequenceArray分配
} sequenceArray;

Status InitSequenceArray(sequenceArray* A, int dim, ...); // 初始化数组
Status DestroySequenceArrayArray(sequenceArray* A); // 注销数组
Status sequenceArrayLocate(sequenceArray A, va_list ap, int* off); // Value()、Assign()调用此函数 */
Status sequenceArrayValue(ElemType* e, sequenceArray A, ...); //在VC++中，...之前的形参不能是引用类型
Status SequenceArrayAssign(sequenceArray* A, ElemType e, ...); // 分配

void execSequenceArray(); // 执行
#endif // !sequenceArray
