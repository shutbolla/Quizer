#pragma once
#include <string>

namespace logger {

    void info(const std::string &msg);
    
    void warn(const std::string &msg);
    
    void error(const std::string &msg);
}