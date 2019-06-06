#include "doubleLink.h"


doubleLinkLine* initDoubleLinkLine(doubleLinkLine* head) {
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
	return head;
}
doubleLinkLine* insertDoubleLinkLine(doubleLinkLine* head, int data, int add) {
	//�½�������Ϊdata�Ľ��
	doubleLinkLine* temp = (doubleLinkLine*)malloc(sizeof(doubleLinkLine));
	temp->data = data;
	temp->prior = NULL;
	temp->next = NULL;
	//���뵽����ͷ��Ҫ���⿼��
	if (add == 1) {
		temp->next = head;
		head->prior = temp;
		head = temp;
	}
	else {
		doubleLinkLine* body = head;
		//�ҵ�Ҫ����λ�õ�ǰһ�����
		for (int i = 1; i < add - 1; i++) {
			body = body->next;
		}
		//�ж�����Ϊ�棬˵������λ��Ϊ����β
		if (body->next == NULL) {
			body->next = temp;
			temp->prior = body;
		}
		else {
			body->next->prior = temp;
			temp->next = body->next;
			body->next = temp;
			temp->prior = body;
		}
	}
	return head;
}
doubleLinkLine* delDoubleLinkLine(doubleLinkLine* head, int data) {
	doubleLinkLine* temp = head;
	//��������
	while (temp) {
		//�жϵ�ǰ������������data�Ƿ���ȣ�����ȣ�ժ���ý��
		if (temp->data == data) {
			temp->prior->next = temp->next;
			temp->next->prior = temp->prior;
			free(temp);
			return head;
		}
		temp = temp->next;
	}
	printf("�������޸�����Ԫ��");
	return head;
}
//headΪԭ˫����elem��ʾ������Ԫ��
int selectDoubleLinkElem(doubleLinkLine* head, int elem) {
	//�½�һ��ָ��t����ʼ��Ϊͷָ�� head
	doubleLinkLine* t = head;
	int i = 1;
	while (t) {
		if (t->data == elem) {
			return i;
		}
		i++;
		t = t->next;
	}
	//����ִ�����˴�����ʾ����ʧ��
	return -1;
}
//���º��������У�add ��ʾ���Ľ����˫�����е�λ�ã�newElem Ϊ�����ݵ�ֵ
doubleLinkLine* amendDoubleLinkElem(doubleLinkLine* p, int add, int newElem) {
	doubleLinkLine* temp = p;
	//��������ɾ�����
	for (int i = 1; i < add; i++) {
		temp = temp->next;
	}
	temp->data = newElem;
	return p;
}
//�������Ĺ��ܺ���
void displayDoubleLink(doubleLinkLine* head) {
	doubleLinkLine* temp = head;
	while (temp) {
		if (temp->next == NULL) {
			printf("%d\n", temp->data);
		}
		else {
			printf("%d->", temp->data);
		}
		temp = temp->next;
	}
}