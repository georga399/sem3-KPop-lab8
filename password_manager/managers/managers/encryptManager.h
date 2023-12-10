#ifndef ENCRYPTMANAGER_H
#define ENCRYPTMANAGER_H
#include <string>

typedef unsigned long long ull;

extern "C" const char* passwordCoder(ull, const char*);

class EncryptManager
{
private:
    /* data */
public:
    EncryptManager(/* args */);
    std::string Encrypt(std::string & pass);
    ~EncryptManager();
};


#endif