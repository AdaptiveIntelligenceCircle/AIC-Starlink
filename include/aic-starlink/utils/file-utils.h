#pragma once 
#include <iostream> 

#include <string>
#include <vector>

using namespace std; 

#include "error.h"

namespace aic_starlink :: utils 
{
    class FileUtils 
    {
        public: 
        [[nodiscard]] static bool exists(const string &path); 

        // static core :: Error readAllText(const string &path, string &out_text); 
        // static core :: Error writeAllText(const string &path, const string &text); 

        // static core :: Error listFiles(const string &dir, vector<string> &out_files); 

    };
}