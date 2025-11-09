#include <iostream>
#include <cmath>

class Point {
private:
    double x, y;

public:
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    double distanceTo(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return std::sqrt(dx*dx + dy*dy);
    }
};

class Segment {
private:
    Point p1, p2;

public:
    Segment() : p1(), p2() {}
    Segment(const Point& p1, const Point& p2) : p1(p1), p2(p2) {}

    double longueur() const { return p1.distanceTo(p2); }
};

class Triangle {
private:
    Point p1, p2, p3;

public:
    Triangle() : p1(), p2(), p3() {}
    Triangle(const Point& p1, const Point& p2, const Point& p3) : p1(p1), p2(p2), p3(p3) {}

    double perimetre() const {
        Segment s1(p1, p2);
        Segment s2(p2, p3);
        Segment s3(p3, p1);
        return s1.longueur() + s2.longueur() + s3.longueur();
    }
};

int main() {
    Point A(0, 0), B(3, 0), C(0, 4);
    Triangle triangle(A, B, C);

    std::cout << "Périmètre du triangle : " << triangle.perimetre() << std::endl;
    return 0;
}
