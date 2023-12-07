#include <gtest/gtest.h>
#include "../include/Point.hpp"
#include "../include/Figure.hpp"
#include "../include/Trapeze.hpp"
#include "../include/Square.hpp"
#include "../include/Rectangle.hpp"
#include "../include/Array.hpp"

TEST(Point_class, default_constructor) {
    Point<int> p;
    ASSERT_TRUE(p.get_x_value() == 0 && p.get_y_value() == 0);
}

TEST(Point_class, values_constructor) {
    Point<double> p(3.2, 1);
    ASSERT_TRUE(p.get_x_value() == 3.2 && p.get_y_value() == 1);
}

TEST(Point_class, copy_constructor) {
    Point<double> a(4.4, 3.545);
    Point b(a);
    ASSERT_TRUE(b.get_x_value() == 4.4 && b.get_y_value() == 3.545);
}

TEST(Point_class, equality_operator_1) {
    Point<float> a(4.4, 3.545);
    Point b(a);
    ASSERT_TRUE(a == b);
}

TEST(Point_class, equality_operator_2) {
    Point<long double> a(2, 5);
    Point<long double> b(3.4, 2);
    ASSERT_FALSE(a == b);
}

TEST(Point_class, lvalue_copy) {
    Point<double> a(3.45, 2);
    Point<double> b = a;
    ASSERT_TRUE(b.get_x_value() == 3.45 && b.get_y_value() == 2);
}

TEST(Point_class, rvalue_copy) {
    Point<float> a(3.45, 2);
    Point<float> b;
    b = std::move(a);
    ASSERT_TRUE(b.get_x_value() - 3.45 <= EPS && b.get_y_value() - 2 <= EPS && a.get_x_value() <= EPS && a.get_y_value() <= EPS);
}

TEST(Point_class, distance_1) {
    Point<long> a(0,3);
    Point<long> b(4,0);
    ASSERT_TRUE(Point<long>::Distance(a, b) == 5);
}

TEST(Point_class, distance_2) {
    Point<int> a(1,1);
    Point<int> b(1,1);
    ASSERT_TRUE(Point<int>::Distance(a, b) == 0);
}

TEST(Trapeze_class, default_constructor) {
    Trapeze<long double> t;
    ASSERT_TRUE(t.getname() == "Trapeze");
}

TEST(Trapeze_class, points_constructor_1) {
    ASSERT_ANY_THROW(Trapeze<int> t(Point<int>(0, 0), Point<int>(0, 0), Point<int>(0, 4), Point<int>(0,3)));
}

TEST(Trapeze_class, copy_constructor) {
    const Point<float> a(0, 0);
    const Point<float> b(1, 3);
    const Point<float> c(3, 3);
    const Point<float> d(4, 0);
    Trapeze<float> t(a, b, c, d);
    Trapeze<float> New(t);
    ASSERT_TRUE(New == t);
}

TEST(Trapeze_class, destructor_and_points_constructor) {
    Trapeze<double> t(Point<double>(0, 0), Point<double>(1,3), Point<double>(4,3), Point<double>(5,0));
    t.~Trapeze();
}

TEST(Trapeze_methods, center_method_1) {
    Trapeze t(Point<long double>(0, 0), Point<long double>(1,3), Point<long double>(4,3), Point<long double>(5,0));
    Point<long double> center = t.Center();
    ASSERT_TRUE(center.get_x_value() - 2.5 <= EPS && center.get_y_value() - 1.5 <= EPS);
}

TEST(Trapeze_methods, area_method_1) {
    Trapeze<double> t(Point<double>(0, 0), Point<double>(1,3), Point<double>(4,3), Point<double>(5,0));
    double area = round(t.Area()*1000)/1000;
    ASSERT_TRUE(area == round(13 * 1000) / 1000);
}

TEST(Trapeze_operators, equality_operator) {
    Trapeze<double> t1(Point<double>(0, 0), Point<double>(1,3), Point<double>(4,3), Point<double>(5,0));
    Trapeze<double> t2(Point<double>(0, 0), Point<double>(1,3), Point<double>(4,3), Point<double>(5,0));
    ASSERT_TRUE(t1 == t2);
}

