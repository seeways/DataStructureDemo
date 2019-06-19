#include "LinkQueue.h"

linkQueueNode* linkQueueNodeInit() {
	//创建一个头节点
	linkQueueNode* linkQueuelink = (linkQueueNode*)malloc(sizeof(linkQueueNode));
	//对头节点进行初始化
	//linkQueuelink->next = NULL;
	return linkQueuelink;
}


linkQueueNode* LinkQueueEnQueue(linkQueueNode* rear, int data) {
	//1、用节点包裹入队元素
	linkQueueNode* link = (linkQueueNode*)malloc(sizeof(linkQueueNode));
	link->data = data;
	link->next = NULL;
	//2、新节点与rear节点建立逻辑关系
	rear->next = link;
	//3、rear指向新节点
	rear = link;
	//返回新的rear，为后续新元素入队做准备
	return rear;
}

linkQueueNode* LinkQueueDeQueue(linkQueueNode* top, linkQueueNode* rear) {
	if (top->next == NULL) {
		printf("队列为空\n");
		return rear;
	}
	// 要释放的元素指向临时元素
	linkQueueNode* temp = top->next;
	// 打印要释放的元素
	printf("%d", temp->data);
	// 临时元素的后继元素赋值给头指针的后继元素
	top->next = temp->next;
	if (rear == temp) {
		rear = top;
	}
	// 释放临时元素
	free(temp);
	return rear;
}