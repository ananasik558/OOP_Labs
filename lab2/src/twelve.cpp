#include "twelve.h"



unsigned char ToUnCh(char c) {
    return (c >= '0' and c <= '9') ? (unsigned char)(c - '0') : (unsigned char)(c - 'a' + 10);
    
}

char ToCh(unsigned char c) {
    return (0 <= c and c <= 9) ? (char)(c + '0') : (char)(c + 'a' - 10);
}

bool Twelve::IsSystem (unsigned char c) const {
    return (0 <= c and c <= Base);
}

Twelve::Twelve() : _size(0), _array{nullptr} {}

Twelve::Twelve(const size_t &n, unsigned char t) {
    _array = new unsigned char[n];
    _size = n;
    for (int i = n - 1; i >= 0; --i) {
        if (IsSystem(t)) _array[i] = t;
        else throw std::invalid_argument("Fill constructor: symbol is not in correct place");
    }   
}

Twelve::Twelve(const std::initializer_list<unsigned char> &t) {
    _array = new unsigned char[t.size()];
    _size = t.size();
    size_t i{t.size() - 1};
    for (auto c : t) {
        if (IsSystem(c)) _array[i--] = c;
        else throw std::invalid_argument("Init list constructor: symbol is not in correct place");
    }
}

Twelve::Twelve(const std::string &str) {
    int ind = 0;
    while (str[ind] == '0') ind++;
    
    if (ind == str.size()) ind--;
    
    _size  = str.size() - ind;
    _array = new unsigned char[_size];

    for (int i = _size - 1; i >= 0; i--) {
        if (IsSystem(ToUnCh(str[ind]))) {
            _array[i] = ToUnCh(str[ind]);
            ind++;
        } 
        else std::invalid_argument("Copy string constructor: symbol is not in correct place");
    }
}


Twelve::Twelve(const Twelve &other) {
    _size  = other._size;
    _array = new unsigned char[_size];

    for(size_t i{0}; i < _size; ++i) _array[i] = other._array[i];
}

Twelve::Twelve(Twelve &&other) noexcept {
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}


Twelve::~Twelve() noexcept {
    if (_size > 0) {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

bool Twelve::operator> (const Twelve &other) const {
    if (_size > other._size) return true;
    else if (_size == other._size) {
        for (int i = _size - 1; i >= 0; i--) {
            if (_array[i] > other._array[i]) return true;
        }
    }
    return false;
}

bool Twelve::operator== (const Twelve &other) const {
    if (_size == other._size) {
        for (int i = 0; i < _size; i++) {
            if (_array[i] != other._array[i]) return false;
        }
        return true;
    } else {
        return false;
    }
}
bool Twelve::operator!= (const Twelve &other) const {
    return (!(*this == other));
}
bool Twelve::operator>= (const Twelve &other) const {
    return (*this > other or *this == other);
}

bool Twelve::operator< (const Twelve &other) const {
    return(!(*this >= other));
}

bool Twelve::operator<= (const Twelve &other) const {
    return (!(*this > other));
}


Twelve Twelve::operator+ (const Twelve &other) const {
    Twelve res;
    res._size = (this->_size < other._size) ? other._size : this->_size;
    res._array = new unsigned char[res._size];

    int val = 0, mod = 0;
    for (int i = 0; i < res._size; i++) {
        if (i < _size) val += this->_array[i];
        if (i < other._size) val += other._array[i];
        val += mod;
        mod = val % Base;
        res._array[i] = mod;
        mod = val / Base;
        val = 0;
    }
    return res;
}

Twelve Twelve::operator- (const Twelve &other) const {
    Twelve res;
    int val, mod = 0;
    if (*this == other) {
        res._size = 1;
        res._array = new unsigned char[res._size];
        res._array[0] = 0;
        return res;
    }
    if (*this >= other) {
        res._size = _size;
        res._array = new unsigned char[res._size];
        for (int i = 0; i < _size; i++) {
            if (i < other._size) {
                if (_array[i] >= other._array[i]) {
                    val = _array[i] - other._array[i] + mod;
                    mod = 0;
                } else {
                    val = _array[i] - other._array[i] + mod + Base;
                    mod = -1;
                }
                res._array[i] = val;
            } else {
                res._array[i] = _array[i] + mod;
            }
        }
    int ind = res._size - 1;
    if (res._array[ind] == 0) {
        while (res._array[ind] == 0) {
            ind--;
        }
        Twelve ans;
        ans._size = ind + 1;
        ans._array = new unsigned char [ans._size];
        for (int i = ind; i >= 0; i--) {
            ans._array[i] = res._array[i];
        }
        delete [] res._array;
        res._size = 0;
        return ans;
    }

    return res;
    } else throw std::invalid_argument("first numb is less then second");
}

Twelve Twelve::operator= (const Twelve &other) {

    delete [] _array;
    _size = other._size;
    _array = new unsigned char[_size];

    for (int i = 0; i < _size; i++) _array[i] = other._array[i];

    return *this;
}

Twelve Twelve::operator+= (const Twelve &other) {
    *this = *this + other;
    return *this;
}

Twelve Twelve::operator-= (const Twelve &other) {
    *this = *this - other;
    return *this;
}

size_t Twelve::getsize() const noexcept {
    return _size;
}

unsigned char* Twelve::getarray() const noexcept {
    return _array;
}

std::ostream& operator<< (std::ostream& os, const Twelve &obj) {
    for (int i = obj.getsize() - 1; i >= 0; i--) {
        os << ToCh(obj.getarray()[i]);
    }
    return os;
}