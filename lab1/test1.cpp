#include <gtest/gtest.h>
#include "calc.h"

TEST(test_01, basis_test_set) {
    ASSERT_TRUE(calc("1") == "00000000000000000000000000000001");
}

TEST(test_02, basis_test_set) {
    ASSERT_TRUE(calc("0") == "00000000000000000000000000000000");
}

TEST(test_03, basis_test_set) {
    ASSERT_TRUE(calc("12") == "00000000000000000000000000001100");
}

TEST(test_04, basis_test_set) {
    ASSERT_TRUE(calc("48") == "00000000000000000000000000110000");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
