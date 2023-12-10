#include "encryptManager.h"

EncryptManager::EncryptManager(/* args */)
{}

std::string EncryptManager::Encrypt(std::string & pass)
{
    ull strSize = pass.size();
    const char* cipherC = passwordCoder(strSize, pass.c_str());
    std::string resCipher;
    resCipher.resize(strSize);
    for(int i = 0; i<strSize; i++)
    {
        resCipher[i] = cipherC[i];
    }
    return resCipher;
}

EncryptManager::~EncryptManager()
{}