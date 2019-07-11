
#include "main.h"


void shunxubiao() {
	// init
	table t = initTable();
	for (int i = 0; i < Size; i++)
	{
		t.head[i] = i + 1;
		t.length++;
	}
	printf("\n ��ʼ��");
	testDisplay(t);

	// insert
	t = insertTable(t, 6, 5);
	printf("\n ���");
	testDisplay(t);

	// update
	t = updateTable(t, 6, 3);
	printf("\n ����");
	testDisplay(t);

	// delete
	t = deleteTable(t, 3);
	printf("\n ɾ��");
	testDisplay(t);

	// select
	int pos = selectTable(t, 5);
	printf("\n �����±�");
	if (pos == -1) printf("%s", "�����λ��");
	else printf("%d", pos);

}

void lianbiao() {
	//��ʼ������1��2��3��4��
	printf("��ʼ������Ϊ��\n");
	link* p = lianbiaoInitLink();
	lianbiaoDisplay(p);

	printf("���±�4��λ�ò���Ԫ��5��\n");
	p = lianbiaoInsertElem(p, 5, 4);
	lianbiaoDisplay(p);

	printf("ɾ���±�3:\n");
	p = lianbiaoDelElem(p, 3);
	lianbiaoDisplay(p);

	printf("����Ԫ��2���±�Ϊ��\n");
	int address = lianbiaoSelectElem(p, 2);
	if (address == -1) {
		printf("û�и�Ԫ��");
	}
	else {
		printf("Ԫ��2���±�Ϊ��%d\n", address);
	}
	printf("�����±�3��λ���ϵ�����Ϊ7:\n");
	p = lianbiaoAmendElem(p, 3, 7);
	lianbiaoDisplay(p);

}

void jingtaibiao() {
	component array[maxSize];
	int body = jingtaibiaoInitArr(array);
	printf("��̬����Ϊ��\n");
	jingtaibiaoDisplayArr(array, body);

	printf("�ڵ�3��λ���ϲ����㡮11��:\n");
	jingtaibiaoInsertArr(array, body, 3, 11);
	jingtaibiaoDisplayArr(array, body);

	printf("ɾ��������Ϊ��3���Ľ��:\n");
	jingtaibiaoDeletArr(array, body, 3);
	jingtaibiaoDisplayArr(array, body);

	printf("����������Ϊ��11���Ľ���λ��:\n");
	int selectAdd = jingtaibiaoSelectElem(array, body, 4);
	printf("%d\n", selectAdd);

	printf("�����������Ϊ��11����Ϊ��12��:\n");
	jingtaibiaoAmendElem(array, body, 11, 12);
	jingtaibiaoDisplayArr(array, body);
}


void josephRing() {
	printf("����Բ���ϵ�����n:");
	int n;
	scanf_s("%d", &n);
	JosephRingPerson* head = initLink(n);
	printf("�ӵ�k�˿�ʼ����(k>1��k<%d)��", n);
	int k;
	scanf_s("%d", &k);
	printf("����m���˳��У�");
	int m;
	scanf_s("%d", &m);
	findAndKillK(head, k, m);

}


void doubleLink() {
	doubleLinkLine* head = NULL;
	//����˫����
	head = initDoubleLinkLine(head);
	displayDoubleLink(head);
	//�ڱ��е� 3 ��λ�ò���Ԫ�� 7
	head = insertDoubleLinkLine(head, 7, 3);
	displayDoubleLink(head);
	//����ɾ��Ԫ�� 2
	head = delDoubleLinkLine(head, 2);
	displayDoubleLink(head);
	printf("Ԫ�� 3 ��λ���ǣ�%d\n", selectDoubleLinkElem(head, 3));
	//���е� 3 ���ڵ��е����ݸ�Ϊ�洢 6
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
	//���
	rear = SequenceQueueEnQueue(a, rear, 1);
	rear = SequenceQueueEnQueue(a, rear, 2);
	rear = SequenceQueueEnQueue(a, rear, 3);
	rear = SequenceQueueEnQueue(a, rear, 4);
	//����
	SequenceQueueDeQueue(a, front, rear);
}

