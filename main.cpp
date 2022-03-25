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
void print_array(array_template **Array, int length) {
    for (int i = 0; i < length; ++i) {
        cout << *Array[i] << ' ';
    }
    cout << endl;
}


void show_point_sort(int array_length) {
    Point **point_array = Point::generate_pointers_array(array_length);

    cout << "Сгенерированный массив точек:" << endl;
    print_array(point_array, array_length);

    cout << "Сортировка:" << endl;
    Sort<Point>::shell_sort(point_array, array_length);
    print_array(point_array, array_length);


    string sorting_check_result =
            Sort<Point>::check_if_array_sorted(point_array, array_length)
            ? "Массив упорядочен"
            : "Массив не упорядочен";

    cout << sorting_check_result << endl << endl;
}

void show_pyramid_sort(int array_length, const string &ordering_type) {
    int **array = generate_random_array(array_length, ordering_type);

    cout << "Сгенерированный массив:" << endl;
    print_array(array, array_length);

    cout << "Пирамидальная сортировка:" << endl;
    Sort<int>::pyramid_sort(array, array_length);
    print_array(array, array_length);


    string sorting_check_result =
            Sort<int>::check_if_array_sorted(array, array_length)
            ? "Массив упорядочен"
            : "Массив не упорядочен";

    cout << sorting_check_result << endl << endl;
}

void show_shell_sort(int array_length, const string &ordering_type) {
    int **array = generate_random_array(array_length, ordering_type);

    cout << "Сгенерированный массив:" << endl;
    print_array(array, array_length);

    cout << "Сортировка Шелла:" << endl;
    Sort<int>::shell_sort(array, array_length);
    print_array(array, array_length);

    string sorting_check_result =
            Sort<int>::check_if_array_sorted(array, array_length)
            ? "Массив упорядочен"
            : "Массив не упорядочен";

    cout << sorting_check_result << endl << endl;
}


int main() {
    init();

    int array_length = 10;

    show_point_sort(array_length);
    show_pyramid_sort(array_length, DESCENDING_ORDER);
    show_shell_sort(array_length, DESCENDING_ORDER);
}