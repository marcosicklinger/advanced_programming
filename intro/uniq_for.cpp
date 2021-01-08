// Write a simple version of the Unix program `uniq -c`, which, when fed with a text, 
// outputs the same text with **consecutive** identical lines collapsed into one 
// prepended with the number of repetitions. 

// FOR-LOOP version

#include <iostream>
#include <string>

int main() 
{

    std::string previous_line{" "}; // define variable needed to store previous line of file/input
    int counter{1}; // define counter of equal lines of file/input (initialized to 1 because its 
                    // the minimum number of identical lines)
    
    for (std::string line; std::getline(std::cin, line);) // get line from file/input
    {
        if (line == previous_line) // compare current line stored from file/input with previous
                                   // line stored from file/input
        {
            ++counter; // if comparison is successfull, increase counter by one
        }
        else
        {
            if(previous_line != " ") std::cout << counter << '\t' << previous_line << std::endl; // if comparison is not
                                                                                                 // successful, print on screen
                                                                                                 // number of identical repeated
                                                                                                 // lines
            counter = 1; // and set counter back to 1
        } 
        previous_line = line; // before acquiring new line from file/input, 
                              // set the line just acquired to previous line
    }
    if(previous_line != " ") std::cout << counter << '\t' << previous_line << std::endl; // print on screen the last set of 
                                                                                         // equal lines (needed if file does
                                                                                         // not end with whitespace (" ") as
                                                                                         // last line)
}