#include "../include/rectangle.hpp"

void Rectangle::check_constructor(const Figure& f) const {
    const Rectangle* temp = dynamic_cast<const Rectangle*>(&f);
    if (temp == nullptr) {
        throw std::logic_error("Bad cast");
    }
    std::vector<Point> points(4);
    points[0] = temp->a;
    points[1] = temp->b;
    points[2] = temp->c;
    points[3] = temp->d;
    for (int i = 0; i < 4; ++i) {
        if (points[i] == points[i + 1]) {
            throw std::logic_error("Some points of Rectangle are the same");
        }
    }
    std::vector<double> sides(4);
    for (int i = 0; i < 4; ++i) {
        if (i < 3) {
            sides[i] = round(Point::distance(points[i], points[i + 1]) * 1000) / 1000;
            continue;
        }
        sides[i] = round(Point::distance(points[i], points[0]) * 1000) / 1000;
    }
    for (int i = 0; i < 2; ++i) {
        if (sides[i] != sides[i + 1] && sides[i] != sides[i + 2] && sides[i + 1] != sides[i + 2]) {
            throw std::logic_error("This Rectangle has three different sides");
        }
    }
    double ac = round(Point::distance(points[0], points[2]) * 1000) / 1000;
    double ab = sides[0];
    double bc = sides[1];
    if (ac != round(sqrt(ab * ab + bc * bc) * 1000) / 1000) {
        throw std::logic_error("The angles of Rectangle are not 90 degrees");
    }
}

void Rectangle::check_points(const Point& a, const Point& b, const Point& c, const Point& d) {
    std::vector<Point> points(4);
    points[0] = a;
    points[1] = b;
    points[2] = c;
    points[3] = d;
    for (int i = 0; i < 4; ++i) {
        if (points[i] == points[i + 1]) {
            throw std::logic_error("Some points of Rectangle are the same");
        }
    }
    std::vector<double> sides(4);
    for (int i = 0; i < 4; ++i) {
        if (i < 3) {
            sides[i] = round(Point::distance(points[i], points[i + 1]) * 1000) / 1000;
            continue;
        }
        sides[i] = round(Point::distance(points[i], points[0]) * 1000) / 1000;
    }
    for (int i = 0; i < 2; ++i) {
        if (sides[i] != sides[i + 1] && sides[i] != sides[i + 2] && sides[i + 1] != sides[i + 2]) {
            throw std::logic_error("This Rectangle has three different sides");
        }
    }
    double ac = round(Point::distance(points[0], points[2]) * 1000) / 1000;
    double ab = sides[0];
    double bc = sides[1];
    if (ac != round(sqrt(ab * ab + bc * bc) * 1000) / 1000) {
        throw std::logic_error("The angles of Rectangle are not 90 degrees");
    }
}

Rectangle::Rectangle() : Figure("Rectangle") {};

Rectangle::Rectangle(const Point& a, const Point& b, const Point& c, const Point& d) : Figure("Rectangle") {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    check_constructor(*this);
}

Rectangle::Rectangle(const Rectangle& t) : Figure("Rectangle") {
    a = t.a;
    b = t.b;
    c = t.c;
    d = t.d;
}

Point Rectangle::Center() const {
    double x_cent = (a.get_x_value() + b.get_x_value() + c.get_x_value() + d.get_x_value()) / 4;
    double y_cent = (a.get_y_value() + b.get_y_value() + c.get_y_value() + d.get_y_value()) / 4;
    Point center(x_cent, y_cent);
    return center;
}

double Rectangle::Area() const {
    double ab = Point::distance(a, b);
    double bc = Point::distance(b, c);
    return ab * bc;
}

Rectangle::operator double() const {
    return this->Area();
}

void Rectangle::print(std::ostream& out) {
    out << a << '\n';
    out << b << '\n';
    out << c << '\n';
    out << d << '\n';
}

void Rectangle::input(std::istream& in) {
    in >> a;
    in >> b;
    in >> c;
    in >> d;
    check_points(a, b, c, d);
}

std::ostream& operator << (std::ostream& out, Rectangle& t) {
    t.print(out);
    return out;
}

std::istream& operator >> (std::istream& in, Rectangle& t) {
    t.input(in);
    return in;
}

Rectangle& Rectangle::operator = (const Rectangle& s) {
    if (this != &s) {
        a = s.a;
        b = s.b;
        c = s.c;
        d = s.d;
    }
   return *this;
}

Rectangle& Rectangle::operator = (Rectangle&& s) {
    if (this != &s) {
        a = s.a;
        b = s.b;
        c = s.c;
        d = s.d;
    }
    return *this;
}

bool Rectangle::operator == (const Figure& f) const {
    if (name != f.getname()) {
        return false;
    }
    const Rectangle* temp = dynamic_cast<const Rectangle*>(&f);
    if (temp == nullptr) {
        throw std::logic_error("Bad cast");
    }
    if (this->Area() == temp->Area()) {
        return true;
    }
    return false;
}