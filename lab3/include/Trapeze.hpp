#include "figure.hpp"

class Trapeze : public Figure {
    private:
        Point a;
        Point b;
        Point c;
        Point d;

        void print(std::ostream&) override;
        void input(std::istream&) override;
        void check_constructor(const Figure&) const override;
        void check_points(const Point&, const Point&, const Point&, const Point&);
    public:
        Trapeze();
        Trapeze(const Point&, const Point&, const Point&, const Point&);
        Trapeze(const Trapeze&);

        virtual Point Center() const override;
        virtual double Area() const override;

        explicit virtual operator double() const override;
        friend std::ostream& operator << (std::ostream&, Trapeze&);
        friend std::istream& operator >> (std::istream&, Trapeze&);
        Trapeze& operator = (const Trapeze&);
        Trapeze& operator = (Trapeze&&);
        bool operator == (const Figure&) const override;

        virtual ~Trapeze() = default;
};