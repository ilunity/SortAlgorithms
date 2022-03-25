#pragma once

#include <iostream>

using namespace std;

const string ASCENDING_ORDER = "ascending";
const string DESCENDING_ORDER = "descending";
const string NONE_ORDER = "none";
const int INTERVAL_LENGTH = 100;

int **generate_random_array(int array_length, const string &ordering_type = NONE_ORDER);