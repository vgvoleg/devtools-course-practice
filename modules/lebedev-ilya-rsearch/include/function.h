// Copyright 2016 Lebedev Ilya

#ifndef MODULES_LEBEDEV_ILYA_RSEARCH_INCLUDE_FUNCTION_H_
#define MODULES_LEBEDEV_ILYA_RSEARCH_INCLUDE_FUNCTION_H_

#include <math.h>
#define PI 3.14159265359f

double RastriginFunction(int dimention, double* x) {
  int j;
  double sum = 0.;

  for (j = 0; j < dimention; j++)
  {
    sum += x[j] * x[j] - 10.f * cos(2.f * PI * x[j]) + 10.f;
  }

  return sum;
};


#endif  // MODULES_LEBEDEV_ILYA_RSEARCH_INCLUDE_FUNCTION_H_
