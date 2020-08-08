import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Random;

public class RandomizedQueue<Item> implements Iterable<Item> {
    private Item[] array;
    private int sizeOfArray;
    private int tail;


    private void resize(int capacity){
        Item[] newArray = (Item[]) new Object[capacity];
        for (int i = 0; i < sizeOfArray; ++i)
            newArray[i] = array[i];
        array = newArray;
    }

    // construct an empty randomized queue
    public RandomizedQueue()
    {
        array = (Item[]) new Object[1];
        sizeOfArray = 0;
        tail = -1;
    }

    // is the randomized queue empty?
    public boolean isEmpty(){return sizeOfArray == 0;}

    // return the number of items on the randomized queue
    public int size(){return sizeOfArray;}

    // add the item
    public void enqueue(Item item){
        if(item == null) throw new IllegalArgumentException("Your argument shouldn't be null.");
        if(sizeOfArray == array.length) resize(sizeOfArray*2);
        array[++tail] = item;
        sizeOfArray++;
    }

    // remove and return a random item
    public Item dequeue()
    {
        if(isEmpty()) throw new NoSuchElementException("Array is empty, therefore; try to enqueue some items");
        if(sizeOfArray == array.length/4) resize(array.length/2);
        int randomNumber = StdRandom.uniform(0, sizeOfArray);
        Item rValue = array[randomNumber];
        array[randomNumber] = array[tail];
        array[tail] = null;
        sizeOfArray--;
        tail--;
        return rValue;
    }

    // return a random item (but do not remove it)
    public Item sample()
    {
        if(isEmpty()) throw new NoSuchElementException("Array is empty, therefore; try to enqueue some items");
        int randomNumber = StdRandom.uniform(0, sizeOfArray);
        return array[randomNumber];
    }

    // return an independent iterator over items in random order
    public Iterator<Item> iterator(){
        return new RandomizedIterator();
    }


    private class RandomizedIterator implements Iterator<Item>{
        private Item[] iteratorArray;
        private int sizeOfIteratorArray;
        private int tailOfIterator;

        RandomizedIterator(){
            iteratorArray = (Item[]) new Object[sizeOfArray];
            sizeOfIteratorArray = sizeOfArray;
            for(int i = 0; i < sizeOfIteratorArray; ++i)
                iteratorArray[i] = array[i];
            tailOfIterator = sizeOfIteratorArray-1;
        }

        @Override
        public boolean hasNext() {
            return sizeOfIteratorArray != 0;
        }

        @Override
        public Item next() {
            if(sizeOfIteratorArray == 0) throw new NoSuchElementException("Sorry, it's empty");
            int randomNumber = StdRandom.uniform(0, sizeOfIteratorArray);
            Item rValue = iteratorArray[randomNumber];
            iteratorArray[randomNumber] = iteratorArray[tailOfIterator];
            iteratorArray[tailOfIterator] = null;
            sizeOfIteratorArray--;
            tailOfIterator--;
            return rValue;
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException("Sorry, this operation is unsupported");
        }
    }

    // unit testing (required)
    public static void main(String[] args){
        RandomizedQueue<Integer> rQueue = new RandomizedQueue<Integer>();
        rQueue.enqueue(10);
        rQueue.enqueue(20);
        rQueue.enqueue(30);
        rQueue.enqueue(40);
        rQueue.enqueue(50);

        StdOut.print("public sample(): ");
        StdOut.println(rQueue.sample());
        StdOut.print("public dequeue(): ");
        StdOut.println(rQueue.dequeue());
        StdOut.print("public size(): ");
        StdOut.println(rQueue.size());
        StdOut.print("public isEmpty(): ");
        StdOut.println(rQueue.isEmpty());

        for(var element : rQueue){
            StdOut.println(element);
        }
        StdOut.print("public dequeue(): ");
        StdOut.println(rQueue.dequeue());
        StdOut.print("public dequeue(): ");
        StdOut.println(rQueue.dequeue());
        StdOut.print("public dequeue(): ");
        StdOut.println(rQueue.dequeue());
        StdOut.print("public dequeue(): ");
        StdOut.println(rQueue.dequeue());
        try {
            StdOut.print("public dequeue(): ");
            StdOut.println(rQueue.dequeue());
        }catch (NoSuchElementException e)
        {
            StdOut.println(e.getMessage());
        }

        rQueue.enqueue(1);
        StdOut.println("public deque: " + rQueue.dequeue());

        int n = 5;
        RandomizedQueue<Integer> queue = new RandomizedQueue<Integer>();
        for (int i = 0; i < n; i++)
            queue.enqueue(i);
        for (int a : queue) {
            for (int b : queue)
                StdOut.print(a + "-" + b + " ");
            StdOut.println();
        }

    }
}
