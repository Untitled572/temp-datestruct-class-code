#include <algorithm>
#include <iostream>
#include "tree.hpp"

using std::cout;
using std::endl;
using std::string;

int main()
{
    BiTree tree;
    char path[100];  // 路径数组，存储路径上每个结点的值
    int pathlen = 0; // 初始化路径到根结点的长度为0
    int m;           // 层次遍历二叉树时统计度为1的结点个数
    int i = -1;
    string s = "AB#CD##E##F#GH###";
    cout << "1、请输入先序建立二叉树的序列：\n";
    //getInput(s);
    cout << s << endl;
    CreateBiTree(tree, s, i);

    cout << "2、中序遍历二叉树的序列为：\n";
    InOrderTraverse(tree);
    cout << endl;
    cout << "2-1、前序遍历二叉树的序列为：\n";
    PreOrderTraverse(tree);
    cout << endl;
    cout << "2-2、后序遍历二叉树的序列为：\n";
    AfterOrderTraverse(tree);
    cout << endl;

    cout << "3、二叉树的深度为:" << Depth(tree) << endl;
    cout << "4、二叉树中结点个数为:" << NodeCount(tree) << endl;
    cout << "5、二叉树中叶子结点个数为:" << LeafCount(tree) << endl;
    cout << "6、二叉树中度为1的结点个数为:" << count1better(tree) << endl;
    cout << "7、二叉树中度为2的结点个数为:" << count2better(tree) << endl;
    cout << "8、二叉树中每个叶子结点到根结点的路径为:\n";
    AllPath(tree, path, pathlen);
    ChangeLR(tree);
    cout << "9、交换每个结点左右孩子后中序遍历二叉树的序列为：\n";
    InOrderTraverse(tree);
    cout << endl;
    cout << "10、层次遍历二叉树的序列为：\n";
    m = Level(tree);
    cout << endl;
    cout << "层次遍历二叉树中度为1的结点个数为:" << m << endl;
}
