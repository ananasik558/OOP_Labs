#include "Figure.hpp"

template<Numeric T>
class Trapeze : public Figure<T> {
    private:
        Point<T> a;
        Point<T> b;
        Point<T> c;
        Point<T> d;

        void check_constructor(const Figure<T>&) const override;
        void check_points(const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&) const;
    public:
        Trapeze();
        Trapeze(const Point<T>&, const Point<T>&, const Point<T>&, const Point<T>&);
        Trapeze(const Trapeze<T>&);

        virtual Point<T> Center() const override;
        virtual double Area() const override;

        explicit virtual operator double() const override;
        Trapeze<T>& operator = (const Trapeze<T>&);
        Trapeze<T>& operator = (Trapeze<T>&&);
        bool operator == (const Figure<T>&) const override;
        friend std::ostream& operator << (std::ostream& out, Trapeze<T>& s) {
            out << s.a << '\n';
            out << s.b << '\n';
            out << s.c << '\n';
            out << s.d << '\n';
            return out;
        }
        friend std::istream& operator >> (std::istream& in, Trapeze<T>& s) {
            in >> s.a;
            in >> s.b;
            in >> s.c;
            in >> s.d;
            s.check_points(s.a, s.b, s.c, s.d);
            return in;
        }

        virtual ~Trapeze() = default;
};

template<Numeric T>
void Trapeze<T>::check_constructor(const Figure<T>& f) const  {
    const Trapeze<T>* temp = dynamic_cast<const Trapeze<T>*>(&f);
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
            throw std::logic_error("Some points of Trapeze are the same");
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
    double x_base1 = abs(a.get_x_value() - b.get_x_value());
    double x_base2 = abs(c.get_x_value() - d.get_x_value());
    if (x_base1 != x_base2) {
        throw std::logic_error("Sides of trapeze are not parallel");
    }
}

template<Numeric T>
void Trapeze<T>::check_points(const Point<T>& a, const Point<T>& b, const Point<T>&, const Point<T>& d) const{
    std::vector<Point<T>> points(4);
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
            sides[i] = round(Point<T>::Distance(points[i], points[i + 1]) * 1000) / 1000;
            continue;
        }
        sides[i] = round(Point<T>::Distance(points[i], points[0]) * 1000) / 1000;
    }
    double x_base1 = abs(a.get_x_value() - b.get_x_value());
    double x_base2 = abs(c.get_x_value() - d.get_x_value());
    if (x_base1 != x_base2) {
        throw std::logic_error("Sides of trapeze are not parallel");
    }
}

template<Numeric T>
Trapeze<T>::Trapeze() : Figure<T>("Trapeze") {};

template<Numeric T>
Trapeze<T>::Trapeze(const Point<T>& a, const Point<T>& b, const Point<T>& c, const Point<T>& d) : Figure<T>("Trapeze") {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    check_constructor(*this);
}

template<Numeric T>
Trapeze<T>::Trapeze(const Trapeze<T>& s) : Figure<T>("Trapeze") {
    a = s.a;
    b = s.b;
    c = s.c;
    d = s.d;
}

template<Numeric T>
Point<T> Trapeze<T>::Center() const {
    T x_cent = (a.get_x_value() + b.get_x_value() + c.get_x_value() + d.get_x_value()) / 4;
    T y_cent = (a.get_y_value() + b.get_y_value() + c.get_y_value() + d.get_y_value()) / 4;
    Point<T> center(x_cent, y_cent);
    return center;
}

template<Numeric T>
double Trapeze<T>::Area() const {
    T bc = Point<T>::Distance(b, c);
    T ad = Point<T>::Distance(a, d);
    T ab = Point<T>::Distance(a, b);
    T cd = Point<T>::Distance(c, d);
    return round(((bc + ad) / 2 * sqrt(ab * ab *((bc - ad) * (bc - ad) + ab * ab - cd * cd) / (2 * abs(bc - ad)))));
}

template<Numeric T>
Trapeze<T>::operator double() const {
    return this->Area();
}

template<Numeric T>
Trapeze<T>& Trapeze<T>::operator = (const Trapeze<T>& s) {
    if (this != &s) {
        a = s.a;
        b = s.b;
        c = s.c;
        d = s.d;
    }
    return *this;
}

template<Numeric T>
Trapeze<T>& Trapeze<T>::operator = (Trapeze<T>&& s) {
    if (this != &s) {
        a = s.a;
        b = s.b;
        c = s.c;
        d = s.d;
    }
    return *this;
}

template<Numeric T>
bool Trapeze<T>::operator == (const Figure<T>& f) const {
    if (this->getname() != f.getname()) {
        return false;
    }
    const Trapeze<T>* temp = dynamic_cast<const Trapeze<T>*>(&f); 
    if (temp == nullptr) {
        throw std::logic_error("Bad cast");
    }
    if (this->Area() == temp->Area()) {
        return true;
    }
    return false;
}
