#pragma once
#ifndef JosephRing
#include <stdio.h>
#include <stdlib.h>
typedef struct JosephRingNode {
	int number;
	struct JosephRingNode* next;
}JosephRingPerson;

JosephRingPerson* initLink(int n);
void findAndKillK(JosephRingPerson* head, int k, int m);
#endif // !JosephRing
