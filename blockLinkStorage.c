#include "blockLinkStorage.h"


//��ʼ����������headΪͷָ�룬strΪ�洢���ַ���
blockLink* initblockLink(blockLink* head, char* str) {
	int length = strlen(str);
	//�����ַ����ĳ��ȣ������������ʹ�ýڵ�ĸ���
	int num = length / blockLinkNum;
	if (length % blockLinkNum) {
		num++;
	}
	//��������ʼ����Ԫ�ڵ�
	head = (blockLink*)malloc(sizeof(blockLink));
	head->next = NULL;
	blockLink* temp = head;
	//��ʼ������
	for (int i = 0; i < num; i++)
	{
		int j = 0;
		for (; j < blockLinkNum; j++)
		{
			if (i * blockLinkNum + j < length) {
				temp->a[j] = str[i * blockLinkNum + j];
			}
			else
				temp->a[j] = '#';
		}
		if (i * blockLinkNum + j < length)
		{
			blockLink* newlink = (blockLink*)malloc(sizeof(blockLink));
			newlink->next = NULL;
			temp->next = newlink;
			temp = newlink;
		}
	}
	return head;
}

void displayblockLink(blockLink* head) {
	blockLink* temp = head;
	while (temp) {
		for (int i = 0; i < blockLinkNum; i++) {
			printf("%c", temp->a[i]);
		}
		temp = temp->next;
	}
}
