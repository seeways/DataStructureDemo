#include "BackTrackAlgorithm.h"

//i���������±꣬n��ʾ����������Ԫ��ֵ
void PowerSet(int i, int n) {
	//��i>nʱ��˵�����������е�Ԫ�ض�����ѡ�񣬿�ʼ�ж�
	if (i > n) {
		for (int j = 1; j <= n; j++) {
			//��������д�ŵ��� 1��˵���ڵ�������ʱ��ѡ��ȡ��Ԫ�أ�����Ӧ�������±꣬���ԣ��������
			if (set[j] == 1) {
				printf("%d ", j);
			}
		}
		printf("\n");
	}
	else {
		//���ѡ��Ҫ��Ԫ�أ���Ӧ�����鵥Ԫ�и�ֵΪ1����֮����ֵΪ0��Ȼ���������̽��
		set[i] = 1; PowerSet(i + 1, n);
		set[i] = 0; PowerSet(i + 1, n);
	}
}