#include "Point.h"

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

