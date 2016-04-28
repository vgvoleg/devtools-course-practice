#include <gtest/gtest.h>
#include "PathFinder.h"

/*TEST(PathFinder, ) {
    // Arrange

    // Act

    // Assert
}*/

TEST(PathFinder, CanGetDistance) {
    // Arrange
    int** gr;
    // Act
    gr = new int*;
    *gr = new int(0);
    // Assert
    PathFinder p(gr, 1, 0);
    ASSERT_EQ(p.GetDistance(0), 0);
}

TEST(PathFinder, CanGetShortestPath) {
    // Arrange
    int** gr = new int*[3];
    // Act
    for (int i = 0; i < 3; i++)
        gr[i] = new int[3]{ 0, 0, 0 };
    gr[0][1] = 3;
    gr[1][2] = 5;
    gr[0][2] = 6;
    // Assert
    PathFinder p(gr, 3, 0);
    ASSERT_EQ(p.GetDistance(2), 6);
}