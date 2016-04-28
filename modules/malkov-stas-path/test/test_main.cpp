// Copyright 2016 Malkov Stanislav

#include <iostream>
#include <gtest/gtest.h>

#include "PathFinder.h"

using namespace std;
//главная функция
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Rus");
    int start;
    int** gr = new int*[6];
    for (int i = 0; i < 6; i++)
        gr[i] = new int[6]{ 0, 0, 0, 0, 0, 0 };
    gr[1][2] = 3;
    gr[2][3] = 5;
    gr[1][3] = 9;
    PathFinder finder(gr, 6, 1);
    cout << finder.GetDistance(3); 
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    getchar();
    return 0;
}