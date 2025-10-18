import java.util.Scanner;

public class Lab1SqList {
    private int length;
    private int[] elem;

    public static final int MAXSIZE = 100;

    public Lab1SqList() {// 算法2.1 顺序表的初始化
        elem = new int[MAXSIZE];
        length = 0;
    }

    int getElem(int i) {// 算法2.2 顺序表的取值
        int length = elem.length;
        if (i < 1 || i > length) {
            return -1;
        }
        return elem[i - 1];
    }

    public int locateElem_Sq(int e) { // 算法2.3 顺序表的查找
        for (int i = 0; i < length; i += 1) {
            if (elem[i] == e) {
                return i + 1; // 查找成功，返回序号i+1
            }
        }
        return 0;
    }

    public boolean listInsert_Sq(int i, int e) {// 算法2.4 顺序表的插入
        // 在顺序表L中第i个位置之前插入新的元素e
        // i值的合法范围是1<=i<=L.length+1
        if ((i < 1) || (i > length + 1))
            return false; // i值不合法
        if (length == MAXSIZE)
            return false; // 当前存储空间已满
        int maxindex = length - 1;
        for (int j = maxindex; j >= i - 1; j -= 1)
            elem[j + 1] = elem[j]; // 插入位置及之后的元素后移
        elem[i - 1] = e; // 将新元素e放入第i个位置
        length += 1; // 表长增1
        return true;
    }

    public int listDelete_Sq(int i) {// 算法2.5 顺序表的删除
        if ((i < 1) || (i > length))
            return -1; // i值不合法
        int e = elem[i - 1];
        for (int j = i; j < length; j += 1)
            elem[j - 1] = elem[j]; // 被删除元素之后的元素前移
        length -= 1;
        return e;
    }

    public boolean addElem(int n, int[] input) {// 算法2.6 顺序表元素的添加
        if (n < 0 || length + n > MAXSIZE || input.length < n) {
            return false; // 越界或输入无效
        }
        for (int k = 0; k < n; k++) {
            elem[length] = input[k];
            length += 1;
        }
        return true;
    }

    public void printElem() {// 算法2.7 顺序表元素的输出
        for (int i = 0; i < length; i += 1) {
            System.out.print(elem[i] + " ");
        } // 输出元素之间以空格隔开，全部输出后换行
        System.out.println();
    }

    public int locateElem(int e) {// 算法2.8 顺序表的查找2
        int count = 0;
        for (int i = 0; i < length; i += 1) {
            if (elem[i] == e) {
                count += 1;
            }
        }
        return count;
    }

    public void listDelete1(int e) {// 算法2.9 顺序表的按值删除1
        for (int i = 0; i < length; i += 1) {
            if (elem[i] == e) {
                for (int j = i + 1; j < length; j += 1) {
                    elem[j - 1] = elem[j];
                }
                length -= 1;
                return;
            }
        }
    }

    public void listDelete2(int e) {// 算法10 顺序表的按值删除2
        int k = 0;
        for (int i = 0; i < length; i += 1) {
            if (elem[i] != e) {
                elem[k] = elem[i];
                k += 1;
            }
        }
        length = k;
    }

    public static int getInt(Scanner scanner) {
        while (true) {
            try {
                int i = scanner.nextInt();
                return i;
            } catch (Exception i) {
                System.out.println("请输入有效的整数！");
                scanner.next();
            }
        }
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int n, i, e, m;
            int T;
            Lab1SqList L = new Lab1SqList();
            System.out.println("这是金容畅的实验结果");

            // 输入元素个数
            System.out.print("请输入顺序表中的元素个数n,回车后输入元素，元素之间用空格间隔: ");
            n = getInt(scanner);
            if (n < 0 || n > MAXSIZE) {
                System.out.println("元素个数无效！");
                return;
            }

            // 输入元素
            int[] temp = new int[n];
            for (int ii = 0; ii < n; ii += 1) {
                temp[ii] = getInt(scanner);
            }
            if (!L.addElem(n, temp)) {
                System.out.println("添加元素失败，检查输入或容量限制！");
                return;
            }

            // 输出线性表中的元素
            L.printElem();

            // 获取第i个元素
            System.out.print("获取第i个元素，请输入i：");
            i = getInt(scanner);
            int result = L.getElem(i);
            if (result == -1) {
                System.out.println("获取第" + i + "个元素失败，序号无效！");
            } else {
                System.out.println("第i个元素的值为：" + result);
            }

            // 查找第一个与e相等的元素
            System.out.print("查找第1个与e相等的元素，请输入e：");
            e = getInt(scanner);
            m = L.locateElem_Sq(e);
            System.out.println("返回值为非零时是位置，0时查找不成功：" + m);

            // 查找所有与e相等的元素
            System.out.print("查找所有与e相等的元素，请输入e：");
            e = getInt(scanner);
            int count = L.locateElem(e);
            System.out.println("所有与e相等的元素个数为：" + count);

            // 在第i位置插入元素e
            System.out.print("在第i位置插入元素e，请输入i和e,以空格隔开：");
            i = getInt(scanner);
            e = getInt(scanner);
            if (!L.listInsert_Sq(i, e)) {
                System.out.println("插入失败！");
            }
            // 输出插入后线性表的元素
            L.printElem();

            // 删除表中第i个元素
            System.out.print("删除表中第i个元素，请输入i：");
            i = getInt(scanner);
            T = L.listDelete_Sq(i);
            System.out.println("返回值为-1时删除第i个元素不成功，删除元素为：" + T);
            L.printElem();

            // 删除表中第一个值为e的元素
            System.out.print("删除表中第一个值为e的元素，请输入e：");
            e = getInt(scanner);
            L.listDelete1(e);
            L.printElem();

            // 删除表中所有值为e的元素
            System.out.print("删除表中所有值为e的元素，请输入e：");
            e = getInt(scanner);
            L.listDelete2(e);
            L.printElem();
        }
    }
}
