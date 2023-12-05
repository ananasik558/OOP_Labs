#include "../include/Trapeze.hpp"

void Trapeze::check_constructor(const Figure& f) const {
    const Trapeze* temp = dynamic_cast<const Trapeze*>(&f);
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
            throw std::logic_error("Some points of Trapeze are the same");
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
    double x_base1 = abs(a.get_x_value() - b.get_x_value());
    double x_base2 = abs(c.get_x_value() - d.get_x_value());
    if (x_base1 != x_base2) {
        throw std::logic_error("Sides of trapeze are not parallel");
    }
}

void Trapeze::check_points(const Point& a, const Point& b, const Point& c, const Point& d) {
    std::vector<Point> points(4);
    points[0] = a;
    points[1] = b;
    points[2] = c;
    points[3] = d;
    for (int i = 0; i < 4; ++i) {
        if (points[i] == points[i + 1]) {
            throw std::logic_error("Some points of Trapeze are the same");
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
    for (int i = 0; i < 3; ++i) {
        if (sides[i] != sides[i + 1]) {
            throw std::logic_error("This Trapeze has different sides");
        }
    }
    double x_base1 = abs(a.get_x_value() - b.get_x_value());
    double x_base2 = abs(c.get_x_value() - d.get_x_value());
    if (x_base1 != x_base2) {
        throw std::logic_error("Sides of trapeze are not parallel");
    }
}

Trapeze::Trapeze() : Figure("Trapeze") {};

Trapeze::Trapeze(const Point& a, const Point& b, const Point& c, const Point& d) : Figure("Trapeze") {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    check_constructor(*this);
}

Trapeze::Trapeze(const Trapeze& t) : Figure("Trapeze") {
    a = t.a;
    b = t.b;
    c = t.c;
    d = t.d;
}

Point Trapeze::Center() const {
    double x_cent = (a.get_x_value() + b.get_x_value() + c.get_x_value() + d.get_x_value()) / 4;
    double y_cent = (a.get_y_value() + b.get_y_value() + c.get_y_value() + d.get_y_value()) / 4;
    Point center(x_cent, y_cent);
    return center;
}

double Trapeze::Area() const {
    double bc = Point::distance(b, c);
    double ad = Point::distance(a, d);
    double ab = Point::distance(a, b);
    double cd = Point::distance(c, d);
    return round(((bc + ad) / 2 * sqrt(ab * ab *((bc - ad) * (bc - ad) + ab * ab - cd * cd) / (2 * abs(bc - ad)))));
}

Trapeze::operator double() const {
    return this->Area();
}

void Trapeze::print(std::ostream& out) {
    out << a << '\n';
    out << b << '\n';
    out << c << '\n';
    out << d << '\n';
}

void Trapeze::input(std::istream& in) {
    in >> a;
    in >> b;
    in >> c;
    in >> d;
    check_points(a, b, c, d);
}

std::ostream& operator << (std::ostream& out, Trapeze& t) {
    t.print(out);
    return out;
}

std::istream& operator >> (std::istream& in, Trapeze& t) {
    t.input(in);
    return in;
}

Trapeze& Trapeze::operator = (const Trapeze& s) {
    if (this != &s) {
        a = s.a;
        b = s.b;
        c = s.c;
        d = s.d;
    }
   return *this;
}

Trapeze& Trapeze::operator = (Trapeze&& s) {
    if (this != &s) {
        a = s.a;
        b = s.b;
        c = s.c;
        d = s.d;
    }
    return *this;
}

bool Trapeze::operator == (const Figure& f) const {
    if (name != f.getname()) {
        return false;
    }
    const Trapeze* temp = dynamic_cast<const Trapeze*>(&f);
    if (temp == nullptr) {
        throw std::logic_error("Bad cast");
    }
    if (this->Area() == temp->Area()) {
        return true;
    }
    return false;
}
