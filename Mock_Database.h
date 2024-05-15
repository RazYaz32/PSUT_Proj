#ifndef MOCK_DATABASE_H
#define MOCK_DATABASE_H
#include <unordered_map>
#include <string>

//Mock user database
std::unordered_map<int, std::string> userDatabase = {
    {1, "password123"},
    {2, "mySecretPass"},
    {3, "admin2024"},
    {4, "secretPassword"},
    {5, "passwordSecret"},
    {6, "userSuper"},
    {7, "123456789"},
    {8, "naiveUser"},
    {9, "complexPassword"},
};

//Mock multi-factor authentication database
std::unordered_map<int, bool> mfaDatabase = {
    {1, true},
    {2, false},
    {3, true},
    {4, false},
    {5, true},
    {6, false},
    {7, true},
    {8, false},
    {9, true}
};


//Mock transaction database (FOR RUNTIME ONLY)
std::unordered_map<int, double> transactionDatabase;


#endif