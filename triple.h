#pragma once
#ifndef triple

#include<stdio.h>

#define MAXSIZE 10000
#define MAXRC 10000
#define ElemType int

//�ṹ��
typedef struct {
	int i, j;//�б�i���б�j
	ElemType data;//Ԫ��ֵ
}triple;

//��Ԫ�����Ľṹ��ʾ
typedef struct {
	triple data[MAXSIZE];//�洢�þ��������з�0Ԫ�ص���Ԫ��
	int n, m, num;//n��m�ֱ��¼�����������������num��¼���������еķ�0Ԫ�صĸ���
}TSMatrix;
void TSMatrixOut();// ��Ԫ���������


//���߼����ӵĽṹ��ʾ
typedef struct
{
	triple  data[MAXSIZE];
	int rpos[MAXRC];//ÿ�е�һ������Ԫ����data�����е�λ��
	int mu, nu, tu;//������������Ԫ�ظ���
}RLSMatrix;
void RLSMatrixOut();// ���߼����ӵ��������



// ����ϡ����󣩵�ת���㷨
TSMatrix transposeMatrix(TSMatrix M, TSMatrix T);
void transposeOut();

// ����Ŀ���ת���㷨
void fastTransposeMatrixOut();


#endif // !triple
