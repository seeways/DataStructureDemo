#pragma once
// �����˳��洢
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
#define INFEASIBLE -1 // ������
#define OVERFLOW 3 // ���
#define UNDERFLOW 4 // �����

typedef int Status; //Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef int Boolean; //Boolean�ǲ�������,��ֵ��TRUE��FALSE
typedef int ElemType;
#define MAX_ARRAY_DIM 8 //��������ά�������ֵΪ8

typedef struct
{
	ElemType* base; //����Ԫ�ػ�ַ����InitSequenceArray����
	int dim; //����ά�� dimension
	int* bounds; //����ά���ַ����InitSequenceArray����
	int* constants; // ����ӳ����������ַ����InitSequenceArray����
} sequenceArray;

Status InitSequenceArray(sequenceArray* A, int dim, ...); // ��ʼ������
Status DestroySequenceArrayArray(sequenceArray* A); // ע������
Status sequenceArrayLocate(sequenceArray A, va_list ap, int* off); // Value()��Assign()���ô˺��� */
Status sequenceArrayValue(ElemType* e, sequenceArray A, ...); //��VC++�У�...֮ǰ���ββ�������������
Status SequenceArrayAssign(sequenceArray* A, ElemType e, ...); // ����

void execSequenceArray(); // ִ��
#endif // !sequenceArray
