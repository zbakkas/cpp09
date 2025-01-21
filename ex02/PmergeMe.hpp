#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

int parse_numbers(char **ag , std::vector<int> &vector_sequence,   std::deque<int> &deque_sequence);
int check_number(std::string &number , std::vector<int> &vector_sequence);
void    sort_vector( std::vector<int> &vector_sequence);
void    sort_deque(std::deque <int> & deque_sequence);
#endif