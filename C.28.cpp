
#include <stdio.h>
#include <stdlib.h>

// �������Ľ�㶨��
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// �ж��Ƿ�Ϊ��������
int isFullBinaryTree(struct Node* root) {
    // ���������Ϊ�գ���Ϊ����������
    if (root == NULL)
        return 1;
    // �������������Ϊ�գ�������������
    if (root->left == NULL && root->right == NULL)
        return 1;
    // ���������������Ϊ�գ�������ݹ��ж�
    if (root->left && root->right)
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    // ���������������һ��Ϊ�գ�������������
    return 0;
}

// �ж��Ƿ�Ϊ��ȫ������
int isCompleteBinaryTree(struct Node* root, int index, int numNodes) {
    // ���������Ϊ�գ���Ϊ����ȫ������
    if (root == NULL)
        return 1;
    // �����ǰ���ʵĽڵ����������˶��������ܽ������������ȫ������
    if (index >= numNodes)
        return 1;
    // �ݹ��ж���������������
    return isCompleteBinaryTree(root->left, 2 * index + 1, numNodes) &&
           isCompleteBinaryTree(root->right, 2 * index + 2, numNodes);
}

// �������������
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void print(Node *n)
{
	static int level = -1; //��¼�ǵڼ����
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
    // ����һ��ʾ��������
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
	print(root);
    // �ж��Ƿ�Ϊ��������
    if (isFullBinaryTree(root))
        printf("����������\n");
    else
        printf("������������\n");

    // �ж��Ƿ�Ϊ��ȫ������������������Ҫ�õ������ܽ����
    if (isCompleteBinaryTree(root, 0, 5))
        printf("����ȫ������\n");
    else
        printf("������ȫ������\n");

    return 0;
}
