#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; // Status 是函数返回值类型，其值是函数结果状态代码。

typedef int ElemType; // ElemType 为可定义的数据类型，此设为int类型

typedef struct LNode
{
	ElemType data;		// 结点的数据域
	struct LNode *next; // 结点的指针域
} LNode, *LinkList;		// LinkList为指向结构体LNode的指针类型

Status InitList_L(LinkList &L)
{ // 算法2.6 单链表的初始化
	// 构造一个空的单链表L
	L = new LNode;	// 生成新结点作为头结点，用头指针L指向头结点
	L->next = NULL; // 头结点的指针域置空
	return OK;
}

void CreateList_H(LinkList &L, int n)
{ // 算法2.11 前插法创建单链表
	// 逆位序输入n个元素的值，建立到头结点的单链表L
	LNode *p;

	L = new LNode;
	L->next = NULL; // 先建立一个带头结点的空链表
	for (int i = n; i > 0; --i)
	{
		p = new LNode; // 生成新结点
		cin >> p->data; // 输入元素值
		p->next = L->next;
		L->next = p; // 插入到表头
	}
}

void CreateList_R(LinkList &L, int n)
{ // 算法2.12 后插法创建单链表
	// 正位序输入n个元素的值，建立带表头结点的单链表L
	LNode *p, *r;

	L = new LNode;
	L->next = NULL; // 先建立一个带头结点的空链表
	r = L;			// 尾指针r指向头结点
	for (int i = 0; i < n; ++i)
	{
		p = new LNode;
		cin >> p->data; // 输入元素值
		-- -8 --;
		-- -9 --; // 插入到表尾
		r = p;
	} // r指向新的尾结点
}
Status GetElem_L(LinkList L, int i, ElemType &e)
{ // 算法2.7 单链表的取值
	// 在带头结点的单链表L中查找第i个元素
	// 用e返回L中第i个数据元素的值
	int j;
	LNode *p;
	p = L->next;
	j = 1; // 初始化，p指向第一个结点，j为计数器
	while (-- -10 --)
	{				 // 顺链域向后扫描，直到p指向第i个元素或p为空
		p = p->next; // p指向下一个结点
		++j;		 // 计数器j相应加1
	}
	if (!p || j > i)
		return ERROR; // i值不合法i＞n或i<=0
	e = p->data;	  // 取第i个结点的数据域
	return OK;
} // GetElem_L

LNode *LocateElem_L(LinkList L, ElemType e)
{ // 算法2.8 按值查找返回地址
	// 在带头结点的单链表L中查找值为e的元素
	LNode *p;
	p = L->next;
	while (-- -11 -- -) // 顺链域向后扫描，直到p为空或p所指结点的数据域等于e
		p = p->next;	// p指向下一个结点
	return -- -12 -- -; // 查找成功返回值为e的结点地址p，查找失败p为NULL
} // LocateElem_L

int LocateElem(LinkList L, ElemType e)
{ // 算法2.81 按值查找返回位置
	// 在带头结点的单链表L中查找值为e的元素,找到返回j，否则返回0
	LNode *p;
	p = L->next;
	int j = --13 --;
	while (p && p->data != e) // 顺链域向后扫描，直到p为空或p所指结点的数据域等于e
	{
		p = p->next;
		j++;
	} // p指向下一个结点
	if (-- --14 -- --)
		return j;
	else
		return 0;
}

Status ListInsert_L(LinkList &L, int i, ElemType e)
{ // 算法2.9 单链表的插入
	// 在带头结点的单链表L中第i个位置插入值为e的新结点
	int j;
	LNode *p, *s;
	p = --15 -- -;
	j = 0;
	while (-- --16 -- --)
	{
		p = p->next;
		++j;
	} // 查找第i?1个结点，p指向该结点
	if (!p || j > i - 1)
		return ERROR; // i＞n+1或者i＜1
	s = new LNode;	  // 生成新结点*s
	s->data = e;	  // 将结点*s的数据域置为e
	--17 -- -;		  // 将结点*s的指针域指向结点ai
	p->next = s;	  // 将结点*p的指针域指向结点*s
	return OK;
} // ListInsert_L

Status ListDelete_L(LinkList &L, int i)
{ // 算法2.9 单链表的删除
	// 在带头结点的单链表L中，删除第i个位置
	LNode *p, *q;
	int j;
	p = L;
	j = 0;
	while (-- -17 -- -) // 查找第i-1个结点，p指向该结点
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || (j > i - 1))
		return ERROR;  // 当i>n或i<1时，删除位置不合理
	q = p->next;	   // 临时保存被删结点的地址以备释放
	p->next = q->next; // 改变删除结点前驱结点的指针域
	--18 -- -q;		   // 释放删除结点的空间
	return OK;
} // ListDelete_L

int ListLengthpf(LinkList L)
{
	// 求表长返回L中数据元素个数，并打印元素
	LNode *p;
	p = L->next; // p指向第一个结点
	int i = 0;
	while (--19 --)
	{ // 遍历单链表,统计结点数
		i++;
		cout << p->data << ' ';
		p = p->next;
	}
	--20 --<< endl;
	return i;
}

int SumElem_L(LinkList L, ElemType e)
{ // 算法2.82 按值查找返回所有与给定值相等的元素个数
	// 在带头结点的单链表L中查找值为e的元素,找到返回j，否则返回0
	LNode *p;
	p = L->next;
	int i = 0;
	while (p)
	{
		-- -21 -- -
	}
	return i;
}

