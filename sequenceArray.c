#include "sequenceArray.h"

Status InitSequenceArray(sequenceArray* A, int dim, ...)
{
	//��ά��dim�͸�ά���ȺϷ���������Ӧ������A��������OK
	int elemtotal = 1, i; // elemtotal��Ԫ����ֵ
	va_list ap;
	if (dim<1 || dim>MAX_ARRAY_DIM)
		return ERROR;
	(*A).dim = dim;
	(*A).bounds = (int*)malloc(dim * sizeof(int));
	if (!(*A).bounds)
		exit(OVERFLOW);
	va_start(ap, dim);
	for (i = 0; i < dim; ++i)
	{
		(*A).bounds[i] = va_arg(ap, int);
		if ((*A).bounds[i] < 0)
			return UNDERFLOW;
		elemtotal *= (*A).bounds[i];
	}
	va_end(ap);
	(*A).base = (ElemType*)malloc(elemtotal * sizeof(ElemType));
	if (!(*A).base)
		exit(OVERFLOW);
	(*A).constants = (int*)malloc(dim * sizeof(int));
	if (!(*A).constants)
		exit(OVERFLOW);
	(*A).constants[dim - 1] = 1;
	for (i = dim - 2; i >= 0; --i)
		(*A).constants[i] = (*A).bounds[i + 1] * (*A).constants[i + 1];
	return OK;
}


Status DestroySequenceArrayArray(sequenceArray* A)
{
	//��������A
	if ((*A).base)
	{
		free((*A).base);
		(*A).base = NULL;
	}
	else
		return ERROR;
	if ((*A).bounds)
	{
		free((*A).bounds);
		(*A).bounds = NULL;
	}
	else
		return ERROR;
	if ((*A).constants)
	{
		free((*A).constants);
		(*A).constants = NULL;
	}
	else
		return ERROR;
	return OK;
}


Status sequenceArrayLocate(sequenceArray A, va_list ap, int* off) // Value()��Assign()���ô˺��� */
{
	//��apָʾ�ĸ��±�ֵ�Ϸ����������Ԫ����A�е���Ե�ַoff
	int i, ind;
	*off = 0;
	for (i = 0; i < A.dim; i++)
	{
		ind = va_arg(ap, int);
		if (ind < 0 || ind >= A.bounds[i])
			return OVERFLOW;
		*off += A.constants[i] * ind;
	}
	return OK;
}


Status sequenceArrayValue(ElemType* e, sequenceArray A, ...) //��VC++�У�...֮ǰ���ββ�������������
{
	//����Ϊ��ά���±�ֵ�������±�Ϸ�����e����ֵΪA����Ӧ��Ԫ��ֵ
	va_list ap;
	Status result;
	int off;
	va_start(ap, A);
	if ((result = sequenceArrayLocate(A, ap, &off)) == OVERFLOW) //����Locate()
		return result;
	*e = *(A.base + off);
	return OK;
}


Status SequenceArrayAssign(sequenceArray* A, ElemType e, ...)
{
	//����Ϊ��ά���±�ֵ�������±�Ϸ�����e��ֵ����A��ָ����Ԫ��
	va_list ap;
	Status result;
	int off;
	va_start(ap, e);
	if ((result = sequenceArrayLocate(*A, ap, &off)) == OVERFLOW) //����Locate()
		return result;
	*((*A).base + off) = e;
	return OK;
}


void execSequenceArray() {
	sequenceArray A;
	int i, j, k, * p, dim = 3, bound1 = 3, bound2 = 4, bound3 = 2; //a[3][4][2]����
	ElemType e, * p1;
	InitSequenceArray(&A, dim, bound1, bound2, bound3); //����3��4��2��3ά����A
	p = A.bounds;
	printf("A.bounds=");
	for (i = 0; i < dim; i++) //˳�����A.bounds
		printf("%d ", *(p + i));
	p = A.constants;
	printf("\nA.constants=");
	for (i = 0; i < dim; i++) //˳�����A.constants
		printf("%d ", *(p + i));
	printf("\n%dҳ%d��%d�о���Ԫ������:\n", bound1, bound2, bound3);
	for (i = 0; i < bound1; i++)
	{
		for (j = 0; j < bound2; j++)
		{
			for (k = 0; k < bound3; k++)
			{
				SequenceArrayAssign(&A, i * 100 + j * 10 + k, i, j, k); // ��i*100+j*10+k��ֵ��A[i][j][k]
				sequenceArrayValue(&e, A, i, j, k); //��A[i][j][k]��ֵ����e
				printf("A[%d][%d][%d]=%2d ", i, j, k, e); //���A[i][j][k]
			}
			printf("\n");
		}
		printf("\n");
	}
	p1 = A.base;
	printf("A.base=\n");
	for (i = 0; i < bound1 * bound2 * bound3; i++) //˳�����A.base
	{
		printf("%4d", *(p1 + i));
		if (i % (bound2 * bound3) == bound2 * bound3 - 1)
			printf("\n");
	}
	DestroySequenceArrayArray(&A);
}