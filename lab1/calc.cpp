#include "calc.h"

std::string calc(std::string k) {
    std::string s;
    long long n = 0;
    n = stoll(k);
    while(n > 0) {
        s += std::to_string(n % 2);
        n /= 2;
    }
    while(s.length() < 32) {
        s += std::to_string(0);
    }
    std::reverse(s.begin(), s.end());
    return s;
}