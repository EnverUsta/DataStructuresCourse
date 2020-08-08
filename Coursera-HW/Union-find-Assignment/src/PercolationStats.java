import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {
    private double allPossibilityResults[];
    private double mean;
    private double standardDeviation;
    private static final double CONFIDENCE_95 = 1.96;

    // perform independent trials on an n-by-n grid
    public PercolationStats(int n, int trials) {
        if (n <= 0 || trials <= 0) throw new IllegalArgumentException("Invalid value");
        allPossibilityResults = new double[trials];

        for (int i = 0; i < trials; ++i) {
            Percolation percolation = new Percolation(n);
            while (!percolation.percolates()) {
                int row = StdRandom.uniform(1, n + 1);
                int column = StdRandom.uniform(1, n + 1);
                percolation.open(row, column);
            }
            double openSites = percolation.numberOfOpenSites();
            double gridNumbers = n * n;
            double possibility = openSites / gridNumbers;
            allPossibilityResults[i] = (possibility);
        }
    }

    // sample mean of percolation threshold
    public double mean() {
        this.mean = StdStats.mean(allPossibilityResults);
        return this.mean;
    }

    // sample standard deviation of percolation threshold
    public double stddev() {
        standardDeviation = StdStats.stddev(allPossibilityResults);
        return standardDeviation;
    }

    // low endpoint of 95% confidence interval
    public double confidenceLo() {
        return (mean - (CONFIDENCE_95 * standardDeviation / Math.sqrt(allPossibilityResults.length)));
    }

    // high endpoint of 95% confidence interval
    public double confidenceHi() {
        return (mean + (CONFIDENCE_95 * standardDeviation / Math.sqrt(allPossibilityResults.length)));
    }

    // test client (see below)
    public static void main(String[] args) {
        int T = Integer.parseInt(args[0]);
        int n = Integer.parseInt(args[1]);
        PercolationStats percolationStats = new PercolationStats(n, T);
        StdOut.print("mean\t = ");
        StdOut.println(percolationStats.mean());
        StdOut.print("stddev\t = ");
        StdOut.println(percolationStats.stddev());
        StdOut.print("95% confidence interval = [");
        StdOut.print(percolationStats.confidenceLo());
        StdOut.print(", ");
        StdOut.print(percolationStats.confidenceHi());
        StdOut.print("]\n");
    }
}