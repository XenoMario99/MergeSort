#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

namespace sort {

// Differten sizes of array pieces
// Temporary vector and after fill up assing to destinate vector?

// TODO: Template version with function pointer as input argument
// in case of lack this argument use default or if it is not possible throw exception

template <typename T>
void merge(typename std::vector<T>::iterator first1,
           typename std::vector<T>::iterator last1,
           typename std::vector<T>::iterator first2,
           typename std::vector<T>::iterator last2,
           bool (*pf)(T, T) = nullptr) {
    typename std::vector<T> tempVec;
    typename std::vector<T>::iterator beg = first1;

    while (first1 != last1 && first2 != last2) {
        if (pf == nullptr) {
            if ((*first1 < *first2)) {
                tempVec.push_back(*first1);
                first1++;
            } else {
                tempVec.push_back(*first2);
                first2++;
            }
        } else {
            if ((*pf)(*first1, *first2)) {
                tempVec.push_back(*first1);
                first1++;
            } else {
                tempVec.push_back(*first2);
                first2++;
            }
        }
    }

    if (first1 != last1) {
        for (first1; first1 != last1; first1++) {
            tempVec.push_back(*first1);
        }
    } else if (first2 != last2) {
        for (first2; first2 != last2; first2++) {
            tempVec.push_back(*first2);
        }
    }

    auto ptr = tempVec.begin();

    for (ptr; ptr != tempVec.end(); ptr++) {
        *beg = *ptr;
        beg++;
    }
}

template <typename T>
void mergeSort(typename std::vector<T>::iterator first,
               typename std::vector<T>::iterator last,
               bool (*pf)(T, T) = nullptr) {
    if (first != last) {
        int size = std::distance(first, last);
        if (size > 1) {
            int mid = size / 2;

            mergeSort(first, first + mid, pf);
            mergeSort(first + mid, last, pf);
            merge(first, first + mid, first + mid, last, pf);
        }
    } else {
        std::cout << "Out of range" << std::endl;
    }
}

}  // namespace sort
