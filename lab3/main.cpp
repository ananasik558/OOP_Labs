#include "include/figure.hpp"
#include "include/point.hpp"
#include "include/rectangle.hpp"
#include "include/square.hpp"
#include "include/Trapeze.hpp"
#include "include/array.hpp"


int main() {
    std::cout.precision(3);
    std::cout << std::fixed;
    Array arr(0);
    Rectangle r;
    Trapeze t;
    Square s;
    std::cout << "Square" << '\n';
    std::cin >> s;
    arr.push_back(&s);
    std::cout << "Trapeze" << '\n';
    std::cin >> t;
    arr.push_back(&t);
    std::cout << "Rectangle" << '\n';
    std::cin >> r;
    arr.push_back(&r);
    std::cout << "Square area: " << s.Area() << " center: " << s.Center() << '\n';
    std::cout << "Trapeze area: " << t.Area() << " center: " << t.Center() << '\n';
    std::cout << "Rectangle area: " << r.Area() << " center: " << r.Center() << '\n';
    std::cout << '\n';
    
    return 0;
}
