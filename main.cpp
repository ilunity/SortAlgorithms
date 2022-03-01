#include <iostream>
#include <ctime>

using namespace std;

class Point {
    int x_coord, y_coord;

public:
    Point();

    bool operator==(Point &second_point) const;
    bool operator>(Point &second_point) const;
    bool operator>=(Point &second_point) const;
    bool operator<(Point &second_point) const;
    bool operator<=(Point &second_point) const;

    friend ostream& operator<<(ostream &stream, Point &obj);
    friend istream& operator>>(istream &stream, Point &obj);
};

Point::Point() {
    x_coord = rand() % 1000 + 1;
    y_coord = rand() % 1000 + 1;
}

bool Point::operator==(Point &second_point) const {
    return (x_coord == second_point.x_coord && y_coord == second_point.y_coord);
}

bool Point::operator>(Point &second_point) const {
    return ((x_coord > second_point.x_coord)
            || (x_coord == second_point.x_coord && y_coord > second_point.y_coord));
}

bool Point::operator>=(Point &second_point) const {
    return (*this > second_point || *this == second_point);
}

bool Point::operator<(Point &second_point) const {
    return ((x_coord < second_point.x_coord)
            || (x_coord == second_point.x_coord && y_coord < second_point.y_coord));
}

bool Point::operator<=(Point &second_point) const {
    return (*this < second_point || *this == second_point);
}

ostream &operator<<(ostream &stream, Point &obj) {
    stream << '(' << obj.x_coord << ',' << obj.y_coord << ')';
    return stream;
}

istream &operator>>(istream &stream, Point &obj) {
    stream >> obj.x_coord >> obj.y_coord;
    return stream;
}

Point ** get_pointer_array_to_Point(int array_count) {
    Point** point_array;
    point_array = new Point*[array_count];

    Point *p;
    for (int i = 0; i < array_count; i++) {
        p = new Point;
        point_array[i] = p;
    }

    return point_array;
}


int main() {
    system("chcp 65001");
    srand(time(0));

    Point** point_array;

    int array_count;
    cout << "Введите количество объектов Point: ";
    cin >> array_count;

    point_array = get_pointer_array_to_Point(array_count);

    for (int i = 0; i < array_count; i++) {
        cout << *point_array[i];
    }
}
