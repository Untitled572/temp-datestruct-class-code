#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
using std::string;

// 二叉树的二叉链表存储表示
typedef struct BiNode
{
    char data;               // 结点数据域
    BiNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

// 算法1 建立二叉链表
void CreateBiTree(BiTree &T, string ch, int &i);

// 算法2 中序遍历的递归算法
void InOrderTraverse(BiTree T);

void PreOrderTraverse(BiTree T);

void AfterOrderTraverse(BiTree T);

// 算法3 求二叉树深度的递归算法
int Depth(BiTree T);

// 算法4：统计二叉树中结点的总个数
int NodeCount(BiTree T);

// 算法5：统计二叉树中叶子结点的个数
int LeafCount(BiTree T); // 统计树中叶子结点的个数

// 算法6：统计二叉树中度为1的结点的个数
int count1(BiTree T);

int count1better(BiTree T);

// 算法7：统计二叉树中度为2的结点的个数
int count2(BiTree T);

int count2better(BiTree T);
// 算法8：输出二叉树中每个叶子结点到根结点的路径
void AllPath(BiTree T, char path[], int pathlen);

// 算法9：交换二叉树每个结点的左右子孩子
void ChangeLR(BiTree &T); // 交换二叉树每个结点的左右子孩子

// 算法10：实现按层次遍历二叉树，并统计返回二叉树中度为1的结点个数
//  队列节点（存储二叉树节点指针）
typedef struct LNode
{
    BiTree data;
    struct LNode *next;
} LNode;

// 队列结构体（用队头和队尾指针实现FIFO）
typedef struct
{
    LNode *front; // 队头（出队端）
    LNode *rear;  // 队尾（入队端）
} Queue;

// 初始化队列（空队列）
void InitQueue(Queue &Q);
// 入队（从队尾插入，保证后入队的节点最后出队）
void EnQueue(Queue &Q, BiTree e);

// 出队（从队头取出，保证先入队的节点先出队）
BiTree DeQueue(Queue &Q);
// 检测队列是否为空
int QueueEmpty(Queue Q);

// 算法10：层次遍历二叉树，并统计度为1的节点个数
int Level(BiTree T);

void getInput(string &s);
bool testTree(string s);

#endif
