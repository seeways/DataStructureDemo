#pragma once

#ifndef jingtaibiao

#include<stdio.h>
#include<stdlib.h>

#define maxSize 6

typedef struct {
	int data;//数据域
	int cur;//游标
}component;

//将结构体数组中所有分量链接到备用链表中
void reserveArr(component* array);
//初始化静态链表
int initArr(component* array);
//输出函数
void test2DisplayArr(component* array, int body);
//从备用链表上摘下空闲节点的函数
int mallocArr(component* array);

#endif // !jingtaibiao

