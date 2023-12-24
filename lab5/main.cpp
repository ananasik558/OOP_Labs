#include <chrono>
#include <list>
#include <iostream>
#include "../include/allocator.h"
#include "../include/list.h"
#include "../include/iterator.h"


int main() {
    List<int, Allocator<Node<int>>> myList;
    
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    Iterator<int> it = myList.begin();
    for (it; it != myList.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
    return 0;
}