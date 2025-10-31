import lab3.*;

public class Stack<Item> {
    public LinarList<Item> items = new SLList<>();      //SLList implement
    //private LinarList<Item> items = new AList<>();       //Array list implement

    public void push(Item x){
        items.addLast(x);
    }

    public Item pop(){
        return items.removeLast();
    }

    public Item peek(){
        return items.get(items.size());
    }

    public int size(){
        return items.size();
    }
}
