#include "ThreadBinaryTree.h"


BiThrTree pre = NULL;

//����ǰ���ʼ��������
//����ͺ���ֻ��ı丳ֵ����λ�ü���
void CreateTree(BiThrTree* tree) {
	char data;
	scanf("%c", &data);
	if (data != '#') {
		if (!((*tree) = (BiThrNode*)malloc(sizeof(BiThrNode)))) {
			printf("������ռ�ʧ��");
			return;
		}
		else {
			(*tree)->data = data;//����ǰ�������ʽ��ʼ��������
			CreateTree(&((*tree)->lchild));//��ʼ��������
			CreateTree(&((*tree)->rchild));//��ʼ��������
		}
		printf("%c",(*tree)->data);
	}
	else {
		*tree = NULL;
	}

}

//����Զ���������������
void InThreading(BiThrTree p) {
	//�����ǰ������
	if (p) {
		InThreading(p->lchild);//�ݹ鵱ǰ����������������������
		//�����ǰ���û�����ӣ����־λ��Ϊ1����ָ����ָ����һ���pre
		if (!p->lchild) {
			p->Ltag = Thread;
			p->lchild = pre;
		}
		//���pre û���Һ��ӣ��ұ�־λ��Ϊ1����ָ����ָ��ǰ��㡣
		if (pre && !pre->rchild) {
			pre->Rtag = Thread;
			pre->rchild = p;
		}
		pre = p;//pre ָ��ǰ���
		InThreading(p->rchild);//�ݹ�����������������
	}
}

//�����������������
void InOrderThraverse_Thr(BiThrTree p)
{
	while (p)
	{
		//һֱ�����ӣ����һ��Ϊ�����������ŵ�һ��
		while (p->Ltag == Link) {
			p = p->lchild;
			printf("%c ", p->data);
		}
		printf("%c ", p->data); //�����������
		//������ұ�־λΪ1 ʱ��ֱ���ҵ����̽��
		while (p->Rtag == Thread && p->rchild != NULL)
		{
			p = p->rchild;
			printf("%c ", p->data);
		}
		//���򣬰�����������Ĺ��ɣ������������������µĽ�㣬Ҳ���Ǽ���ѭ������
		p = p->rchild;
	}
}



//����˫����������
void InOrderThread_Head(BiThrTree* h, BiThrTree t)
{
	//��ʼ��ͷ���
	(*h) = (BiThrTree)malloc(sizeof(BiThrNode));
	if ((*h) == NULL) {
		printf("�����ڴ�ʧ��");
		return;
	}
	(*h)->rchild = *h;
	(*h)->Rtag = Link;
	//����������ǿ���
	if (!t) {
		(*h)->lchild = *h;
		(*h)->Ltag = Link;
	}
	else {
		pre = *h;//pre ָ��ͷ���
		(*h)->lchild = t;//ͷ���������Ϊ�������
		(*h)->Ltag = Link;
		InThreading(t);//��������������pre �����Ϊȫ�ֱ�����������������pre ���ָ���������������һ�����
		pre->rchild = *h;
		pre->Rtag = Thread;
		(*h)->rchild = pre;
	}
}

//�����������˫������������
void DoubleInOrderThraverse_Thr(BiThrTree h)
{
	BiThrTree p;
	p = h->lchild; //p ָ������
	while (p != h)
	{
		while (p->Ltag == Link) //��ltag = 0 ʱѭ�����������еĵ�һ�����
		{
			p = p->lchild;
		}
		printf("%c ", p->data); //��ʾ������ݣ����Ը���Ϊ�����Խ��Ĳ���
		while (p->Rtag == Thread && p->rchild != h)
		{
			p = p->rchild;
			printf("%c ", p->data);
		}
		p = p->rchild; //p ������������
	}
}