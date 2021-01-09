// Write a simple text formatter that breaks the 
// lines longer than a given number of characters. 
// This formatter does not break words and leaves 
// unmodified the lines shorter than the given threshold.

#include <iostream>
#include <string>
#include <fstream>

int main()
{

    std::string name_myfile{" "}; // String in which to store name of the file user wants to format.
    std::cout << "Give the name of the file you want to feed to the text formatter." << std::endl;
    std::cin >> name_myfile;

    int max_char{}; // Integer to store number of characters each line of the formatted file should have.
    std::cout << "How many characters per line?" << std::endl;
    std::cin >> max_char;

    std::ifstream myfile; // Create object with which user can read file to format.
    myfile.open(name_myfile); // Open aformentioned file.

    std::ofstream myfile_formatted ("text_formatted.txt"); // Create and open new file for formatted text.

    if (myfile.is_open()) // Check if file to format is actually open.
    {
        for(std::string line; std::getline(myfile, line);) // Get lines of file to format, one by one, storing
                                                           // it in a string variable.
        {   
            while(line.length() > max_char) // As long as the pieces of the original line to chop are longer than
                                            // the given threshold, program keeps chopping them into more lines.
            {
                int break_point = max_char; // Formatter must not break words nor modify lines shorter than the
                                            // given threshold; thus, program must find the nearest white space 
                                            // located after the max_char-th character of the line.
                while(!(std::isspace(line.at(break_point)))) // If the max_char-th character is not a white space,
                {                                            // program must find the nearest white after the 
                    ++break_point;                           // max_char-th character.
                }                                            //
                myfile_formatted << line.substr(0,break_point) << '\n'; // Once it finds it, the line is chopped into
                                                                        // two lines: the first from the beginning of
                                                                        // the original line to the break_point just 
                                                                        // found.
                line = line.substr(break_point+1,line.length()-break_point-1); // The second from the break_point to the
                                                                               // end of the line: this becomes the new line
                                                                               // which length is checked by the first while
                                                                               // loop.
            }
            myfile_formatted << line << '\n'; // The last piece of line, which is shorter than max_char, is ignored by the 
                                              // first while loop. Thus, it must be printed on file separately.
        }
    } else std::cerr << "Error. Unable to open file" << std::endl; // If file is not open (doesn't exist, user mispelled
                                                                   // its name, etc.), notify the user.
    
    myfile.close();           // Close opened files.
    myfile_formatted.close(); //

}