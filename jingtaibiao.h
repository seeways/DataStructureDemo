#pragma once

#ifndef jingtaibiao

#include<stdio.h>

#define maxSize 7

typedef struct {
	int data;//������
	int cur;//�α�
}component;

//���ṹ�����������з������ӵ�����������
void jingtaibiaoReserveArr(component* array);
//��ʼ����̬����
int jingtaibiaoInitArr(component* array);
//�������в������ݣ�body��ʾ�����ͷ����������е�λ�ã�add��ʾ����Ԫ�ص�λ�ã�a��ʾҪ���������
void jingtaibiaoInsertArr(component* array, int body, int add, int a);
//ɾ�������к����ַ�a�Ľ��
void jingtaibiaoDeletArr(component* array, int body, int a);
//���Ҵ洢���ַ�elem�Ľ���������λ��
int jingtaibiaoSelectElem(component* array, int body, int elem);
//�������е��ַ�oldElem��ΪnewElem
void jingtaibiaoAmendElem(component* array, int body, int oldElem, int newElem);

//�ӱ���������ժ�����нڵ��ʵ�ֺ���
int jingtaibiaoMallocArr(component* array);
//��ժ�������Ľڵ����ӵ�����������
void jingtaibiaoFreeArr(component* array, int k);


//�������
void jingtaibiaoDisplayArr(component* array, int body);

#endif // !jingtaibiao

