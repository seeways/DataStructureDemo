#pragma once
#pragma once


#ifndef lianbiao

#include<stdio.h>
#include<stdlib.h>


typedef struct Link {
	char elem;
	struct Link* next;
}link;


link* initLink();

link* insertElem(link* p, int elem, int pos);

link* delElem(link* p, int add);

int selectElem(link* p, int elem);

link* amendElem(link* p, int add, int newElem);

void test1Display(link* p);

#endif // !lianbiao