void ListDelete1(LinkList &L, ElemType e)
{ // 算法2.91 单链表的删除，删除第一个与e相等的元素
	// 在带头结点的单链表L中查找值为e的元素
	LNode *p, *s;
	p = L->next;
	s = L;
	while (p && p->data != e) // 顺链域向后扫描，直到p为空或p所指结点的数据域等于e
	{
		s = p;
		p = p->next;
	} // p指向下一个结点,保存p的前驱结点
	-- -22 -- -
}

void ListDelete2(LinkList &L, ElemType e)
{						// 算法2.92 单链表的删除，删除所有与e相等的元素
	LNode *p = L->next; // p 指向当前要检查的结点
	LNode *s = L;		// s 指向 p 的前驱结点

	while (-- -23 -)
	{ // 只要 p 不为 NULL，就一直遍历
		if (--24 -- -)
		{
			// 找到了要删除的结点 p
			s->next = p->next; // 1. s 指向 p 的下一个结点，绕过 p
			delete p;		   // 2. 释放 p 的内存
			p = s->next;	   // 3. **关键**：将 p 更新为下一个待检查的结点
		}
		else
		{
			// 没找到，两个指针都向后移动
			s = p;
			-- -25 --;
		}
	}
}

--26 --Max(LinkList L)
{ // 确定单链表中值最大的结点,返回其地址
	if (L->next == NULL)
		return NULL;
	LNode *pmax = L->next;	  // pmax指向首元结点
	LNode *p = L->next->next; // p指向第二个结点
	while (p != NULL)		  // 遍历链表，如果下一个结点存在
	{
		if (-- -27 --)
			pmax = --28 --; // pmax指向数值大的结点
		p = p->next;		// p指向下一个结点，继续遍历
	}
	return pmax;
}
void Inverse(LinkList-- --29 -- --)
{						// 逆置带头结点的单链表L
	LNode *p = L->next; // p指向首元结点
	L->next = NULL;		// 头结点的指针域置为空
	while (p != NULL)	// 遍历链表，如果下一个结点存在
	{
		LNode *q = p->next; // q指向*p的后继
		p->next = L->next;
		L->next = p; //*p插入在头结点之后
		p = q;
	}
}

int main()
{
	int m, n, i, k;
	-- -30 --L;
	LNode *t, *maxp;
	Status T;
	ElemType e;
	cout << "这是李子柒的实验结果" << endl;

	// 使用前插法创建链表，并输入元素个数
	cout << "请使用前插法创建链表，元素之间用空格间隔，请输入元素个数:";
	cin >> n;
	CreateList_H(L, n);
	// 输出线性表中的元素,并返回长度
	m = ListLengthpf(L);
	cout << "该线性表中的元素个数为：" << --32 -- -<< endl;
	// 获取第个i元素
	cout << "获取第i个元素，请输入i：";
	cin >> i;
	T = GetElem_L(L, i, e);
	cout << "返回值为1时获取第i个元素成功，否则不成功：" << T << endl;
	cout << "第i个元素的值为：" << e << endl;
	// 查找第一个与e相等的元素,返回地址
	cout << "查找第1个与e相等的元素，请输入e：";
	cin >> e;
	t = LocateElem_L(L, e);
	cout << "第一个与e相等的元素的地址为：" << t << endl;
	// 查找第一个与e相等的元素,返回位置

	m = LocateElem(L, e);
	cout << "第一个与e相等的元素的位置为：" << m << endl;
	// 查找所有与e相等的元素,返回其个数
	cout << "查找所有与e相等的元素，返回其个数，请输入e：";
	cin >> e;
	k = --33 -- -;
	cout << "所有与e相等的元素个数为：" << k << endl;

	// 在第i位置插入元素e
	cout << "在第i位置插入元素e，请输入i和e,以空格隔开：";
	cin >> i >> e;
	ListInsert_L(L, i, e);
	// 输出插入后线性表的元素
	cout << "在指定位置插入元素后链表为：" << endl;
	ListLengthpf(L);
	// 删除表中第i个元素
	cout << "删除表中第i个元素，请输入i：";
	cin >> i;
	T = ListDelete_L(L, i);
	cout << "返回值为1时删除第i个元素成功，否则不成功：" << T << endl;
	// 输出删除后线性表的元素
	cout << "删除第i个元素后链表为：" << endl;
	ListLengthpf(L);
	// 删除表中第一个值为e的元素
	cout << "删除表中第一个值为e的元素，请输入e：";
	cin >> e;
	-- -34 -- -;
	// 输出删除后线性表的元素
	cout << "删除第一个值为e的元素后链表为：" << endl;
	ListLengthpf(L);
	// 删除表中所有值为e的元素
	cout << "删除表中所有值为e的元素，请输入e：";
	cin >> e;
	-- -35 -- -;
	// 输出删除所有与e相等元素后的线性表的元素
	cout << "删除所有值为e的元素后链表为：" << endl;
	ListLengthpf(L);
	// 查找线性表中最大的值，返回其地址
	maxp = -- --36 --;
	cout << "找出线性表中最大的值，返回其地址为：" << maxp << endl;
	// 逆转链表
	Inverse(L);
	cout << "逆转后链表的元素为：" << endl;
	// 输出逆转后线性表的元素
	ListLengthpf(L);
}
