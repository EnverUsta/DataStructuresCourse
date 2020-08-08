import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Permutation {

    public static void main(String[] args)
    {
        RandomizedQueue<String> rQueue = new RandomizedQueue<>();
        int k = Integer.parseInt(args[0]);
        int outputSize = k;
        while(!StdIn.isEmpty())
        {
            if(rQueue.size() == k && outputSize != 0){
                StdOut.println(rQueue.dequeue());
                outputSize--;
            }
            rQueue.enqueue(StdIn.readString());
        }
    }
}
