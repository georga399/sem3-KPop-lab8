#include "dataManager.h"

#include <fstream>
#include <filesystem>
#include <dirent.h>
#include <sys/types.h>
#include <iostream>
#include <cstdio>

DataManager::DataManager(std::string connectionString)
{
    path = connectionString;
}

bool DataManager::Login(std::string & username, std::string & password)
{
    std::ifstream ifs;
    std::string filepath = path + username;
    ifs.open(filepath, std::ios::binary);
    std::string inputCipher = encryptManager.Encrypt(password);
    ull size;
    ifs.read((char*)&size, sizeof(std::size_t));
    char buf[255] = {0};
    ifs.read(buf, size);
    std::string fileCipher(buf);
    ifs.close();
    if(fileCipher.size() < 2)
    {
        return false;
        // return "";
    }
    // return fileCipher;  
    return fileCipher == inputCipher;  
}

bool DataManager::AddPassword(std::string username, std::string key, std::string password)
{
    std::fstream fs;
    std::string filePath = path + "" + username + "_" + key;
    fs.open(filePath, std::ios_base::binary|std::ios::out);
    std::string cipher = encryptManager.Encrypt(password);
    auto size = cipher.size();
    fs.write(reinterpret_cast<const char*>(&size), sizeof(size));
    fs.write(cipher.c_str(), size);
    fs.close();
    return true;
}

std::string DataManager::GetPassword(std::string username, std::string key)
{
    std::ifstream ifs;
    std::string filePath = path + "" + username + "_" + key;
    // std::cout << "openning: " << filePath << std::endl;
    ifs.open(filePath, std::ios_base::binary|std::ios::in);
    if(ifs.bad())
        return "";
    ull size;
    ifs.read((char*)&size, sizeof(std::size_t));
    char buf[255] = {0};
    ifs.read(buf, size);
    std::string fileCipher(buf);
    ifs.close();
    if(fileCipher.size() < 2)
        return "";
    std::string pass = encryptManager.Encrypt(fileCipher);
    return pass;
}

std::vector<std::string> DataManager::GetAllUserKeys(std::string username)
{
    DIR *dr;
    struct dirent *en;
    std::vector<std::string> keys;
    dr = opendir(path.c_str()); //open all directory
    if (dr) 
    {
        while ((en = readdir(dr)) != NULL) 
        {
            std::string filename = en->d_name; //print all directory name
            int pos = filename.find('_');
            if(pos < 0 || pos >= filename.size())
                continue;
            std::string userFile = filename.substr(0, pos);
            if(userFile == username)
            {
                std::string key = filename.substr(pos+1);
                if(!key.empty())
                    keys.push_back(key);
            }
        }
        closedir(dr); //close all directory
    }
    return keys;
}

bool DataManager::GenUser(std::string username, std::string password)
{
    std::ofstream ofs;
    std::string filePath = path + username;
    ofs.open(filePath);
    std::string cipher = encryptManager.Encrypt(password);
    ull size = cipher.size();
    ofs.write((char*)&size, sizeof(ull));
    ofs.write(cipher.c_str(), size);
    ofs.close();
    return true;
}

bool DataManager::DeletePassword(std::string username, std::string key)
{
    std::string filePath = path + username + "_" + key;
    return !(remove(filePath.c_str()));
}