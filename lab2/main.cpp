#include <iostream>
#include "twelve.h"

using namespace std;

int main() {
    Twelve empt;
    cout << empt << "There is must be nothing!" << endl;

    Twelve a(5, 10);
    cout << a << endl;
    string str;
    cin >> str;
    Twelve b = {4, 10, 12};
    Twelve c = str;
    if (b != c) cout << b << " and " << c << " are not equal and their sum = " << b + c << endl;
    
    Twelve d = string("000000000004");
    Twelve f = string("01");
    cout << d << endl;
    cout << f << endl;
    cout << d - f << endl;
    cout << d + f << endl;

return 0;
}