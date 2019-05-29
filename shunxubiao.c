
#include "shunxubiao.h"




/*
	顺序表
*/


table initTable() {
	table t;
	t.head = (int*)malloc(Size * sizeof(int));
	if (!t.head) {
		printf("init fail!");
		exit(0);
	}

	t.length = 0;
	t.size = Size;

	return t;
}


table insertTable(table t, int elem, int pos) {

	if (pos > t.length + 1 || pos < 0) {
		printf("position error!");
		return t;
	}

	if (t.length == t.size) {
		t.head = (int*)realloc(t.head, (t.size + 1) * sizeof(int));

		if (!t.head) {
			printf("momery allocation failed!");
			return t;
		}
		t.size += 1;
	}

	for (int i = t.length; i > pos; i--)
	{
		t.head[i + 1] = t.head[i];
	}

	t.head[pos] = elem;
	t.length++;

	return t;
}

table deleteTable(table t, int pos) {

	if (pos > t.length || pos < 0) {
		printf("position error!");
		return t;
	}

	for (int i = pos; i < t.length; i++)
	{
		t.head[i] = t.head[i + 1];
	}

	t.length--;
	return t;
}

table updateTable(table t, int elem, int pos) {

	if (pos > t.length + 1 || pos < 0) {
		printf("position error!");
		return t;
	}
	else {
		t.head[pos] = elem;
	}

	return t;
}

int selectTable(table t, int elem) {

	for (int i = 0; i < t.length; i++)
	{
		if (elem == t.head[i]) return i;
	}

	return -1;
}

void testDisplay(table t) {
	for (int i = 0; i < t.length; i++)
	{
		printf("%d", t.head[i]);
	}
	printf("\n");
}


//void main() {
//	// init
//	table t = initTable();
//	for (int i = 0; i < Size; i++)
//	{
//		t.head[i] = i + 1;
//		t.length++;
//	}
//	printf("\n 初始化");
//	testDisplay(t);
//
//	// insert
//	t = insertTable(t, 6, 5);
//	printf("\n 添加");
//	testDisplay(t);
//
//	// update
//	t = updateTable(t, 6, 3);
//	printf("\n 更新");
//	testDisplay(t);
//
//	// delete
//	t = deleteTable(t, 3);
//	printf("\n 删除");
//	testDisplay(t);
//
//	// select
//	int pos = selectTable(t, 5);
//	printf("\n 查找下标");
//	if (pos == -1) printf("%s", "错误的位置");
//	else printf("%d", pos);
//
//}
