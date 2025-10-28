import lab3.*;

public class Stack<Item> {
    private LinarList<Item> items = new SLList<>();
    //private LinarList<Item> items = new AList<>();       //Array list implement

    //private

    public void push(Item x){
        items.addLast(x);
    }

    public Item pop(){
        return items.removeLast();
    }

    public Item getTop(){
        return items.get(items.size());
    }

    public int size(){
        return items.size();
    }

    public static void main(String[] args) {
        Stack<String> s = new Stack<>();
        s.push("4");
        s.push("0");
        s.push("5");
        s.push("2");
        System.out.println(s.pop());
    }
}
