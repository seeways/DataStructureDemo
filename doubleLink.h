#pragma once
#ifndef doubleLink
#include <stdio.h>
#include <stdlib.h>

typedef struct doubleLinkLine {
	struct doubleLinkLine* prior; //ָ��ֱ��ǰ��
	int data;
	struct doubleLinkLine* next; //ָ��ֱ�Ӻ��
}doubleLinkLine;

//˫����Ĵ���
doubleLinkLine* initLine(doubleLinkLine* head);
//˫�������Ԫ�أ�add��ʾ����λ��
doubleLinkLine* insertLine(doubleLinkLine* head, int data, int add);
//˫����ɾ��ָ��Ԫ��
doubleLinkLine* delLine(doubleLinkLine* head, int data);
//˫�����в���ָ��Ԫ��
int selectElem(doubleLinkLine* head, int elem);
//˫�����и���ָ��λ�ýڵ��д洢�����ݣ�add��ʾ����λ��
doubleLinkLine* amendElem(doubleLinkLine* p, int add, int newElem);
//���˫�����ʵ�ֺ���
void display(doubleLinkLine* head);
#endif // !doubleLink
