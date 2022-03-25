#include <iostream>
#include <ctime>
using namespace std;


class Point {
    int x_coord, y_coord;

public:
    Point();

    static Point **generate_pointers_array(int array_count);

    bool operator==(Point &second_point) const;

    bool operator>(Point &second_point) const;

    bool operator>=(Point &second_point) const;

    bool operator<(Point &second_point) const;

    bool operator<=(Point &second_point) const;

    friend ostream &operator<<(ostream &stream, Point &obj);

    friend istream &operator>>(istream &stream, Point &obj);
};