void sequenceQueue1() {
	int a[MAX];
	int front, rear;
	//���ö�ͷָ��Ͷ�βָ�룬��������û��Ԫ��ʱ����ͷ�Ͷ�βָ��ͬһ���ַ
	front = rear = 0;
	//���
	rear = SequenceQueueEnQueue1(a, front, rear, 1);
	rear = SequenceQueueEnQueue1(a, front, rear, 2);
	rear = SequenceQueueEnQueue1(a, front, rear, 3);
	rear = SequenceQueueEnQueue1(a, front, rear, 4);
	//����
	front = SequenceQueueDeQueue1(a, front, rear);
	//�����
	rear = SequenceQueueEnQueue1(a, front, rear, 5);
	//�ٳ���
	front = SequenceQueueDeQueue1(a, front, rear);
	//�����
	rear = SequenceQueueEnQueue1(a, front, rear, 6);
	//�ٳ���
	front = SequenceQueueDeQueue1(a, front, rear);
	front = SequenceQueueDeQueue1(a, front, rear);
	front = SequenceQueueDeQueue1(a, front, rear);
	front = SequenceQueueDeQueue1(a, front, rear);
}

void linkQueue() {
	linkQueueNode* queue, * top, * rear;
	queue = top = rear = linkQueueNodeInit();//����ͷ���
	//������������ӽ�㣬ʹ��β�巨��ӵ�ͬʱ����βָ����Ҫָ����������һ��Ԫ��
	rear = LinkQueueEnQueue(rear, 1);
	rear = LinkQueueEnQueue(rear, 2);
	rear = LinkQueueEnQueue(rear, 3);
	rear = LinkQueueEnQueue(rear, 4);
	//�����ɣ���������Ԫ�ؿ�ʼ������
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
	strcpy(a1, "data.bian");//���ַ���"data.bian"���Ƹ�a1
	a2 = (char*)malloc(10 * sizeof(char));
	strcpy(a2, "cheng.net");
	int lengthA1 = strlen(a1);//a1���ĳ���
	int lengthA2 = strlen(a2);//a2���ĳ���
	//���Խ��ϲ��Ĵ��洢�� a1 �У���� a1 �ռ䲻��������realloc��̬����
	if (lengthA1 < lengthA1 + lengthA2) {
		a1 = (char*)realloc(a1, (lengthA1 + lengthA2 + 1) * sizeof(char));
	}
	//�ϲ��������� a1 ��
	for (int i = lengthA1; i < lengthA1 + lengthA2; i++) {
		a1[i] = a2[i - lengthA1];
	}
	//����ĩβҪ��� \0���������
	a1[lengthA1 + lengthA2] = '\0';
	printf("%s", a1);
	//���궯̬����Ҫ�����ͷ�
	free(a1);
	free(a2);
}

void blockStorage() {
	blockLink* head = NULL;
	head = initblockLink(head, "www.jiataoyuan.com");
	displayblockLink(head);
}

