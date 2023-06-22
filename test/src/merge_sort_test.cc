#include <gtest/gtest.h>

#include <algorithm>
#include <random>

#include "mergeSort.h"

bool intCompare(int a, int b) {
    return a > b ? true : false;
}

TEST(mergeSortTest, sortRandomFilledVectorProperlyWithDefaultCompare) {
    const int n = 50;
    std::vector<int> vec(n);

    std::random_device rnd;
    std::mt19937 engine{rnd()};
    std::uniform_int_distribution<int> distr{1, 100};

    auto gen = [&distr, &engine]() {
        return distr(engine);
    };

    std::generate(vec.begin(), vec.end(), gen);

    std::vector<int> reference(vec);

    sort::mergeSort<int>(vec.begin(), vec.end());
    std::sort(reference.begin(), reference.end());

    for (int i = 0; i < n; i++) {
        std::cout << vec[i] << " == " << reference[i] << std::endl;
        EXPECT_EQ(vec[i], reference[i]);
    }
}

TEST(mergeSortTest, sortRandomFilledVectorProperlyWithOptionalCompare) {
    const int n = 50;
    std::vector<int> vec(n);

    std::random_device rnd;
    std::mt19937 engine{rnd()};
    std::uniform_int_distribution<int> distr{1, 100};

    auto gen = [&distr, &engine]() {
        return distr(engine);
    };

    std::generate(vec.begin(), vec.end(), gen);

    std::vector<int> reference(vec);

    sort::mergeSort<int>(vec.begin(), vec.end(), intCompare);
    std::sort(reference.begin(), reference.end(), intCompare);

    for (int i = 0; i < n; i++) {
        std::cout << vec[i] << " == " << reference[i] << std::endl;
        EXPECT_EQ(vec[i], reference[i]);
    }
}