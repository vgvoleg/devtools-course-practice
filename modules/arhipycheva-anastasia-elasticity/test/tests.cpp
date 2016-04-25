// Copyright 2016 Arhipycheva Anastasia

#include "gtest/gtest.h"
#include "TElasticity.h"


TEST(TElasticity, ElasticityByPricePointDo_When_Null_1var) {
  // Arrange
  int Q1 = 10, Q0 = 0;
  float P1 = 10, P0 = 5;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByPricePointDo(Q1,Q0,P1,P0));
}

TEST(TElasticity, ElasticityByPricePointDo_When_Null_2var) {
  // Arrange
  int Q1 = 10, Q0 = 5, P1 = 10, P0 = 10;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePointDo_When_Null_3var) {
  // Arrange
  int Q1 = 10, Q0 = 0, P1 = 10, P0 = 10;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_When_Null_1var) {
  // Arrange
  int Q1 = 0, Q0 = 0, P1 = 10, P0 = 5;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_When_Null_2var) {
  // Arrange
  int Q1 = 10, Q0 = 5, P1 = 10, P0 = 10;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_When_Null_3var) {
  // Arrange
  int Q1 = 0, Q0 = 0, P1 = 10, P0 = 10;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByIncomeDo_When_Null_1var) {
  // Arrange
  int Q1 = 10, Q0 = 0, I1 = 10, I0 = 5;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_When_Null_2var) {
  // Arrange
  int Q1 = 10, Q0 = 5, I1 = 10, I0 = 10;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_When_Null_3var) {
  // Arrange
  int Q1 = 10, Q0 = 0, I1 = 10, I0 = 10;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityCrossDo_When_Null_1var) {
  // Arrange
  int QA1 = 10, QA0 = 0, PB1 = 10, PB0 = 5;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCrossDo_When_Null_2var) {
  // Arrange
  int  QA1 = 10, QA0 = 5, PB1 = 10, PB0 = 0;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCrossDo_When_Null_3var) {
  // Arrange
  int  QA1 = 10, QA0 = 0, PB1 = 10, PB0 = 0;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityByPricePointDo_Not_Null_1ver) {
	// Arrange
  int Q1 = 10, Q0 = 15;
  float P1 = 10, P0 = 5;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePointDo_Not_Null_2ver) {
  // Arrange
  int Q1 = 3000, Q0 = 2500;
  float P1 = 100, P0 = 100;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPricePointDo_Not_Null_ver3) {
  // Arrange
  int Q1 = 3000, Q0 = 2500;
  float P1 = 90, P0 = 100;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByPricePointDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_Not_Null_ver1) {
  // Arrange
  int Q1 = 10, Q0 = 15;
  float P1 = 10, P0 = 5;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_Not_Null_ver2) {
  // Arrange
  int Q1 = 3000, Q0 = 2500;
  float P1 = 100, P0 = 100;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByPriceArcDo_Not_Null_ver3) {
  // Arrange
  int Q1 = 3000, Q0 = 2500;
  float P1 = 90, P0 = 100;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByPriceArcDo(Q1, Q0, P1, P0));
}

TEST(TElasticity, ElasticityByIncomeDo_Not_Null_ver1) {
  // Arrange
  int Q1 = 10, Q0 = 15;
  float I1 = 10, I0 = 5;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_Not_Null_ver2) {
  // Arrange
  int Q1 = 3000, Q0 = 2500;
  float I1 = 100, I0 = 100;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityByIncomeDo_Not_Null_ver3) {
  // Arrange
  int Q1 = 3000, Q0 = 2500;
  float I1 = 90, I0 = 100;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityByIncomeDo(Q1, Q0, I1, I0));
}

TEST(TElasticity, ElasticityCrossDo_Not_Null_ver1) {
  // Arrange
  int QA1 = 10, QA0 = 15;
  float PB1 = 10, PB0 = 5;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityByCrossDo_Not_Null_ver2) {
  // Arrange
  int QA1 = 3000, QA0 = 2500;
  float PB1 = 100, PB0 = 100;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityCrossDo(QA1, QA0, PB1, PB0));
}

TEST(TElasticity, ElasticityCrossDo_Not_Null_ver3) {
  // Arrange
  int QA1 = 3000, QA0 = 2500;
  float PB1 = 90, PB0 = 100;
  TElasticity E;

  // Act & Assert
  EXPECT_EQ(1000, E.ElasticityCrossDo(QA1, QA0, PB1, PB0));
}
