// Library in which function get_int() and get_double() are defined:
// - get_int() is a function thank to which a valid integer number can be read as input.
// - get_double() is a function thank to which a valid double number can be read as input.

#ifndef GETTERS_H__
#define GETTERS_H__

#include <iostream>

int get_int() 
{
    int i; // define int variable whose value will be given as input by the user

    while(!(std::cin >> i))                                        //
    {                                                              //
        std::cin.clear();                                          // read i since the user gives a valid integer
        std::cin.ignore();                                         //
        std::cout << "not an integer number. Repeat" << std::endl; //
    }                                                              //
    return i; // return valid integer
}

double get_double() 
{
    double d; // define double variable whose value will be given as input by the user

    while(!(std::cin >> d))                                      //
    {                                                            //
        std::cin.clear();                                        // read d since the user gives a valid integer
        std::cin.ignore();                                       //
        std::cout << "not a double number. Repeat" << std::endl; //
    }                                                            //
    return d; // return valid double
}

#endif 