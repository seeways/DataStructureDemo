

#include "jingtaibiao.h"



//������������
void jingtaibiaoReserveArr(component* array) {
	for (int i = 0; i < maxSize; i++) {
		array[i].cur = i + 1;//��ÿ������������ӵ�һ��
	}
	array[maxSize - 1].cur = 0;//�������һ�������α�ֵΪ0
}

//��ȡ����ռ�
int jingtaibiaoMallocArr(component* array) {
	//����������ǿգ��򷵻ط���Ľ���±꣬���򷵻� 0�����������һ�����ʱ���ý����α�ֵΪ 0��
	int i = array[0].cur;
	if (array[0].cur) {
		array[0].cur = array[i].cur;
	}
	return i;
}

//��ʼ����̬����
int jingtaibiaoInitArr(component* array) {
	jingtaibiaoReserveArr(array);
	int body = jingtaibiaoMallocArr(array);
	//����һ��������������ָ��ʹ��ָ�����������һ����㣬��Ϊ����Ϊ�գ����Ժ�ͷ����غ�
	int tempBody = body;
	array[tempBody].data = 0;
	for (int i = 1; i < 5; i++) {
		int j = jingtaibiaoMallocArr(array);//�ӱ����������ó����еķ���
		array[tempBody].cur = j;//������Ŀ��з�����������������һ��������
		array[j].data = i;//��������ķ������������ʼ��
		tempBody = j;//��ָ���������һ������ָ�����
	}
	
	array[tempBody].cur = 0;//�µ��������һ������ָ������Ϊ0
	return body;
}


//�������в������ݣ�body��ʾ�����ͷ����������е�λ�ã�add��ʾ����Ԫ�ص�λ�ã�a��ʾҪ���������
void jingtaibiaoInsertArr(component* array, int body, int add, int a) {
	int tempBody = body;//tempBody�������ṹ������ʹ��
	//�ҵ�Ҫ����λ�õ���һ������������е�λ��
	for (int i = 1; i < add; i++) {
		tempBody = array[tempBody].cur;
	}
	int insert = jingtaibiaoMallocArr(array);//����ռ䣬׼������
	array[insert].data = a;
	array[insert].cur = array[tempBody].cur;//�²�������α������ֱ��ǰ�������α�
	array[tempBody].cur = insert;//ֱ��ǰ�������α�����²��������������е��±�
}

//����������տռ�ĺ���������arrayΪ�洢���ݵ����飬k��ʾδʹ�ýڵ�����������±�
void jingtaibiaoFreeArr(component* array, int k) {
	array[k].cur = array[0].cur;
	array[0].cur = k;
}
//ɾ����㺯����body��ʾ�����ͷ����������е�λ��,a ��ʾ��ɾ��������������ŵ�����
void jingtaibiaoDeletArr(component* array, int body, int a) {
	int tempBody = body;
	//�ҵ���ɾ������λ��
	while (array[tempBody].data != a) {
		tempBody = array[tempBody].cur;
		//��tempBodyΪ0ʱ����ʾ�������������˵��������û�д洢�����ݵĽ��
		if (tempBody == 0) {
			printf("������û�д�����");
			return;
		}
	}
	//���е��ˣ�֤���иý��
	int del = tempBody;
	tempBody = body;
	//�ҵ��ý�����һ����㣬��ɾ������
	while (array[tempBody].cur != del) {
		tempBody = array[tempBody].cur;
	}
	//����ɾ�������α�ֱ�Ӹ���ɾ��������һ�����
	array[tempBody].cur = array[del].cur;
	//���ձ�ժ���ڵ�Ŀռ�
	jingtaibiaoFreeArr(array, del);

}

//����body��Ϊͷ���������в���������Ϊelem�Ľ���������е�λ��
int jingtaibiaoSelectElem(component* array, int body, int elem) {
	int tempBody = body;
	//���α�ֵΪ0ʱ����ʾ�������
	while (array[tempBody].cur != 0) {
		if (array[tempBody].data == elem) {
			return tempBody;
		}
		tempBody = array[tempBody].cur;
	}
	return -1;//����-1����ʾ��������û���ҵ���Ԫ��
}

//����body��Ϊͷ���������н�������ΪoldElem�Ľ�㣬�������ΪnewElem
void jingtaibiaoAmendElem(component* array, int body, int oldElem, int newElem) {
	int add = jingtaibiaoSelectElem(array, body, oldElem);
	if (add == -1) {
		printf("�޸���Ԫ��");
		return;
	}
	array[add].data = newElem;
}


void jingtaibiaoDisplayArr(component* array, int body) {
	int tempBody = body;//tempBody׼��������ʹ��
	while (array[tempBody].cur) {
		printf("%d,%d  ", array[tempBody].data, array[tempBody].cur);
		tempBody = array[tempBody].cur;
	}
	printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
}


