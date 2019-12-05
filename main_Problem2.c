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
		printf("in 의 malloc 실패\n");
		return -1;
	}
	printf("BST를 사용함에 앞서, 정렬기준은 무엇입니까?(문자열크기순서=0 사전식순서=1 비중값순서=2)\n");
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
		printf("\n비중값 순서는 문자열의 아스키코드 정수값을 합한 값을 기준으로 정렬하는 것으로 구현\n\n");
		head->compare = compareASCII;
		break;
	}
	while (1) {
		printf("삽입(0) 삭제(1) 검색(2) 나가기(3)\n");
		scanf("%d", &menu);
		if (menu == 3) break;
		in[idx] = (char*)malloc(sizeof(char) * LEN);
		if (in[idx] == NULL) break;
		switch (menu) {
		case 0:
			printf("입력하세요:");
			scanf("%s", in[idx]);
			head = InsertBST(head, in[idx++]);
			printAll(head->root, printstr, pQ);
			break;
		case 1:
			printf("삭제할 문자열:");
			scanf("%s", SearchDel);
			head->root = Delete(head, head->root, SearchDel, &suc);
			printf("\n%s을 삭제오퍼레이션 결과 suc = %d\n", SearchDel, suc);
			printAll(head->root, printstr, pQ);
			break;
		case 2:
			printf("검색할 문자열:");
			scanf("%s", SearchDel);
			if (SearchBST(head, head->root, SearchDel) != NULL)
				printf("\n\n%s 는 BST에 <있음>\n\n", SearchDel);
			else
				printf("\n\n%s 는 BST에 <없음>\n\n", SearchDel);
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