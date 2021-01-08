// - Write a function `get_int` that reads from stdin until a valid number is fed
// - Write a function `get_double` that reads from stdin until a valid number is fed.

#include <iostream>
#include "getters.hpp"

int main() 
{
    int valid_int;    //
    double valid_dbl; // define variables in which valid integer and double will be stored

    valid_int = get_int();                                      //
    std::cout << "valid integer is " << valid_int << std::endl; //
                                                                // call the functions get_int and get double
    valid_dbl = get_double();                                   // and print valid numbers
    std::cout << "valid double is " << valid_dbl << std::endl;  //
}
