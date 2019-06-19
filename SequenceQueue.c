#include "SequenceQueue.h"



int SequenceQueueEnQueue(int* a, int rear, int data) {
	// 元素赋值给尾指针，尾指针后移至空位，并返回尾指针位置
	a[rear] = data;
	rear++;
	return rear;
}


void SequenceQueueDeQueue(int* a, int front, int rear) {
	// 如果front==rear，说明队列为空
	while (front != rear) {
		printf("出队元素：%d\n", a[front]);
		front++;
	}
}


int SequenceQueueEnQueue1(int* a, int front, int rear, int data) {
	//添加判断语句，如果rear超过max，则直接将其从a[0]重新开始存储，如果rear+1和front重合，则表示数组已满
	if ((rear + 1) % MAX == front) {
		printf("空间已满\n");
		return rear;
	}
	a[rear % MAX] = data;
	rear++;
	return rear;
}

int SequenceQueueDeQueue1(int* a, int front, int rear) {
	// 如果front==rear，说明队列为空
	if (front == rear % MAX) {
		printf("队列为空\n");
		return front;
	}
	printf("%d\n", a[front]);
	// front+1后同max进行比较，如果=max，则直接跳转到 a[0]
	front = (front + 1) % MAX;
	return front;
}

