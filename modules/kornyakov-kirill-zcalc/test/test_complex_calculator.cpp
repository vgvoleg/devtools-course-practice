// Copyright 2014 Gladilov Gleb

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/complex_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class AppTest : public ::testing::Test {
 protected:
    virtual void SetUp() {
        args.clear();
    }

    void Act(vector<string> args_) {
        vector<const char*> starts;
        starts.push_back("appname");

        for (size_t i = 0; i < args_.size(); ++i) {
            starts.push_back(args_[i].c_str());
        }
        const char** argv = &starts.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

    ComplexCalculator app_;
    string output_;
    vector<string> args;
};

TEST_F(AppTest, Do_Print_Help_Without_Arguments) {
    Act(args);

    Assert("This is a complex number calculator application\\..*");
}

TEST_F(AppTest, Is_Checking_Number_Of_Arguments) {
    args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be 5 arguments\\..*");
}

TEST_F(AppTest, Can_Detect_Wrong_Number_Format) {
    args = {"1", "pi", "2", "4", "+"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(AppTest, Can_Detect_Wrong_Operation_Format) {
    args = {"1", "1", "1", "1", "garbage"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(AppTest, Can_Add_Complexs) {
    args = {"2.0", "3.5", "1.5", "4.0", "+"};

    Act(args);

    Assert("Real = 3.5 Imaginary = 7.5");
}

TEST_F(AppTest, Can_Diff_Complexs) {
    args = {"13", "7.6", "26", "-14", "-"};

    Act(args);

    Assert("Real = -13 Imaginary = 21.6");
}

TEST_F(AppTest, Can_Mult_Complexs) {
    args = {"0", "-3.6", "17.4", "21", "*"};

    Act(args);

    Assert("Real = 75.6 Imaginary = -62.64");
}

TEST_F(AppTest, Can_Divide_Complexs) {
    args = {"27", "30", "15", "20", "/"};

    Act(args);

    Assert("Real = 1.608 Imaginary = -0.144");
}

TEST_F(AppTest, Can_Detect_Divide_By_Zero) {
    args = {"27", "30", "0", "0", "/"};

    Act(args);

    Assert("Can't divide by zero");
}
