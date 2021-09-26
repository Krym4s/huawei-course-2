#include "complex_number.hpp"

int main()
{
    complex_number a(1, 0);
    complex_number b(0, 1);
    complex_number c(0,0);
    complex_number d(1/sqrt(2),1/sqrt(2));
    c = a; 
    c = d.power(4);
    c /= c;
    c *= 3;

    c.print();

    std::cout << c;
    return 0;
}