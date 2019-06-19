#include "SequenceQueue.h"



int SequenceQueueEnQueue(int* a, int rear, int data) {
	// Ԫ�ظ�ֵ��βָ�룬βָ���������λ��������βָ��λ��
	a[rear] = data;
	rear++;
	return rear;
}


void SequenceQueueDeQueue(int* a, int front, int rear) {
	// ���front==rear��˵������Ϊ��
	while (front != rear) {
		printf("����Ԫ�أ�%d\n", a[front]);
		front++;
	}
}


int SequenceQueueEnQueue1(int* a, int front, int rear, int data) {
	//����ж���䣬���rear����max����ֱ�ӽ����a[0]���¿�ʼ�洢�����rear+1��front�غϣ����ʾ��������
	if ((rear + 1) % MAX == front) {
		printf("�ռ�����\n");
		return rear;
	}
	a[rear % MAX] = data;
	rear++;
	return rear;
}

int SequenceQueueDeQueue1(int* a, int front, int rear) {
	// ���front==rear��˵������Ϊ��
	if (front == rear % MAX) {
		printf("����Ϊ��\n");
		return front;
	}
	printf("%d\n", a[front]);
	// front+1��ͬmax���бȽϣ����=max����ֱ����ת�� a[0]
	front = (front + 1) % MAX;
	return front;
}

