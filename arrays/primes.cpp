/*
Populate an array named `primes` containing the first prime numbers smaller than 100. Consider 2 as the first prime (i.e. `primes[0] == 2`).

- you are free to choose the design and the implementation.

- please comment and motivate your choices (e.g., allocate one big
  array, or every time I find a new prime number I increase the size of
  the previous `primes` array, etc.)
*/

#include "getters.hpp"
#include "check.hpp"
#include "error.hpp"

int main() 
{

    try
    {

        std::cout << "Read upper limit of calculation." << std::endl;
        std::string n_string;
        std::getline(std::cin, n_string);

        // check correctness of input
        std::stringstream sstream(n_string);
        int n{};
        if(check_size_t(n_string))
        {
            sstream >> n;
        } else
        {
            error("ERROR: bad type for 'n'");
        }
        
        std::vector<int> primes;
        primes = get_primes(n);
        std::cout << "Primes number up to " << n << " are:" << std::endl;
        for(const auto& x : primes) std::cout << x << std::endl;

        std::cout << "To conclude, ";

        if(is_prime(n))
        {
            std::cout << n << " is prime." << std::endl;
        } else
        {
            std::cout << n << " is not prime." << std::endl;
        }
        

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}