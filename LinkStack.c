#include "LinkStack.h"

//stackΪ��ǰ����ջ��a��ʾ��ջԪ��
lineStack* LinkStackPush(lineStack* stack, int a) {
	//�����洢��Ԫ�صĽڵ�
	lineStack* line = (lineStack*)malloc(sizeof(lineStack));
	line->data = a;
	//�½ڵ���ͷ�ڵ㽨���߼���ϵ
	line->next = stack;
	//����ͷָ���ָ��
	stack = line;
	return stack;
}

//ջ��Ԫ�س���ջ��ʵ�ֺ���
lineStack* LinkStackPop(lineStack* stack) {
	if (stack) {
		//����һ����ָ��ָ��ջ���ڵ�
		lineStack* p = stack;
		//����ͷָ��
		stack = stack->next;
		printf("��ջԪ�أ�%d ", p->data);
		if (stack) {
			printf("ջ��Ԫ�أ�%d\n", stack->data);
		}
		else {
			printf("ջ�ѿ�\n");
		}
		free(p);
	}
	else {
		printf("ջ��û��Ԫ��");
		return stack;
	}
	return stack;
}