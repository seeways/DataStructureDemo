#include "SequenceStack.h"

//Ԫ��elem��ջ
int SequenceStackPush(int* a, int top, int elem) {
	a[++top] = elem;
	return top;
}

//����Ԫ�س�ջ
int SequenceStackPop(int* a, int top) {
	if (top == -1) {
		printf("��ջ");
		return -1;
	}
	printf("��ջԪ�أ�%d\n", a[top]);
	top--;
	return top;
}