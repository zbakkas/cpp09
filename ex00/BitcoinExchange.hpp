#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <vector>

void   read_data(std::string path);
std::vector<std::string> read_data_csv(std::string path);
std::vector<double> read_price_csv(std::string path);
double calculate_bitcoin(std::string date, std::vector<std::string> vdata, std::vector<double> vprice);

#endif