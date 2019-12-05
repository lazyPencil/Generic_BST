#include "BST_queue_array_Problem2.h"

queue* createQ(int size) {
	queue* pQ = (queue*)malloc(sizeof(queue));
	int i;
	if (pQ == NULL) return NULL;
	pQ->arr = (TreeNode**)malloc(sizeof(TreeNode*) * size);
	if (pQ->arr == NULL) {
		free(pQ);
		return NULL;
	}
	for (i = 0; i < size; i++) {
		pQ->arr[i] = (TreeNode*)malloc(sizeof(TreeNode));
		pQ->arr[i]->dataPtr = NULL;
		if (pQ->arr[i] == NULL) {
			printf("pQ->arr[i]에러떴다\n");
		}
	}
	pQ->front = pQ->rear = 0;
	pQ->size = size;
	return pQ;
}
void enqueue(queue* pQ, TreeNode* item) {
	if (isfullqueue(pQ)) {
		printf("queue is full...\n");
		return;
	}
	else
	{
		pQ->rear = (pQ->rear + 1) % pQ->size;
		pQ->arr[pQ->rear] = item;
	}
}
TreeNode* dequeue(queue* pQ) {
	TreeNode* x;
	if (isemptyqueue(pQ)) {
		printf("queue is empty...\n");
		return NULL;
	}
	else {
		pQ->front = (pQ->front + 1) % pQ->size;
		x = pQ->arr[pQ->front];
		return x;
	}
}
TreeNode* queuefront(queue* pQ) {
	if (isemptyqueue(pQ))
		return NULL;
	else
		return pQ->arr[pQ->front];
}
TreeNode* queuerear(queue* pQ) {
	if (isemptyqueue(pQ))
		return NULL;
	else
		return pQ->arr[pQ->rear];
}
bool isfullqueue(queue* pQ) {
	if ((pQ->front - pQ->rear == 1) || (pQ->rear - pQ->front == pQ->size - 1)) // r,f 순일 땐 전자 / f,r 순일 땐 후자
		return true;
	else
		return false;
}
bool isemptyqueue(queue* pQ) {
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}
void clearqueue(queue* pQ) {
	pQ->rear = pQ->front;
}
void destroyqueue(queue* pQ) {
	/*int i;
	for (i = pQ->size - 1; i > -1; i--) {
		//printf("%d번째 인덱스 %s를 free하려고합니다.\n", i , (char*)pQ->arr[i]->dataPtr);
		printf("%d번째 인덱스를 free하려고합니다.\n", i);
		free(pQ->arr[i]);
	}*/
	int i;
	for (i = pQ->size - 1; i > -1; i--) {
		//printf("%d번째 인덱스 %s를 free하려고합니다.\n", i , (char*)pQ->arr[i]->dataPtr);
		printf("%d번째 인덱스를 free하려고합니다.\n", i);
		free(pQ->arr[i]);
	}
	free(pQ->arr);
	pQ->arr = NULL;
	free(pQ);
	pQ = NULL;
}

int comparelen(void* dataPtr1, void* dataPtr2) {// Compare between integer types // If a>b, res>0
	return strlen((char*)dataPtr1) - strlen((char*)dataPtr2);
}
int comparestr(void* dataPtr1, void* dataPtr2) {// Compare between string types
	return strcmp((char*)dataPtr1, (char*)dataPtr2); // a<b, A<a, aa<ab, aaa>aa
}
void printint(void* dataptr) {//Since printing an integer or a string is different, we make these 2 simple functions.
	printf("%d ", *(int*)dataptr);
}
void printstr(void* dataptr) {
	printf("%10s ", (char*)dataptr);
}
BST_head* createBST(int (*func) (void* dataPtr1, void* dataPtr2)) {// Create BST_head : cnt, compare, root  
	BST_head* pNew = (BST_head*)malloc(sizeof(BST_head));
	if (!pNew) return NULL;
	pNew->cnt = 0;
	pNew->compare = NULL; // main 함수에서 사용자에게 입력받을 것.
	pNew->root = NULL;
	return pNew;
}
TreeNode* createTree(TreeNode* t1, void* newData, TreeNode* t2) {// Create NewNode : Left = t1 , Right = t2 , "Address" of Data = newData
	TreeNode* pNew = (TreeNode*)malloc(sizeof(TreeNode));
	if (pNew == NULL) return NULL;
	pNew->left = t1;
	pNew->right = t2;
	pNew->dataPtr = newData;
	return pNew;
}

