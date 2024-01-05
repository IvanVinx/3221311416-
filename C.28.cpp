
#include <stdio.h>
#include <stdlib.h>

// 二叉树的结点定义
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// 判断是否为满二叉树
int isFullBinaryTree(struct Node* root) {
    // 如果二叉树为空，认为是满二叉树
    if (root == NULL)
        return 1;
    // 如果左右子树都为空，则是满二叉树
    if (root->left == NULL && root->right == NULL)
        return 1;
    // 如果左右子树都不为空，则继续递归判断
    if (root->left && root->right)
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    // 如果左右子树其中一个为空，则不是满二叉树
    return 0;
}

// 判断是否为完全二叉树
int isCompleteBinaryTree(struct Node* root, int index, int numNodes) {
    // 如果二叉树为空，认为是完全二叉树
    if (root == NULL)
        return 1;
    // 如果当前访问的节点索引超过了二叉树的总结点数，则不是完全二叉树
    if (index >= numNodes)
        return 1;
    // 递归判断左子树和右子树
    return isCompleteBinaryTree(root->left, 2 * index + 1, numNodes) &&
           isCompleteBinaryTree(root->right, 2 * index + 2, numNodes);
}

// 创建二叉树结点
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void print(Node *n)
{
	static int level = -1; //记录是第几层次
	int i;
	if (NULL == n)
		return;
	level++;
	print(n->right);
	level--;
	level++;
	for (i = 0; i < level; i++)
		printf("\t");
	printf("%2d\n", n->data);
	print(n->left);
	level--;
}


int main() {
    // 创建一个示例二叉树
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
	print(root);
    // 判断是否为满二叉树
    if (isFullBinaryTree(root))
        printf("是满二叉树\n");
    else
        printf("不是满二叉树\n");

    // 判断是否为完全二叉树，参数传入需要得到树的总结点数
    if (isCompleteBinaryTree(root, 0, 5))
        printf("是完全二叉树\n");
    else
        printf("不是完全二叉树\n");

    return 0;
}