TEST(Trapeze_operators, lvalue_copy_1) {
    Trapeze<double> t(Point<double>(0, 0), Point<double>(1,3), Point<double>(4,3), Point<double>(5,0));
    Trapeze<double> New;
    New = t;
    ASSERT_TRUE(New == t);
}

TEST(Square_constructors, default_constructor) {
    Square<int> s;
    ASSERT_TRUE(s.getname() == "Square");
}

TEST(Square_constructors, points_constructor_1) {
    ASSERT_ANY_THROW(Square<float> s(Point<float>(0, 0), Point<float>(0,0), Point<float>(1,1), Point<float>(2,2)));
}

TEST(Square_constructos, points_constructor_2) {
    ASSERT_ANY_THROW(Square<double> s(Point<double>(1, 1), Point<double>(2, 2), Point<double>(3, 3), Point<double>(4, 4)));
}

TEST(Square_construcors, points_constructor_3) {
    Square<long> s(Point<long>(-2, -2), Point<long>(-2, 2), Point<long>(2, 2), Point<long>(2, -2));
}

TEST(Square_methods, center_method_1) {
    Square<long double> s(Point<long double>(-2, -2), Point<long double>(-2, 2), Point<long double>(2, 2), Point<long double>(2, -2));
    Point<long double> center = s.Center();
    ASSERT_TRUE(center.get_x_value() <= EPS && center.get_y_value() <= EPS);
}

TEST(Square_methods, center_method_2) {
    Square<int> s(Point<int>(0,0), Point<int>(0,4), Point<int>(4,4), Point<int>(4,0));
    Point<int> center = s.Center();
    ASSERT_TRUE(center.get_x_value() - 2 <= EPS && center.get_y_value() - 2 <= EPS);
}

TEST(Square_methods, area_method_1) {
    Square<float> s(Point<float>(-2, -2), Point<float>(-2, 2), Point<float>(2, 2), Point<float>(2, -2));
    double area = s.Area();
    ASSERT_TRUE(area == 16);
}

TEST(Square_methods, area_method_2) {
    Square<int> s(Point<int>(0,0), Point<int>(0,4), Point<int>(4,4), Point<int>(4,0));
    double area = s.Area();
    ASSERT_TRUE(area == 16);
}

TEST(Square_operators, double_cast_operator) {
    Square<int> s(Point<int>(0,0), Point<int>(0,4), Point<int>(4,4), Point<int>(4,0));
    double temp = double(s);
    ASSERT_TRUE(temp == 16);
}

TEST(Square_operators, equality_operator) {
    Square<int> s1(Point<int>(0,0), Point<int>(0,4), Point<int>(4,4), Point<int>(4,0));
    Square<int> s2(Point<int>(0,0), Point<int>(0,4), Point<int>(4,4), Point<int>(4,0));
    ASSERT_TRUE(s1 == s2);
}

TEST(Square_operators, lvalue_copy_1) {
    Square<float> s1(Point<float>(0,0), Point<float>(0,4), Point<float>(4,4), Point<float>(4,0));
    Square<float> s2;
    s2 = s1;
    ASSERT_TRUE(s1 == s2);
}

TEST(Square_operators, lvalue_copy_2) {
    Square<float> s1(Point<float>(0,0), Point<float>(0,4), Point<float>(4,4), Point<float>(4,0));
    Square<float> s2;
    s1 = s2;
    ASSERT_TRUE(s1 == s2 && s1.getname() == "Square");
}

TEST(Square_operators, rvalue_copy) {
    Square<int> s1(Point<int>(0,0), Point<int>(0,4), Point<int>(4,4), Point<int>(4,0));
    Square<int> s2;
    Square<int> s3;
    s3 = s1;
    s2 = std::move(s1);
    ASSERT_TRUE(s2 == s3);
}

