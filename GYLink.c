#include "GYLink.h"

// �����1
Glist1 creatGlist1(Glist1 C) {
	//�����C
	C = (Glist1)malloc(sizeof(Glist1));
	C->tag = 1;
	//��ͷԭ�ӡ�a��
	C->ptr.hp = (Glist1)malloc(sizeof(Glist1));
	C->ptr.hp->tag = 0;
	C->ptr.hp->atom = 'a';
	//��β�ӱ�b,c,d��,��һ������
	C->ptr.tp = (Glist1)malloc(sizeof(Glist1));
	C->ptr.tp->tag = 1;
	C->ptr.tp->ptr.hp = (Glist1)malloc(sizeof(Glist1));
	C->ptr.tp->ptr.tp = NULL;
	//��ʼ�����һ������Ԫ�أ�b,c,d��,��ͷΪ��b������βΪ��c,d��
	C->ptr.tp->ptr.hp->tag = 1;
	C->ptr.tp->ptr.hp->ptr.hp = (Glist1)malloc(sizeof(Glist1));
	C->ptr.tp->ptr.hp->ptr.hp->tag = 0;
	C->ptr.tp->ptr.hp->ptr.hp->atom = 'b';
	C->ptr.tp->ptr.hp->ptr.tp = (Glist1)malloc(sizeof(Glist1));
	//����ӱ�(c,d)����ͷΪc����βΪd
	C->ptr.tp->ptr.hp->ptr.tp->tag = 1;
	C->ptr.tp->ptr.hp->ptr.tp->ptr.hp = (Glist1)malloc(sizeof(Glist1));
	C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->tag = 0;
	C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->atom = 'c';
	C->ptr.tp->ptr.hp->ptr.tp->ptr.tp = (Glist1)malloc(sizeof(Glist1));
	//��ű�βd
	C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->tag = 1;
	C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp = (Glist1)malloc(sizeof(Glist1));
	C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->tag = 0;
	C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->atom = 'd';
	C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.tp = NULL;
	return C;
}

// �����1 �ĳ���
int GlistLength1(Glist1 C) {
	int Number = 0;
	Glist1 P = C;
	while (P) {
		Number++;
		P = P->ptr.tp;
	}
	return Number;
}


int GlistDepth1(Glist1 C) {
	//�����C Ϊ�ձ�ʱ��ֱ�ӷ��س���1��
	if (!C) {
		return 1;
	}
	//�����C Ϊԭ��ʱ��ֱ�ӷ���0��
	if (C->tag == 0) {
		return 0;
	}
	int max = 0;//���ñ�C �ĳ�ʼ����Ϊ0��
	for (Glist1 pp = C; pp; pp = pp->ptr.tp) {
		int dep = GlistDepth1(pp->ptr.hp);
		if (dep > max) {
			max = dep;//ÿ���ҵ����б�����������ı�����max ��¼
		}
	}
	//�����������˴�������������ǿձ�����ԭ�ӷ��ص���0����ʵ�ʳ�����1�����ԣ��˴�Ҫ+1��
	return max + 1;
}


// �����2
Glist2 creatGlist2(Glist2 C) {
	C = (Glist2)malloc(sizeof(Glist2));
	C->tag = 1;
	C->hp = (Glist2)malloc(sizeof(Glist2));
	C->tp = NULL;
	//��ͷԭ��a
	C->hp->tag = 0;
	C->atom = 'a';

	C->hp->tp = (Glist2)malloc(sizeof(Glist2));
	C->hp->tp->tag = 1;
	C->hp->tp->hp = (Glist2)malloc(sizeof(Glist2));
	C->hp->tp->tp = NULL;
	//ԭ��b
	C->hp->tp->hp->tag = 0;
	C->hp->tp->hp->atom = 'b';
	C->hp->tp->hp->tp = (Glist2)malloc(sizeof(Glist2));
	//ԭ��c
	C->hp->tp->hp->tp->tag = 0;
	C->hp->tp->hp->tp->atom = 'c';
	C->hp->tp->hp->tp->tp = (Glist2)malloc(sizeof(Glist2));
	//ԭ��d
	C->hp->tp->hp->tp->tp->tag = 0;
	C->hp->tp->hp->tp->tp->atom = 'd';
	C->hp->tp->hp->tp->tp->tp = NULL;
	return C;
}

// �����2 �ĳ���
int GlistLength2(Glist2 C) {
	int Number = 0;
	Glist2 P = C;
	while (P) {
		if (P->tag == 0)
		{
			printf("tag=0 %c %d ", P->atom, Number);
			Number++;
			P = P->tp;
		}else if (P->tag == 1) {
			Number++;
			printf("tag=1 %d ", Number);
			P = P->hp;
		}
	}
	return Number;
}