TreeNode* DestroyTree(BST_head * head, TreeNode * root) {
	if (!root)
		return NULL;
	root->left = DestroyTree(head, root->left);
	root->right = DestroyTree(head, root->right);
	free(root);
	root->dataPtr = NULL;
	root = NULL;
	head->cnt--;
	return NULL;
}
void DestroyBST(BST_head * head) {
	DestroyTree(head, head->root);
	head->compare = NULL;
	free(head);
	head = NULL;
}
// your BST has the Key -> return "the" TreeNode
// 1. Compare between "Key" and "root->dataPtr" 2. If "Key" is bigger, Search "Right subtree" again (Recursion)
TreeNode* SearchBST(BST_head * head, TreeNode * root, void* Key) {
	if (!root)										// base case
		return NULL;
	//if (head->compare(root->dataPtr, Key) > 0)		// C1) dataPtr이 크다
	if(strcmp((char*)root->dataPtr,(char*)Key) > 0)
		return SearchBST(head, root->left, Key);
	//else if (head->compare(root->dataPtr, Key) < 0) // C2) dataPtr이 작다
	else if (strcmp((char*)root->dataPtr, (char*)Key) < 0)
		return SearchBST(head, root->right, Key);
	else											// C3) Found
		return root;
}
// All node is visited by this function.  operate can be "printint" or "printstr"
void traverse(TreeNode * root, void (*operate)(void* dataPtr)) {
	if (root == NULL)
		return;
	traverse(root->left, operate);
	(*operate)(root->dataPtr);
	traverse(root->right, operate);
}
void Preorder(TreeNode * root, void (*operate)(void* dataPtr)) {
	if (root == NULL)
		return;
	(*operate)(root->dataPtr);
	Preorder(root->left, operate);
	Preorder(root->right, operate);
}
void Postorder(TreeNode * root, void (*operate)(void* dataPtr)) {
	if (root == NULL)
		return;
	Postorder(root->left, operate);
	Postorder(root->right, operate);
	(*operate)(root->dataPtr);
}
// param1 : for compare function // param2 : necessary // param3 : Node to "be inserted" to "param2"
// return : "Changed" root
// Subfunction of "InsertBST"
TreeNode* Insert(BST_head * head, TreeNode * root, TreeNode * newTree) {
	if (!root)														// Base Case
		return newTree;
	if (head->compare(root->dataPtr, newTree->dataPtr) > 0) {		// C1) root가 크다. 왼쪽에 다세요
		root->left = Insert(head, root->left, newTree);
		return root;	// 변화된 root
	}
	else {	// C2) root가 작거나 같다. 오른쪽에 다세요
		root->right = Insert(head, root->right, newTree);
		return root;
	}
}
// When you insert "param2" into "param1"
// If cnt != 0 , be careful about inserting the data into "Right place"
BST_head* InsertBST(BST_head * head, void* dataPtr) {
	TreeNode* pNew = createTree(NULL, dataPtr, NULL);
	if (head->cnt == 0)
		head->root = pNew;
	else
		head->root = Insert(head, head->root, pNew);
	head->cnt++;
	return head;
}
//1. Find the tree that has the data to want to delete 2. C1) has "NO child" C2,3) has "ONLY child" C4) has "TWO children"
TreeNode* Delete(BST_head * head, TreeNode * root, void* dataDel, short* success) {
	TreeNode* pDel = NULL;
	if (!root) { // Not Found
		*success = 0;
		return root;
	}
	if (strcmp((char*)root->dataPtr,(char*)dataDel) > 0)
		root->left = Delete(head, root->left, dataDel, success);
	//else if (head->compare(root->dataPtr, dataDel) < 0)
	else if (strcmp((char*)root->dataPtr, (char*)dataDel) < 0)
		root->right = Delete(head, root->right, dataDel, success);
	else {												// Found
		if (root->right == NULL) {
			pDel = root;
			root = root->left;			// root->left = NULL or Not NULL
			free(pDel);
			head->cnt--;
			*success = 1;
		}
		else if (root->left == NULL) {	// Only right is Not NULL
			pDel = root;
			root = root->right;
			free(pDel);
			head->cnt--;
			*success = 1;
		}
		else {			// Two children ( 1. choice largest data of left subtree 2.(ME) choice smallest data of right subtree ) as the "root"
			for (pDel = root->right; pDel->left != NULL; pDel = pDel->left); // 오른쪽 중에 제일 작은 놈
			root->dataPtr = pDel->dataPtr;
			root->right = Delete(head, root->right, pDel->dataPtr, success);
			head->cnt--;
			*success = 1;
		}
	}
	return root;
}
// In BST, Smallest value is saved in the "Leftmost & Bottom" place
// That place's left is NULL && itself is NOT.
TreeNode* findSmallestBST(TreeNode * root) {
	if (root != NULL && root->left == NULL) // 자신이 가장 왼쪽 아래일 때
		return root;
	else
		return findSmallestBST(root->left);
}
// In BST, Largest value is saved in the "Rightmost & Bottom" place
// That place's right is NULL && inself is NOT.
TreeNode* findLargestBST(TreeNode * root) {
	if (root != NULL && root->right == NULL)
		return root;
	else
		return findLargestBST(root->right);
}