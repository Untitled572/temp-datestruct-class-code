#ifndef CODE2ST_H
#define CODE2ST_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

// 定义模板化的 LNode 结构体
template <typename ElemType>
struct LNode
{
    ElemType data; // 结点的数据域
    LNode<ElemType> *next; // 结点的指针域，显式指定模板参数
};

// 定义模板化的 LinkList 类型
template <typename ElemType>
using LinkList = LNode<ElemType> *;

// 模板函数实现
template <typename ElemType>
Status InitList_L(LinkList<ElemType> &L)
{ // 算法2.1 单链表的初始化
    // 构造一个空的单链表L
    L = new LNode<ElemType>; // 生成新结点作为头结点，用头指针L指向头结点
    if (!L)
        return OVERFLOW;
    L->next = NULL; // 头结点的指针域置空
    return OK;
}

template <typename ElemType>
void CreateList_H(LinkList<ElemType> &L, int n)
{ // 算法2.21 前插法创建单链表
    // 逆位序输入n个元素的值，建立到头结点的单链表L
    LNode<ElemType> *p;

    L = new LNode<ElemType>;
    L->next = NULL; // 先建立一个带头结点的空链表
    for (int i = n; i > 0; --i)
    {
        p = new LNode<ElemType>; // 生成新结点
        cin >> p->data;          // 输入元素值
        p->next = L->next;
        L->next = p; // 插入到表头
    }
}

template <typename ElemType>
void CreateList_R(LinkList<ElemType> &L, int n)
{ // 算法2.22 后插法创建单链表
    // 正位序输入n个元素的值，建立带表头结点的单链表L
    LNode<ElemType> *p, *r;

    L = new LNode<ElemType>;
    L->next = NULL; // 先建立一个带头结点的空链表
    r = L;          // 尾指针r指向头结点
    for (int i = 0; i < n; ++i)
    {
        p = new LNode<ElemType>;
        cin >> p->data; // 输入元素值
        p->next = NULL;
        r->next = p; // 插入到表尾
        r = p;
    } // r指向新的尾结点
}

template <typename ElemType>
Status GetElem_L(LinkList<ElemType> L, int i, ElemType *e)
{ // 算法2.3 单链表的取值
    // 在带头结点的单链表L中查找第i个元素
    // 用e返回L中第i个数据元素的值
    int j;
    LNode<ElemType> *p;
    p = L->next;
    j = 1; // 初始化，p指向第一个结点，j为计数器
    while (i != j)
    {                // 顺链域向后扫描，直到p指向第i个元素或p为空
        p = p->next; // p指向下一个结点
        ++j;         // 计数器j相应加1
    }
    if (!p || j > i)
        return ERROR; // i值不合法i＞n或i<=0
    *e = p->data;     // 取第i个结点的数据域
    return OK;
} // GetElem_L

template <typename ElemType>
LNode<ElemType> *LocateElem_L(LinkList<ElemType> L, ElemType e)
{ // 算法2.41 按值查找返回地址
    // 在带头结点的单链表L中查找值为e的元素
    LNode<ElemType> *p;
    p = L->next;
    while (!p || p->data != e) // 顺链域向后扫描，直到p为空或p所指结点的数据域等于e
        p = p->next;           // p指向下一个结点
    return p;                  // 查找成功返回值为e的结点地址p，查找失败p为NULL
} // LocateElem_L

template <typename ElemType>
int LocateElem(LinkList<ElemType> L, ElemType e)
{ // 算法2.42 按值查找返回位置
    // 在带头结点的单链表L中查找值为e的元素,找到返回j，否则返回0
    LNode<ElemType> *p = L->next;
    int j = 1;
    while (p && p->data != e) // 顺链域向后扫描，直到p为空或p所指结点的数据域等于e
    {
        p = p->next;
        j++;
    } // p指向下一个结点
    if (p)
        return j;
    else
        return 0;
}

template <typename ElemType>
Status ListInsert_L(LinkList<ElemType> &L, int i, ElemType e)
{ // 算法2.5 单链表的插入
    // 在带头结点的单链表L中第i个位置插入值为e的新结点
    int j;
    LNode<ElemType> *p, *s;
    p = L->next;
    j = 1;
    while (j != i - 1 && p->next)
    {
        p = p->next;
        ++j;
    } // 查找第i?1个结点，p指向该结点
    // if (!p || j > i - 1)
    // return ERROR; // i＞n+1或者i＜1
    s = new LNode<ElemType>; // 生成新结点*s
    s->data = e;             // 将结点*s的数据域置为e
    s->next = p->next;       // 将结点*s的指针域指向结点ai
    p->next = s;             // 将结点*p的指针域指向结点*s
    return OK;
} // ListInsert_L

