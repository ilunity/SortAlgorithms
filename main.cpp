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

    friend ostream &operator<<(ostream &stream, Point &obj);

    friend istream &operator>>(istream &stream, Point &obj);
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

Point **get_pointer_array_to_Point(int array_count) {
    Point **point_array;
    point_array = new Point *[array_count];

    Point *p;
    for (int i = 0; i < array_count; i++) {
        p = new Point;
        point_array[i] = p;
    }

    return point_array;
}


template<class array_template>
class Sort {

    static void sift(array_template *sorting_array, int init_index, int final_index) {
        int current_index = init_index, k = init_index * 2 + 1;
        while (k <= final_index) {
            if (k < final_index && sorting_array[k] < sorting_array[k + 1]) k++;
            if (sorting_array[current_index] < sorting_array[k]) {
                swap(sorting_array[current_index], sorting_array[k]);
                current_index = k;
                k = k * 2 + 1;
            } else break;
        }
    }

    static int* get_indexes_array(int length) {
//        int *indexes_array;
        int *indexes_array = new int[length];
        for (int i = 0; i < length; i++) indexes_array[i] = i;
    }
public:
    static void pyramid_sort(array_template *sorting_array, int array_length) {
//        int* indexes_array = get_indexes_array(array_length);
        int i, m;
        // построение пирамиды
        for (i = array_length / 2; i >= 0; i--)
            sift(sorting_array, i, array_length - 1);
        // сортировка массива
        for (m = array_length - 1; m >= 1; m--) {
            swap(sorting_array[0], sorting_array[m]);
            sift(sorting_array, 0, m - 1);
        }

    }
};

void init() {
    system("chcp 65001");
    srand(time(0));
}

//int main() {
//    Point **point_array;
//
//    int array_count;
//    cout << "Введите количество объектов Point: ";
//    cin >> array_count;
//
//    point_array = get_pointer_array_to_Point(array_count);
//
//    for (int i = 0; i < array_count; i++) {
//        cout << *point_array[i];
//    }
//}

int main() {
    init();
    int Array[] = { 19, 10, 8, 17, 9 };
    Sort<int>::pyramid_sort(Array, 5);
}
