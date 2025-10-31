import lab3.*;

public class Queue<Item> {
    private LinarList<Item> items = new SLList<>();

    public void push(Item x){items.addFirst(x);}

    public Item pop(){return items.removeLast();}

    public Item getFront(){return items.get(1);}

    public int size(){return items.size();}
}
