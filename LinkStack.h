#pragma once
#ifndef LinkStack
#include <stdio.h>
#include <stdlib.h>
typedef struct lineStack {
	int data;
	struct lineStack* next;
}lineStack;

lineStack* LinkStackPush(lineStack* stack, int a);
lineStack* LinkStackPop(lineStack* stack);
#endif // !LinkStack
