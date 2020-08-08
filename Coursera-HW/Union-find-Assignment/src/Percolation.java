import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    private final WeightedQuickUnionUF id;
    private final boolean status[];

    private int countOpenSites;
    private final int topIndex, bottomIndex, N;

    private int convertThePositionAsIdIndex(int row, int column) {
        return (row-1)*N + (column-1);
    }

    // creates n-by-n grid, with all sites initially blocked.
    public Percolation(int N){
        if(N <= 0) throw new IllegalArgumentException("Out of bounds!");

        this.N = N;
        id = new WeightedQuickUnionUF(N*N+2);
        status = new boolean[N*N];
        for (int i = 0; i < N*N; ++i)
            status[i] = false;

        topIndex = N*N;
        bottomIndex = N*N+1;
        countOpenSites = 0;

        for(int i = 1; i <= N; i++)
        {
            id.union(topIndex, convertThePositionAsIdIndex(1, i));
            id.union(bottomIndex, convertThePositionAsIdIndex(N, i));
        }

    }

    // opens the site if it is not open already
    public void open(int row, int col)
    {
        if(row > N || row < 1 || col > N || col < 1) throw new IllegalArgumentException("Out of bounds");
        if(isOpen(row, col)) return;
        countOpenSites++;
        status[convertThePositionAsIdIndex(row, col)] = true;
        if(row - 1 > 0 && isOpen(row-1, col)) id.union(convertThePositionAsIdIndex(row, col), convertThePositionAsIdIndex(row-1,col));
        if(row + 1 <= N && isOpen(row+1, col)) id.union(convertThePositionAsIdIndex(row,col), convertThePositionAsIdIndex(row+1, col));
        if(col - 1 > 0 && isOpen(row, col-1)) id.union(convertThePositionAsIdIndex(row,col), convertThePositionAsIdIndex(row, col-1));
        if(col + 1 <= N && isOpen(row, col +1)) id.union(convertThePositionAsIdIndex(row, col), convertThePositionAsIdIndex(row, col+1));
    }

    //is the site(row, col) open?
    public boolean isOpen(int row, int col)
    {
        return status[convertThePositionAsIdIndex(row, col)];
    }

    //is the site(row, col) full?
    public boolean isFull(int row, int col)
    {
        if(id.connected(topIndex, convertThePositionAsIdIndex(row, col)) && isOpen(row, col)) return true;
        else return false;
    }

    //returns the number of open sites
    public int numberOfOpenSites()
    {
        return countOpenSites;
    }

    //Does the system percolate?
    public boolean percolates()
    {
        return id.connected(topIndex, bottomIndex);
    }

    public static void main(String[] args)
    {
        Percolation percolation = new Percolation(10);

        while(!percolation.percolates())
        {
            int row = StdRandom.uniform(1, 11);
            int column = StdRandom.uniform(1, 11);
            percolation.open(row, column);
            StdOut.println(percolation.isOpen(row, column));
            StdOut.printf("opened(%d, %d)\n", row, column);
            StdOut.println(percolation.percolates());
        }
        StdOut.println(percolation.numberOfOpenSites());


    }
}