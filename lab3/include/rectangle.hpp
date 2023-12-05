#include "figure.hpp"

class Rectangle : public Figure {
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
        Rectangle();
        Rectangle(const Point&, const Point&, const Point&, const Point&);
        Rectangle(const Rectangle&);

        virtual Point Center() const override;
        virtual double Area() const override;

        explicit virtual operator double() const override;
        friend std::ostream& operator << (std::ostream&, Rectangle&);
        friend std::istream& operator >> (std::istream&, Rectangle&);
        Rectangle& operator = (const Rectangle&);
        Rectangle& operator = (Rectangle&&);
        bool operator == (const Figure&) const override;

        virtual ~Rectangle() = default;
};