void BFAlgorithm(char* B, char* A) {
	//����ͨģʽƥ���㷨��ʵ�ֺ��������� B��α������A��α�Ӵ�
	int i = 0, j = 0;
	while (i < strlen(B) && j < strlen(A)) {
		if (B[i] == A[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	//����ѭ�������ֿ���
	//i=strlen(B)˵���Ѿ�������������ƥ��ʧ�ܣ�
	//j=strlen(A),˵���Ӵ�������ɣ��������гɹ�ƥ��
	if (j == strlen(A)) {
		printf("%d", i - strlen(A) + 1);
	}
	else {
		//���е��ˣ�Ϊi==strlen(B)�����
		printf("%s", "ƥ��ʧ��");
	}

}


void KMPAlgorithm(char* S, char* T) {
	int next[10];
	//����ģʽ��T,��ʼ��next ����
	{
		int i = 1;
		int j = 0;
		next[1] = 0;
		while (i < strlen(T)) {
			if (j == 0 || T[i - 1] == T[j - 1]) {
				i++;
				j++;
				next[i] = j;
				printf("i=%d j=%d next[i]=%d\n", i, j, next[i]);
			}
			else {
				j = next[j];
				printf("next[j]=%d\n", next[j]);
			}
		}
	}
	int i = 1;
	int j = 1;
	while (i <= strlen(S) && j <= strlen(T)) {
		//j==0:����ģʽ���ĵ�һ���ַ��ͺ͵�ǰ���Ե��ַ�����ȣ�
		//S[i-1]==T[j-1],�����Ӧλ���ַ���ȣ���������£�ָ��ǰ���Ե�����ָ���±�i ��j �������
		if (j == 0 || S[i - 1] == T[j - 1]) {
			i++;
			j++;
		}
		else {
			j = next[j];//������Ե������ַ�����ȣ�i ������j ��Ϊ��ǰ�����ַ�����next ֵ
		}
	}
	int result = -1;
	if (j > strlen(T)) {//�������Ϊ�棬˵��ƥ��ɹ�
		result = i - (int)strlen(T);
	}
	printf("%d", result);
}

void orthogonalListOut() {
	CrossList M;
	M.rhead = NULL;
	M.chead = NULL;
	M = CreateMatrix_OL(M);
	printf("�������M:\n");
	OLDisplay(M);
}

void GYLinkDemo() {
	// �����1�ĳ���
	Glist1 C1 = NULL;
	C1 = creatGlist1(C1);
	int dep = GlistDepth1(C1);
	printf("�����1 ����Ϊ��%d ���Ϊ��%d\n", GlistLength1(C1), dep);

	//// �����2�ĳ���
	//Glist2 C2 = NULL;
	//C2 = creatGlist2(C2);
	//printf("�����2 ����Ϊ��%d\n", GlistLength2(C2));
}

void BinaryTreeDemo() {
	// ��ʼ��������
	BiTree Tree;
	CreateBiTree(&Tree);
	printf("�������: \n");
	PreOrderTraverse(Tree);

}

void main() {
	// ���Ա�
	//shunxubiao(); // ˳���
	//lianbiao(); // ����
	//jingtaibiao(); // ��̬����
	//josephRing(); // Լɪ��
	//doubleLink(); // ˫������
	//doubleRingLink(); // ˫��ѭ������
	//rouletteShow(); // ���̶�

	// ջ�Ͷ���
	//sequenceStack(); // ˳��ջ
	//linkStack(); // ��ջ
	//sequenceQueue(); // ˳�����
	//sequenceQueue1(); // ˳�����1 ��״����
	//linkQueue(); // ��ʽ����

	// �ַ���
	//normalStr(); // ����˳��洢
	//heapStorage();// �ѷ���洢
	//blockStorage();// �����洢
	// ��ģʽƥ���㷨
	//BFAlgorithm("ababcabcacbab", "abcac");// BF�㷨����ͨģʽƥ�䣩
	//KMPAlgorithm("ababcabcacbab", "abcac");// KMP�㷨������ģʽƥ���㷨��

	// ����͹����
	// 1 ����
	//execSequenceArray(); // �����˳��洢��ʾ��Ϊ����ʽ����λ����
	//TSMatrixOut(); // ��Ԫ��˳���
	//RLSMatrixOut();// ���߼����ӵ�˳���
	//orthogonalListOut();// ʮ������ѹ��ϡ�����
	//transposeOut(); // �����ת���㷨
	//fastTransposeMatrixOut(); // ����Ŀ���ת���㷨
	//MultSMatrixOut(); // ����˷������߼����ӵ�˳���
	// ����ӷ�������ʮ������

	// 2 �����
	//GYLinkDemo();

	// ������
	BinaryTreeDemo();

}