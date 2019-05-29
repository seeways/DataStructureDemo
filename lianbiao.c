#include "lianbiao.h"



/*
	����
*/

link* initLink() {
	// no head pointer 
	//link* p = NULL; // create head pointer
	//link* temp = (link*)malloc(sizeof(link));// create firstNode

	//// init firstNode
	//temp->elem = 1;
	//temp->next = NULL;

	//p = temp;

	//// create other node
	//for (int i = 2; i < 6; i++)
	//{
	//	link* a = (link*)malloc(sizeof(link));
	//	a->elem = i;
	//	a->next = NULL;
	//	// create logical relationships using temp node and a node
	//	temp->next = a;

	//	// temp pointer's last node to new link every time, that is the 'a' node , so temp=a also right.
	//	temp = temp->next;
	//}

	// have head pointer
	link* p = (link*)malloc(sizeof(link));// create a head node
	link* temp = p;//  state a pointer to head node
	for (int i = 1; i < 5; i++) {
		link* a = (link*)malloc(sizeof(link));
		a->elem = i;
		a->next = NULL;
		temp->next = a;
		temp = temp->next;
	}


	return p;
}


//pΪԭ����elem��ʾ������Ԫ�أ�pos��ʾ��Ԫ��Ҫ�����λ��
link* insertElem(link* p, int elem, int pos) {
	link* temp = p;//������ʱ���temp
	//�����ҵ�Ҫ����λ�õ���һ�����
	for (int i = 0; i < pos; i++) {
		if (temp == NULL) {
			printf("����λ����Ч\n");
			return p;
		}
		temp = temp->next;
	}
	//����������c
	link* c = (link*)malloc(sizeof(link));
	c->elem = elem;
	//�������в�����
	c->next = temp->next;
	temp->next = c;
	return  p;
}

//pΪԭ����posΪҪɾ��Ԫ�ص�ֵ
link* delElem(link* p, int pos) {
	link* temp = p;
	//tempָ��ɾ��������һ�����
	for (int i = 0; i < pos; i++) {
		temp = temp->next;
	}
	link* del = temp->next;//��������һ��ָ��ָ��ɾ����㣬�Է���ʧ
	temp->next = temp->next->next;//ɾ��ĳ�����ķ������Ǹ���ǰһ������ָ����
	free(del);//�ֶ��ͷŸý�㣬��ֹ�ڴ�й©
	return p;
}

//pΪԭ����elem��ʾ������Ԫ�ء�
int selectElem(link* p, int elem) {
	//�½�һ��ָ��t����ʼ��Ϊͷָ�� p
	link* t = p;
	int i = 0;
	//����ͷ�ڵ�Ĵ��ڣ����while�е��ж�Ϊt->next
	while (t->next) {
		t = t->next;
		if (t->elem == elem) {
			return i;
		}
		i++;
	}
	//����ִ�����˴�����ʾ����ʧ��
	return -1;
}

//���º��������У�add ��ʾ���Ľ���������е�λ�ã�newElem Ϊ�µ��������ֵ
link* amendElem(link* p, int pos, int newElem) {
	link* temp = p;
	temp = temp->next;//�ڱ���֮ǰ��tempָ����Ԫ���
	//��������ɾ�����
	for (int i = 0; i < pos; i++) {
		temp = temp->next;
	}
	temp->elem = newElem;
	return p;
}



void test1Display(link* p) {
	link* temp = p;//��tempָ������ָ��ͷ���
	//ֻҪtempָ��ָ��Ľ���next����Null����ִ�������䡣
	while (temp->next) {
		temp = temp->next;
		printf("%d ", temp->elem);
	}
	printf("\n");
}


//void main() {
//	//��ʼ������1��2��3��4��
//	printf("��ʼ������Ϊ��\n");
//	link* p = initLink();
//	test1Display(p);
//}