#pragma once

#ifndef jingtaibiao

#include<stdio.h>
#include<stdlib.h>

#define maxSize 6

typedef struct {
	int data;//������
	int cur;//�α�
}component;

//���ṹ�����������з������ӵ�����������
void reserveArr(component* array);
//��ʼ����̬����
int initArr(component* array);
//�������
void test2DisplayArr(component* array, int body);
//�ӱ���������ժ�¿��нڵ�ĺ���
int mallocArr(component* array);

#endif // !jingtaibiao

