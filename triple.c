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

// 矩阵（稀疏矩阵）的转置算法
TSMatrix transposeMatrix(TSMatrix M, TSMatrix T) {
	// 旧矩阵的行列分别赋值给新矩阵的列和行，实现行列互换
	T.m = M.n;
	T.n = M.m;
	T.num = M.num;
	// 如果数据存在，则遍历，由于有2个循环，时间复杂度为n的平方
	if (T.num) {
		int q = 0;
		// 遍历旧矩阵的列(新矩阵的行)
		for (int col = 1; col <= M.m; col++) {
			// 遍历数据，如果矩阵列等于数据的列标，则数据的行列标互换
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

//实现快速转置算法的函数
TSMatrix fastTransposeMatrix(TSMatrix M, TSMatrix T) {
	//第1 步：行和列置换
	T.m = M.n;
	T.n = M.m;
	T.num = M.num;
	if (T.num) {
		//计算array 数组
		int array[MAXSIZE];
		for (int col = 1; col <= M.m; col++) {
			array[col] = 0;
		}
		for (int t = 0; t < M.num; t++) {
			int j = M.data[t].j;
			array[j]++;
		}
		//创建并初始化cpot 数组
		int cpot[MAXSIZE];// T.m+1没法用
		cpot[1] = 1;//第一列中第一个非0 元素的位置默认为1
		// 从第二个位置开始，遍历原矩阵的列，并套用公式
		for (int col = 2; col <= M.m; col++) {
			cpot[col] = cpot[col - 1] + array[col - 1];
		}
		//遍历一次即可实现三元组表的转置
		for (int p = 0; p < M.num; p++) {
			//提取当前三元组的列数
			int col = M.data[p].j;
			//根据列数和cpot 数组，找到当前元素需要存放的位置
			int q = cpot[col];
			//转置矩阵的三元组默认从数组下标0 开始，而得到的q 值是单纯的位置，所以要减1
			T.data[q - 1].i = M.data[p].j;
			T.data[q - 1].j = M.data[p].i;
			T.data[q - 1].data = M.data[p].data;
			//存放完成后，cpot 数组对应的位置要+1，以便下次该列存储下一个三元组
			cpot[col]++;
		}
	}
	return T;
}


// 矩阵乘法（行逻辑链接的顺序表）
RLSMatrix MultSMatrix(RLSMatrix A, RLSMatrix B, RLSMatrix C)
{
	//如果矩阵A的列数与矩阵B的行数不等，则不能做矩阵乘运算
	if (A.nu != B.mu)
		return C;
	C.mu = A.mu;
	C.nu = B.nu;
	C.tu = 0;
	//如果其中任意矩阵的元素个数为零，做乘法元素没有意义，全是0
	if (A.tu * B.tu == 0)
		return C;
	else
	{
		int arow;
		int ccol;
		//遍历矩阵A的每一行
		for (arow = 1; arow <= A.mu; arow++)
		{
			//创建一个临时存储乘积结果的数组，且初始化为0，遍历每次都需要清空
			int ctemp[MAXRC + 1] = { 0 };
			C.rpos[arow] = C.tu + 1;
			//根据行数，在三元组表中找到该行所有的非0元素的位置
			int tp;
			if (arow < A.mu)
				tp = A.rpos[arow + 1];//获取矩阵A的下一行第一个非零元素在data数组中位置
			else
				tp = A.tu + 1;//若当前行是最后一行，则取最后一个元素+1

			int p;
			int brow;
			//遍历当前行的所有的非0元素
			for (p = A.rpos[arow]; p < tp; p++)
			{
				brow = A.data[p].j;//取该非0元素的列数，便于去B中找对应的做乘积的非0元素
				int t;
				// 判断如果对于A中非0元素，找到矩阵B中做乘法的那一行中的所有的非0元素
				if (brow < B.mu)
					t = B.rpos[brow + 1];
				else
					t = B.tu + 1;
				int q;
				//遍历找到的对应的非0元素，开始做乘积运算
				for (q = B.rpos[brow]; q < t; q++)
				{
					//得到的乘积结果，每次和ctemp数组中相应位置的数值做加和运算
					ccol = B.data[q].j;
					ctemp[ccol] += A.data[p].data * B.data[q].data;
				}
			}
			//矩阵C的行数等于矩阵A的行数，列数等于矩阵B的列数，所以，得到的ctemp存储的结果，也会在C的列数的范围内
			for (ccol = 1; ccol <= C.nu; ccol++)
			{
				//由于结果可以是0，而0不需要存储，所以在这里需要判断
				if (ctemp[ccol])
				{
					//不为0，则记录矩阵中非0元素的个数的变量tu要+1；且该值不能超过存放三元素数组的空间大小
					if (++C.tu > MAXSIZE)
						return C;
					else {
						C.data[C.tu].data = ctemp[ccol];
						C.data[C.tu].i = arow;
						C.data[C.tu].j = ccol;
					}
				}
			}
		}
		return C;
	}
}
void transposeOut() {
	TSMatrix M;
	// 定义矩阵的行，列，非0元素个数
	M.m = 2;
	M.n = 3;
	M.num = 4;
	// 定义矩阵的行标，列表，数据值
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
	// 定义一个要转置的新矩阵
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

// 矩阵的快速转置输出
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
	printf("转置矩阵三元组表为：\n");
	for (int i = 0; i < T.num; i++) {
		printf("(%d,%d,%d)\n", T.data[i].i, T.data[i].j, T.data[i].data);
	}
}


// 矩阵乘法（行逻辑链接的顺序表）
void MultSMatrixOut() {
	RLSMatrix M, N, T;

	M.tu = 4;
	M.mu = 3;
	M.nu = 4;

	M.rpos[1] = 1;
	M.rpos[2] = 3;
	M.rpos[3] = 4;

	M.data[1].data = 3;
	M.data[1].i = 1;
	M.data[1].j = 1;

	M.data[2].data = 5;
	M.data[2].i = 1;
	M.data[2].j = 4;

	M.data[3].data = -1;
	M.data[3].i = 2;
	M.data[3].j = 2;

	M.data[4].data = 2;
	M.data[4].i = 3;
	M.data[4].j = 1;

	N.tu = 4;
	N.mu = 4;
	N.nu = 2;

	N.rpos[1] = 1;
	N.rpos[2] = 2;
	N.rpos[3] = 3;
	N.rpos[4] = 5;

	N.data[1].data = 2;
	N.data[1].i = 1;
	N.data[1].j = 2;

	N.data[2].data = 1;
	N.data[2].i = 2;
	N.data[2].j = 1;

	N.data[3].data = -2;
	N.data[3].i = 3;
	N.data[3].j = 1;

	N.data[4].data = 4;
	N.data[4].i = 3;
	N.data[4].j = 2;

	T = MultSMatrix(M, N, T);
	for (int i = 1; i <= T.tu; i++) {
		printf("(%d,%d,%d)\n", T.data[i].i, T.data[i].j, T.data[i].data);
	}
}