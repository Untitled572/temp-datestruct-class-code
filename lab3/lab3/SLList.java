package lab3;

public class SLList<Item> implements LinarList<Item> {
    private class Node {
        public Item data;
        public Node next;

        public Node(Item data, Node next) {
            this.data = data;
            this.next = next;
        }
    }

    private Node sentential;
    public int size;

    public SLList() {
        size = 0;
        sentential = new Node(null, null);
    }

    public SLList(Item i) {
        sentential = new Node(null, null);
        sentential.next = new Node(i, null);
        size = 1;
    }

    @Override
    public void addFirst(Item x) {
        sentential.next = new Node(x, sentential.next);
        size += 1;
    }

    @Override
    public void addLast(Item x) {
        Node p = sentential;
        while (p.next != null) {
            p = p.next;
        }
        p.next = new Node(x, null);
        size += 1;
    }

    @Override
    public Item getFirst() {
        return sentential.next.data;
    }

    @Override
    public Item getLast(){
        Node p = sentential;
        while (p.next != null) {
            p = p.next;
        }
        return p.data;
    }

    @Override
    public Item removeLast(){
        Node p = sentential;
        Node rm = p;
        while (p.next != null) {
            rm = p;
            p = p.next;
        }
        Item re = p.data;
        rm.next = null;
        size -= 1;
        return re;
    }


    @Override
    public Item get(int i){
        Node p = sentential;
        while(i > 0 && p.next != null){
            p = p.next;
            i -= 1;
        }
        return p.data;
    }

    @Override
    public void insert(Item x, int position){
        Node p = sentential;
        while(position >= 0 && p.next != null){
            p = p.next;
            position -= 1;
        }
        p.next = new Node(x, p.next);
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public void print(){
        for(Node p = sentential.next; p != null; p = p.next){
            System.out.print(p.data + " ");
        }
        System.out.println();
    }
}
