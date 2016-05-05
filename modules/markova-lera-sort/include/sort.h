/* sort_h */

//  Copyright © 2016 Markova

#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

class MySort {
private:
    int* intArr_;
	int length_;

	void swap(int i);
	void merge( int first, int last);
public:
	MySort(const int intArr[], int length);
	~MySort();
	MySort(const MySort&) = delete;
    int operator[] (int i) const {return intArr_[i]; }

	bool operator== (const MySort& q) const;
    void quickSort(int l, int r);
    void selectionSort(void);
    void gnomeSort(void);
    void shakerSort(int Start, int N);
    void pasteSort(void);
	void mergeSort( int first, int last);
};
