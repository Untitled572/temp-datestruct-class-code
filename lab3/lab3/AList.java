package lab3;

public class AList<Item> implements LinarList<Item> {
    private int MAXSIZE = 100;
    private Item[] items;
    private int size;

    public AList() {
        items = (Item[]) new Object[MAXSIZE];
        size = 0;
    }

    public AList(Item x) {
        items = (Item[]) new Object[MAXSIZE];
        items[0] = x;
        size = 1;
    }

    private void resize(int capacity) {
        MAXSIZE = capacity;
        Item[] itemsNew = (Item[]) new Object[MAXSIZE];
        if (size >= 0) {
            System.arraycopy(items, 0, itemsNew, 0, size);
        }
        items = itemsNew;
    }

    @Override
    public void addFirst(Item x) {
        if (size == items.length) {
            resize(size * 2);
        }
        for(int i = 0; i < size; i += 1) {
            Item temp = items[i + 1];
            items[i + 1] = items[i];
        }
        items[0] = x;
        size += 1;
    }

    @Override
    public void addLast(Item x) {
        if (size == items.length) {
            resize(size * 2);
        }
        items[size] = x;
        size = size + 1;
    }

    @Override
    public Item getFirst() {
        return items[0];
    }

    @Override
    public Item getLast() {
        return items[size - 1];
    }

    @Override
    public Item removeLast() {
        size -= 1;
        return items[size];
    }

    @Override
    public Item get(int i) {
        return items[i + 1];
    }

    @Override
    public void insert(Item x, int position) {
        if (size == items.length) {
            resize(size * 2);
        }
        for (int i = position; i < size; i += 1) {
            items[i + 1] = items[i];
        }
        items[position] = x;
        size += 1;
    }

    @Override
    public int size() {
        return size;
    }
}