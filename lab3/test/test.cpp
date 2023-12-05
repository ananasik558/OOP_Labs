#include <gtest/gtest.h>
#include "../include/point.hpp"
#include "../include/figure.hpp"
#include "../include/Trapeze.hpp"
#include "../include/square.hpp"
#include "../include/rectangle.hpp"
#include "../include/array.hpp"

TEST(Point_class, default_constructor) {
    Point p;
    ASSERT_TRUE(p.get_x_value() == 0 && p.get_y_value() == 0);
}

TEST(Point_class, values_constructor) {
    Point p(3.2, 1);
    ASSERT_TRUE(p.get_x_value() == 3.2 && p.get_y_value() == 1);
}

TEST(Point_class, copy_constructor) {
    Point a(4.4, 3.545);
    Point b(a);
    ASSERT_TRUE(b.get_x_value() == 4.4 && b.get_y_value() == 3.545);
}

TEST(Point_class, equality_operator_1) {
    Point a(4.4, 3.545);
    Point b(a);
    ASSERT_TRUE(a == b);
}

TEST(Point_class, equality_operator_2) {
    Point a(2, 5);
    Point b(3.4, 2);
    ASSERT_FALSE(a == b);
}

TEST(Point_class, lvalue_copy) {
    Point a(3.45, 2);
    Point b = a;
    ASSERT_TRUE(b.get_x_value() == 3.45 && b.get_y_value() == 2);
}

TEST(Point_class, distance_1) {
    Point a(0,3);
    Point b(4,0);
    ASSERT_TRUE(Point::distance(a, b) == 5);
}

TEST(Point_class, distance_2) {
    Point a(1,1);
    Point b(1,1);
    ASSERT_TRUE(Point::distance(a, b) == 0);
}

TEST(Trapeze_class, default_constructor) {
    Trapeze t;
    ASSERT_TRUE(t.getname() == "Trapeze");
}

TEST(Trapeze_class, points_constructor_1) {
    ASSERT_ANY_THROW(Trapeze t(Point(0, 0), Point(0,3), Point(1, 4), Point(-3, 6)));
}

TEST(Trapeze_class, points_constructor_2) {
    ASSERT_ANY_THROW(Trapeze t(Point(0,0), Point(0, 0), Point(0, 4), Point(0, 6)));
}

TEST(Trapeze_class, copy_constructor) {
    const Point a(0, 0);
    const Point b(1, sqrt(3));
    const Point c(-1, sqrt(3));
    const Point d(-2, 4);
    Trapeze t(a, b, c, d);
    Trapeze New(t);
    ASSERT_TRUE(New == t);
}

TEST(Trapeze_methods, center_method_1) {
    Trapeze t(Point(-2, 1), Point(-1, 3), Point(1, 3), Point(2, 1));
    Point center = t.Center();
    ASSERT_TRUE(center.get_x_value() <= EPS && center.get_y_value() == 2);
}

TEST(Trapeze_methods, area_method_1) {
    Trapeze t(Point(-2,0), Point(-1,3), Point(1,3), Point(2,0));
    double area = round(t.Area()*1000)/1000;
    ASSERT_TRUE(area == round(sqrt(81)*1000)/1000);
}

TEST(Trapeze_operators, equality_operator) {
    Trapeze t1(Point(-2,0), Point(-1,3), Point(1,3), Point(2,0));
    Trapeze t2(Point(-2,0), Point(-1,3), Point(1,3), Point(2,0));
    ASSERT_TRUE(t1 == t2);
}

TEST(Trapeze_operators, lvalue_copy_1) {
    Trapeze t(Point(-2,0), Point(-1,3), Point(1,3), Point(2,0));
    Trapeze New;
    New = t;
    ASSERT_TRUE(New == t);
}

TEST(Square_constructors, default_constructor) {
    Square s;
    ASSERT_TRUE(s.getname() == "Square");
}

TEST(Square_constructors, points_constructor_1) {
    ASSERT_ANY_THROW(Square s(Point(0, 0), Point(0,0), Point(1,1), Point(2,2)));
}

TEST(Square_constructos, points_constructor_2) {
    ASSERT_ANY_THROW(Square s(Point(1, 1), Point(2, 2), Point(3, 3), Point(4, 4)));
}

TEST(Square_construcors, points_constructor_3) {
    Square s(Point(-2, -2), Point(-2, 2), Point(2, 2), Point(2, -2));
}

TEST(Square_methods, center_method_1) {
    Square s(Point(-2, -2), Point(-2, 2), Point(2, 2), Point(2, -2));
    Point center = s.Center();
    ASSERT_TRUE(center.get_x_value() <= EPS && center.get_y_value() <= EPS);
}

TEST(Square_methods, center_method_2) {
    Square s(Point(0,0), Point(0,4), Point(4,4), Point(4,0));
    Point center = s.Center();
    ASSERT_TRUE(center.get_x_value() - 2 <= EPS && center.get_y_value() - 2 <= EPS);
}

TEST(Square_methods, area_method_1) {
    Square s(Point(-2, -2), Point(-2, 2), Point(2, 2), Point(2, -2));
    double area = s.Area();
    ASSERT_TRUE(area == 16);
}

TEST(Square_methods, area_method_2) {
    Square s(Point(0,0), Point(0,4), Point(4,4), Point(4,0));
    double area = s.Area();
    ASSERT_TRUE(area == 16);
}

TEST(Square_operators, double_cast_operator) {
    Square s(Point(0,0), Point(0,4), Point(4,4), Point(4,0));
    double temp = double(s);
    ASSERT_TRUE(temp == 16);
}

