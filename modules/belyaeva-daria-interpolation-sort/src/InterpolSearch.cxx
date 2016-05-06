// Copyright 2016 Belyaeva Daria

#include "include/InterpolationSearch.h"

#include <stdlib.h>
#include <algorithm>
#include <string>
#include <iostream>

using std::swap;

InterpolSearch::InterpolSearch(int _size) {
    if (_size < 0)
        throw std::string("Not permissible dimension");
    Size = _size;
    Arr = new int[Size];
    for (int i = 0; i < Size; i++)
        Arr[i] = 0;
}

InterpolSearch::InterpolSearch(const int intArr[], int _size) {
    if (_size < 0)
        throw std::string("Not permissible dimension");
    Arr = new int[_size];
    Size = _size;
    for (int i = 0; i < Size; i++)
         Arr[i] = intArr[i];
}

InterpolSearch::~InterpolSearch() {
    delete[] Arr;
}

int InterpolSearch::operator[](int _number) const {
    if (_number < 0)
        throw std::string("Not permissible number");
    else if (_number > Size)
        throw std::string("Not permissible number");
    else
        return Arr[_number];
}

bool InterpolSearch::operator==(const InterpolSearch & myIS) const {
    bool result = true;
    if (myIS.Size != Size) {
        result = false;
    } else {
        for (int i = 0; i < Size; i++) {
            if (myIS.Arr[i] != Arr[i]) {
                result = false;
            }
        }
    }
    return result;
}

int InterpolSearch::GetSize() {
    return (Size);
}

void InterpolSearch::QuickSort(int _left, int _right) {
    if ((_left < 0) || (_left > Size))
        throw std::string("Not permissible left number");
    else if ((_right < 0) || (_right > Size))
        throw std::string("Not permissible right number");
    int _mid = Arr[_left + (_right - _left) / 2];
    int tempLeft = _left;
    int tempRight = _right;
    while (tempLeft <= tempRight) {
        while (Arr[tempLeft] < _mid)
            tempLeft++;
        while (Arr[tempRight] > _mid)
            tempRight--;
        if (tempLeft <= tempRight) {
            swap(Arr[tempLeft], Arr[tempRight]);
            tempLeft++;
            tempRight--;
        }
    }
    if (tempLeft < _right)
        QuickSort(tempLeft, _right);
    if (_left < tempRight)
        QuickSort(_left, tempRight);
}


int InterpolSearch::InterpolationSearch(int key) {
    if (Size == 1)
        return (Arr[0] == key ? 0 : -1);
    for (int i = 0; i < Size - 1; i++)
        if (Arr[i] > Arr[i + 1])
            throw std::string("Unsorted array");
    int mid;
    int left = 0;
    int right = Size - 1;
    while (Arr[left] <= key && Arr[right] >= key) {
        if (Arr[left] == Arr[right])
            return (Arr[left] == key ? left : -1);
        mid = left + ((key - Arr[left]) * (right - left))
                / (Arr[right] - Arr[left]);
        if (Arr[mid] < key)
            left = mid + 1;
        else if (Arr[mid] > key)
            right = mid - 1;
        else
            return mid;
    }
    if (Arr[left] == key)
        return left;
    else
        return -1;
}
