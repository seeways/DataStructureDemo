#pragma once
#ifndef blockLinkStorage

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define blockLinkNum 3//ȫ�����������нڵ�洢���ݵĸ���
typedef struct blockLink {
	char a[blockLinkNum]; //������ɴ�� blockLinkNum ������
	struct blockLink* next; //����ָ����ָ��ֱ�Ӻ��Ԫ��
}blockLink; // nkΪ�ڵ�����ÿ���ڵ㶼��һ�� link �ṹ��
blockLink* initblockLink(blockLink* head, char* str);
void displayblockLink(blockLink* head);

#endif // !blockLinkStorage

