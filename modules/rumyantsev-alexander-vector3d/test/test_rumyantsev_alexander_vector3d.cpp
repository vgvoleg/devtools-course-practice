// Copyright 2016 Rumyantsev Alexander

#include <gtest/gtest.h>

#include "include/vector3d.h"

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Create_Default_Vector) {
  // Arrange & Act
  Vector3D v;

  // Assert
  EXPECT_DOUBLE_EQ(0.0, v.getX());
  EXPECT_DOUBLE_EQ(0.0, v.getY());
  EXPECT_DOUBLE_EQ(0.0, v.getZ());
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Create_With_XYZ_Double) {
  // Arrange
  double x = -10.0;
  double y = 26.0;
  double z = 0.333;

  // Act
  Vector3D v(x, y, z);

  // Assert
  EXPECT_DOUBLE_EQ(x, v.getX());
  EXPECT_DOUBLE_EQ(y, v.getY());
  EXPECT_DOUBLE_EQ(z, v.getZ());
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Create_With_XYZ_Not_Double) {
  // Arrange
  int x = -10;
  char y = 26;
  float z = 0.333;

  // Act
  Vector3D v(x, y, z);

  // Assert
  EXPECT_DOUBLE_EQ(x, v.getX());
  EXPECT_DOUBLE_EQ(y, v.getY());
  EXPECT_DOUBLE_EQ(z, v.getZ());
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Set_X) {
  // Arrange
  Vector3D v;
  double x = 21.0;

  // Act
  v.setX(x);

  // Assert
  ASSERT_DOUBLE_EQ(x, v.getX());
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Set_Y) {
  // Arrange
  Vector3D v;
  double y = -13.2;

  // Act
  v.setY(y);

  // Assert
  ASSERT_DOUBLE_EQ(y, v.getY());
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Set_Z) {
  // Arrange
  Vector3D v;
  double z = 0.256;

  // Act
  v.setZ(z);

  // Assert
  ASSERT_DOUBLE_EQ(z, v.getZ());
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Determine_If_Vectors_Are_Equal) {
  // Arrange
  Vector3D v1(26.0, -14.0, 0.24);
  Vector3D v2(26.0, -14.0, 0.24);

  // Act & Assert
  ASSERT_TRUE(v1 == v2);
}

TEST(Rumyantsev_Alexander_Vector3DTest,
     Equality_Check_Fails_With_Different_Vectors) {
  // Arrange
  Vector3D v1(123.4, -4.4, 0.0001);
  Vector3D v2(123.4, -4.3, 0.0001);

  // Act & Assert
  ASSERT_FALSE(v1 == v2);
}

TEST(Rumyantsev_Alexander_Vector3DTest,
     Can_Determine_If_Vectors_Are_Not_Equal) {
  // Arrange
  Vector3D v1(26.0, -14.0, 0.24);
  Vector3D v2(25.2, -14.0, 0.24);

  // Act & Assert
  ASSERT_TRUE(v1 != v2);
}

TEST(Rumyantsev_Alexander_Vector3DTest,
     Inequality_Check_Fails_With_Equal_Vectors) {
  // Arrange
  Vector3D v1(-5.0, 0.0, 100.4);
  Vector3D v2(-5.0, 0.0, 100.4);

  // Act & Assert
  ASSERT_FALSE(v1 != v2);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Create_With_Copying) {
  // Arrange
  Vector3D v(11.1, -0.3, 3.4);

  // Act
  Vector3D expected_v(v);

  // Assert
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Vector_Is_Equal_To_Itself) {
  // Arrange
  Vector3D v(9, 5, 1945);

  // Act & Assert
  ASSERT_EQ(v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Assign_To_Vector) {
  // Arrange
  Vector3D v(-3.1415, 2.71828, 1.61803);

  // Act
  Vector3D expected_v = v;

  // Assert
  ASSERT_EQ(expected_v, v);
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Assign_Vector_To_Itself) {
  // Arrange
  double x = -2.4;
  double y = 8.16;
  double z = -32.64;
  Vector3D v(x, y, z);

  // Act
  v = v;

  // Assert
  EXPECT_DOUBLE_EQ(x, v.getX());
  EXPECT_DOUBLE_EQ(y, v.getY());
  EXPECT_DOUBLE_EQ(z, v.getZ());
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Do_Multiple_Assignment) {
  // Arrange
  Vector3D v1, v2, v3(0.7, -0.07, 0.007);

  // Act
  v1 = v2 = v3;

  // Assert
  EXPECT_EQ(v1, v3);
  EXPECT_EQ(v2, v3);
}
