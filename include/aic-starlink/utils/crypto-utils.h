#pragma once 
#include <string> 
using namespace std; 

namespace aic_starlink :: utils 
{
    class CryptoUtils 
    {
        public: 
        // NOTE : This is a placeholder API
        // Actual cryptographic implementation must use vetted libraries..

        [[nodiscard]] static string sha256(const string &input); 
        [[nodiscard]] static string randomToken(size_t length); 
    }; 
}