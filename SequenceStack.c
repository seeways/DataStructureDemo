#include "SequenceStack.h"

//元素elem进栈
int SequenceStackPush(int* a, int top, int elem) {
	a[++top] = elem;
	return top;
}

//数据元素出栈
int SequenceStackPop(int* a, int top) {
	if (top == -1) {
		printf("空栈");
		return -1;
	}
	printf("弹栈元素：%d\n", a[top]);
	top--;
	return top;
}