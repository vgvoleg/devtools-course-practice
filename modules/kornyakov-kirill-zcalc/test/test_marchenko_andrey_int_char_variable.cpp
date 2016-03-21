#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Marchenko_Andrey_ComplexNumberTest, Can_Create_Int_Char_Variable) {
    
    int re = 0;
    char im = 0;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}
