#pragma once
#ifndef SequenceQueue
#include <stdio.h>
#define MAX 5

// ��������
int SequenceQueueEnQueue(int* a, int rear, int data);
void SequenceQueueDeQueue(int* a, int front, int rear);

// ��״����
int SequenceQueueEnQueue1(int* a, int front, int rear, int data);
int SequenceQueueDeQueue1(int* a, int front, int rear);
#endif // !SequenceQueue

