// Copyright 2016 Rumyantsev Alexander

#include <gtest/gtest.h>

#include "include/vector3d.h"

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Create_Default_Vector) {
  // Act
  Vector3D v;

  // Assert
  EXPECT_DOUBLE_EQ(0.0, v.getX());
  EXPECT_DOUBLE_EQ(0.0, v.getY());
  EXPECT_DOUBLE_EQ(0.0, v.getZ());
}

TEST(Rumyantsev_Alexander_Vector3DTest, Can_Create_With_XYZ) {
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
