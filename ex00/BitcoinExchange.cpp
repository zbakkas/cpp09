
#include "BitcoinExchange.hpp"


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;  // Invalid format
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 1) {
        return false;  // Invalid year
    }

    if (month < 1 || month > 12) {
        return false;  // Invalid month
    }

    // Days in each month (index 0 is unused)
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year)) {
        daysInMonth[2] = 29;  // Adjust February for leap year
    }

    if (day < 1 || day > daysInMonth[month]) {
        return false;  // Invalid day
    }

    return true;
}


void read_data(std::string path)
{
    std::ifstream file;

    file.open(path,std::fstream::in);

    if(!file.is_open())
    {
        std::cout << "Error: cannot open file " << path << std::endl;
        return;
    }
    std::cout << path << std::endl;

    std::string buffer;
    while (std::getline(file, buffer))
    {
        std::cout << buffer << "<    ----    >" << std::endl;
        std::string date = buffer.substr(0, buffer.find(" "));
        std::string value = buffer.substr(buffer.find_last_of(" ")+1 );

        if (isValidDate(date)) 
        {
            double number = std::atof(value.c_str());
            if(number < std::numeric_limits<int>::max()  && number > 0 )
            {
            //     std::cout << "date: " << date <<std::endl;
            //     std::cout << "value: " << number << std::endl;
                std::cout << date << " => " << number << " = " << calculate_bitcoin(date) << std::endl;
            }
            else if(number < 0)
                std::cout << "Error : Negative value: " << value << std::endl;
            else if(number == 0)
                std::cout << "Error : Zero value: " << value << std::endl;
            else if(number > std::numeric_limits<int>::max())
                std::cout << "Error : Value too large: " << value << std::endl;
            else
                std::cout << "Error : Invalid value: " << value << std::endl;

        } else {
            std::cout << "Error : Invalid date format: " << date << std::endl;
        }

       
    }
    file.close();
  
}

double calculate_bitcoin(std::string date)
{
    return 0.0;
}