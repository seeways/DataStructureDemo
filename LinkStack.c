#include "LinkStack.h"

//stack为当前的链栈，a表示入栈元素
lineStack* LinkStackPush(lineStack* stack, int a) {
	//创建存储新元素的节点
	lineStack* line = (lineStack*)malloc(sizeof(lineStack));
	line->data = a;
	//新节点与头节点建立逻辑关系
	line->next = stack;
	//更新头指针的指向
	stack = line;
	return stack;
}

//栈顶元素出链栈的实现函数
lineStack* LinkStackPop(lineStack* stack) {
	if (stack) {
		//声明一个新指针指向栈顶节点
		lineStack* p = stack;
		//更新头指针
		stack = stack->next;
		printf("弹栈元素：%d ", p->data);
		if (stack) {
			printf("栈顶元素：%d\n", stack->data);
		}
		else {
			printf("栈已空\n");
		}
		free(p);
	}
	else {
		printf("栈内没有元素");
		return stack;
	}
	return stack;
}