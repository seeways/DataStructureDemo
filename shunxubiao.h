#pragma once
#pragma once

#ifndef shunxubiao

#include <stdio.h>
#include <stdlib.h>
#define Size 5

typedef struct Table
{
	int* head;
	int length;
	int size;
}table;

table initTable();

table insertTable(table t, int elem, int pos);

table deleteTable(table t, int pos);

table updateTable(table t, int elem, int pos);

int selectTable(table t, int elem);

void testDisplay(table t);
#endif // !shunxubiao
