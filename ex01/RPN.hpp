#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
bool isvalid(std::string str);
void rpn(std::string str);

void calculate(std::stack<std::string> &digit_stack, std::stack<std::string> &temp_stack);

#endif