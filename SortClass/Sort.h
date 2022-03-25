#include <iostream>

#pragma once
using namespace std;


template<class array_template>
class Sort {
    static void sift(array_template **array, int init_index, int final_index) {
        int father_index = init_index, son_index = init_index * 2 + 1;

        int large_son_index;
        while (son_index <= final_index) {
            large_son_index =
                    (son_index != final_index) && (*array[son_index + 1] > *array[son_index])
                    ? son_index + 1
                    : son_index;


            if (*array[father_index] >= *array[large_son_index]) break;

            swap(array[father_index], array[large_son_index]);
            father_index = large_son_index;
            son_index = father_index * 2 + 1;
        }
    }

public:
    static void pyramid_sort(array_template **array, int array_length) {
        for (int init_index = array_length / 2; init_index >= 0; init_index--)
            sift(array, init_index, array_length - 1);

        for (int last_pyramid_elem = array_length - 1; last_pyramid_elem >= 1; last_pyramid_elem--) {
            swap(array[0], array[last_pyramid_elem]);
            sift(array, 0, last_pyramid_elem - 1);
        }
    }

    static void shell_sort(array_template **array, int array_length) {
        int i, j, chain;
        for (chain = 1; chain <= array_length / 9; chain = chain * 3 + 1);
        while (chain >= 1) {
            for (i = 0; i < array_length - chain; i++) {
                for (j = i; j >= 0 && *array[j] > *array[j + chain]; j -= chain) {
                    swap(array[j], array[j + chain]);
                }
            }
            chain = (chain - 1) / 3;
        }
    }

    static bool check_if_array_sorted(array_template **array, int array_length) {
        for (int i = 0; i < array_length - 1; i++) {
            if (*array[i] > *array[i + 1]) return false;
        }

        return true;
    }
};