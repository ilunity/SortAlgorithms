#include "GenerateArray.h"


int *generate_random_array(int array_length, const string &ordering_type) {
    int *generated_array = new int[array_length];

    const int intervals_count = array_length - 1;

    int step, interval_for_random, current_interval_begin;
    if (ordering_type == NONE_ORDER) {
        current_interval_begin = 0;
        step = 0;
        interval_for_random = INTERVAL_LENGTH * array_length;
    } else if (ordering_type == ASCENDING_ORDER) {
        current_interval_begin = 0;
        step = INTERVAL_LENGTH;
        interval_for_random = INTERVAL_LENGTH;
    } else if (ordering_type == DESCENDING_ORDER) {
        const int interval_begin_max = INTERVAL_LENGTH * intervals_count;
        current_interval_begin = interval_begin_max;
        step = (-1) * INTERVAL_LENGTH;
        interval_for_random = INTERVAL_LENGTH;
    }

    for (int index = 0; index < array_length; index++, current_interval_begin += step) {
        generated_array[index] = current_interval_begin + rand() % interval_for_random;
    }

    return generated_array;
}