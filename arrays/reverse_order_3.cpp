/*
- Write a program that reads from stdin the length of an array and then stores in it the 
  numbers given from stdin. The program should then print the numbers in **reverse order**. 
  Remember to free the used memory properly. Divide the problem into two parts:
    1. Write one **template** function that allocates on the *heap* one array of a given size, 
       initializes its elements, and returns the pointer to the first element.
    2. Write a **template** function that prints the elements of an array in the reverse order.

- Test with integers and doubles.

- Use `std::size_t`
*/

#include <sstream>
#include "error.hpp"
#include "check.hpp"

// Initialization function
template<typename T>
T* init_array(std::size_t _size);

// Print-in-reversed-order function
template<typename T>
void reverse_print(const T* _array, std::size_t _size);

int main() 
{

    try
    {

        /*  In order to check if the size given by the user is the correct type of number,
            the user is first asked to give a string, the string is checked properly. If the 
            input is invalid, the program terminate with an error.  */
        std::cout << "Read the size of the 'array'." << std::endl;
        std::string size_string;
        std::getline(std::cin, size_string);

        std::stringstream sstream(size_string);
        std::size_t size{0};
        if(check_size_t(size_string)) 
        {
            sstream >> size;
            if(size == 0) error("ERROR: 0 dimensions for array");
        } else
        {
            error("ERROR: bad type for 'size'");
        } 
        
        //TEST WITH INTs
        std::cout << "TEST WITH INTs" << std::endl;
        /*  function init_array(...) here cannot deduce template type: 
            it's not in the arguments! Must specify in the <...>.   */
        int* int_array{nullptr};
        int_array = init_array<int>(size);

        /*  function reverse_print(...) here cannot deduce template type: 
            there is an extra arg which is not templated with the template! 
            Must specify in the <...>.  */
        std::cout << "Reversed array: " << std::endl;
        reverse_print<int>(int_array, size);

        delete[] int_array;

        //TEST WITH DOUBLEs
        std::cout << "TEST WITH DOUBLEs" << std::endl;
        /*  function init_array(...) here cannot deduce template type: 
            it's not in the arguments! Must specify in the <...>.   */
        double* double_array{nullptr};
        double_array = init_array<double>(size);

        /*  function reverse_print(...) here cannot deduce template type: 
            there is an extra arg which is not templated with the template! 
            Must specify in the <...>.  */
        std::cout << "Reversed array: " << std::endl;
        reverse_print<double>(double_array, size);
        
        delete[] double_array;

    }
    catch(const std::exception& e)
    {

        std::cerr << e.what() << std::endl;

    }
    
}

template<typename T>
T* init_array(std::size_t _size)
{

    T* _array{new T[_size]};

    std::cout << "Read the elements of the array" << std::endl;
    for(std::size_t i{0}; i < _size; ++i)
    {
        std::cin >> _array[i];
        if(!std::cin) 
        {
            std::cin.ignore();
            std::cin.clear();
            error("ERROR: bad type for 'array[i]'");
        }  
    }

    // return pointer to first element
    return _array;

}

template<typename T>
void reverse_print(const T* _array, std::size_t _size)
{

    for(std::size_t i{_size}; i --> 0;)
    {
        std::cout << _array[i] << " " ;
        if(i==0) std::cout << "" << std::endl;
    }
    
}