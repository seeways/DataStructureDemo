
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
	link* p = initLink();
	test1Display(p);

	printf("���±�4��λ�ò���Ԫ��5��\n");
	p = insertElem(p, 5, 4);
	test1Display(p);

	printf("ɾ���±�3:\n");
	p = delElem(p, 3);
	test1Display(p);

	printf("����Ԫ��2���±�Ϊ��\n");
	int address = selectElem(p, 2);
	if (address == -1) {
		printf("û�и�Ԫ��");
	}
	else {
		printf("Ԫ��2���±�Ϊ��%d\n", address);
	}
	printf("�����±�3��λ���ϵ�����Ϊ7:\n");
	p = amendElem(p, 3, 7);
	test1Display(p);

}

void jingtaibiao() {
	component array[maxSize];
	int body = initArr(array);
	printf("��̬����Ϊ��\n");
	test2DisplayArr(array, body);

}


void main() {
	//shunxubiao(); 

	//lianbiao();

	jingtaibiao();

}