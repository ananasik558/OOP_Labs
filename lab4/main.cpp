#include "include/Figure.hpp"
#include "include/Square.hpp"
#include "include/Trapeze.hpp"
#include "include/Rectangle.hpp"
#include "include/Array.hpp"

int main() {
    std::cout.precision(3);
    std::cout << std::fixed;
    Array<Figure<double>*> arr(0);
    Rectangle<double> o;
    Trapeze<double> t;
    Square<double> s;
    std::cin >> s;
    arr.push_back(&s);
    std::cin >> t;
    arr.push_back(&t);
    std::cin >> o;
    arr.push_back(&o);
    for (int i = 0; i < arr.getsize(); ++i) {
        std::cout << arr[i]->getname() << " area: " << arr[i]->Area() << " center: " << arr[i]->Center() << '\n'; 
    }
    std::cout << '\n';
    arr.erase(1);
    for (int i = 0; i < arr.getsize(); ++i) {
        std::cout << arr[i]->getname() << " area: " << arr[i]->Area() << " center: " << arr[i]->Center() << '\n'; 
    }
    std::cout << '\n';
    arr.pop_back();
    for (int i = 0; i < arr.getsize(); ++i) {
        std::cout << arr[i]->getname() << " area: " << arr[i]->Area() << " center: " << arr[i]->Center() << '\n'; 
    }
    std::cout << '\n';

    return 0;
}