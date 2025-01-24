#include "PmergeMe.hpp"

int main(int ac, char **ag)
{
    std::vector<int> vector_sequence;
    std::deque<int>  deque_sequence;
    clock_t start_v;
    clock_t end_v;
    clock_t start_d;
    clock_t end_d;
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
    print_vector('b', vector_sequence);

    start_v = clock();
    sort_container(vector_sequence);
    end_v = clock();

    start_d = clock();
    sort_container(deque_sequence);
    end_d = clock();

    print_vector('a', vector_sequence);
   print_deque('a', deque_sequence);
    
    std::cout   << "Time to process a range of  v" << vector_sequence.size()<< " " <<static_cast<double>(end_v - start_v) / CLOCKS_PER_SEC *10   << " us" << std::endl;
    std::cout   << "Time to process a range of  d" << deque_sequence.size()<<" " <<static_cast<double>(end_d - start_d) / CLOCKS_PER_SEC *10 << " us"  << std::endl;
    return (0);
}
