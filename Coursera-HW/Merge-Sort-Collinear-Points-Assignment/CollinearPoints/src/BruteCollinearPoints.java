import java.util.ArrayList;
import java.util.Arrays;

public class BruteCollinearPoints {
    private ArrayList<LineSegment> lineSegments;

    private boolean hasNullPoint(Point[] points)
    {
        for (Point p: points) if(p == null) return true;
        return false;
    }

    private static LineSegment[] getArray(ArrayList<LineSegment> ls)
    {
        LineSegment[] lsArray = new LineSegment[ls.size()];
        int i = 0;
        for (LineSegment l : ls) lsArray[i++] = l;
        return lsArray;
    }

    private Point[] copyPoints(Point[] points){
        Point[] copyPoint = new Point[points.length];
        int countCopy = 0;
        for (Point p: points) copyPoint[countCopy++] = p;
        return copyPoint;
    }

    public BruteCollinearPoints(Point[] points)
    {
        if(points == null || hasNullPoint(points)) throw new IllegalArgumentException();
        double slopeValue;
        lineSegments = new ArrayList<>();
        Point[] copyPoints = copyPoints(points);
        Arrays.sort(copyPoints);
        for(int i = 0; i < copyPoints.length; i++){
            for (int j = i+1; j < copyPoints.length; j++)
            {
                slopeValue = copyPoints[i].slopeTo(copyPoints[j]);
                if(copyPoints[j].compareTo(copyPoints[i]) == 0) throw new IllegalArgumentException();
                for (int k = j+1; k < copyPoints.length; k++){
                    if(slopeValue == copyPoints[i].slopeTo(copyPoints[k])){
                        for (int l = k+1; l < copyPoints.length; l++){
                            if(slopeValue == copyPoints[i].slopeTo(copyPoints[l])) {
                                if(copyPoints[i] == null || copyPoints[j] == null || copyPoints[k] == null || copyPoints[l] == null)
                                    throw new IllegalArgumentException();
                                lineSegments.add(new LineSegment(copyPoints[i], copyPoints[l]));
                            }
                        }
                    }
                }
            }
        }
    }
    public int numberOfSegments()
    {
        return lineSegments.size();
    }
    public LineSegment[] segments()
    {
        return getArray(lineSegments);
    }
}
