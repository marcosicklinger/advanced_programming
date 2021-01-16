/*  
    Header file in which function get_int() and get_double() are defined:

    - get_int() is a function thank to which a valid integer number can be read as input.

    - get_double() is a function thank to which a valid double number can be read as input.

    - get_int_lim('int_1','int_2') returns an integer in the interval ['int_1','int_2'].

    - get_double_lim('d_1','d_2') returns a double in the interval ['d_1','d_2'].

    - skip() checks if the inputs given by the user to get_int() and get_double() are valid inputs.
      It throws a runtime exception if no input is given.

    - get_primes('int') is a function build to return a vector of prime numbers from 2 (conventionally
      taken as first prime number) to an upper limit specified by the user.

    - is_prime('int') is a function that returns 'true' if its 'int' (int) is prime, 'false' otherwise. 
      It has been implemented using get_primes() function, retrieving the largest prime smaller than
      the 'int'+1.
*/


#ifndef GETTERS_H__
#define GETTERS_H__

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include "error.hpp"

// DECLARATIONS

int get_int();

double get_double();

int get_int_lim(int int_min, int int_max);

double get_double_lim(double d_min, double d_max);

void skip();

std::vector<int> get_primes(int _n);

bool is_prime(int _n);


// DEFINITIONS

int get_int() 
{
    int i; // define int variable whose value will be given as input by the user

    while(!(std::cin >> i)) // loop goes on until valid integer is given
    {
        std::cout << "not an integer number. Repeat" << std::endl; // read i since the user gives a valid integer
        skip();
    }
    return i; // return valid integer
}

double get_double() 
{
    double d; // define double variable whose value will be given as input by the user

    while(!(std::cin >> d)) // loop goes on until valid double is given
    {
        std::cout << "not an double number. Repeat" << std::endl;
        skip();
    }
    return d; // return valid double
}

int get_int_lim(int int_min, int int_max)
{
    while(true)
    {
        int i_lim = get_int();
        if(i_lim >= int_min && i_lim <= int_max) return i_lim; 
        std::cout << "WARNING: interval limits not respected" << std::endl;
    }
}

double get_double_lim(double d_min, double d_max)
{
    while(true)
    {
        double d_lim = get_double();
        if(d_lim > d_min && d_lim < d_max) return d_lim;
        std::cout << "WARNING: interval limits not respected" << std::endl;
    }
}

void skip()
{
    // if no input is give (f.i. users types Ctrl+D), exception is thrown 
    if(std::cin.eof()) 
    {
        error("ERROR: no valid input");
    } else // otherwise (wrong input) the error flag in 'cin' is cleared and wrong input ignored.
    {
        std::cin.clear();
        std::cin.ignore();
        return;
    }
}

std::vector<int> get_primes(int _n)
{

    std::vector<int> _primes;

    if(_n < 0)
    {
        error("ERROR: negative int unacceptable");
    } else if(_n < 2) 
    {
        std::cout << "Number smaller than 2 is prime" << std::endl;
        _primes.push_back(_n);
    } else
    {
        // first element of primes is 2
        _primes.push_back(2);
        for(int i{2}; i < _n+1; ++i)
        {
            // primes are those numbers that give non-zero remainder when divided by smaller primes
            int j{0};
            while(i%_primes[j])
            {
                if(_primes[j] >= static_cast<int>(sqrt(i))) 
                {
                    _primes.push_back(i);
                    break;
                }
                ++j;
            }
            
        }
    }
    
    return _primes;
    
}

bool is_prime(int _n)
{

    if(_n < 0)
    {
        error("ERROR: negative int unacceptable");
    } else if(_n > 0 && _n < 2) return true;

    std::vector<int> primes_to_n = get_primes(_n);
    if(_n == *max_element(primes_to_n.begin(),primes_to_n.end()))
    {
        return true;
    } else
    {
        return false;
    }

}


#endif 