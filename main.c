
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

void main() {
	//shunxubiao(); 

	//lianbiao();

	//jingtaibiao();

	josephRing();

}