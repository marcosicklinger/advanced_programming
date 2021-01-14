#ifndef CHECK_H__
#define CHECK_H__

#include <iostream>
#include <string>

/*  function build to check if the given number is a good size_t number:
    - takes a string as argument (user gives the number as a string);
    - returns 'true' if it is;
    - returns 'false' if it is not.  */
// DECLARATION
bool check_size_t(std::string& _size);

// DEFINITION
bool check_size_t(std::string& _size)
{
    bool is_char{};
    for(const auto& x : _size)
        {
            if(isalpha(x)) 
            {
                is_char = true;
                break;
            }
        }
    if(_size.find(".") != std::string::npos || 
       _size.find(",") != std::string::npos ||
       is_char)
    {
        return false;
    } else
    {
        return true;
    }
}

#endif