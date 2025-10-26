#include <iostream>
#include <vector>
#include "code2st.hpp"

typedef int ElemType; // ElemType 为可定义的数据类型，此设为int类型

int main()
{
	LinkList<ElemType> L;
	InitList_L(L);
	LNode<ElemType> *t, *maxp;
	ElemType e;
	cout << "这是金容畅的实验结果" << endl;

	// 使用前插法创建链表，并输入元素个数
	cout << "使用前插法创建链表, 请输入元素个数";
	int n = getInput(n);
	cout << "输入" << n << "个元素, 用空格分割";
	CreateList_H(L, n);
	// 输出线性表中的元素,并返回长度
	int m = ListLengthpf(L);
	cout << "该线性表中的元素个数为：" << m << endl;

	// 获取第个i元素
	cout << "获取第i个元素，请输入i";
	int i = getInput(i);
	Status T = GetElem_L(L, i, e);
	cout << "返回值为1时获取第i个元素成功，否则不成功：" << T << endl;
	cout << "第i个元素的值为：" << e << endl;

	// 查找第一个与e相等的元素,返回地址
	cout << "查找第1个与e相等的元素，请输入e";
	getInput(e);
	t = LocateElem_L(L, e);
	cout << "第一个与e相等的元素的地址为：" << t << endl;
	// 查找第一个与e相等的元素,返回位置
	m = LocateElem(L, e);
	cout << "第一个与e相等的元素的位置为：" << m << endl;

	// 查找所有与e相等的元素,返回其个数
	cout << "查找所有与e相等的元素，返回其个数，请输入e";
	getInput(e);
	int k = SumElem_L(L, e);
	cout << "所有与e相等的元素个数为：" << k << endl;

	// 在第i位置插入元素e
	cout << "在第i位置插入元素e，请输入i和e,以空格隔开";
	std::vector<ElemType> values;
	while(!getMultipleInput(values, 2)){}
	i = values[0];
	e = values[1];
	ListInsert_L(L, i, e);
	// 输出插入后线性表的元素
	cout << "在指定位置插入元素后链表为：" << endl;
	ListLengthpf(L);

	// 删除表中第i个元素
	cout << "删除表中第i个元素，请输入i";
	getInput(i);
	T = ListDelete_L(L, i);
	cout << "返回值为1时删除第i个元素成功，否则不成功：" << T << endl;
	// 输出删除后线性表的元素
	cout << "删除第i个元素后链表为：" << endl;
	ListLengthpf(L);

	// 删除表中第一个值为e的元素
	cout << "删除表中第一个值为e的元素，请输入e";
	getInput(e);
	ListDelete1(L, e);
	// 输出删除后线性表的元素
	cout << "删除第一个值为e的元素后链表为：" << endl;
	ListLengthpf(L);

	// 删除表中所有值为e的元素
	cout << "删除表中所有值为e的元素，请输入e";
	getInput(e);
	ListDelete2(L, e);
	// 输出删除所有与e相等元素后的线性表的元素
	cout << "删除所有值为e的元素后链表为：" << endl;
	ListLengthpf(L);

	// 查找线性表中最大的值，返回其地址
	maxp = Max(L, &e);
	cout << "找出线性表中最大的值为"<< e <<"，返回其地址为：" << maxp << endl;

	// 逆转链表
	Inverse(L);
	cout << "逆转后链表的元素为：" << endl;
	// 输出逆转后线性表的元素
	ListLengthpf(L);
}
