#include <iostream>
#include "code2st.h"

typedef char ElemType;

int main(){
    int m, n, i, k;
    LinkList<ElemType> L;
    InitList_L(L);
    LNode<ElemType> *t, *maxp;
    Status T;
    ElemType e;
    cout << "这是金容畅的实验结果" << endl;

    // 使用前插法创建链表，并输入元素个数
    cout << "请使用前插法创建链表，元素之间用空格间隔，请输入元素个数:";
    cin >> n;
    CreateList_H(L, n);
    // 输出线性表中的元素,并返回长度
    m = ListLengthpf(L);
    cout << "该线性表中的元素个数为：" << m << endl;

    // 获取第个i元素
    cout << "获取第i个元素，请输入i：";
    cin >> i;
    T = GetElem_L(L, i, &e);
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
    k = SumElem_L(L, e);
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
    ListDelete1(L, e);
    // 输出删除后线性表的元素
    cout << "删除第一个值为e的元素后链表为：" << endl;
    ListLengthpf(L);

    // 删除表中所有值为e的元素
    cout << "删除表中所有值为e的元素，请输入e：";
    cin >> e;
    ListDelete2(L, e);
    // 输出删除所有与e相等元素后的线性表的元素
    cout << "删除所有值为e的元素后链表为：" << endl;
    ListLengthpf(L);

    // 查找线性表中最大的值，返回其地址
    maxp = Max(L, &e);
    cout << "找出线性表中最大的值为" << e << "，返回其地址为：" << maxp << endl;

    // 逆转链表
    Inverse(L);
    cout << "逆转后链表的元素为：" << endl;
    // 输出逆转后线性表的元素
    ListLengthpf(L);
}
