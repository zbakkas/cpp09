#include "RPN.hpp"


bool isvalid(std::string str)
{
    if(str.empty())
        return false;
    if(str.length() >1)
        return false;
 
        for(int j = 0; j < (int)str.size(); j++)
        {
            if(!isdigit(str[j]) && str[j] != '+' && str[j] != '-' && str[j] != '*' && str[j] != '/')
                return false;
        }
  
 
    return true;
   
}


void rpn(std::string str)
{
    std::cout << "RPN " << str << std::endl;
    std::stack<std::string> main_stack;
    std::stack<std::string> temp_stack;
    std::stack<std::string> digit_stack;
    std::stringstream ss(str);
    std::string token;
    while (ss >> token) 
    {
        if(!isvalid(token))
        {
            std::cout << "Error 00" << std::endl;
            return;
        }
        // std::cout << "Token: " << token << std::endl;
        main_stack.push(token); 
    }

    // for (size_t i = 0; i < main_stack.size(); ++i) 
    // {
    //     std::cout << main_stack.top() << std::endl;
    //     main_stack.pop();
    // }

    while (main_stack.size() > 0)
    {
            // std::cout << main_stack.top() << std::endl;

            if(isdigit(main_stack.top()[0]))
            {
                digit_stack.push(main_stack.top());
            }
            else
            {
                temp_stack.push(main_stack.top());
            }
        main_stack.pop();
    }
    
    if(temp_stack.size() +1 != digit_stack.size())
    {
        std::cout << "Error 02" << std::endl;
        return ;
    }
    calculate(digit_stack,temp_stack);
    // while (temp_stack.size() > 0)
    // {
    //     std::cout <<" Temp " << temp_stack.top() << std::endl;
    //     temp_stack.pop();
    // }
    // while (digit_stack.size() > 0)
    // {
    //     std::cout <<"digit "<< digit_stack.top() << std::endl;
    //     digit_stack.pop();
    // }

   
}

void calculate(std::stack<std::string> &digit_stack, std::stack<std::string> &temp_stack)
{

    int re = 0;
    re +=atoi(digit_stack.top().c_str()) ;
    digit_stack.pop();

    while (temp_stack.size() > 0)
    {
    if(temp_stack.top() == "+")
    {
        re += atoi(digit_stack.top().c_str()) ;
        digit_stack.pop();
            
    }
    else if(temp_stack.top() == "-")
    {
        re -= atoi(digit_stack.top().c_str()) ;
        digit_stack.pop();
    }
    else if(temp_stack.top() == "*")
    {
        re *= atoi(digit_stack.top().c_str()) ;
        digit_stack.pop();
    }
    else if(temp_stack.top() == "/")
    {
         re /= atoi(digit_stack.top().c_str()) ;
        digit_stack.pop();
    }
    temp_stack.pop();
    }


    std::cout << re << std::endl;
}