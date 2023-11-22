#pragma once

#include <iostream>
#include <string>
#include <algorithm>

class Twelve { 
public:

   Twelve();
   Twelve(const size_t &n, unsigned char t = 0);
   Twelve(const std::initializer_list< unsigned char> &t);
   Twelve(const std::string &t);
   Twelve(const Twelve& other);
   Twelve(Twelve&& other) noexcept;
   virtual ~Twelve() noexcept;

   bool operator> (const Twelve &other) const;
   bool operator== (const Twelve &other) const;
   bool operator!= (const Twelve &other) const;
   bool operator>= (const Twelve &other) const;
   bool operator< (const Twelve &other) const;
   bool operator<= (const Twelve &other) const;

   Twelve operator+ (const Twelve &other) const;
   Twelve operator- (const Twelve &other) const;
   Twelve operator=(const Twelve &other);
   Twelve operator+= (const Twelve &other);
   Twelve operator-= (const Twelve &other);

   friend std::ostream& operator<< (std::ostream &os, const Twelve &obj);

   size_t getsize() const noexcept;
   unsigned char* getarray() const noexcept;
   

private:
    const int Base = 12;
    size_t _size;
    unsigned char* _array;
    bool IsSystem (unsigned char c) const;
    
};

unsigned char ToUnCh(char c);
char ToCh(unsigned char c);
int ToInt(char c);
