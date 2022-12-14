#include <iostream>
using namespace std;

int* getIntPtr();

int main() {
    int* val = new int[4];
    int* same_mem = val;

    int* ptr = getIntPtr();
    std::cout << ptr << " " << *ptr << std::endl;

    //std::cout << val << " " << same_mem << std::endl;
    //delete [] val;
    //delete [] same_mem;
}

int* getIntPtr() {
    int number = 5;
    int* ptr = &number;
    return ptr;
}