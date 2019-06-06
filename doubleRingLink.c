#include "doubleLink.h"


doubleLinkLine* initDoubleRingLinkLine(doubleLinkLine* head) {
	head = (doubleLinkLine*)malloc(sizeof(doubleLinkLine));
	head->prior = NULL;
	head->next = NULL;
	head->data = 1;
	doubleLinkLine* list = head;
	for (int i = 2; i <= 5; i++) {
		doubleLinkLine* body = (doubleLinkLine*)malloc(sizeof(doubleLinkLine));
		body->prior = NULL;
		body->next = NULL;
		body->data = i;
		list->next = body;
		body->prior = list;
		list = list->next;
	}
	//通过以上代码，已经创建好双线链表，接下来将链表的首尾节点进行双向连接
	list->next = head;
	head->prior = list;
	return head;
}

void displayDoubleRingLink(doubleLinkLine* head) {
	doubleLinkLine* temp = head;
	//由于是循环链表，所以当遍历指针temp 指向的下一个节点是head 时，证明此时已经循环至链表的最后一个节点
	while (temp->next != head) {
		if (temp->next == NULL) {
			printf("%d\n", temp->data);
		}
		else {
			printf("%d->", temp->data);
		}
		temp = temp->next;
	}
	//输出循环链表中最后一个节点的值
	printf("%d", temp->data);
}