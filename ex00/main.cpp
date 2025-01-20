

#include "BitcoinExchange.hpp"

int main(int arc ,char **arv)
{

    if(arc==2)
    {
        // read_data_csv(arv[1]);
        // read_price_csv(arv[1]);
        read_data(arv[1]);
    }
    else
        std::cout << "Usage: ./bitcoin path" << std::endl;
    return 0;

}