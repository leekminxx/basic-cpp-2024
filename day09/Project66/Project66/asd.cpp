#include <iostream>

class Point {
private:
    int xpos, ypos;

public:
    // Constructor
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

    // Member function to view point
    void viewPoint() const {
        std::cout << xpos << " " << ypos << " " << std::endl;
    }

    // Overloaded addition operator
    Point operator+(const Point& other) const {
        Point result(xpos + other.xpos, ypos + other.ypos);
        return result;
    }

    // Friend function for reversed order of addition
    friend Point operator+(int value, const Point& point) {
        Point result(point.xpos + value, point.ypos + value);
        return result;
    }

    // Overloaded output stream operator
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << point.xpos << " " << point.ypos;
        return os;
    }
};

int main() {
    Point a(10, 20);
    Point b(30, 40);
    Point c = a + b;
    Point d = a + 100;
    Point e = 100 + a;

    d.viewPoint();
    e.viewPoint();

    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;

    return 0;
}
