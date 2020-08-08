import edu.princeton.cs.algs4.StdOut;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {
    private Node front;
    private Node rear;

    private int numberOfItems;

    private class Node
    {
        private Item data;
        private Node next;
        private Node back;
    }

    private class ListIterator implements Iterator<Item>
    {
        Node current;

        ListIterator() {
            current = front;
        }

        @Override
        public boolean hasNext() {
            return current != null;
        }

        @Override
        public Item next() {
            if(current == null) throw new NoSuchElementException();

            Item returnValue = current.data;
            current = current.next;
            return returnValue;
        }

        @Override
        public void remove(){
            throw new UnsupportedOperationException();
        }
    }

    //construct an empty deque
    public Deque()
    {
        front = rear = null;
        numberOfItems = 0;
    }

    //is the deque empty?
    public boolean isEmpty()
    {
        return front == null && rear == null;
    }

    //return the number of items on the deque
    public int size()
    {
        return numberOfItems;
    }

    //add the item to the front
    public void addFirst(Item item)
    {
        if(item == null)  throw new IllegalArgumentException();

        if(isEmpty())
        {
            front = rear = new Node();
            front.data = item;
            front.next = null;
            front.back = null;
            numberOfItems++;
            return;
        }
        Node oldFront = front;
        front = new Node();
        front.data = item;
        front.next = oldFront;
        oldFront.back = front;
        numberOfItems++;
    }

    //add the item to the back
    public void addLast(Item item)
    {
        if(item == null)   throw new IllegalArgumentException();

        if(isEmpty())
        {
            front = rear = new Node();
            front.data = item;
        }
        else
        {
            Node oldRear = rear;
            rear = new Node();
            rear.data = item;
            rear.back = oldRear;
            oldRear.next = rear;
        }
        numberOfItems++;
    }

    //remove and return the item from the front
    public Item removeFirst()
    {
        if(numberOfItems == 0) throw new NoSuchElementException();

        if(numberOfItems == 1)
        {
            Item rValue = front.data;
            front = rear = null;
            return rValue;
        }

        Item returnValue = front.data;
        front = front.next;
        front.back = null;
        numberOfItems--;
        return  returnValue;
    }

    //remove and return the item from the back
    public Item removeLast()
    {
        if(numberOfItems == 0) throw new NoSuchElementException();

        if(numberOfItems == 1)
        {
            Item rValue = front.data;
            front = rear = null;
            return rValue;
        }

        Item returnValue = rear.data;
        rear = rear.back;
        rear.next = null;
        numberOfItems--;
        return returnValue;
    }

    //return an iterator over items in order from front to back
    @Override
    public Iterator<Item> iterator() {
        return new ListIterator();
    }

    //unit testing (required)
    public static void main(String[] args)
    {
        Deque<Integer> deque = new Deque<>();

        deque.addFirst(10);
        deque.addFirst(20);
        deque.addFirst(30);
        deque.addFirst(40);

        deque.addLast(50);
        deque.addLast(60);

        StdOut.println(deque.removeFirst());
        StdOut.println(deque.removeLast());
        StdOut.print("public size(): ");
        StdOut.println(deque.size());
        StdOut.print("public isEmpty(): ");
        StdOut.println(deque.isEmpty());

        for(int element: deque)
            StdOut.println(element);

        Iterator<Integer> i  = deque.iterator();
        while(i.hasNext())
        {
            StdOut.println(i.next());
        }

        StdOut.println("deque2");
        Deque deque2 = new Deque<Integer>();
        deque.addLast(1);
        StdOut.println(deque2.removeFirst());
        deque.addFirst(3);
        deque.addFirst(4);
        deque.addLast(5);
        StdOut.println(deque2.removeFirst());
        StdOut.println(deque2.removeFirst());
        StdOut.println(deque2.removeFirst());
    }
}
