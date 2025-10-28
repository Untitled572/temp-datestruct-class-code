package lab3;

public interface LinarList<Item> {
    public void addFirst(Item x);
    public void addLast(Item x);
    public Item getFirst();
    public Item getLast();
    public Item removeLast();
    public Item get(int i);
    public void insert(Item x, int position);
    public int size();
    default public void print(){
        int size = size();
        for(int i = 1; i <= size; i += 1){
            System.out.print(get(i) + " ");
        }
        System.out.println();
    }
}