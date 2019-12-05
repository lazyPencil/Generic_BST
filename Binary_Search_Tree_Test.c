#include <stdio.h>
#include "Binary_Search_Tree.h"

int main(void) {
	BST_head* head = createBST(comparestr); // compare �Լ� ����
	TreeNode* ptr = NULL;
	//int a[5] = { 50, 15, 17, 49, 150 };
	//int a[15] = { 150,156,14343,123,1,2,5,77,200,1451,12342,12412,123,0,1 };
	//int a[3] = { 10,123,1};
	char a[8][6] = { "aaaaa", "zzzzz","AAAaa","zzzzA","asdf","xvzcq","qpqoz","Az"};
	char b[] = "DATA STRUCTURE";
	short suc = 0;
	int i=0;
	/*
	InsertBST(head, &a[0]); // Only Address ! ( Generic Coding )
	InsertBST(head, &a[1]);
	InsertBST(head, &a[2]);
	InsertBST(head, &a[3]);
	InsertBST(head, &a[4]);*/
	for (i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
		InsertBST(head, &a[i]);
	traverse(head->root, printstr);
	puts("");
	for (i = 0; i < (sizeof(a) / sizeof(a[0])); i++) {
		ptr = SearchBST(head, head->root, &a[i]);
		if (ptr)
			//printf("%d\n", *(int*)ptr->dataPtr);
			printf("%s�� BST���� ã�ҽ��ϴ�.\n", (char*)ptr->dataPtr);
		else
			printf("%s�� BST�� �����ϴ�\n", a[i]);
	}
	ptr = SearchBST(head, head->root, b);
	if (ptr)
		//printf("%d\n", *(int*)ptr->dataPtr);
		printf("%s\n", (char*)ptr->dataPtr);
	else
		printf("%s�� BST�� �����ϴ�\n", b);
	ptr = findSmallestBST(head->root);
	//printf("�ּҰ� %d\n", *(int*)ptr->dataPtr);
	printf("�ּҰ� %s\n", (char*)ptr->dataPtr);
	ptr = findLargestBST(head->root);
	//printf("�ִ밪 %d\n", *(int*)ptr->dataPtr);
	printf("�ִ밪 %s\n", (char*)ptr->dataPtr);
	head->root = Delete(head, head->root, &a[0], &suc);
	//printf("%d�� ������ ���״µ� suc = %d\n", a[0], suc);
	printf("%s�� ������ ���״µ� suc = %d\n", a[0], suc);
	head->root = Delete(head, head->root, &a[1], &suc);
	//printf("%d�� ������ ���״µ� suc = %d\n", a[1], suc);
	printf("%s�� ������ ���״µ� suc = %d\n", a[1], suc);
	head->root = Delete(head, head->root, b, &suc);
	//printf("%d�� ������ ���״µ� suc = %d\n", a[13], suc);
	printf("%s�� ������ ���״µ� suc = %d\n", b, suc);
	traverse(head->root, printstr);
	puts("");
	for (i = 0; i < (sizeof(a) / sizeof(a[0])); i++) {
		ptr = SearchBST(head, head->root, &a[i]);
		if (ptr)
			//printf("%d\n", *(int*)ptr->dataPtr);
			printf("%s�� BST���� ã�ҽ��ϴ�.\n", (char*)ptr->dataPtr);
		else
			printf("%s�� BST�� �����ϴ�\n", a[i]);
	}
	DestroyBST(head);
	return 0;
}