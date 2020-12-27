import static java.lang.Math.sqrt;

public class TryGeometry {
    public static void main(String[] args) {
        Point start = new Point(0.0, 1.0);
        Point end = new Point(5.0, 6.0);
        System.out.println("Points created are " + start + " and " + end);
        
        Line line1 = new Line(start, end);
        Line line2 = new Line(0.0, 3.0, 3.0, 0.0);
        System.out.println("Lines created are " + line1 + " and " + line2);
        
        System.out.println("Intersection is " + line2.intersects(line1));
    
        end.move(1.0, -5.0);
        System.out.println("Intersection is " + line1.intersects(line2));

    }
}

class Point {
    // Coordinates of the point
    double x;
    double y;

    Point(double xVal, double yVal) {
        x = xVal;
        y = yVal;
    }

    Point(final Point oldPoint) {
        x = oldPoint.x;
        y = oldPoint.y;
    }

    void move(double xDelta, double yDelta) {

        x += xDelta;
        y += yDelta;
    }

    double distance(final Point aPoint) {
        return sqrt((x - aPoint.x)*(x - aPoint.x) + (y - aPoint.y)*(y - aPoint.y));
    }


    public String toString() {
        return Double.toString(x) + ", " + y;
    }
}

class Line {
    Point start; 
    Point end; 

    Line(final Point start, final Point end) {
        this.start = new Point(start);
        this.end = new Point(end);
    }

    Line(double xStart, double yStart, double xEnd, double yEnd) {
        start = new Point(xStart, yStart);
        end = new Point(xEnd, yEnd); 
    }

    double length() {
        return start.distance(end); 
    }
    
    public String toString() {
        return "(" + start+ "):(" + end + ")"; 
    } 

    Point intersects(final Line line1) {
        Point localPoint = new Point(0, 0);
        double num = (this.end.y - this.start.y)*(this.start.x - line1.start.x) -
        (this.end.x - this.start.x)*(this.start.y - line1.start.y);
        double denom = (this.end.y - this.start.y)*(line1.end.x - line1.start.x) -
        (this.end.x - this.start.x)*(line1.end.y - line1.start.y);
        localPoint.x = line1.start.x + (line1.end.x - line1.start.x)*num/denom;
        localPoint.y = line1.start.y + (line1.end.y - line1.start.y)*num/denom;
        return localPoint;
    }
}
