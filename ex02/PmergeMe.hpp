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
void    print_vector(char c ,std::vector<int> &vector_sequence);
void    print_deque(char c ,std::deque<int> &deque_sequence);



template <typename Container>
void sort_container(Container &container_sequence) 
{
    size_t i = 0, j;
    typename Container::iterator insertion_point;

    int is_pended = -1;
    Container container_main;
    Container container_pend;

    int jacobsthal[16] = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923};

    // Handle odd-sized containers
    if (container_sequence.size() % 2 != 0)
        is_pended = container_sequence[container_sequence.size() - 1];

    // Split container_sequence into main and pend containers
    while (i < container_sequence.size() && i + 1 < container_sequence.size()) {
        container_main.push_back(std::max(container_sequence[i], container_sequence[i + 1]));
        container_pend.push_back(std::min(container_sequence[i], container_sequence[i + 1]));
        i += 2;
    }

    if (is_pended != -1)
        container_pend.push_back(is_pended);

    // Sort the main container
    std::sort(container_main.begin(), container_main.end());

    // Insert the first element from pend into main
    container_main.insert(container_main.begin(), container_pend[0]);
    container_pend.erase(container_pend.begin());

    // Use Jacobsthal sequence to merge pend into main
    for (i = 2; i < container_pend.size(); i++) {
        j = jacobsthal[i];
        if (j > container_pend.size())
            break;

        insertion_point = std::lower_bound(container_main.begin(), container_main.end(), container_pend[j - 1]);
        container_main.insert(insertion_point, container_pend[j - 1]);
        container_pend.erase(container_pend.begin() + (j - 1));
    }

    // Insert the remaining elements from pend into main
    for (i = 0; i < container_pend.size(); i++) {
        insertion_point = std::lower_bound(container_main.begin(), container_main.end(), container_pend[i]);
        container_main.insert(insertion_point, container_pend[i]);
    }

    container_sequence = container_main;
}


#endif