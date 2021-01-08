// Write a code that reads a number with its proper unit of measure, 
// and prints back that number according to the SI units

#include <iostream>
#include <string>
#include "getters.hpp"

void si_converter(double x, std::string u);

int main ()
{
    double measure; // variable in which to store measurment data
    std::string unit, answer; // "unit": variable in which to store the unit of measurment used;
                              // "answer": variable in which to store the answer of the user when
                              // she/he is asked if she/he wants to convert more measurments.

    std::cout << "Do you want to convert some measures? (yes/no)" << std::endl;

    while(std::cin >> answer) // as long as user provide an answer the program runs
    {    
        if(answer == "no")                                                                     // if user's answer is negative,
        {                                                                                      // the program stops. If the 
            break;                                                                             // user doesn't spell correctly
        } else if (answer != "no" && answer != "yes")                                          // the answer the program asks
        {                                                                                      // again.
            std::cout << "Sorry, I don't get it. " << '\n';                                    // If the answer is positive 
            std::cout << "Do you want to convert some measures or not? (yes/no)" << std::endl; // the program keeps running.
            continue;                                                                          //
        }                                                                                      //
        
        std::cout << "Please, write the result of your measurment followed by the unit of measurment used ";
        std::cout << "(no capital letters allowed)" << std::endl;
        measure = get_double(); // get valid measurment ("real" number)
        std::cin >> unit; // get the unit of measurment
    
        si_converter(measure, unit); // call function to conver measurments

        std::cout << "Do you want to convert another measure? (yes/no)" << std::endl;
    }
}

void si_converter(double x, std::string u) 
{
    if(u == "metre" || u == "metres")                                           // if measure is already in SI length units,
    {                                                                           // the program returns the value given by the
        std::cout << "Your measure amounts to " << x << " metres" << std::endl; // user.
    }                                                                           //
    else if(u == "inch" || u == "inches")                                              // otherwise a conversion is performed.
    {                                                                                  //
        std::cout << "Your measure amounts to " << x*0.0254 << " metres" << std::endl; //
    } else                                                                             //
    {                                                                                  //
        std::cout << "Unit of measurment not found" << std::endl;                      //
    }                                                                                  //
}