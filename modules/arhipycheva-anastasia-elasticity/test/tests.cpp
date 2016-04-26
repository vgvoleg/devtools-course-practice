// Copyright 2016 Arhipycheva Anastasia

#include "gtest/gtest.h"
#include "TElasticity.h"


TEST(TElasticity, ElasticityByPricePointDo_When_Null_1_var) {
  // Arrange
  int Q1 = 10, Q0 = 0;
  float P1 = 10, P0 = 5;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(E.CODE_ERROR, E.ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePointDo_When_Null_2_var) {
  // Arrange
  int Q1 = 10, Q0 = 5, P1 = 10, P0 = 10;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(E.CODE_ERROR, E.ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePointDo_When_Null_3_var) {
  // Arrange
  int Q1 = 10, Q0 = 0, P1 = 10, P0 = 10;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(E.CODE_ERROR, E.ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_When_Null_1_var) {
  // Arrange
  int Q1 = 0, Q0 = 0, P1 = 10, P0 = 5;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(E.CODE_ERROR, E.ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_When_Null_2_var) {
  // Arrange
  int Q1 = 10, Q0 = 5, P1 = 10, P0 = 10;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(E.CODE_ERROR, E.ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_When_Null_3_var) {
  // Arrange
  int Q1 = 0, Q0 = 0, P1 = 10, P0 = 10;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(E.CODE_ERROR, E.ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByIncomeDo_When_Null_1_var) {
  // Arrange
  int Q1 = 10, Q0 = 0, I1 = 10, I0 = 5;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(E.CODE_ERROR, E.ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_When_Null_2_var) {
  // Arrange
  int Q1 = 10, Q0 = 5, I1 = 10, I0 = 10;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(E.CODE_ERROR, E.ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_When_Null_3_var) {
  // Arrange
  int Q1 = 10, Q0 = 0, I1 = 10, I0 = 10;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(E.CODE_ERROR, E.ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityCrossDo_When_Null_1_var) {
  // Arrange
  int QA1 = 10, QA0 = 0, PB1 = 10, PB0 = 5;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(E.CODE_ERROR, E.ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCrossDo_When_Null_2_var) {
  // Arrange
  int  QA1 = 10, QA0 = 5, PB1 = 10, PB0 = 0;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(E.CODE_ERROR, E.ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCrossDo_When_Null_3_var) {
  // Arrange
  int  QA1 = 10, QA0 = 0, PB1 = 10, PB0 = 0;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(E.CODE_ERROR, E.ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityByPricePointDo_Not_Null_1_var) {
  // Arrange
  int Q1 = 10, Q0 = 15;
  float P1 = 10, P0 = 5, rezult;
  TElasticity E;

  // Act & Assert
  rezult = -1 / 3;
  EXPECT_EQ(rezult, E.ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePointDo_Not_Null_2_var) {
  // Arrange
  int Q1 = 3000, Q0 = 2500;
  float P1 = 100, P0 = 100;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(E.CODE_ERROR, E.ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePointDo_Not_Null_3_var) {
  // Arrange
  int Q1 = 3000, Q0 = 2500;
  float P1 = 90, P0 = 100;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(-2, E.ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePointDo_Not_Null_4_var) {
  // Arrange
  int Q1 = 100, Q0 = 100;
  float P1 = 90, P0 = 100;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(0, E.ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePointDo_Not_Null_5_var) {
  // Arrange
  int Q1 = 0, Q0 = 10;
  float P1 = 2, P0 = 1;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(-1, E.ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_Not_Null_1_var) {
  // Arrange
  int Q1 = 10, Q0 = 15;
  float P1 = 10, P0 = 5, rezult;
  TElasticity E;

  // Act & Assert
  rezult = -1 / 3;
  EXPECT_EQ(rezult, E.ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_Not_Null_2_var) {
  // Arrange
  int Q1 = 3000, Q0 = 2500;
  float P1 = 100, P0 = 100;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(E.CODE_ERROR, E.ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_Not_Null_3_var) {
  // Arrange
  int Q1 = 3000, Q0 = 2500;
  float P1 = 90, P0 = 100, rezult;
  TElasticity E;

  // Act & Assert
  rezult = -19 / 11;
  EXPECT_EQ(rezult, E.ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_Not_Null_4_var) {
  // Arrange
  int Q1 = 100, Q0 = 100;
  float P1 = 90, P0 = 100;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(0, E.ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_Not_Null_5_var) {
  // Arrange
  int Q1 = 20, Q0 = 10;
  float P1 = 20, P0 = 10;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1, E.ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_Not_Null_6_var) {
  // Arrange
  int Q1 = 20, Q0 = 10;
  float P1 = 30, P0 = 20, rezult;
  TElasticity E;

  // Act & Assert
  rezult = 5 / 3;
  EXPECT_EQ(rezult, E.ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByIncomeDo_Not_Null_1_var) {
  // Arrange
  int Q1 = 10, Q0 = 15;
  float I1 = 10, I0 = 5, rezult;
  TElasticity E;

  // Act & Assert
  rezult = -1 / 2;
  EXPECT_EQ(rezult, E.ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_Not_Null_2_var) {
  // Arrange
  int Q1 = 3000, Q0 = 2500;
  float I1 = 100, I0 = 100;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(E.CODE_ERROR, E.ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_Not_Null_3_var) {
  // Arrange
  int Q1 = 3000, Q0 = 2500;
  float I1 = 90, I0 = 100, rezult;
  TElasticity E;

  // Act & Assert
  rezult = -2;
  EXPECT_EQ(rezult, E.ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_Not_Null_4_var) {
  // Arrange
  int Q1 = 10, Q0 = 10;
  float I1 = 90, I0 = 100;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(0, E.ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_Not_Null_5_var) {
  // Arrange
  int Q1 = 15, Q0 = 10;
  float I1 = 10, I0 = 5, rezult;
  TElasticity E;

  // Act & Assert
  rezult = 1 / 2;
  EXPECT_EQ(rezult, E.ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_Not_Null_6_var) {
  // Arrange
  int Q1 = 3000, Q0 = 2500;
  float I1 = 100, I0 = 90, rezult;
  TElasticity E;

  // Act & Assert
  rezult = 9 / 5;
  EXPECT_EQ(rezult, E.ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityCrossDo_Not_Null_1_var) {
  // Arrange
  int QA1 = 10, QA0 = 15;
  float PB1 = 10, PB0 = 5, rezult;
  TElasticity E;

  // Act & Assert
  rezult = -1 / 3;
  EXPECT_EQ(rezult, E.ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCrossDo_Not_Null_2_var) {
  // Arrange
  int QA1 = 3000, QA0 = 2500;
  float PB1 = 100, PB0 = 100;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(0, E.ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCrossDo_Not_Null_3_var) {
  // Arrange
  int QA1 = 3000, QA0 = 2500;
  float PB1 = 90, PB0 = 100, rezult;
  TElasticity E;

  // Act & Assert
  rezult = -1 / 50;
  EXPECT_EQ(rezult, E.ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityByPricePointDo_With_float_P) {
  // Arrange
  int Q1 = 10, Q0 = 15;
  float P1 = 10.5, P0 = 5.25, rezult;
  TElasticity E;

  // Act & Assert
  rezult = -1 / 2;
  EXPECT_EQ(rezult, E.ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_With_float_P) {
  // Arrange
  int Q1 = 10, Q0 = 15;
  float P1 = 10.5, P0 = 5.25, rezult;
  TElasticity E;

  // Act & Assert
  rezult = -3 / 5;
  EXPECT_EQ(rezult, E.ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByIncomeDo_With_float_P) {
  // Arrange
  int Q1 = 10, Q0 = 15;
  float I1 = 10.25, I0 = 20.50, rezult;
  TElasticity E;

  // Act & Assert
  rezult = 2 / 3;
  EXPECT_EQ(rezult, E.ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityCrossDo_With_float_P) {
  // Arrange
  int QA1 = 3000, QA0 = 2500;
  float PB1 = 100.5, PB0 = 75.25, rezult;
  TElasticity E;

  // Act & Assert
  rezult = 101 / 1505;
  EXPECT_EQ(rezult, E.ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

