
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
	link* p = lianbiaoInitLink();
	lianbiaoDisplay(p);

	printf("在下标4的位置插入元素5：\n");
	p = lianbiaoInsertElem(p, 5, 4);
	lianbiaoDisplay(p);

	printf("删除下标3:\n");
	p = lianbiaoDelElem(p, 3);
	lianbiaoDisplay(p);

	printf("查找元素2的下标为：\n");
	int address = lianbiaoSelectElem(p, 2);
	if (address == -1) {
		printf("没有该元素");
	}
	else {
		printf("元素2的下标为：%d\n", address);
	}
	printf("更改下标3的位置上的数据为7:\n");
	p = lianbiaoAmendElem(p, 3, 7);
	lianbiaoDisplay(p);

}

void jingtaibiao() {
	component array[maxSize];
	int body = jingtaibiaoInitArr(array);
	printf("静态链表为：\n");
	jingtaibiaoDisplayArr(array, body);

	printf("在第3的位置上插入结点‘11’:\n");
	jingtaibiaoInsertArr(array, body, 3, 11);
	jingtaibiaoDisplayArr(array, body);

	printf("删除数据域为‘3’的结点:\n");
	jingtaibiaoDeletArr(array, body, 3);
	jingtaibiaoDisplayArr(array, body);

	printf("查找数据域为‘11’的结点的位置:\n");
	int selectAdd = jingtaibiaoSelectElem(array, body, 4);
	printf("%d\n", selectAdd);

	printf("将结点数据域为‘11’改为‘12’:\n");
	jingtaibiaoAmendElem(array, body, 11, 12);
	jingtaibiaoDisplayArr(array, body);
}


void josephRing() {
	printf("输入圆桌上的人数n:");
	int n;
	scanf_s("%d", &n);
	JosephRingPerson* head = initLink(n);
	printf("从第k人开始报数(k>1且k<%d)：", n);
	int k;
	scanf_s("%d", &k);
	printf("数到m的人出列：");
	int m;
	scanf_s("%d", &m);
	findAndKillK(head, k, m);

}

void main() {
	//shunxubiao(); 

	//lianbiao();

	//jingtaibiao();

	josephRing();

}