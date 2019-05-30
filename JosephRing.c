#include "JosephRing.h"

JosephRingPerson* initLink(int n) {
	JosephRingPerson* head = (JosephRingPerson*)malloc(sizeof(JosephRingPerson));
	head->number = 1;
	head->next = NULL;
	JosephRingPerson* cyclic = head;
	for (int i = 2; i <= n; i++) {
		JosephRingPerson* body = (JosephRingPerson*)malloc(sizeof(JosephRingPerson));
		body->number = i;
		body->next = NULL;
		cyclic->next = body;
		cyclic = cyclic->next;
	}
	cyclic->next = head;//��β����
	return head;
}

void findAndKillK(JosephRingPerson* head, int k, int m) {
	JosephRingPerson* tail = head;
	//�ҵ������һ��������һ����㣬Ϊɾ��������׼��
	while (tail->next != head) {
		tail = tail->next;
	}
	JosephRingPerson* p = head;
	//�ҵ����Ϊk���� p���Ǳ��Ϊk����
	while (p->number != k) {
		tail = p;
		p = p->next;
	}
	//�ӱ��Ϊk���˿�ʼ��ֻ�з���p->next==pʱ��˵�������г���p��㣬���б�Ŷ������ˣ�
	while (p->next != p) {
		//�ҵ���p����1��ʼ����m���ˣ����һ�Ҫ֪����m-1de�˵�λ��tail��������ɾ��������
		for (int i = 1; i < m; i++) {
			tail = p;
			p = p->next;
		}
		tail->next = p->next;//�������Ͻ�p���ժ����
		printf("�����˵ı��Ϊ:%d\n", p->number);
		free(p);
		p = tail->next;//����ʹ��pָ��ָ����б�ŵ���һ����ţ���Ϸ����
	}
	printf("�����˵ı��Ϊ:%d\n", p->number);
	free(p);
}
