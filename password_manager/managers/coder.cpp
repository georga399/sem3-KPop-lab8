#include <iostream>
#include <cstring>
typedef unsigned long long ull;
extern "C" char* passwordCoder(ull, const char*);

int main()
{
    const char* inp = "aaafda";
    ull resSize = strlen(inp);
    const char* res;
    res = passwordCoder(resSize, inp);
    std::cout << res << std::endl;
    char cpres[100];
    for (int i = 0; i<resSize; i++)
    {
        cpres[i] = res[i];
    }
    const char* insp = passwordCoder(resSize, cpres);
    std::cout << insp << std::endl;
    return 0;
}