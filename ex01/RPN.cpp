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

bool is_stack_valid(int i)
{
    if(i <=2)
        return false;
    return true;
    
}


void rpn(std::string str)
{
    // std::cout << "RPN " << str << std::endl;
    std::stack<std::string> main_stack;
    std::stringstream ss(str);
    std::stringstream ss2(str);
    std::string token;
    int number =0;
    int temp =0;

    while (ss2 >> token)
    {
        if(!isvalid(token))
        {
            std::cout << "Error 00" << std::endl;
            return;
        }
        if(isdigit(token[0]))
        {
           number++;
        }
        else
            temp++;
    }
    if(temp+1 != number || number == 1)
    {
        std::cout << "number or operator" << std::endl;
        return;
    }

    
    temp =0;
    number =0;
    
    while (ss >> token) 
    {
        main_stack.push(token); 
        if(main_stack.top() == "+" )
        {
            if(!is_stack_valid(main_stack.size()))
            {
                std::cout << "Error op" << std::endl;
                return;
            }
            main_stack.pop();
            // std::cout << "+ "  << std::endl;
            temp = atoi(main_stack.top().c_str());
            // std::cout << "Temp: " << temp << std::endl;
            main_stack.pop();
            number  = (atoi(main_stack.top().c_str()) + temp);
            main_stack.pop();
            main_stack.push(std::to_string(number));
            // std::cout << "Re: " << re << std::endl;

        } 
        else if(main_stack.top() == "-")
        {
            if(!is_stack_valid(main_stack.size()))
            {
                std::cout << "Error op" << std::endl;
                return;
            }
            main_stack.pop();
            // std::cout << "- "  << std::endl;
            temp = atoi(main_stack.top().c_str());
            main_stack.pop();
            number  = (atoi(main_stack.top().c_str()) - temp);
            main_stack.pop();
            main_stack.push(std::to_string(number));
            // std::cout << "Re: " << re << std::endl;
        }
        else if(main_stack.top() == "*")
        {
            if(!is_stack_valid(main_stack.size()))
            {
                std::cout << "Error op" << std::endl;
                return;
            }
            main_stack.pop();
            // std::cout << "* "  << std::endl;
            temp = atoi(main_stack.top().c_str());
            main_stack.pop();
            number  = (atoi(main_stack.top().c_str()) * temp);
            main_stack.pop();
            main_stack.push(std::to_string(number));
            // std::cout << "Re: " << re << std::endl;
        }
        else if(main_stack.top() == "/")
        {
            if(!is_stack_valid(main_stack.size()))
            {
                std::cout << "Error op" << std::endl;
                return;
            }
            main_stack.pop();
            // std::cout << "/"  << std::endl;
            temp = atoi(main_stack.top().c_str());
            main_stack.pop();
            if(temp == 0)
            {
                std::cout << "Error / 0" << std::endl;
                return;
            }
            number  = (atoi(main_stack.top().c_str()) / temp);
            main_stack.pop();
            main_stack.push(std::to_string(number));
            // std::cout << "Re: " << re << std::endl;
        }
        
    }
    std::cout << "=> "<< number << std::endl;

}



