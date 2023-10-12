#include <gtest/gtest.h>
#include "twelve.h"

TEST(equal, test01) {
    Twelve num1("0"), num2("0");
    ASSERT_TRUE(num1 == num2);
}

TEST(equal, test02) {
    Twelve num1("00000000000000"), num2("0");
    std::cout << num1 << ' ' << num2 << std::endl;
    ASSERT_TRUE(num1 == num2);
}

TEST(equal, test03) {
    Twelve num1("1a2"), num2("1a1");
    ASSERT_FALSE(num1 == num2);
}

TEST(equal, test04) {
    Twelve num1("31a");
    ASSERT_TRUE(num1 == Twelve("31a"));
}

TEST(equal, test05) {
    Twelve num1("aaa");
    ASSERT_FALSE(num1 == Twelve("aab"));
}

TEST(equal, test06) {
    Twelve num1("00000000000000aaa"), num2("aaa");
    ASSERT_TRUE(num1 == num2);
}



TEST(not_equal, test01) {
    Twelve num1("10ab"), num2("10ab");
    ASSERT_FALSE(num1 != num2);
}

TEST(not_equal, test02) {
    Twelve num1("ab"), num2("1000");
    ASSERT_TRUE(num1 != num2);
}

TEST(not_eq, test03) {
    Twelve num1("322");
    ASSERT_TRUE(num1 != Twelve());
}

TEST (greater, test01) {
    Twelve num1("10ab"), num2("22");
    ASSERT_TRUE(num1 > num2);
}

TEST(greater, test02) {
    Twelve num1("10ab");
    ASSERT_FALSE(num1 > num1);
}

TEST(greater, test03) {
    Twelve num1("1010b"), num2("10010");
    ASSERT_TRUE(num1 > num2);
}

TEST(greater, test04) {
    Twelve num1("10b"), num2("22b");
    ASSERT_FALSE(num1 > num2);
}


TEST(greater_or_eq, test01) {
    Twelve num1("10ab"), num2("22");
    ASSERT_TRUE(num1 >= num2);
}

TEST(greater_or_eq, test02) {
    Twelve num1("10ab");
    ASSERT_TRUE(num1 >= num1);
}


TEST(greater_or_eq, test03) {
    Twelve num1("0"), num2("1220");
    ASSERT_FALSE(num1 >= num2);
}



TEST(less, test01) {
    Twelve num1("10ab"), num2("22");
    ASSERT_FALSE(num1 < num2);
}

TEST(less, test02) {
    Twelve num1("145");
    ASSERT_FALSE(num1 < num1);
}

TEST(less, test03) {
    Twelve num1("10100"), num2("10010");
    ASSERT_FALSE(num1 < num2);
}

TEST(less, test04) {
    Twelve num1("10"), num2("1220");
    ASSERT_TRUE(num1 < num2);
}



TEST(less_or_eq, test01) {
    Twelve num1("3a4"), num2("1b");
    ASSERT_FALSE(num1 <= num2);
}

TEST(less_or_eq, test02) {
    Twelve num1("145");
    ASSERT_TRUE(num1 <= num1);
}

TEST(less_or_eq, test03) {
    Twelve num1("22a"), num2("12");
    ASSERT_FALSE(num1 <= num2);
}

TEST(less_or_eq, test04) {
    Twelve num1("10"), num2("1220");
    ASSERT_TRUE(num1 <= num2);
}


TEST(add, test01) {
    Twelve num1("0"), num2("10ab");
    ASSERT_TRUE(num1 + num2 == Twelve("10ab"));
}

TEST(add, test02) {
    Twelve num1("10"), num2("0");
    ASSERT_TRUE(num1 + num2 == Twelve("10"));
}

TEST(add, test03) {
    Twelve num1("4a"), num2("1");
    ASSERT_TRUE(num1 + num2 == Twelve("4b"));
}

TEST(add, test04) {
    Twelve num1("4"), num2("1ab2222");
    ASSERT_TRUE(num1 + num2 == Twelve("1ab2226"));
}

TEST(add, test05) {
    Twelve num1("00000000000004"), num2("1ab2222");
    std::cout<< num1 << std::endl;
    ASSERT_TRUE(num1 + num2 == Twelve("1ab2226"));
}

TEST(add_n_ravno, test01) {
    Twelve num1("0"), num2("4ab");
    num1 += num2;
    ASSERT_TRUE (num1 == num2);
}

TEST(add_n_ravno, test02) {
    Twelve num1("4ab"), num2("0");
    num1 += num2;
    ASSERT_TRUE (num1 == Twelve("4ab"));
}

TEST(add_n_ravno, test03) {
    Twelve num1("4ab"), num2("4ab");
    num1 += num2;
    ASSERT_TRUE (num1 == Twelve("99a"));
}

TEST(sub, test01) {
    Twelve num1("10ab104032bc"), num2("22");
    Twelve res(num1 - num2);
    ASSERT_TRUE(num1 - num2 == res);
}

TEST(sub, test02) {
    Twelve num1("4ab10101"), num2("4ab10100");
    Twelve res = num1 - num2;
    ASSERT_TRUE(num1 - num2 == Twelve("1"));
}

TEST(sub, test03) {
    Twelve num1("4ab10101"), num2("4ab10100");
    Twelve res = num1 - num2;
    ASSERT_TRUE(num1 - num2 == Twelve("0001"));
}

TEST(sub, test04) {
    Twelve num1("10ab"), num2("0");
    Twelve res(num1 - num2);
    ASSERT_TRUE(num1 - num2 == num1);
}

TEST(sub, test05) {
    Twelve num1("22"), num2("10ab");
    ASSERT_ANY_THROW(num1 - num2);
}

TEST(sub_n_ravno, test01) {
    Twelve num1("0"), num2("4ab");
    ASSERT_ANY_THROW(num1 -= num2;);
}

TEST(sub_n_ravno, test02) {
    Twelve num1("4ab"), num2("0");
    num1 -= num2;
    ASSERT_TRUE (num1 == Twelve("4ab"));
}

TEST(sub_n_ravno, test03) {
    Twelve num1("4ab"), num2("4ab");
    num1 -= num2;
    ASSERT_TRUE (num1 == Twelve("0"));
}

TEST(sub_n_ravno, test04) {
    Twelve num1("4ab10101"), num2("4ab10100");
    num1 -= num2;
    ASSERT_TRUE(num1 == Twelve("1"));
}

TEST(sub_n_ravno, test06) {
    Twelve num1("4ab"), num2("4ab101");
    ASSERT_ANY_THROW(num1 -= num2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}