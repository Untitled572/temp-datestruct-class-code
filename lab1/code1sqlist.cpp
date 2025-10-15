#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;   // Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType; // ElemType 为可定义的数据类型，此设为int类型
#define MAXSIZE 100   // 顺序表可能达到的最大长度
typedef struct SqList
{
    ElemType *elem; // 存储空间的基地址
    int length;     // 当前长度
} SqList;
Status InitList_Sq(SqList &L)
{ // 算法2.1 顺序表的初始化
    // 构造一个空的顺序表L
    L.elem = new ElemType[MAXSIZE]; // 为顺序表分配一个大小为MAXSIZE的数组空间
    if (!L.elem)
        exit(OVERFLOW); // 存储分配失败退出
    L.length = 0;       // 空表长度为0
    return OK;
}
Status GetElem(SqList L, int i, ElemType &e)
{ // 算法2.2　顺序表的取值
    if (i < 1 || i > L.length)
        return ERROR;  // 判断i值是否合理，若不合理，返回ERROR
    e = L.elem[i - 1]; // elem[i-1]单元存储第i个数据元素
    return OK;
}
int LocateElem_Sq(SqList L, ElemType e)
{ // 算法2.3 顺序表的查找
    // 顺序表的查找
    for (int i = 0; i < L.length; i++)
        if (L.elem[i] == e)
            return i + 1; // 查找成功，返回序号i+1
    return 0;             // 查找失败，返回0
}
Status ListInsert_Sq(SqList &L, int i, ElemType e)
{ // 算法2.4 顺序表的插入
    // 在顺序表L中第i个位置之前插入新的元素e
    // i值的合法范围是1<=i<=L.length+1
    if ((i < 1) || (i > L.length + 1))
        return ERROR; // i值不合法
    if (L.length == MAXSIZE)
        return ERROR; // 当前存储空间已满
    int maxindex = L.length - 1;
    for (int j = maxindex; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j]; // 插入位置及之后的元素后移
    L.elem[i - 1] = e;             // 将新元素e放入第i个位置
    ++L.length;                    // 表长增1
    return OK;
}
Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{ // 算法2.5 顺序表的删除
    // 在顺序表L中删除第i个元素，并用e返回其值
    // i值的合法范围是1<=i<=L.length
    if ((i < 1) || (i > L.length))
        return ERROR; // i值不合法
    e = L.elem[i - 1];
    for (int j = i; j < L.length; j++)
        L.elem[j - 1] = L.elem[j]; // 被删除元素之后的元素前移
    L.length -= 1;
    return OK;
}
void addelem(SqList &L, int n)
{ // 算法2.6 顺序表元素的添加
    if (n < 0 || n > MAXSIZE)
    {
        cout << "输入的元素个数不合法！" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int ele;
        if (cin >> ele)
        {
            L.elem[i] = ele;
            L.length += 1;
        }
        else
        {
            cout << "输入错误，停止添加！" << endl;
            break;
        }
    }
}
void printelem(SqList L)
{ // 算法2.7 顺序表元素的输出
    for (int i = 0; i < L.length; i += 1)
    {
        cout << L.elem[i] << " ";
    } // 输出元素之间以空格隔开，全部输出后换行
    cout << endl;
}
int LocateElem(SqList L, ElemType e)
{ // 算法2.8 顺序表的查找2
    // 查找所有值为e的元素
    int k = 0;
    for (int i = 0; i < L.length; i += 1)
    {
        if (L.elem[i] == e)
        {
            k += 1;
        }
    }
    return k;
}
void ListDelete1(SqList &L, int e)
{ // 算法2.9 顺序表的按值删除1
    // 删除第一个值为e的元素
    for (int i = 0; i < L.length; i += 1)
    {
        if (L.elem[i] == e)
        {
            for (int j = i + 1; j < L.length; j += 1)
            {
                L.elem[j - 1] = L.elem[j];
            }
            L.length -= 1;
            return;
        }
    }
}
void ListDelete2(SqList &L, int e)
{ // 算法10 顺序表的按值删除2
    // 删除所有值为e的元素
    for (int i = 0; i < L.length; i += 1)
    {
        if (L.elem[i] == e)
        {
            for (int j = i + 1; j < L.length; j += 1)
            {
                L.elem[j - 1] = L.elem[j];
            }
            L.length -= 1;
            i -= 1;
        }
    }
}
void DestroyList_Sq(SqList &L)
{
    delete[] L.elem;
    L.elem = nullptr;
    L.length = 0;
}
int main()
{
    int i, m, n, k;
    SqList L;
    Status T;
    ElemType e;
    cout << "这是金容畅的实验结果" << endl;
    // 建立空表
    InitList_Sq(L);
    // 输入元素
    cout << "请输入顺序表中的元素个数n,回车后输入元素，元素之间用空格间隔:";
    cin >> n;
    addelem(L, n); // 调用函数实现输入元素
    // 输出线性表中的元素
    printelem(L);
    // 获取第个i元素
    cout << "获取第i个元素，请输入i：";
    cin >> i;
    T = GetElem(L, i, e);
    cout << "返回值为1时获取第i个元素成功，否则不成功：" << T << endl;
    cout << "第" << i << "个元素的值为：" << e << endl;
    // 查找第一个与e相等的元素
    cout << "查找第1个与e相等的元素，请输入e：";
    cin >> e;
    m = LocateElem_Sq(L, e);
    cout << "返回值为非零时是位置，0时查找不成功：" << m << endl;
    // 查找所有与e相等的元素
    cout << "查找所有与e相等的元素，请输入e：";
    cin >> e;
    k = LocateElem(L, e);
    cout << "所有与e相等的元素个数为：" << k << endl;
    // 在第i位置插入元素e
    cout << "在第i位置插入元素e，请输入i和e,以空格隔开：";
    cin >> i >> e;
    ListInsert_Sq(L, i, e); // 调用函数
    // 输出插入后线性表的元素
    printelem(L);
    // 删除表中第i个元素
    cout << "删除表中第i个元素，请输入i：";
    cin >> i;
    T = ListDelete_Sq(L, i, e);
    cout << "返回值为1时删除第i个元素成功，否则不成功：" << T << ", 删除元素为" << e << endl;
    // 输出删除后线性表的元素
    printelem(L);
    // 删除表中第一个值为e的元素
    cout << "删除表中第一个值为e的元素，请输入e：";
    cin >> e;
    ListDelete1(L, e); // 调用函数
    // 输出删除后线性表的元素
    printelem(L);
    // 删除表中所有值为e的元素
    cout << "删除表中所有值为e的元素，请输入e：";
    cin >> e;
    ListDelete2(L, e); // 调用函数
    // 输出删除后线性表的元素
    printelem(L);
    DestroyList_Sq(L);
}
