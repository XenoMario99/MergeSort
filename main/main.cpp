#include <algorithm>
#include <iostream>
#include <vector>

#include "mergeSort.h"

bool intCompare(int a, int b) {
    return a < b ? true : false;
}

int main() {
    std::cout << "Hello world" << std::endl;

    std::vector<int> vec{2, 5, 6, 56, 1};
    sort::mergeSort<int>(vec.begin(), vec.end(), nullptr);

    std::cout << "Sorted vec (default): ";

    for (auto x : vec) {
        std::cout << x << " ";
    }

    sort::mergeSort<int>(vec.begin(), vec.end(), intCompare);

    std::cout << std::endl
              << "Sorted vec (custom): ";

    for (auto x : vec) {
        std::cout << x << " ";
    }

    return 0;
}