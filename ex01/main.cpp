#include "RPN.hpp"

int main(int arc ,char **arv)
{
    if(arc==2)
    {
       rpn(arv[1]);
    }
    else
        std::cout << "Error" << std::endl;
    return 0;
}

// #include <iostream>
// #include <sstream>
// #include <vector>
// #include <string>

// int main() {
//     std::string expression = "89 9 * 9 - 9 - 9 - 4 - 1 +";
//     std::stringstream ss(expression);  // Create a stringstream object
//     std::string token;                 // Variable to store each token
//     std::vector<std::string> tokens;   // Vector to store all tokens

//     // Tokenize the string using space as a delimiter
//     while (ss >> token) {
//         tokens.push_back(token);  // Store each token in the vector
//     }

//     // Display the tokens
//     std::cout << "Tokens:" << std::endl;
//     for (size_t i = 0; i < tokens.size(); ++i) {
//         std::cout << tokens[i] << std::endl;
//     }

//     return 0;
// }
