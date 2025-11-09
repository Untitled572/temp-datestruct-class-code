#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <sstream>
#include "tree.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 算法1 建立二叉链表
void CreateBiTree(BiTree &T, string ch, int &i)
{
    // 按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
    i += 1;
    if (ch[i] == '#')
        T = NULL; // 递归结束，建空树
    else
    {
        T = new BiNode;
        T->data = ch[i];
        CreateBiTree(T->lchild, ch, i);
        CreateBiTree(T->rchild, ch, i);
    } // else
} // CreateBiTree

// 算法2 中序遍历的递归算法
void InOrderTraverse(BiTree T)
{
    // 中序遍历二叉树T的递归算法
    if (T != NULL)
    {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}

void PreOrderTraverse(BiTree T)
{
    // 前序遍历二叉树T的递归算法
    if (T != NULL)
    {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void AfterOrderTraverse(BiTree T)
{
    // 前序遍历二叉树T的递归算法
    if (T != NULL)
    {
        AfterOrderTraverse(T->lchild);
        AfterOrderTraverse(T->rchild);
        cout << T->data;
    }
}
// 算法3 求二叉树深度的递归算法
int Depth(BiTree T)
{
    return !T ? 0 : 1 + std::max(Depth(T->lchild), Depth(T->rchild));
}

// 算法4：统计二叉树中结点的总个数
int NodeCount(BiTree T)
{
    return !T ? 0 : 1 + NodeCount(T->lchild) + NodeCount(T->rchild);
}

// 算法5：统计二叉树中叶子结点的个数
int LeafCount(BiTree T) // 统计树中叶子结点的个数
{
    return !T ? 0 : !T->lchild && !T->rchild ? 1 : LeafCount(T->lchild) + LeafCount(T->rchild);
}
// 算法6：统计二叉树中度为1的结点的个数
int count1(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    if (T->lchild != NULL && T->rchild == NULL)
    {
        return 1 + count1(T->lchild);
    }
    else if (T->lchild == NULL && T->rchild != NULL)
    {
        return 1 + count1(T->rchild);
    }
    else
    {
        return count1(T->lchild) + count1(T->rchild);
    }
}

int count1better(BiTree T)
{
    return !T ? 0 : ((!T->lchild) != (!T->rchild)) + count1(T->lchild) + count1(T->rchild);
}

// 算法7：统计二叉树中度为2的结点的个数
int count2(BiTree T)

{
    if (T == NULL)
    {
        return 0;
    }
    if (T->lchild != NULL && T->rchild != NULL)
    {
        return 1 + count2(T->lchild) + count2(T->rchild);
    }
    return count2(T->lchild) + count2(T->rchild);
}

int count2better(BiTree T) {
    return !T ? 0 : (T->lchild && T->rchild) + count2(T->lchild) + count2(T->rchild);
}

// 算法8：输出二叉树中每个叶子结点到根结点的路径
void AllPath(BiTree T, char path[], int pathlen)
{ // 输出二叉树中从每个叶子结点到根结点的路径，pathlen初始为0
    if (T != NULL)
    {
        path[pathlen] = T->data;                    // 将当前结点放入路径中
        if (T->lchild == NULL && T->rchild == NULL) // 叶子结点
        {
            for (int i = pathlen; i >= 0; i--)
                cout << path[i];
            cout << endl;
        }
        else
        {
            pathlen++;                         // 路径长度增1
            AllPath(T->lchild, path, pathlen); // 递归遍历左子树
            AllPath(T->rchild, path, pathlen); // 递归遍历右子树
            pathlen--;                         // 恢复环境
        }
    }
    if (T == NULL)
    {
        return;
    }
}

// 算法9：交换二叉树每个结点的左右子孩子
void ChangeLR(BiTree &T) // 交换二叉树每个结点的左右子孩子
{
    if (T == NULL)
    {
        return;
    }
    BiNode *t = T->lchild;
    T->lchild = T->rchild;
    T->rchild = t;
    ChangeLR(T->lchild);
    ChangeLR(T->rchild);
}

// 初始化队列（空队列）
void InitQueue(Queue &Q)
{
    Q.front = Q.rear = new LNode; // 创建头节点（哨兵）
    Q.front->next = NULL;         // 头节点指针置空
}

// 入队（从队尾插入，保证后入队的节点最后出队）
void EnQueue(Queue &Q, BiTree e)
{
    LNode *p = new LNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p; // 新节点接在队尾
    Q.rear = p;       // 更新队尾指针
}

// 出队（从队头取出，保证先入队的节点先出队）
BiTree DeQueue(Queue &Q)
{
    if (Q.front == Q.rear)
        return NULL;          // 队空
    LNode *p = Q.front->next; // 指向队头元素
    BiTree e = p->data;       // 保存出队元素
    Q.front->next = p->next;  // 队头指针后移
    if (Q.rear == p)
        Q.rear = Q.front; // 若队尾是出队元素，修正队尾
    delete p;             // 释放节点
    return e;
}

// 检测队列是否为空
int QueueEmpty(Queue Q)
{
    return (Q.front == Q.rear) ? 1 : 0;
}

// 算法10：层次遍历二叉树，并统计度为1的节点个数
int Level(BiTree T)
{
    int num = 0; // 度为1的节点计数
    if (T)
    {
        Queue Q;
        InitQueue(Q);
        EnQueue(Q, T); // 根节点入队

        while (!QueueEmpty(Q))
        {
            BiTree p = DeQueue(Q); // 队头元素出队（先入先出）
            cout << p->data;       // 访问节点

            // 统计度为1的节点（左、右孩子有且仅有一个）
            if ((p->lchild && !p->rchild) || (!p->lchild && p->rchild))
            {
                num += 1;
            }

            // 左孩子先入队，保证同层左节点先访问
            if (p->lchild)
                EnQueue(Q, p->lchild);
            // 右孩子后入队，同层右节点后访问
            if (p->rchild)
                EnQueue(Q, p->rchild);
        }
    }
    return num;
}

void getInput(string &s) {
    string result;
    while (true)
    {
        cout << ": ";
        string line = "";
        std::getline(cin, line);
        std::istringstream iss(line);
        iss >> result;
        if(!testTree(result)){
            cout << "Invalid Tree" << endl;
            cin.clear();
            continue;
        }
        break;
    }
}

bool testTree(string s) {
    int length = s.size();
    if (length % 2 != 1)
    {
        return false;
    }
    int i = 100;
    for (int j = 0; j < length; j += 1){
        if(std::isalpha(s[j])) {
            i += 1;
        }
        else if(s[j] == '#') {
            i -= 1;
        }
    }
    if(i < 100) {
        return true;
    }
    return false;
}
