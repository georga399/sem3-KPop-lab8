#include <iostream>
typedef unsigned long long ull;

extern "C" const char* passwordGenerator(ull size);

int main()
{
    const char* pass;
    std::cout << "passwordGenerator" << std::endl;
    pass = passwordGenerator(500);
    std::cout << pass << std::endl;
}