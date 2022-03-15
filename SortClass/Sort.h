#include <iostream>
#pragma once
using namespace std;

int *get_indexes_array(int length) {
    int *indexes_array = new int[length];
    for (int i = 0; i < length; i++) indexes_array[i] = i;
    return indexes_array;
}


template<class array_template>
class Sort {
    static void sift(array_template *array, int *indexes_array, int init_index, int final_index) {
        int current_index = init_index, son_index = init_index * 2 + 1;

        int large_son_index;
        while (son_index <= final_index) {
            large_son_index =
                    (son_index != final_index) && (array[indexes_array[son_index + 1]] > array[indexes_array[son_index]])
                    ? son_index + 1 : son_index;


            if (array[indexes_array[current_index]] >= array[indexes_array[large_son_index]]) break;

            swap(indexes_array[current_index], indexes_array[large_son_index]);
            current_index = large_son_index;
            son_index = large_son_index * 2 + 1;
        }
    }

public:
    static int *pyramid_sort(array_template *array, int array_length) {
        int *indexes_array = get_indexes_array(array_length);

        for (int init_index = array_length / 2; init_index >= 0; init_index--)
            sift(array, indexes_array, init_index, array_length - 1);

        for (int last_pyramid_elem = array_length - 1; last_pyramid_elem >= 1; last_pyramid_elem--) {
            swap(indexes_array[0], indexes_array[last_pyramid_elem]);
            sift(array, indexes_array, 0, last_pyramid_elem - 1);
        }

        return indexes_array;
    }
    static bool check_undirected_array_ordering(array_template *array, const int *indexes_array, int array_length) {
        for (int i = 0; i < array_length - 1; i++) {
            if (array[indexes_array[i]] > array[indexes_array[i + 1]]) return false;
        }

        return true;
    }
};