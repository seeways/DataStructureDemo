
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


void doubleLink() {
	doubleLinkLine* head = NULL;
	//创建双链表
	head = initDoubleLinkLine(head);
	displayDoubleLink(head);
	//在表中第 3 的位置插入元素 7
	head = insertDoubleLinkLine(head, 7, 3);
	displayDoubleLink(head);
	//表中删除元素 2
	head = delDoubleLinkLine(head, 2);
	displayDoubleLink(head);
	printf("元素 3 的位置是：%d\n", selectDoubleLinkElem(head, 3));
	//表中第 3 个节点中的数据改为存储 6
	head = amendDoubleLinkElem(head, 3, 6);
	displayDoubleLink(head);
}

void doubleRingLink() {
	doubleLinkLine* head = NULL;
	head = initDoubleRingLinkLine(head);
	displayDoubleRingLink(head);
}

void sequenceStack() {
	int a[100];
	int top = -1;
	top = SequenceStackPush(a, top, 1);
	top = SequenceStackPush(a, top, 2);
	top = SequenceStackPush(a, top, 3);
	top = SequenceStackPush(a, top, 4);
	top = SequenceStackPop(a, top);
	top = SequenceStackPop(a, top);
	top = SequenceStackPop(a, top);
	top = SequenceStackPop(a, top);
	top = SequenceStackPop(a, top);
}

void linkStack() {
	lineStack* stack = NULL;
	stack = LinkStackPush(stack, 1);
	stack = LinkStackPush(stack, 2);
	stack = LinkStackPush(stack, 3);
	stack = LinkStackPush(stack, 4);
	stack = LinkStackPop(stack);
	stack = LinkStackPop(stack);
	stack = LinkStackPop(stack);
	stack = LinkStackPop(stack);
	stack = LinkStackPop(stack);
}


void sequenceQueue() {
	int a[100];
	int front = 0, rear = 0;
	//入队
	rear = SequenceQueueEnQueue(a, rear, 1);
	rear = SequenceQueueEnQueue(a, rear, 2);
	rear = SequenceQueueEnQueue(a, rear, 3);
	rear = SequenceQueueEnQueue(a, rear, 4);
	//出队
	SequenceQueueDeQueue(a, front, rear);
}

void sequenceQueue1() {
	int a[MAX];
	int front, rear;
	//设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址
	front = rear = 0;
	//入队
	rear = SequenceQueueEnQueue1(a, front, rear, 1);
	rear = SequenceQueueEnQueue1(a, front, rear, 2);
	rear = SequenceQueueEnQueue1(a, front, rear, 3);
	rear = SequenceQueueEnQueue1(a, front, rear, 4);
	//出队
	front = SequenceQueueDeQueue1(a, front, rear);
	//再入队
	rear = SequenceQueueEnQueue1(a, front, rear, 5);
	//再出队
	front = SequenceQueueDeQueue1(a, front, rear);
	//再入队
	rear = SequenceQueueEnQueue1(a, front, rear, 6);
	//再出队
	front = SequenceQueueDeQueue1(a, front, rear);
	front = SequenceQueueDeQueue1(a, front, rear);
	front = SequenceQueueDeQueue1(a, front, rear);
	front = SequenceQueueDeQueue1(a, front, rear);
}

void linkQueue() {
	linkQueueNode* queue, * top, * rear;
	queue = top = rear = linkQueueNodeInit();//创建头结点
	//向链队列中添加结点，使用尾插法添加的同时，队尾指针需要指向链表的最后一个元素
	rear = LinkQueueEnQueue(rear, 1);
	rear = LinkQueueEnQueue(rear, 2);
	rear = LinkQueueEnQueue(rear, 3);
	rear = LinkQueueEnQueue(rear, 4);
	//入队完成，所有数据元素开始出队列
	rear = LinkQueueDeQueue(top, rear);
	rear = LinkQueueDeQueue(top, rear);
	rear = LinkQueueDeQueue(top, rear);
	rear = LinkQueueDeQueue(top, rear);
	rear = LinkQueueDeQueue(top, rear);
}

void normalStr() {
	char str[20] = "jiataoyuan.com";
	printf("%s\n", str);
}

void heapStorage() {
	char* a1 = NULL;
	char* a2 = NULL;
	a1 = (char*)malloc(10 * sizeof(char));
	strcpy(a1, "data.bian");//将字符串"data.bian"复制给a1
	a2 = (char*)malloc(10 * sizeof(char));
	strcpy(a2, "cheng.net");
	int lengthA1 = strlen(a1);//a1串的长度
	int lengthA2 = strlen(a2);//a2串的长度
	//尝试将合并的串存储在 a1 中，如果 a1 空间不够，则用realloc动态申请
	if (lengthA1 < lengthA1 + lengthA2) {
		a1 = (char*)realloc(a1, (lengthA1 + lengthA2 + 1) * sizeof(char));
	}
	//合并两个串到 a1 中
	for (int i = lengthA1; i < lengthA1 + lengthA2; i++) {
		a1[i] = a2[i - lengthA1];
	}
	//串的末尾要添加 \0，避免出错
	a1[lengthA1 + lengthA2] = '\0';
	printf("%s", a1);
	//用完动态数组要立即释放
	free(a1);
	free(a2);
}

void blockStorage() {
	blockLink* head = NULL;
	head = initblockLink(head, "www.jiataoyuan.com");
	displayblockLink(head);
}

void BFAlgorithm() {

}
void KMPAlgorithm() {

}


void main() {
	// 第一章 线性表
	//shunxubiao(); // 顺序表
	//lianbiao(); // 链表
	//jingtaibiao(); // 静态链表
	//josephRing(); // 约瑟夫环
	//doubleLink(); // 双向链表
	//doubleRingLink(); // 双向循环链表
	//rouletteShow(); // 轮盘赌

	// 第二章 栈和队列
	//sequenceStack(); // 顺序栈
	//linkStack(); // 链栈
	//sequenceQueue(); // 顺序队列
	//sequenceQueue1(); // 顺序队列1 环状队列
	//linkQueue(); // 链式队列

	// 第三章 字符串
	//normalStr(); // 定长顺序存储
	//heapStorage();// 堆分配存储
	//blockStorage();// 块链存储
	BFAlgorithm();// BF算法（串模式匹配算法）
	KMPAlgorithm();// KMP算法


}