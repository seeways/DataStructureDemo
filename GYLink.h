#pragma once
#ifndef GYLink

#include <stdio.h>
#include <stdlib.h>

// �����1
typedef struct GLNode1 {
	int tag;//��־��
	union {
		char atom;//ԭ�ӽ���ֵ��
		struct {
			struct GLNode1* hp, * tp;
		}ptr;//�ӱ����ָ����hpָ���ͷ��tpָ���β
	};
}*Glist1;
Glist1 creatGlist1(Glist1 C);
int GlistLength1(Glist1 C);
int GlistDepth1(Glist1 C);

// �����2
typedef struct GLNode2 {
	int tag;//��־��
	union {
		char atom;//ԭ�ӽ���ֵ��
		struct GLNode2* hp;//�ӱ����ָ����hpָ���ͷ
	};
	struct GLNode2* tp;//�����tp�൱�������nextָ�룬����ָ����һ������Ԫ��
}*Glist2;

Glist2 creatGlist2(Glist2 C);
int GlistLength2(Glist2 C);

#endif // !GYLink