template <typename ElemType>
Status ListDelete_L(LinkList<ElemType> &L, int i)
{ // 算法2.6 单链表的删除
    // 在带头结点的单链表L中，删除第i个位置
    LNode<ElemType> *p, *q;
    int j;
    p = L;
    j = 0;
    while (j != i - 1) // 查找第i-1个结点，p指向该结点
    {
        p = p->next;
        ++j;
    }
    // if (!(p->next) || (j > i - 1))
    // return ERROR;  // 当i>n或i<1时，删除位置不合理
    q = p->next;       // 临时保存被删结点的地址以备释放
    p->next = q->next; // 改变删除结点前驱结点的指针域
    delete q;          // 释放删除结点的空间
    return OK;
} // ListDelete_L

template <typename ElemType>
int ListLengthpf(LinkList<ElemType> L)
{
    // 算法2.7打印链表总长度
    //  求表长返回L中数据元素个数，并打印元素
    LNode<ElemType> *p;
    p = L->next; // p指向第一个结点c
    int i = 0;
    while (p->next)
    { // 遍历单链表,统计结点数
        i++;
        cout << p->data << ' ';
        p = p->next;
    }
    cout << p->data << endl;
    i += 1;
    return i;
}

template <typename ElemType>
int SumElem_L(LinkList<ElemType> L, ElemType e)
{ // 算法2.8 按值查找返回所有与给定值相等的元素个数
    // 在带头结点的单链表L中查找值为e的元素,找到返回j，否则返回0
    LNode<ElemType> *p;
    p = L->next;
    int i = 0;
    while (p)
    {
        if (p->data == e)
        {
            i += 1;
        }
        p = p->next;
    }
    return i;
}

template <typename ElemType>
void ListDelete1(LinkList<ElemType> &L, ElemType e)
{ // 算法2.9 单链表的删除，删除第一个与e相等的元素
    // 在带头结点的单链表L中查找值为e的元素
    LNode<ElemType> *p, *s;
    p = L->next;
    s = L;
    while (p && p->data != e) // 顺链域向后扫描，直到p为空或p所指结点的数据域等于e
    {
        s = p;
        p = p->next;
    } // p指向下一个结点,保存p的前驱结点
    s->next = p->next;
    delete p;
}

template <typename ElemType>
void ListDelete2(LinkList<ElemType> &L, ElemType e)
{                                 // 算法2.10 单链表的删除，删除所有与e相等的元素
    LNode<ElemType> *p = L->next; // p 指向当前要检查的结点
    LNode<ElemType> *s = L;       // s 指向 p 的前驱结点

    while (p)
    { // 只要 p 不为 NULL，就一直遍历
        if (p->data == e)
        {
            // 找到了要删除的结点 p
            s->next = p->next; // 1. s 指向 p 的下一个结点，绕过 p
            delete p;          // 2. 释放 p 的内存
            p = s->next;       // 3. **关键**：将 p 更新为下一个待检查的结点
        }
        else
        {
            // 没找到，两个指针都向后移动
            s = p;
            p = p->next;
        }
    }
}

template <typename ElemType>
LNode<ElemType> *Max(LinkList<ElemType> L, ElemType *e)
{ // 算法2.11确定单链表中值最大的结点,返回其地址
    if (L->next == NULL)
        return NULL;
    LNode<ElemType> *pmax = L->next;    // pmax指向首元结点
    LNode<ElemType> *p = L->next->next; // p指向第二个结点
    while (p != NULL)                   // 遍历链表，如果下一个结点存在
    {
        if (p->data >= pmax->data)
            pmax = p; // pmax指向数值大的结点
        p = p->next;  // p指向下一个结点，继续遍历
    }
    *e = pmax->data;
    return pmax;
}

template <typename ElemType>
void Inverse(LinkList<ElemType> &L)
{                                 // 算法2.12逆置带头结点的单链表L
    LNode<ElemType> *p = L->next; // p指向首元结点
    L->next = NULL;               // 头结点的指针域置为空
    while (p != NULL)             // 遍历链表，如果下一个结点存在
    {
        LNode<ElemType> *q = p->next; // q指向*p的后继
        p->next = L->next;
        L->next = p; //*p插入在头结点之后
        p = q;
    }
}

#endif
