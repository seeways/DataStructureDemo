#pragma once
#ifndef HuffmanTree

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//�����������ṹ
typedef struct {
	int weight;//���Ȩ��
	int parent, left, right;//����㡢���ӡ��Һ����������е�λ���±�
}HTNode, * HuffmanTree;

//��̬��ά���飬�洢����������
typedef char** HuffmanCode;

//HT�����д�ŵĹ���������end��ʾHT�����д�Ž�������λ�ã�s1��s2���ݵ���HT������Ȩ��ֵ��С����������������е�λ��
void Select(HuffmanTree HT, int end, int* s1, int* s2);

//HTΪ��ַ���ݵĴ洢�������������飬wΪ�洢���Ȩ��ֵ�����飬nΪ������
void CreateHuffmanTree(HuffmanTree* HT, int* w, int n);

//HTΪ����������HCΪ�洢������������Ķ�ά��̬���飬nΪ���ĸ���
void HuffmanCoding(HuffmanTree HT, HuffmanCode* HC, int n);

//��ӡ����������ĺ���
void PrintHuffmanCode(HuffmanCode htable, int* w, int n);

#endif // !HuffmanTree
