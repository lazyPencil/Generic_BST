//Binary Search Tree : Generic Coding .ver : Data Structure 
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <stdbool.h>

typedef struct TreeNode {// "dataPtr" should have the "address" of any data.  Because of the name of this tree, it has "only 2" links.
	void* dataPtr;
	struct TreeNode* left, * right;
}TreeNode;
typedef struct BST_head {// "BST_head" points the "root" of BST. // cnt : the number of Nodes // compare : function pointer for compare functions 
	int cnt;
	int (*compare) (void*, void*);
	TreeNode* root;
} BST_head;
typedef struct {
	TreeNode** arr;
	int size;
	int front, rear;
}queue;

queue* createQ(int size);
void enqueue(queue* pQ, TreeNode* item);
TreeNode* dequeue(queue* pQ);
TreeNode* queuefront(queue* pQ);
TreeNode* queuerear(queue* pQ);
bool isfullqueue(queue* pQ);
bool isemptyqueue(queue* pQ);
void clearqueue(queue* pQ);
void destroyqueue(queue* pQ);

int comparelen(void* dataPtr1, void* dataPtr2);
int comparestr(void* dataPtr1, void* dataPtr2);
void printint(void* dataptr);
void printstr(void* dataptr);
BST_head* createBST(int (*func) (void* dataPtr1, void* dataPtr2));
TreeNode* createTree(TreeNode* t1, void* newData, TreeNode* t2);
TreeNode* DestroyTree(BST_head* head, TreeNode* root);
void DestroyBST(BST_head* head);
TreeNode* SearchBST(BST_head* head, TreeNode* root, void* Key);
void traverse(TreeNode* root, void (*operate)(void* dataPtr));
void Preorder(TreeNode* root, void (*operate)(void* dataPtr));
void Postorder(TreeNode* root, void (*operate)(void* dataPtr));
TreeNode* Insert(BST_head* head, TreeNode* root, TreeNode* newTree);
BST_head* InsertBST(BST_head* head, void* dataPtr);
TreeNode* Delete(BST_head* head, TreeNode* root, void* dataDel, short* success);
TreeNode* findSmallestBST(TreeNode* root);
TreeNode* findLargestBST(TreeNode* root);