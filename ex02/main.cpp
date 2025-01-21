#include "PmergeMe.hpp"

int main(int ac, char **ag)
{
    std::vector<int> vector_sequence;
    std::deque<int>  deque_sequence;
    if (ac <= 1)
    {
        std::cout << "Error: sequence of numbers needed" << std::endl;
        return (1);
    }
    
    if (parse_numbers(ag,vector_sequence, deque_sequence))
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
    sort_vector(vector_sequence);
    // sort_deque(deque_sequence);
    return (0);
}
