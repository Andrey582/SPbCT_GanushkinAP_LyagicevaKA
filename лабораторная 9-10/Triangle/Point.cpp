#include <iostream>
#include <math.h>
#include "Point.h"
#include "Triangle.h"
using namespace std;
// F U N C T I O N S /////////////////////////////////////////////////////////
//показать точку

void Point::Show() const {
    cout << " (" << x << ", " << y << ")";
}

void Point::operator +=(Point& p) {
    x += p.x; y += p.y;//запуск перегружаемого +=
}

Point Point::operator + (Point& p) {
    return Point(x + p.x, y + p.y);//запуск перегружаемого +
}

Point Point::operator - (Point& p) {
    return Point(x - p.x, y - p.y);//запуск перегружаемого -
}

double Point::Length() const {
    return sqrt(x * x + y * y);
}

ORIENT Point::Classify(Point& beg_p, Point& end_p) const {
    Point p0 = *this;
    Point a = end_p - beg_p;
    Point b = p0 - beg_p;
    double sa = a.x * b.y - b.x * a.y;
    if (sa > 0.0) return LEFT;
    if (sa < 0.0) return RIGHT;
    if ((a.x * b.x < 0.0) || (a.y * b.y < 0.0)) return BEHIND;
    if (a.Length() < b.Length()) return AHEAD;
    return BETWEEN;
}

 

bool Point::InTriangle(Triangle& tria) const {
    Point a = tria.Get_v1();
    Point b = tria.Get_v2();
    Point c = tria.Get_v3();
    ORIENT or1 = Classify(a, b);
    ORIENT or2 = Classify(b, c);
    ORIENT or3 = Classify(c, a);
    if ((or1 == RIGHT) || (or1 == BETWEEN) && (or2 == RIGHT) || (or2 == BETWEEN) && (or3 == RIGHT) || (or3 == BETWEEN))
        return true;
    else return false;
}