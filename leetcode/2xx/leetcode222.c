/*
@File    :   leetcode222.c
@Time    :   2020/02/29 20:27:38
@Author  :   xiaosongsong
@Desc    :   None
给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:

输入:
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6


*/

#include <stdio.h>
#include <malloc.h>
typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
TreeNode *createBtTree(int *nodelist, int i)
{
    TreeNode *newnode;
    if (nodelist[i] == 0 || i > 6)
        return NULL;
    else
    {
        newnode = (TreeNode *)malloc(sizeof(TreeNode));
        newnode->val = nodelist[i];
        newnode->left = createBtTree(nodelist, 2 * i);
        newnode->right = createBtTree(nodelist, 2 * i + 1);
        return newnode;
    }
}
int getMaxDepth(struct TreeNode *root)
{
    int left = 0, right = 0;
    if (root == NULL)
        return 0;
    left = getMaxDepth(root->left) + 1;
    right = getMaxDepth(root->right) + 1;
    return left > right ? left : right;
}

int countNodes(struct TreeNode *root)
{
    int left = 0, right = 0;
    int count = 0;
    if (root == NULL)
        return 0;
    left = getMaxDepth(root->left);
    right = getMaxDepth(root->right);
    if (left == right)
        return (1 << left) + countNodes(root->right);
    else
        return (1 << right) + countNodes(root->left);
}
int main()
{
    int size = 0;
    TreeNode *root;
    int a[] = {0, 1, 2, 3, 4, 5, 6};
    root = createBtTree(a, 1);
    printf("%d", countNodes(root));
    return 0;
}