TEST(Square_operators, equality_operator) {
    Square s1(Point(0,0), Point(0,4), Point(4,4), Point(4,0));
    Square s2(Point(0,0), Point(0,4), Point(4,4), Point(4,0));
    ASSERT_TRUE(s1 == s2);
}

TEST(Square_operators, lvalue_copy_1) {
    Square s1(Point(0,0), Point(0,4), Point(4,4), Point(4,0));
    Square s2;
    s2 = s1;
    ASSERT_TRUE(s1 == s2);
}

TEST(Square_operators, lvalue_copy_2) {
    Square s1(Point(0,0), Point(0,4), Point(4,4), Point(4,0));
    Square s2;
    s1 = s2;
    ASSERT_TRUE(s1 == s2 && s1.getname() == "Square");
}

TEST(Square_operators, rvalue_copy) {
    Square s1(Point(0,0), Point(0,4), Point(4,4), Point(4,0));
    Square s2;
    Square s3;
    s3 = s1;
    s2 = std::move(s1);
    ASSERT_TRUE(s2 == s3);
}

TEST(Rectangle_class, default_constructor) {
    Rectangle o;
    ASSERT_TRUE(o.getname() == "Rectangle");
}

TEST(Rectangle_class, points_constructor_1) {
    ASSERT_ANY_THROW(Rectangle o(Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0)));
}

TEST(Rectangle_class, points_constructor_2) {
    Rectangle o( Point(0, 2), Point(0, 6), Point(4, 6), Point(4, 2));
    o.~Rectangle();
}

TEST(Rectangle_methods, center_method_1) {
    Rectangle o(Point(0, 2), Point(0, 6), Point(4, 6), Point(4, 2));
    Point center = o.Center();
    ASSERT_TRUE(center.get_x_value() == 2 && center.get_y_value() == 4);
}

TEST(Rectangle_methods, area_method_1) {
    Rectangle o(Point(0, 2), Point(0, 6), Point(4, 6), Point(4, 2));
    double area = o.Area();
    ASSERT_TRUE(area = 16);
}

TEST(Rectangle_operators, equality_operator) {
    Rectangle o1(Point(0, 2), Point(0, 6), Point(4, 6), Point(4, 2));
    Rectangle o2(Point(0, 2), Point(0, 6), Point(4, 6), Point(4, 2));
    ASSERT_TRUE(o1 == o2);
}

TEST(Rectangle_operators, lvalue_copy_1) {
    Rectangle o(Point(0, 2), Point(0, 6), Point(4, 6), Point(4, 2));
    Rectangle temp;
    temp = o;
    ASSERT_TRUE(temp == o);
}

TEST(Array_constructors, default_constructor) {
    Array arr;
    ASSERT_TRUE(arr.getcapacity() == 2 && arr.getsize() == 0);
}

TEST(Array_constructors, default_constructor_destructor) {
    Array arr;
    arr.~Array();
}

TEST(Array_constructors, size_constructor_1) {
    Array arr(0);
    ASSERT_TRUE(arr.getcapacity() == 2 && arr.getsize() == 0);
}

TEST(Array_constructors, size_constructor_2) {
    Array arr(3);
    ASSERT_TRUE(arr.getcapacity() == 6 && arr.getsize() == 3);
}

TEST(Array_methods, push_back_method) {
    Array arr(0);
    Square s1(Point(0,0), Point(0,4), Point(4,4), Point(4,0));
    arr.push_back(&s1);
    ASSERT_TRUE(arr.getsize() == 1);
}

TEST(Array_methods, pop_back_method) {
    Array arr(1);
    arr.pop_back();
    ASSERT_TRUE(arr.getsize() == 0);
}

TEST(Array_methods, erase_method) {
    Array arr(0);
    Square s1(Point(0,0), Point(0,4), Point(4,4), Point(4,0));
    Rectangle o(Point(0, 2), Point(0, 6), Point(4, 6), Point(4, 2));
    Trapeze t(Point(-2,0), Point(-1,3), Point(1,3), Point(2,0));
    arr.push_back(&s1);
    arr.push_back(&o);
    arr.push_back(&t);
    arr.erase(1);
    ASSERT_TRUE(arr.getsize() == 2 && *(arr[0]) == s1 && *(arr[1]) == t);
}

TEST(Array_methods, methods_thows_1) {
    Array arr(0);
    Square s1(Point(0,0), Point(0,4), Point(4,4), Point(4,0));
    Rectangle o(Point(0, 2), Point(0, 6), Point(4, 6), Point(4, 2));
    Trapeze t(Point(-2,0), Point(-1,3), Point(1,3), Point(2,0));
    arr.push_back(&s1);
    arr.push_back(&o);
    arr.push_back(&t);
    ASSERT_ANY_THROW(arr.FigureCenter(10));
}

TEST(Array_methods, methods_thows_2) {
    Array arr;
    Square s1(Point(0,0), Point(0,4), Point(4,4), Point(4,0));
    Rectangle o(Point(0, 2), Point(0, 6), Point(4, 6), Point(4, 2));
    Trapeze t(Point(-2,0), Point(-1,3), Point(1,3), Point(2,0));
    arr.push_back(&s1);
    arr.push_back(&o);
    arr.push_back(&t);
    ASSERT_ANY_THROW(arr.FigureArea(10));
}

TEST(Array_methods, methods_throws_3) {
    Array arr;
    Square s1(Point(0,0), Point(0,4), Point(4,4), Point(4,0));
    Rectangle o(Point(0, 2), Point(0, 6), Point(4, 6), Point(4, 2));
    Trapeze t(Point(-2,0), Point(-1,3), Point(1,3), Point(2,0));
    arr.push_back(&s1);
    arr.push_back(&o);
    arr.push_back(&t);
    ASSERT_ANY_THROW(arr[10]);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}