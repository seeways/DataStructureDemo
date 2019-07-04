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

// ����ϡ����󣩵�ת���㷨
TSMatrix transposeMatrix(TSMatrix M, TSMatrix T) {
	// �ɾ�������зֱ�ֵ���¾�����к��У�ʵ�����л���
	T.m = M.n;
	T.n = M.m;
	T.num = M.num;
	// ������ݴ��ڣ��������������2��ѭ����ʱ�临�Ӷ�Ϊn��ƽ��
	if (T.num) {
		int q = 0;
		// �����ɾ������(�¾������)
		for (int col = 1; col <= M.m; col++) {
			// �������ݣ���������е������ݵ��б꣬�����ݵ����б껥��
			for (int p = 0; p < M.num; p++) {
				if (M.data[p].j == col) {
					T.data[q].i = M.data[p].j;
					T.data[q].j = M.data[p].i;
					T.data[q].data = M.data[p].data;
					q++;
				}
			}
		}
	}

	return T;
}

//ʵ�ֿ���ת���㷨�ĺ���
TSMatrix fastTransposeMatrix(TSMatrix M, TSMatrix T) {
	//��1 �����к����û�
	T.m = M.n;
	T.n = M.m;
	T.num = M.num;
	if (T.num) {
		//����array ����
		int array[MAXSIZE];
		for (int col = 1; col <= M.m; col++) {
			array[col] = 0;
		}
		for (int t = 0; t < M.num; t++) {
			int j = M.data[t].j;
			array[j]++;
		}
		//��������ʼ��cpot ����
		int cpot[MAXSIZE];// T.m+1û����
		cpot[1] = 1;//��һ���е�һ����0 Ԫ�ص�λ��Ĭ��Ϊ1
		// �ӵڶ���λ�ÿ�ʼ������ԭ������У������ù�ʽ
		for (int col = 2; col <= M.m; col++) {
			cpot[col] = cpot[col - 1] + array[col - 1];
		}
		//����һ�μ���ʵ����Ԫ����ת��
		for (int p = 0; p < M.num; p++) {
			//��ȡ��ǰ��Ԫ�������
			int col = M.data[p].j;
			//����������cpot ���飬�ҵ���ǰԪ����Ҫ��ŵ�λ��
			int q = cpot[col];
			//ת�þ������Ԫ��Ĭ�ϴ������±�0 ��ʼ�����õ���q ֵ�ǵ�����λ�ã�����Ҫ��1
			T.data[q - 1].i = M.data[p].j;
			T.data[q - 1].j = M.data[p].i;
			T.data[q - 1].data = M.data[p].data;
			//�����ɺ�cpot �����Ӧ��λ��Ҫ+1���Ա��´θ��д洢��һ����Ԫ��
			cpot[col]++;
		}
	}
	return T;
}

void transposeOut() {
	TSMatrix M;
	// ���������У��У���0Ԫ�ظ���
	M.m = 2;
	M.n = 3;
	M.num = 4;
	// ���������б꣬�б�����ֵ
	M.data[0].i = 1;
	M.data[0].j = 2;
	M.data[0].data = 1;
	M.data[1].i = 2;
	M.data[1].j = 2;
	M.data[1].data = 3;
	M.data[2].i = 3;
	M.data[2].j = 1;
	M.data[2].data = 6;
	M.data[3].i = 3;
	M.data[3].j = 2;
	M.data[3].data = 5;
	// ����һ��Ҫת�õ��¾���
	TSMatrix T;
	T = transposeMatrix(M, T);
	for (int i = 0; i < T.num; i++) {
		printf("(%d,%d,%d)\n", T.data[i].i, T.data[i].j, T.data[i].data);
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





void fastTransposeMatrixOut() {
	TSMatrix M;
	M.m = 2;
	M.n = 3;
	M.num = 3;
	M.data[0].i = 1;
	M.data[0].j = 2;
	M.data[0].data = 1;
	M.data[1].i = 2;
	M.data[1].j = 2;
	M.data[1].data = 3;
	M.data[2].i = 3;
	M.data[2].j = 1;
	M.data[2].data = 6;
	TSMatrix T;
	T = fastTransposeMatrix(M, T);
	printf("ת�þ�����Ԫ���Ϊ��\n");
	for (int i = 0; i < T.num; i++) {
		printf("(%d,%d,%d)\n", T.data[i].i, T.data[i].j, T.data[i].data);
	}
}