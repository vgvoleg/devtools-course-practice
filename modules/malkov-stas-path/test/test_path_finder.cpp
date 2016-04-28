#include <gtest/gtest.h>
#include "PathFinder.h"

TEST(PathFinder, CanGetDistance) {
    // Arrange
    int** gr;
    gr = new int*;
    *gr = new int(0);
    // Act
    // Assert
    PathFinder p(gr, 1, 0);
    ASSERT_EQ(p.GetDistance(0), 0);
}

TEST(PathFinder, CanGetAllDistances) {
    // Arrange
    int** gr = new int*[2];
    // Act
    for (int i = 0; i < 2; i++)     // 1 2  1->2:2
        gr[i] = new int[2]{ 1, 2 }; // 1 2  1->1:0
    PathFinder p(gr, 2, 0);
    int* d = p.GetDistances();
    // Assert
    EXPECT_EQ(d[0], 0);
    EXPECT_EQ(d[1], 2);
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
    EXPECT_EQ(p.GetDistance(2), 6);
}

TEST(PathFinder, CanCheckWhenPathNotExists) {
    // Arrange
    int** gr = new int*[2];
    for (int i = 0; i < 2; i++)
        gr[i] = new int[2]{ 0, 0 };
    PathFinder p(gr, 2, 0);
    // Act
    // Assert
    EXPECT_EQ(p.GetDistance(1), PATH_NOT_EXISTS);
}

TEST(PathFinder, CanInitializeAfterInstantiate) {
    // Arrange
    PathFinder p;
    int** gr= new int*;
    *gr = new int(0);
    // Act
    p.SetGraph(gr, 1, 0);
    // Assert
    EXPECT_EQ(p.GetDistance(0), 0);
}

TEST(PathFinder, CanReInitialize) {
    // Arrange
    PathFinder p;
    int** gr1 = new int*;
    *gr1 = new int(0);
    int** gr2 = new int*[2];
    for (int i = 0; i < 2; i++)
        gr2[i] = new int[2]{ 1, 2 };
    // Act
    p.SetGraph(gr1, 1, 0);
    p.SetGraph(gr2, 2, 0);
    // Assert
    EXPECT_EQ(p.GetDistance(1), 2);
}

TEST(PathFinder, CanSetStartIndex) {
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
    EXPECT_EQ(p.GetDistance(2), 6);
    p.SetStartVertex(1);
    EXPECT_EQ(p.GetDistance(2), 5);
}

TEST(PathFinder, ThrowsExceptionWhenNotInitialized) {
    // Arrange
    PathFinder p;
    // Act
    // Assert
    EXPECT_ANY_THROW(p.GetDistance(0));
}

TEST(PathFinder, ThrowsExceptionWithNullGraph) {
    // Arrange
    PathFinder p;
    int** gr = new int*;
    *gr = new int(0);
    // Act
    // Assert
    EXPECT_ANY_THROW(p.SetGraph(gr, 1, 5));
}

TEST(PathFinder, ThrowsExceptionWithNegativeSize) {
    // Arrange
    PathFinder p;
    int** gr = new int*;
    *gr = new int(0);
    // Act
    // Assert
    EXPECT_ANY_THROW(p.SetGraph(gr, -1, 0));
}

TEST(PathFinder, ThrowsExceptionWithNegativeStartIndex) {
    // Arrange
    PathFinder p;
    int** gr = new int*;
    *gr = new int(0);
    // Act
    // Assert
    EXPECT_ANY_THROW(p.SetGraph(gr, 1, -1));
}

TEST(PathFinder, ThrowsExceptionWithStartIndexOutOfRange) {
    // Arrange
    PathFinder p;
    int** gr = new int*;
    *gr = new int(0);
    // Act
    // Assert
    EXPECT_ANY_THROW(p.SetGraph(gr, 1, 5));
}

TEST(PathFinder, ThrowExceptionWithSettingNewStartIndexNegative) {
    // Arrange
    PathFinder p;
    int** gr = new int*;
    *gr = new int(0);
    // Act
    // Assert
    EXPECT_ANY_THROW(p.SetStartVertex(-1));
}

TEST(PathFinder, ThrowExceptionWithSettingNewStartIndexOutOfRange) {
    // Arrange
    PathFinder p;
    int** gr = new int*;
    *gr = new int(0);
    // Act
    // Assert
    EXPECT_ANY_THROW(p.SetStartVertex(5));
}

TEST(PathFinder, ThrowsExceptionWithDistanceIndexOutOfRange) {
    // Arrange
    int** gr = new int*;
    *gr = new int(0);
    PathFinder p(gr, 1, 0);
    // Act
    // Assert
    EXPECT_ANY_THROW(p.GetDistance(2));
}