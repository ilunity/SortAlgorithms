#include <iostream>
#include <time.h>
#include "PointClass/Point.h"
#include "SortClass/Sort.h"
#include "GenerateArray/GenerateArray.h"
using namespace std;


void init() {
    srand(time(0));
    system("chcp 65001");
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

//int main() {
//    init();
//    Point *point_array;
//
//    int array_count;
//    cout << "Введите количество объектов Point:";
//    cin >> array_count;
//
//    point_array = Point::get_pointers_array(array_count);
//
//    for (int i = 0; i < array_count; i++) {
//        cout << point_array[i];
//    }
//}

int main() {
    init();

    int array_length = 13;
    int *Array = generate_random_array(array_length, DESCENDING_ORDER);
    print_array(Array, array_length);

    int *sorted_indexes_array = Sort<int>::shell_sort(Array, array_length);
    print_array_by_indexes(Array, sorted_indexes_array, array_length);
    cout << Sort<int>::check_is_undirected_array_sorted(Array, sorted_indexes_array, array_length);
}
