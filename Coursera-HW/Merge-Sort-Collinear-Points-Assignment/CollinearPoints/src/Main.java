import edu.princeton.cs.algs4.StdOut;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        Point[] points = new Point[]{
                new Point(1,4),
                new Point(2,2),
                new Point(4,4),
                new Point(1,1),
                new Point(2,1),
                new Point(0,0)
        };

        BruteCollinearPoints collinearPoints = new BruteCollinearPoints(points);
        //StdOut.println(collinearPoints.numberOfSegments());
        LineSegment[] l = collinearPoints.segments();
        StdOut.println(l[0]);

        Arrays.sort(points, points[1].slopeOrder());
        for (int i = 0; i < points.length; ++i)
            System.out.println(points[i]);
    }
}
