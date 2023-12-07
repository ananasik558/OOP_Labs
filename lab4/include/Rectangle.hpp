#include "Figure.hpp"

template<Numeric T>
class Rectangle : public Figure<T> {
    private:
        Point<T> a;
        Point<T> b;
        Point<T> c;
        Point<T> d;

        void check_constructor(const Figure<T>&) const override;
        void check_points(const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&) const;
    public:
        Rectangle();
        Rectangle(const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&);
        Rectangle(const Rectangle<T>&);

        virtual Point<T> Center() const override;
        virtual double Area() const override;

        explicit virtual operator double() const override;
        Rectangle<T>& operator = (const Rectangle<T>&);
        Rectangle<T>& operator = (Rectangle<T>&&);
        bool operator == (const Figure<T>&) const override;
        friend std::ostream& operator << (std::ostream& out, Rectangle<T>& s) {
            out << s.a << '\n';
            out << s.b << '\n';
            out << s.c << '\n';
            out << s.d << '\n';
            return out;
        }
        friend std::istream& operator >> (std::istream& in, Rectangle<T>& s) {
            in >> s.a;
            in >> s.b;
            in >> s.c;
            in >> s.d;
            s.check_points(s.a, s.b, s.c, s.d);
            return in;
        }

        virtual ~Rectangle() = default;
};

template<Numeric T>
void Rectangle<T>::check_constructor(const Figure<T>& f) const  {
    const Rectangle<T>* temp = dynamic_cast<const Rectangle<T>*>(&f);
    if (temp == nullptr) {
        throw std::logic_error("Bad cast");
    }
    std::vector<Point<T>> points(4);
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
            sides[i] = round(Point<T>::Distance(points[i], points[i + 1]) * 1000) / 1000;
            continue;
        }
        sides[i] = round(Point<T>::Distance(points[i], points[0]) * 1000) / 1000;
    }
    for (int i = 0; i < 2; ++i) {
        if (sides[i] != sides[i + 1] && sides[i] != sides[i + 2] && sides[i + 1] != sides[i + 2]) {
            throw std::logic_error("This Rectangle has three different sides");
        }
    }
    double ac = round(Point<T>::Distance(points[0], points[2]) * 1000) / 1000;
    double ab = sides[0];
    double bc = sides[1];
    if (ac != round(sqrt(ab * ab + bc * bc) * 1000) / 1000) {
        throw std::logic_error("The angles of Rectangle are not 90 degrees");
    }
}

template<Numeric T>
void Rectangle<T>::check_points(const Point<T>& a, const Point<T>& b, const Point<T>&, const Point<T>& d) const{
    std::vector<Point<T>> points(4);
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
            sides[i] = round(Point<T>::Distance(points[i], points[i + 1]) * 1000) / 1000;
            continue;
        }
        sides[i] = round(Point<T>::Distance(points[i], points[0]) * 1000) / 1000;
    }
     for (int i = 0; i < 2; ++i) {
        if (sides[i] != sides[i + 1] && sides[i] != sides[i + 2] && sides[i + 1] != sides[i + 2]) {
            throw std::logic_error("This Rectangle has three different sides");
        }
    }
    double ac = round(Point<T>::Distance(points[0], points[2]) * 1000) / 1000;
    double ab = sides[0];
    double bc = sides[1];
    if (ac != round(sqrt(ab * ab + bc * bc) * 1000) / 1000) {
        throw std::logic_error("The angles of Rectangle are not 90 degrees");
    }
}

template<Numeric T>
Rectangle<T>::Rectangle() : Figure<T>("Rectangle") {};

template<Numeric T>
Rectangle<T>::Rectangle(const Point<T>& a, const Point<T>& b, const Point<T>& c, const Point<T>& d) : Figure<T>("Rectangle") {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    check_constructor(*this);
}

template<Numeric T>
Rectangle<T>::Rectangle(const Rectangle<T>& s) : Figure<T>("Rectangle") {
    a = s.a;
    b = s.b;
    c = s.c;
    d = s.d;
}

template<Numeric T>
Point<T> Rectangle<T>::Center() const {
    T x_cent = (a.get_x_value() + b.get_x_value() + c.get_x_value() + d.get_x_value()) / 4;
    T y_cent = (a.get_y_value() + b.get_y_value() + c.get_y_value() + d.get_y_value()) / 4;
    Point<T> center(x_cent, y_cent);
    return center;
}

template<Numeric T>
double Rectangle<T>::Area() const {
    T ab = Point<T>::Distance(a, b);
    T bc = Point<T>::Distance(b, c);
    return ab * bc;
}

template<Numeric T>
Rectangle<T>::operator double() const {
    return this->Area();
}

template<Numeric T>
Rectangle<T>& Rectangle<T>::operator = (const Rectangle<T>& s) {
    if (this != &s) {
        a = s.a;
        b = s.b;
        c = s.c;
        d = s.d;
    }
    return *this;
}

template<Numeric T>
Rectangle<T>& Rectangle<T>::operator = (Rectangle<T>&& s) {
    if (this != &s) {
        a = s.a;
        b = s.b;
        c = s.c;
        d = s.d;
    }
    return *this;
}

template<Numeric T>
bool Rectangle<T>::operator == (const Figure<T>& f) const {
    if (this->getname() != f.getname()) {
        return false;
    }
    const Rectangle<T>* temp = dynamic_cast<const Rectangle<T>*>(&f); 
    if (temp == nullptr) {
        throw std::logic_error("Bad cast");
    }
    if (this->Area() == temp->Area()) {
        return true;
    }
    return false;
}