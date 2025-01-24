 
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

void    print_deque(char c ,std::deque<int> &deque_sequence)
{
    size_t i;

    i = 0;
    if (c == 'b')
        std::cout << "Before:\t";
    else
        std::cout << "After:\t";
    while (i < deque_sequence.size())
    {
        if (i + 1 == deque_sequence.size())
            std::cout << deque_sequence[i] << std::endl;
        else
            std::cout << deque_sequence[i] << " ";
        ++i;
    }
}
// 20 =>
// 37 47 9 54 25 60 92 83 29 27 18 17 22 57 31 79 91 78 34 48 
// void    sort_vector( std::vector<int> &vector_sequence)
// {
//     size_t  i;
//     size_t  j;

//     std::vector<int>::iterator insertion_point;

//     i = 0;
//     int is_pended =-1;
//     std::vector<int> vector_main;
//     std::vector<int> vector_pend;
//     int jacobsthal[16]= {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923};

 
    
//     if (vector_sequence.size() % 2 != 0)
//         is_pended = vector_sequence[vector_sequence.size() - 1];
//     // std::cout << "is_pended: " << is_pended << std::endl;
//     while (i < vector_sequence.size() && i + 1 < vector_sequence.size())
//     {
//         vector_main.push_back((std::max(vector_sequence[i], vector_sequence[i + 1])));
//         vector_pend.push_back((std::min(vector_sequence[i], vector_sequence[i + 1])));
//         i += 2;
//     }

//     if (is_pended != -1)
//         vector_pend.push_back(is_pended);

//     std::sort(vector_main.begin(), vector_main.end());
//     vector_main.insert(vector_main.begin(), vector_pend[0]);
//     vector_pend.erase(vector_pend.begin());

//     for (i =2 ; i < vector_pend.size(); i++)//9
//     {
//         j = jacobsthal[i];
//         if (j > vector_pend.size())
//         {
//             break;
//         }
//         insertion_point = std::lower_bound(vector_main.begin(), vector_main.end(), vector_pend[j - 1]);
//         vector_main.insert(insertion_point, vector_pend[j - 1]);
//         vector_pend.erase(vector_pend.begin() + (j - 1));

//     }

//     for (i =0; i < vector_pend.size() ; i++)
//     {
//         insertion_point = std::lower_bound(vector_main.begin(), vector_main.end(), vector_pend[i]);
//         vector_main.insert(insertion_point, vector_pend[i]);
//     }
    
//     vector_sequence = vector_main;
// }



// void    sort_deque(std::deque <int> & deque_sequence)
// {
//     size_t i;
//     size_t j;
//     std::deque<int>::iterator insertion_point;

//     i = 0;
//         int is_pended =0;
//     std:: deque<int>  deque_main;
//     std:: deque<int>  deque_pend;
//     int jacobsthal[16]= {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923};
//     is_pended = -1;

//     if (deque_sequence.size() % 2 != 0)
//         is_pended = deque_sequence[deque_sequence.size() - 1];
//     while (i < deque_sequence.size() && i + 1 < deque_sequence.size())
//     {
//         deque_main.push_back((std::max(deque_sequence[i], deque_sequence[i + 1])));
//         deque_pend.push_back((std::min(deque_sequence[i], deque_sequence[i + 1])));
//         i += 2;
//     }
//     if (is_pended != -1)
//         deque_pend.push_back(is_pended);
//     std::sort(deque_main.begin(), deque_main.end());
//     deque_main.insert(deque_main.begin(), deque_pend[0]);
//     deque_pend.erase(deque_pend.begin());

//     for (i=2; i < deque_pend.size() ; i++)
//     {
//         j = jacobsthal[i];
//         if (j > deque_pend.size())
//             break;
//         insertion_point = std::lower_bound(deque_main.begin(), deque_main.end(), deque_pend[j - 1]);
//         deque_main.insert(insertion_point, deque_pend[j - 1]);
//         deque_pend.erase(deque_pend.begin() + (j - 1));
//     }

//     for (i =0; i < deque_pend.size();i++)
//     {
//         insertion_point = std::lower_bound(deque_main.begin(), deque_main.end(), deque_pend[i]);
//         deque_main.insert(insertion_point, deque_pend[i]);
//     }
//     deque_sequence = deque_main;


// }


