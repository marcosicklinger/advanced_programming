/*  
    Header file in which function get_int() and get_double() are defined:
    - get_int() is a function thank to which a valid integer number can be read as input.
    - get_double() is a function thank to which a valid double number can be read as input.
    - get_primes() is a function build to return a vector of prime numbers from 2 (conventionally
      taken as first prime number) to an upper limit specified by the user.
    - is_prime('arg') is a function that returns 'true' if its 'arg' (int) is prime, 'false' otherwise. 
      It has been implemented using get_primes() function, retrieving the largest prime smaller than
      the 'arg'+1.
*/


#ifndef GETTERS_H__
#define GETTERS_H__

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>

// DECLARATIONS

int get_int();

double get_double();

std::vector<int> get_primes(int _n);

bool is_prime(int _n);


// DEFINITIONS

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
        std::cin.clear();                                        // read d since the user gives a valid double
        std::cin.ignore();                                       //
        std::cout << "not a double number. Repeat" << std::endl; //
    }                                                            //
    return d; // return valid double
}

std::vector<int> get_primes(int _n)
{

    std::vector<int> _primes;

    if(_n < 2) 
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

    if(_n < 2) return true;

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