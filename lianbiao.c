#include "lianbiao.h"



/*
	链表
*/

link* initLink() {
	// no head pointer 
	//link* p = NULL; // create head pointer
	//link* temp = (link*)malloc(sizeof(link));// create firstNode

	//// init firstNode
	//temp->elem = 1;
	//temp->next = NULL;

	//p = temp;

	//// create other node
	//for (int i = 2; i < 6; i++)
	//{
	//	link* a = (link*)malloc(sizeof(link));
	//	a->elem = i;
	//	a->next = NULL;
	//	// create logical relationships using temp node and a node
	//	temp->next = a;

	//	// temp pointer's last node to new link every time, that is the 'a' node , so temp=a also right.
	//	temp = temp->next;
	//}

	// have head pointer
	link* p = (link*)malloc(sizeof(link));// create a head node
	link* temp = p;//  state a pointer to head node
	for (int i = 1; i < 5; i++) {
		link* a = (link*)malloc(sizeof(link));
		a->elem = i;
		a->next = NULL;
		temp->next = a;
		temp = temp->next;
	}


	return p;
}


//p为原链表，elem表示新数据元素，pos表示新元素要插入的位置
link* insertElem(link* p, int elem, int pos) {
	link* temp = p;//创建临时结点temp
	//首先找到要插入位置的上一个结点
	for (int i = 0; i < pos; i++) {
		if (temp == NULL) {
			printf("插入位置无效\n");
			return p;
		}
		temp = temp->next;
	}
	//创建插入结点c
	link* c = (link*)malloc(sizeof(link));
	c->elem = elem;
	//向链表中插入结点
	c->next = temp->next;
	temp->next = c;
	return  p;
}

//p为原链表，pos为要删除元素的值
link* delElem(link* p, int pos) {
	link* temp = p;
	//temp指向被删除结点的上一个结点
	for (int i = 0; i < pos; i++) {
		temp = temp->next;
	}
	link* del = temp->next;//单独设置一个指针指向被删除结点，以防丢失
	temp->next = temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
	free(del);//手动释放该结点，防止内存泄漏
	return p;
}

//p为原链表，elem表示被查找元素、
int selectElem(link* p, int elem) {
	//新建一个指针t，初始化为头指针 p
	link* t = p;
	int i = 0;
	//由于头节点的存在，因此while中的判断为t->next
	while (t->next) {
		t = t->next;
		if (t->elem == elem) {
			return i;
		}
		i++;
	}
	//程序执行至此处，表示查找失败
	return -1;
}

//更新函数，其中，add 表示更改结点在链表中的位置，newElem 为新的数据域的值
link* amendElem(link* p, int pos, int newElem) {
	link* temp = p;
	temp = temp->next;//在遍历之前，temp指向首元结点
	//遍历到被删除结点
	for (int i = 0; i < pos; i++) {
		temp = temp->next;
	}
	temp->elem = newElem;
	return p;
}



void test1Display(link* p) {
	link* temp = p;//将temp指针重新指向头结点
	//只要temp指针指向的结点的next不是Null，就执行输出语句。
	while (temp->next) {
		temp = temp->next;
		printf("%d ", temp->elem);
	}
	printf("\n");
}


//void main() {
//	//初始化链表（1，2，3，4）
//	printf("初始化链表为：\n");
//	link* p = initLink();
//	test1Display(p);
//}