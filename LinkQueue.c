#include "LinkQueue.h"

linkQueueNode* linkQueueNodeInit() {
	//����һ��ͷ�ڵ�
	linkQueueNode* linkQueuelink = (linkQueueNode*)malloc(sizeof(linkQueueNode));
	//��ͷ�ڵ���г�ʼ��
	//linkQueuelink->next = NULL;
	return linkQueuelink;
}


linkQueueNode* LinkQueueEnQueue(linkQueueNode* rear, int data) {
	//1���ýڵ�������Ԫ��
	linkQueueNode* link = (linkQueueNode*)malloc(sizeof(linkQueueNode));
	link->data = data;
	link->next = NULL;
	//2���½ڵ���rear�ڵ㽨���߼���ϵ
	rear->next = link;
	//3��rearָ���½ڵ�
	rear = link;
	//�����µ�rear��Ϊ������Ԫ�������׼��
	return rear;
}

linkQueueNode* LinkQueueDeQueue(linkQueueNode* top, linkQueueNode* rear) {
	if (top->next == NULL) {
		printf("����Ϊ��\n");
		return rear;
	}
	// Ҫ�ͷŵ�Ԫ��ָ����ʱԪ��
	linkQueueNode* temp = top->next;
	// ��ӡҪ�ͷŵ�Ԫ��
	printf("%d", temp->data);
	// ��ʱԪ�صĺ��Ԫ�ظ�ֵ��ͷָ��ĺ��Ԫ��
	top->next = temp->next;
	if (rear == temp) {
		rear = top;
	}
	// �ͷ���ʱԪ��
	free(temp);
	return rear;
}