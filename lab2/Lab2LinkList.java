import java.util.Scanner;


public class Lab2LinkList<ElemType> {
    private class LNode {
        public ElemType data;
        public LNode next;

        public LNode(ElemType d, LNode n) {
            data = d;
            next = n;
        }
    }

    public LNode first;


    public Lab2LinkList() {
        first = new LNode(null, null);
    }

    public void initListL() {
        // 算法2.6 单链表初始化
        Lab2LinkList<Integer> L = new Lab2LinkList<>();
    }

    public void createListH(int n) {

        Scanner input = new Scanner(System.in);
        int number = input.nextInt();
        input.close();
    }

    public static void main(String[] args) {
        
    }

}
