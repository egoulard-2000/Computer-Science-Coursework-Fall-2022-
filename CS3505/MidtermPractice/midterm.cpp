#include <iostream>

void negate(int* input) {
    *input *= -1;
}

int main() {

    // int* z = new int;
    // *z = 1;
    // int* y = z;
    // *z = *z + 1;
    // int x = *y;
    // x++;
    // *y = *y +1;

    // std::cout << x << *y << *z << std::endl;

    int val = 1;
    negate(&val);

    std::cout << val << std::endl;
}

class IntHolder {
    private:
        int* intPtr;

    public:
        IntHolder(int num) {
            intPtr = new int(num);
        }
        ~IntHolder() {
            delete intPtr;
        }
        IntHolder(const IntHolder& other) {
            intPtr = new int(*(other.intPtr));
        }
        IntHolder& operator+(IntHolder other) {
            std::swap(intPtr, other.intPtr);

            return *this;
        }
};