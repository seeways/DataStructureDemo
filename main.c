
#include "main.h"


void shunxubiao() {
	// init
	table t = initTable();
	for (int i = 0; i < Size; i++)
	{
		t.head[i] = i + 1;
		t.length++;
	}
	printf("\n 初始化");
	testDisplay(t);

	// insert
	t = insertTable(t, 6, 5);
	printf("\n 添加");
	testDisplay(t);

	// update
	t = updateTable(t, 6, 3);
	printf("\n 更新");
	testDisplay(t);

	// delete
	t = deleteTable(t, 3);
	printf("\n 删除");
	testDisplay(t);

	// select
	int pos = selectTable(t, 5);
	printf("\n 查找下标");
	if (pos == -1) printf("%s", "错误的位置");
	else printf("%d", pos);

}
void lianbiao() {
	//初始化链表（1，2，3，4）
	printf("初始化链表为：\n");
	link* p = initLink();
	test1Display(p);

	printf("在下标4的位置插入元素5：\n");
	p = insertElem(p, 5, 4);
	test1Display(p);

	printf("删除下标3:\n");
	p = delElem(p, 3);
	test1Display(p);

	printf("查找元素2的下标为：\n");
	int address = selectElem(p, 2);
	if (address == -1) {
		printf("没有该元素");
	}
	else {
		printf("元素2的下标为：%d\n", address);
	}
	printf("更改下标3的位置上的数据为7:\n");
	p = amendElem(p, 3, 7);
	test1Display(p);

}

void jingtaibiao() {
	component array[maxSize];
	int body = initArr(array);
	printf("静态链表为：\n");
	test2DisplayArr(array, body);

}


void main() {
	//shunxubiao(); 

	//lianbiao();

	jingtaibiao();

}