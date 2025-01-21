 
 #include "PmergeMe.hpp"

int check_number(std::string &number)
{
    size_t  i;
    
    i = 0;
    if (number[i] == '+')
        ++i;
    while (i < number.size())
    {
        if (!isdigit(number[i]))
            return (1);
        ++i;
    }
    return (0);
}

int parse_numbers(char **ag , std::vector<int> &vector_sequence, std::deque<int> &deque_sequence)
{
    size_t i;
    std::string number;

    i = 1;
    while (ag[i])
    {
        number = ag[i];
        if (check_number(number))
            return (1);
        vector_sequence.push_back(atoi(ag[i]));
        deque_sequence.push_back(atoi(ag[i]));
        ++i;
        // number_of_elements++;
    }
    return (0);
}
void    print_vector(char c ,std::vector<int> &vector_sequence)
{
    size_t i;

    i = 0;
    if (c == 'b')
        std::cout << "Before:\t";
    else
        std::cout << "After:\t";
    while (i < vector_sequence.size())
    {
        if (i + 1 == vector_sequence.size())
            std::cout << vector_sequence[i] << std::endl;
        else
            std::cout << vector_sequence[i] << " ";
        ++i;
    }
}
void    sort_vector( std::vector<int> &vector_sequence)
{
    size_t  i;
    size_t  j;
    clock_t start;
    clock_t end;
    std::vector<int>::iterator insertion_point;

    i = 0;
    int is_pended =0;
    std::vector<int> vector_main;
    std::vector<int> vector_pend;
    int jacobstal[14];
    print_vector('b',vector_sequence);///
    start = clock();
    if (vector_sequence.size() % 2 != 0)
        is_pended = vector_sequence[vector_sequence.size() - 1];
    while (i < vector_sequence.size() && i + 1 < vector_sequence.size())
    {
        vector_main.push_back((std::max(vector_sequence[i], vector_sequence[i + 1])));
        vector_pend.push_back((std::min(vector_sequence[i], vector_sequence[i + 1])));
        i += 2;
    }
    if (is_pended != -1)
        vector_pend.push_back(is_pended);
    std::sort(vector_main.begin(), vector_main.end());
    vector_main.insert(vector_main.begin(), vector_pend[0]);
    vector_pend.erase(vector_pend.begin());
    i = 2;
    while (i < vector_pend.size())
    {
        j = jacobstal[i];
        if (j > vector_pend.size())
            break;
        insertion_point = std::lower_bound(vector_main.begin(), vector_main.end(), vector_pend[j - 1]);
        vector_main.insert(insertion_point, vector_pend[j - 1]);
        vector_pend.erase(vector_pend.begin() + (j - 1));
        ++i;
    }
    i = 0;
    while (i < vector_pend.size())
    {
        insertion_point = std::lower_bound(vector_main.begin(), vector_main.end(), vector_pend[i]);
        vector_main.insert(insertion_point, vector_pend[i]);
        ++i;
    }
    end = clock();
    vector_sequence = vector_main;
    print_vector('a',vector_sequence);//////
    std::cout   << "Time to process a range of "
                /*<< this->number_of_elements*/
                <<  " elements with std::vector\t: "
                << end - start
                << " us"
                << std::endl;
}



void    sort_deque(std::deque <int> & deque_sequence)
{
    size_t i;
    size_t j;
    clock_t start;
    clock_t end;
    std::deque<int>::iterator insertion_point;

    i = 0;
        int is_pended =0;
    std:: deque<int>  deque_main;
    std:: deque<int>  deque_pend;
    int jacobstal[14];
    is_pended = -1;
    start = clock();
    if (deque_sequence.size() % 2 != 0)
        is_pended = deque_sequence[deque_sequence.size() - 1];
    while (i < deque_sequence.size() && i + 1 < deque_sequence.size())
    {
        deque_main.push_back((std::max(deque_sequence[i], deque_sequence[i + 1])));
        deque_pend.push_back((std::min(deque_sequence[i], deque_sequence[i + 1])));
        i += 2;
    }
    if (is_pended != -1)
        deque_pend.push_back(is_pended);
    std::sort(deque_main.begin(), deque_main.end());
    deque_main.insert(deque_main.begin(), deque_pend[0]);
    deque_pend.erase(deque_pend.begin());
    i = 2;
    while (i < deque_pend.size())
    {
        j = jacobstal[i];
        if (j > deque_pend.size())
            break;
        insertion_point = std::lower_bound(deque_main.begin(), deque_main.end(), deque_pend[j - 1]);
        deque_main.insert(insertion_point, deque_pend[j - 1]);
        deque_pend.erase(deque_pend.begin() + (j - 1));
        ++i;
    }
    i = 0;
    while (i < deque_pend.size())
    {
        insertion_point = std::lower_bound(deque_main.begin(), deque_main.end(), deque_pend[i]);
        deque_main.insert(insertion_point, deque_pend[i]);
        ++i;
    }
    end = clock();
    deque_sequence = deque_main;
    std::cout   << "Time to process a range of "
                /*<< number_of_elements*/
                <<  " elements with std::deque\t: "
                << end - start
                << " us"
                << std::endl;
}