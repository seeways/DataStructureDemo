#include "doubleLink.h"


doubleLinkLine* initDoubleRingLinkLine(doubleLinkLine* head) {
	head = (doubleLinkLine*)malloc(sizeof(doubleLinkLine));
	head->prior = NULL;
	head->next = NULL;
	head->data = 1;
	doubleLinkLine* list = head;
	for (int i = 2; i <= 5; i++) {
		doubleLinkLine* body = (doubleLinkLine*)malloc(sizeof(doubleLinkLine));
		body->prior = NULL;
		body->next = NULL;
		body->data = i;
		list->next = body;
		body->prior = list;
		list = list->next;
	}
	//ͨ�����ϴ��룬�Ѿ�������˫���������������������β�ڵ����˫������
	list->next = head;
	head->prior = list;
	return head;
}

void displayDoubleRingLink(doubleLinkLine* head) {
	doubleLinkLine* temp = head;
	//������ѭ���������Ե�����ָ��temp ָ�����һ���ڵ���head ʱ��֤����ʱ�Ѿ�ѭ������������һ���ڵ�
	while (temp->next != head) {
		if (temp->next == NULL) {
			printf("%d\n", temp->data);
		}
		else {
			printf("%d->", temp->data);
		}
		temp = temp->next;
	}
	//���ѭ�����������һ���ڵ��ֵ
	printf("%d", temp->data);
}