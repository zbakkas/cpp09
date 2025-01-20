
#include "BitcoinExchange.hpp"


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const std::string& date) 
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') 
    {
        std::cout << "Error: Invalid format: " << date << std::endl;
        return false;  
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if(year < 2009)
    {
        std::cout << "Error: Date too old: " << date << std::endl;
        return false;
    }

    if (month < 1 || month > 12) {
        std::cout << "Error: Invalid month: " << date << std::endl;
        return false;  
    }

   
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year)) {
        daysInMonth[2] = 29;  
    }

    if (day < 1 || day > daysInMonth[month]) {
        std::cout << "Error: Invalid day: " << date << std::endl;
        return false;  
    }


    return true;
}

bool isvalid(std::string number)
{
    int count = 0;
    for (int i = 0; i < (int)number.length(); i++)
    {
        if(number[i] == '.')
            count++;
        if(number[0] == '.')
            return false;
 
        if((!isdigit(number[i]) && number[i] != '.') || count > 1)
        {
            return false;
        }
    }
    return true;
}

std::vector<std::string> read_data_csv(std::string path)
{
    std::vector<std::string> vdata;

    std::ifstream file;
    file.open(path,std::fstream::in);
    if(!file.is_open())
    {
        std::cout << "Error: cannot open file " << path << std::endl;
        return vdata;
    }

    std::string buffer;
    std::getline(file,buffer);
    while(std::getline(file,buffer))
    {
        vdata.push_back(buffer.substr(0,buffer.find(",")));
    }
    file.close();
    return vdata;
}

std::vector<double> read_price_csv(std::string path)
{
    std::vector<double> vprice;

    std::ifstream file;
    file.open(path,std::fstream::in);
    if(!file.is_open())
    {
        std::cout << "Error: cannot open file " << path << std::endl;
        return vprice;
    }

    std::string buffer;
    std::getline(file,buffer);
    double number = 0;
    while(std::getline(file,buffer))
    {
         number = std::atof((buffer.substr(buffer.find_last_of(",")+1)).c_str());
        vprice.push_back(number);
        // std::cout << number << std::endl;
    }
    file.close();
    return vprice;
}


void read_data(std::string path)
{
    std::vector<std::string> vdata;
    std::vector<double> vprice;
    vdata = read_data_csv("data.csv");
    vprice = read_price_csv("data.csv");

    std::ifstream file;
    file.open(path,std::fstream::in);
    if(!file.is_open())
    {
        std::cout << "Error: cannot open file " << path << std::endl;
        return;
    }
    std::cout << path << std::endl;

    std::string buffer;
    std::getline(file, buffer);
    while (std::getline(file, buffer))
    {
        // std::cout << buffer << "<    ----    >" << std::endl;
        std::string date = buffer.substr(0, buffer.find(" "));
        std::string value = buffer.substr(buffer.find("|")+2 );

        // std::cout << "****" << value << std::endl;
        if (isValidDate(date)) 
        {
            double number = std::atof(value.c_str());
            if( isvalid(value) && number < std::numeric_limits<int>::max()  && number > 0 )
            {
            //     std::cout << "date: " << date <<std::endl;
            //     std::cout << "value: " << number << std::endl;
                std::cout << date << " => " << number << " = " << number *calculate_bitcoin(date,vdata,vprice) << std::endl;
            }
            else if(!isvalid(value))
                std::cout << "Error : Invalid value: " << value << std::endl;
            else if(number < 0)
                std::cout << "Error : Negative value: " << value << std::endl;
            else if(number == 0)
                std::cout << "Error : Zero value: " << value << std::endl;
            else if(number > std::numeric_limits<int>::max())
                std::cout << "Error : Value too large: " << value << std::endl;
            else
                std::cout << "Error : Invalid value: " << value << std::endl;

        } 
        // else {
        //     std::cout << date << std::endl;
        // }

       
    }
    file.close();
  
}

double calculate_bitcoin(std::string date, std::vector<std::string> vdata , std::vector<double> vprice)
{
    int i = 0;
    while (vdata[i] < date)
    {
        i++;
    }
    if(vdata[i] == date)
    {
        // std::cout <<"**************" <<vdata[i] << std::endl;
        return vprice[i];
    }
    else
    {
        // std::cout <<"**************" <<vdata[i-1] << std::endl;
        return vprice[i-1];
    }
    
    
}