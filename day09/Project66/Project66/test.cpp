

#include <iostream>
using namespace std;
class Point {
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y)
    {}
    void viewPoint() const {
        cout << xpos << "" << ypos << "" << endl;
    }

    friend Point operator(const Point& other) {
        Point result(xpos + other.xpos, ypos + other.ypos);

        return pos;
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

        cout << c << endl;
        cout << d << endl;
        cout << e << endl;

        return 0;
    }

