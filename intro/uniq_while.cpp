#include <iostream>
#include <string>

int main() 
{

    std::string line, last_line, previous_line{" "};
    int counter{1};
    
    while (std::getline(std::cin, line))
    {
        if (line == previous_line)
        {
            ++counter;
        }
        else
        {
            if(previous_line != " ") std::cout << counter << '\t' << previous_line << std::endl;
            counter = 1;
        } 
        previous_line = line;
    }
    if(previous_line != " ") std::cout << counter << '\t' << previous_line << std::endl;
}