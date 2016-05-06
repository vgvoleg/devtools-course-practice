// Copyright 2016 Belyaeva Daria

#ifndef MODULES_BELYAEVA_DARIA_INTERPOLATION_SEARCH_H_
#define MODULES_BELYAEVA_DARIA_INTERPOLATION_SEARCH_H_

class InterpolSearch {
 public:
    InterpolSearch(int _size);
    ~InterpolSearch();
    InterpolSearch(const int intArr[], int _size);

    int operator[] (int _number) const;
    bool operator==(const InterpolSearch & q) const;
    int GetSize();

    void QuickSort(int _left, int _right);

    int InterpolationSearch(int key);
 private:
     int* Arr;
     int Size;
};

#endif  // MODULES_BELYAEVA_DARIA_INTERPOLATION_SEARCH_H_
