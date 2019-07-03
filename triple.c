#include "triple.h"

//����洢��ϡ�����
void TSMatrixDisplay(TSMatrix M) {
	// ������1��ʼ��< �趨����n
	for (int i = 1; i <= M.n; i++) {
		// ������1��ʼ��< �趨����m
		for (int j = 1; j <= M.m; j++) {
			// ����Ԫ��
			int value = 0;
			// ���ݸ���С���趨����num
			for (int k = 0; k < M.num; k++) {
				// ����=���ݵ��б꣬��������=���ݵ��б꣬���ӡ����
				if (i == M.data[k].i && j == M.data[k].j) {
					printf("%d ", M.data[k].data);
					value = 1;
					break;
				}
			}
			// �����Ķ���ӡ0
			if (value == 0)
				printf("0 ");
		}
		printf("\n");
	}
}

//������������
void RLSMatrixDisplay(RLSMatrix M) {
	// ������1��ʼ��<= ���������
	for (int i = 1; i <= M.mu; i++) {
		// ������1��ʼ��С�ھ��������
		for (int j = 1; j <= M.nu; j++) {
			// ����Ԫ��
			int value = 0;
			// �������+1С�ڻ���������������ÿ���׸���0Ԫ��
			if (i + 1 <= M.mu) {
				for (int k = M.rpos[i]; k < M.rpos[i + 1]; k++) {
					// ����=���ݵ��б꣬��������=���ݵ��б꣬���ӡ����
					if (i == M.data[k].i && j == M.data[k].j) {
						printf("%d ", M.data[k].data);
						value = 1;
						break;
					}
				}
				if (value == 0) {
					printf("0 ");
				}
			}
			else {
				// ���һ�е�ʣ��ֵ��0
				for (int k = M.rpos[i]; k <= M.tu; k++) {
					if (i == M.data[k].i && j == M.data[k].j) {
						printf("%d ", M.data[k].data);
						value = 1;
						break;
					}
				}
				if (value == 0) {
					printf("0 ");
				}
			}
		}
		printf("\n");
	}
}

void TSMatrixOut() {
	TSMatrix M;
	M.m = 3;
	M.n = 3;
	M.num = 3;
	// ���϶�����һ��3��3�У���0Ԫ����3���ľ���ṹ
	// ���¶����˵�1�е�1������Ϊ1�Ľṹ��
	M.data[0].i = 1;
	M.data[0].j = 1;
	M.data[0].data = 1;
	// ���¶����˵�2�е�3������Ϊ5�Ľṹ��
	M.data[1].i = 2;
	M.data[1].j = 3;
	M.data[1].data = 5;
	// ���¶����˵�3�е�1������Ϊ3�Ľṹ��
	M.data[2].i = 3;
	M.data[2].j = 1;
	M.data[2].data = 3;
	TSMatrixDisplay(M);
}




void RLSMatrixOut() {
	RLSMatrix M;
	M.mu = 3; // ����
	M.nu = 4; // ����
	M.tu = 4; // ��0Ԫ�ظ���

	// ÿ�е�һ���� 0 Ԫ����һά�����еĴ洢λ��
	M.rpos[1] = 1; //value=3 
	M.rpos[2] = 3; //value=1
	M.rpos[3] = 4; //value=2
	// ���¶����˵�1�е�2������Ϊ3�Ľṹ��
	M.data[1].data = 3;
	M.data[1].i = 1;
	M.data[1].j = 2;
	// ���¶����˵�1�е�4������Ϊ5�Ľṹ��
	M.data[2].data = 5;
	M.data[2].i = 1;
	M.data[2].j = 4;
	// ���¶����˵�2�е�3������Ϊ1�Ľṹ��
	M.data[3].data = 1;
	M.data[3].i = 2;
	M.data[3].j = 3;
	// ���¶����˵�3�е�1������Ϊ2�Ľṹ��
	M.data[4].data = 2;
	M.data[4].i = 3;
	M.data[4].j = 1;
	//�������
	RLSMatrixDisplay(M);
}