#include "Point.h"

Point::Point() {
    x_coord = rand() % 1000 + 1;
    y_coord = rand() % 1000 + 1;
}

Point** Point::generate_pointers_array(int array_count) {
    Point **point_array;
    point_array = new Point* [array_count];

    Point *p;
    for (int i = 0; i < array_count; i++) {
        p = new Point;
        point_array[i] = p;
    }

    return point_array;
}

bool Point::operator==(Point &second_point) const {
    return (x_coord == second_point.x_coord && y_coord == second_point.y_coord);
}

bool Point::operator>(Point &second_point) const {
    return ((x_coord > second_point.x_coord)
            || (x_coord == second_point.x_coord && y_coord > second_point.y_coord));
}

bool Point::operator<(Point &second_point) const {
    return ((x_coord < second_point.x_coord)
            || (x_coord == second_point.x_coord && y_coord < second_point.y_coord));
}

bool Point::operator>=(Point &second_point) const {
    return (*this > second_point || *this == second_point);
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