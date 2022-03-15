#include <iostream>
#include <time.h>
#include "PointClass/Point.h"
#include "SortClass/Sort.h"
using namespace std;

const string ASCENDING_ORDER = "ascending";
const string DESCENDING_ORDER = "descending";
const string NONE_ORDER = "none";
const int RANDOM_SPREAD = 100;

void init() {
    srand(time(0));
    system("chcp 65001");
}


Point **get_pointers_array_to_Point(int array_count) {
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
void print_array_by_indexes(array_template *Array, const int *indexes_array, int length) {
    for (int i = 0; i < length; i++) {
        cout << Array[indexes_array[i]] << ' ';
    }
    cout << endl;
}

template<class array_template>
void print_array(array_template *Array, int length) {
    for (int i = 0; i < length; ++i) {
        cout << Array[i] << ' ';
    }
    cout << endl;
}

int *generate_random_array(int array_length, const string& ordering_type = NONE_ORDER) {
    int *generated_array = new int[array_length];

    const int interval_left_min = 0;
    const int interval_left_max = RANDOM_SPREAD * (array_length - 1);
    int random_interval = RANDOM_SPREAD;
    int current_interval_left = 0;

    int step;
    if (ordering_type == NONE_ORDER) {
        step = 0;
        random_interval *= array_length;
    } else if (ordering_type == ASCENDING_ORDER) {
        step = RANDOM_SPREAD;
    } else if (ordering_type == DESCENDING_ORDER) {
        current_interval_left = interval_left_max;
        step = (-1) * RANDOM_SPREAD;
    }

    int index = 0;
    while (current_interval_left >= interval_left_min && current_interval_left <= interval_left_max) {
        generated_array[index] = current_interval_left + rand() % random_interval;
        current_interval_left += step; index += 1;
    }

    return generated_array;
}






//int main() {
//    init();
//    Point **point_array;
//
//    int array_count;
//    cout << "Введите количество объектов Point: ";
//    cin >> array_count;
//
//    point_array = get_pointers_array_to_Point(array_count);
//
//    for (int i = 0; i < array_count; i++) {
//        cout << *point_array[i];
//    }
//}

int main() {
    init();

    int array_length = 5;
    int *Array = generate_random_array(array_length, DESCENDING_ORDER);
    print_array(Array, array_length);

    int *sorted_indexes_array = Sort<int>::pyramid_sort(Array, array_length);
    print_array_by_indexes(Array, sorted_indexes_array, array_length);
    cout << Sort<int>::check_undirected_array_ordering(Array, sorted_indexes_array, array_length);
}
