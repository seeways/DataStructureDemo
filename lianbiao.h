#pragma once
#pragma once


#ifndef lianbiao

#include<stdio.h>
#include<stdlib.h>


typedef struct Link {
	char elem;
	struct Link* next;
}link;


link* lianbiaoInitLink();

link* lianbiaoInsertElem(link* p, int elem, int pos);

link* lianbiaoDelElem(link* p, int add);

int lianbiaoSelectElem(link* p, int elem);

link* lianbiaoAmendElem(link* p, int add, int newElem);

void lianbiaoDisplay(link* p);

#endif // !lianbiao