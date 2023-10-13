#include <iostream>
#include "twelve.h"

using namespace std;

int main() {
    string str;
    cin >> str;
    Twelve a = string("000ab1");
    Twelve b = str;
    if (a != b) cout << a << " and " << b << " are not equal" << endl;
    if(a == b) cout << a << " and " << b << "are equal" << endl;
    if(a > b) cout << a << " greater then " << b << endl;
    if(a < b) cout << a << " less then " << b << endl;
    cout << "summ = " << a + b << endl;
    cout << "sub = " << a - b << endl;
    return 0;
}