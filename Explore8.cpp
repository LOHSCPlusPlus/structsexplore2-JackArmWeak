
#include <iostream>
using namespace std;
struct Point {
	double x;
	double y;
	Point();
	Point(double xVal, double yVal);
};
struct Line {
    Point start;
    Point end;
    Line(Point s, Point e);
};
Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(double xVal, double yVal) {
    x = xVal;
    y = yVal;
}

Line::Line(Point s, Point e) {
    start = s;
    end = e;
}

void PrintPoint(Point p) {
    cout << ": x = " << p.x << ", y = " << p.y;
}


void PrintLine(Line l) {
    cout << "  Start";
    PrintPoint(l.start);
    cout << "   End";
    PrintPoint(l.end); 
    cout << endl;
}

// This is new
Point FindMidPoint(Line l) {
    Point mid;
    mid.x = (l.start.x + l.end.x)/2.0;
    mid.y = (l.start.y + l.end.y)/2.0;
    return mid;
}

Point FindLowestPoint(Line p) {
  Point lowest;
  if(p.start.y > p.end.y) {
    lowest.y = p.end.y;
    lowest.x = p.end.x;
  }
  else {
    lowest.y = p.start.y;
    lowest.x = p.start.x;
  }
  return lowest;
}

int main() {
    Line a(Point(3,9), Point(12,22));
    cout << "Line a";
    PrintLine(a);
    cout << "Line a's midpoint";
    // This is new
    Point midPoint = FindMidPoint(a);
    PrintPoint(midPoint);
    cout << endl;
    cout << "Lines a's lowest point";
    Point lowestPoint = FindLowestPoint(a);
    PrintPoint(lowestPoint);
    cout << endl;
    cout << "Line b's lowest point";
    Line b(Point(7,-9), Point(8,-15));
    lowestPoint = FindLowestPoint(b);
    PrintPoint(lowestPoint);
    cout << endl;

    return 0;
}


