#pragma once
#ifndef LinkQueue
#include <stdio.h>
#include <stdlib.h>

typedef struct linkQueueNode {
	int data;
	struct linkQueueNode* next;
}linkQueueNode;

linkQueueNode* linkQueueNodeInit(); // ��ʼ��
linkQueueNode* LinkQueueEnQueue(linkQueueNode* rear, int data); // ���
linkQueueNode* LinkQueueDeQueue(linkQueueNode* top, linkQueueNode* rear); // ����
#endif // !LinkQueue

