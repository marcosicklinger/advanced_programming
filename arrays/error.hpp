// Error functions

#include <iostream>
#include <string>

void error(std::string s);

void error(std::string s)
{
    throw std::runtime_error(s);
}

