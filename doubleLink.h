#pragma once
#ifndef doubleLink
#include <stdio.h>
#include <stdlib.h>

typedef struct doubleLinkLine {
	struct doubleLinkLine* prior; //ָ��ֱ��ǰ��
	int data;
	struct doubleLinkLine* next; //ָ��ֱ�Ӻ��
}doubleLinkLine;
/*
	˫������
*/
//˫����Ĵ���
doubleLinkLine* initDoubleLinkLine(doubleLinkLine* head);
//˫�������Ԫ�أ�add��ʾ����λ��
doubleLinkLine* insertDoubleLinkLine(doubleLinkLine* head, int data, int add);
//˫����ɾ��ָ��Ԫ��
doubleLinkLine* delDoubleLinkLine(doubleLinkLine* head, int data);
//˫�����в���ָ��Ԫ��
int selectDoubleLinkElem(doubleLinkLine* head, int elem);
//˫�����и���ָ��λ�ýڵ��д洢�����ݣ�add��ʾ����λ��
doubleLinkLine* amendDoubleLinkElem(doubleLinkLine* p, int add, int newElem);
//���˫�����ʵ�ֺ���
void displayDoubleLink(doubleLinkLine* head);

/*
	˫��ѭ������
*/
doubleLinkLine* initDoubleRingLinkLine(doubleLinkLine* head);
void displayDoubleRingLink(doubleLinkLine* head);

#endif // !doubleLink
