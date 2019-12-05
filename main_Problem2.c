#define _CRT_SECURE_NO_WARNINGS
#define NUM 5
#define LEN 30
#include <stdio.h>
#include "BST_queue_array_Problem2.h"

void BreadthFirstSearch(TreeNode* pRoot, queue* pQ);
void printAll(TreeNode* pRoot, void(*func)(void* dataptr), queue* pQ);
void compareASCII(void* dataPtr1, void* dataPtr2);

int main(void) {
	int menu,sort,idx=0,k;
	short suc;
	char SearchDel[LEN + 1] = { 0, };
	BST_head* head = createBST(comparestr);
	queue* pQ = createQ(NUM);
	char** in = (char**)malloc(sizeof(char*) * NUM);
	if (in == NULL) {
		printf("in �� malloc ����\n");
		return -1;
	}
	printf("BST�� ����Կ� �ռ�, ���ı����� �����Դϱ�?(���ڿ�ũ�����=0 �����ļ���=1 ���߰�����=2)\n");
	scanf("%d", &sort);
	switch (sort) {
	case 0:
		head->compare = comparelen;
		break;
	case 1:
		head->compare = comparestr;
		break;
	case 2:
		//
		printf("\n���߰� ������ ���ڿ��� �ƽ�Ű�ڵ� �������� ���� ���� �������� �����ϴ� ������ ����\n\n");
		head->compare = compareASCII;
		break;
	}
	while (1) {
		printf("����(0) ����(1) �˻�(2) ������(3)\n");
		scanf("%d", &menu);
		if (menu == 3) break;
		in[idx] = (char*)malloc(sizeof(char) * LEN);
		if (in[idx] == NULL) break;
		switch (menu) {
		case 0:
			printf("�Է��ϼ���:");
			scanf("%s", in[idx]);
			head = InsertBST(head, in[idx++]);
			printAll(head->root, printstr, pQ);
			break;
		case 1:
			printf("������ ���ڿ�:");
			scanf("%s", SearchDel);
			head->root = Delete(head, head->root, SearchDel, &suc);
			printf("\n%s�� �������۷��̼� ��� suc = %d\n", SearchDel, suc);
			printAll(head->root, printstr, pQ);
			break;
		case 2:
			printf("�˻��� ���ڿ�:");
			scanf("%s", SearchDel);
			if (SearchBST(head, head->root, SearchDel) != NULL)
				printf("\n\n%s �� BST�� <����>\n\n", SearchDel);
			else
				printf("\n\n%s �� BST�� <����>\n\n", SearchDel);
			printAll(head->root, printstr, pQ);
			break;
		}
	}
	for (k = 0; k < idx; k++) {
		free(in[k]);
		in[k] = NULL;
	}
	free(in);
	in = NULL;
	DestroyBST(head);
	destroyqueue(pQ);
	return 0;
}

void BreadthFirstSearch(TreeNode* pRoot, queue* pQ) { // Recursion Model
	TreeNode* pTemp = NULL;
	if (!pRoot) return;
	printf("%10s ", (char*)pRoot->dataPtr);
	if (pRoot->left != NULL)
		enqueue(pQ, pRoot->left);
	if (pRoot->right != NULL)
		enqueue(pQ, pRoot->right);
	if (!isemptyqueue(pQ)) { // general case
		pTemp = dequeue(pQ);
		BreadthFirstSearch(pTemp, pQ);
	}
	else // base case
		return;
}
void printAll(TreeNode* pRoot, void(*func)(void* dataptr), queue* pQ) {
	printf("\nPreorder           : ");
	Preorder(pRoot, func);
	puts("");
	printf("Inorder            : ");
	traverse(pRoot, func);
	puts("");
	printf("Postorder          : ");
	Postorder(pRoot, func);
	puts("");
	printf("BreadthFirstSearch : ");
	BreadthFirstSearch(pRoot, pQ);
	puts("");
}
void compareASCII(void* dataPtr1, void* dataPtr2) {
	int i;
	int sum1 = 0, sum2 = 0;
	char t1[50] = { 0, };
	strcpy(t1, (char*)dataPtr1);
	for (i = 0; i <= strlen((char*)dataPtr1); i++) {
		printf("index = %d / ASCII value = %d\n", i, t1[i]);
		sum1 += t1[i];
	}
	strcpy(t1, (char*)dataPtr2);
	for (i = 0; i <= strlen((char*)dataPtr2); i++) {
		printf("index = %d / ASCII value = %d\n", i, t1[i]);
		sum2 += t1[i];
	}
	printf("sum1=%d / sum2=%d\n", sum1, sum2);
	return sum1 - sum2;
}