TEST(Rectangle_class, default_constructor) {
    Rectangle<long double> o;
    ASSERT_TRUE(o.getname() == "Rectangle");
}

TEST(Rectangle_class, points_constructor_1) {
    ASSERT_ANY_THROW(Rectangle<int> o(Point<int>(0, 0), Point<int>(0, 0), Point<int>(0, 0), Point<int>(0, 0)));
}

TEST(Rectangle_methods, center_method_1) {
    Rectangle<float> o(Point<float>(0, 0), Point<float>(0, 2), Point<float>(4, 2), Point<float>(4, 0));
    Point<float> center = o.Center();
    ASSERT_TRUE(fabs(center.get_x_value()) - 2 <= EPS && fabs(center.get_y_value()) - 1 <= EPS);
}

TEST(Rectangle_methods, area_method_1) {
    Rectangle<long double> o(Point<long double>(0, 0), Point<long double>(0, 2), Point<long double>(4, 2), Point<long double>(4, 0));
    double area = o.Area();
    ASSERT_TRUE(area = 8);
}

TEST(Rectangle_operators, equality_operator) {
    Rectangle<float> o1(Point<float>(0, 0), Point<float>(0, 2), Point<float>(4, 2), Point<float>(4, 0));
    Rectangle<float> o2(Point<float>(0, 0), Point<float>(0, 2), Point<float>(4, 2), Point<float>(4, 0));
    ASSERT_TRUE(o1 == o2);
}

TEST(Rectangle_operators, lvalue_copy_1) {
    Rectangle<double> o(Point<double>(0, 0), Point<double>(0, 2), Point<double>(4, 2), Point<double>(4, 0));
    Rectangle<double> temp;
    temp = o;
    ASSERT_TRUE(temp == o);
}

TEST(Rectangle_operators, rvalue_copy) {
    Rectangle<float> o(Point<float>(0, 0), Point<float>(0, 2), Point<float>(4, 2), Point<float>(4, 0));
    Rectangle<float> temp;
    Rectangle<float> oct;
    oct = o;
    temp = std::move(o);
    ASSERT_TRUE(temp == oct);
}

TEST(Array_constructors, default_constructor) {
    Array<Figure<int>*> arr;
    ASSERT_TRUE(arr.getcapacity() == 2 && arr.getsize() == 0);
}

TEST(Array_constructors, default_constructor_destructor) {
    Array<Figure<double>*> arr;
    arr.~Array();
}

TEST(Array_constructors, size_constructor_1) {
    Array<Figure<double>*> arr(0);
    ASSERT_TRUE(arr.getcapacity() == 2 && arr.getsize() == 0);
}

TEST(Array_constructors, size_constructor_2) {
    Array<Figure<long>*> arr(3);
    ASSERT_TRUE(arr.getcapacity() == 6 && arr.getsize() == 3);
}

TEST(Array_methods, push_back_method) {
    Array<Figure<long>*> arr(0);
    Square<long> s1(Point<long>(0,0), Point<long>(0,4), Point<long>(4,4), Point<long>(4,0));
    arr.push_back(&s1);
    ASSERT_TRUE(arr.getsize() == 1);
}

TEST(Array_methods, pop_back_method) {
    Array<Figure<float>*> arr(1);
    arr.pop_back();
    ASSERT_TRUE(arr.getsize() == 0);
}

TEST(Array_methods, erase_method) {
    Array<Figure<double>*> arr(0);
    Square<double> s1(Point<double>(0,0), Point<double>(0,4), Point<double>(4,4), Point<double>(4,0));
    Rectangle<double> o(Point<double>(0,0), Point<double>(0,4), Point<double>(4,4), Point<double>(4,0));
    Trapeze<double> t(Point<double>(0, 0), Point<double>(1, 4), Point<double>(4, 4), Point<double>(5, 0));
    arr.push_back(&s1);
    arr.push_back(&o);
    arr.push_back(&t);
    arr.erase(1);
    ASSERT_TRUE(arr.getsize() == 2 && *(arr[0]) == s1 && *(arr[1]) == t);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}