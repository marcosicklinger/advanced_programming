// Error functions

#ifndef ERROR_H__
#define ERROR_H__

#include <iostream>
#include <string>

void error(std::string s);

void error(std::string s)
{
    throw std::runtime_error(s);
}

#endif
