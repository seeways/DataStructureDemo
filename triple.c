#include "triple.h"

//输出存储的稀疏矩阵
void TSMatrixDisplay(TSMatrix M) {
	// 行数从1开始，< 设定行数n
	for (int i = 1; i <= M.n; i++) {
		// 列数从1开始，< 设定列数m
		for (int j = 1; j <= M.m; j++) {
			// 控制元素
			int value = 0;
			// 数据个数小于设定个数num
			for (int k = 0; k < M.num; k++) {
				// 行数=数据的行标，并且列数=数据的列标，则打印数据
				if (i == M.data[k].i && j == M.data[k].j) {
					printf("%d ", M.data[k].data);
					value = 1;
					break;
				}
			}
			// 其他的都打印0
			if (value == 0)
				printf("0 ");
		}
		printf("\n");
	}
}

//矩阵的输出函数
void RLSMatrixDisplay(RLSMatrix M) {
	// 行数从1开始，<= 矩阵的行数
	for (int i = 1; i <= M.mu; i++) {
		// 列数从1开始，小于矩阵的列数
		for (int j = 1; j <= M.nu; j++) {
			// 控制元素
			int value = 0;
			// 如果行数+1小于或等于行数，则遍历每行首个非0元素
			if (i + 1 <= M.mu) {
				for (int k = M.rpos[i]; k < M.rpos[i + 1]; k++) {
					// 行数=数据的行标，并且列数=数据的列标，则打印数据
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
				// 最后一行的剩余值置0
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
	// 以上定义了一个3行3列，非0元素有3个的矩阵结构
	// 以下定义了第1行第1列数据为1的结构体
	M.data[0].i = 1;
	M.data[0].j = 1;
	M.data[0].data = 1;
	// 以下定义了第2行第3列数据为5的结构体
	M.data[1].i = 2;
	M.data[1].j = 3;
	M.data[1].data = 5;
	// 以下定义了第3行第1列数据为3的结构体
	M.data[2].i = 3;
	M.data[2].j = 1;
	M.data[2].data = 3;
	TSMatrixDisplay(M);
}




void RLSMatrixOut() {
	RLSMatrix M;
	M.mu = 3; // 行数
	M.nu = 4; // 列数
	M.tu = 4; // 非0元素个数

	// 每行第一个非 0 元素在一维数组中的存储位置
	M.rpos[1] = 1; //value=3 
	M.rpos[2] = 3; //value=1
	M.rpos[3] = 4; //value=2
	// 以下定义了第1行第2列数据为3的结构体
	M.data[1].data = 3;
	M.data[1].i = 1;
	M.data[1].j = 2;
	// 以下定义了第1行第4列数据为5的结构体
	M.data[2].data = 5;
	M.data[2].i = 1;
	M.data[2].j = 4;
	// 以下定义了第2行第3列数据为1的结构体
	M.data[3].data = 1;
	M.data[3].i = 2;
	M.data[3].j = 3;
	// 以下定义了第3行第1列数据为2的结构体
	M.data[4].data = 2;
	M.data[4].i = 3;
	M.data[4].j = 1;
	//输出矩阵
	RLSMatrixDisplay(M);
}