#pragma once

#ifndef jingtaibiao

#include<stdio.h>

#define maxSize 7

typedef struct {
	int data;//数据域
	int cur;//游标
}component;

//将结构体数组中所有分量链接到备用链表中
void jingtaibiaoReserveArr(component* array);
//初始化静态链表
int jingtaibiaoInitArr(component* array);
//向链表中插入数据，body表示链表的头结点在数组中的位置，add表示插入元素的位置，a表示要插入的数据
void jingtaibiaoInsertArr(component* array, int body, int add, int a);
//删除链表中含有字符a的结点
void jingtaibiaoDeletArr(component* array, int body, int a);
//查找存储有字符elem的结点在数组的位置
int jingtaibiaoSelectElem(component* array, int body, int elem);
//将链表中的字符oldElem改为newElem
void jingtaibiaoAmendElem(component* array, int body, int oldElem, int newElem);

//从备用链表中摘除空闲节点的实现函数
int jingtaibiaoMallocArr(component* array);
//将摘除下来的节点链接到备用链表上
void jingtaibiaoFreeArr(component* array, int k);


//输出函数
void jingtaibiaoDisplayArr(component* array, int body);

#endif // !jingtaibiao

