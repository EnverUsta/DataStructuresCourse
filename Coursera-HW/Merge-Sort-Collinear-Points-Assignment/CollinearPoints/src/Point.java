import edu.princeton.cs.algs4.StdDraw;

import java.util.Comparator;

public class Point implements Comparable<Point> {
    private final int x;     // x-coordinate of this point
    private final int y;     // y-coordinate of this point

    public Point(int x, int y) {
        /* DO NOT MODIFY */
        this.x = x;
        this.y = y;
    }

    public void draw() {
        /* DO NOT MODIFY */
        StdDraw.point(x, y);
    }

    public void drawTo(Point that) {
        /* DO NOT MODIFY */
        StdDraw.line(this.x, this.y, that.x, that.y);
    }

    public double slopeTo(Point that) {
        /* YOUR CODE HERE */
        double numerator = that.y - this.y;
        double denominator = that.x - this.x;

        if(numerator == 0 && denominator == 0) return Double.NEGATIVE_INFINITY;
        else if(numerator == 0) return 0.0;
        else if(denominator == 0) return Double.POSITIVE_INFINITY;
        else return (double)numerator/denominator;
    }

    public int compareTo(Point that) {
        /* YOUR CODE HERE */
        if(this.y < that.y) return -1;
        else if(this.y > that.y) return 1;
        else
        {
            if(this.x < that.x) return -1;
            else if(this.x > that.x) return 1;
            else return 0;
        }
    }

    public Comparator<Point> slopeOrder()
    {
        return new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                double slope1 = slopeTo(o1);
                double slope2 = slopeTo(o2);
                if (slope1 == slope2) return 0;
                if (slope1 < slope2) return -1;
                return 1;
            }
        };
    }

    public String toString() {
        /* DO NOT MODIFY */
        return "(" + x + ", " + y + ")";
    }

    public static void main(String[] args) {
        /* YOUR CODE HERE */
    }
}