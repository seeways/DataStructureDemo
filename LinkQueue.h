#pragma once
#ifndef LinkQueue
#include <stdio.h>
#include <stdlib.h>

typedef struct linkQueueNode {
	int data;
	struct linkQueueNode* next;
}linkQueueNode;

linkQueueNode* linkQueueNodeInit(); // 初始化
linkQueueNode* LinkQueueEnQueue(linkQueueNode* rear, int data); // 入队
linkQueueNode* LinkQueueDeQueue(linkQueueNode* top, linkQueueNode* rear); // 出队
#endif // !LinkQueue

