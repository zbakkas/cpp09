 
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
// 20 =>
// 37 47 9 54 25 60 92 83 29 27 18 17 22 57 31 79 91 78 34 48 
void    sort_vector( std::vector<int> &vector_sequence)
{
    size_t  i;
    size_t  j;
    clock_t start;
    clock_t end;
    std::vector<int>::iterator insertion_point;

    i = 0;
    int is_pended =-1;
    std::vector<int> vector_main;
    std::vector<int> vector_pend;
    int jacobstal[16]= {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923};

 
    print_vector('b',vector_sequence);///
    start = clock();
    if (vector_sequence.size() % 2 != 0)
        is_pended = vector_sequence[vector_sequence.size() - 1];
    // std::cout << "is_pended: " << is_pended << std::endl;
    while (i < vector_sequence.size() && i + 1 < vector_sequence.size())
    {
        vector_main.push_back((std::max(vector_sequence[i], vector_sequence[i + 1])));
        vector_pend.push_back((std::min(vector_sequence[i], vector_sequence[i + 1])));
        i += 2;
    }

    if (is_pended != -1)
        vector_pend.push_back(is_pended);

    std::cout << " => vector_pend B"  << std::endl;//
    for(i = 0; i < vector_pend.size(); i++)//
        std::cout << vector_pend[i] << " ";//
    std::cout << std::endl;//

    std::cout << "vector_main B"  << std::endl;//
    for(i = 0; i < vector_main.size(); i++)//
        std::cout << vector_main[i] << " ";//
    std::cout << std::endl;//

    std::sort(vector_main.begin(), vector_main.end());

    std::cout << "vector_main A"  << std::endl;//
    for(i = 0; i < vector_main.size(); i++)//
        std::cout << vector_main[i] << " ";//
    std::cout << std::endl;//

    vector_main.insert(vector_main.begin(), vector_pend[0]);

      std::cout << "vector_main A 2"  << std::endl;//
    for(i = 0; i < vector_main.size(); i++)//
        std::cout << vector_main[i] << " ";//
    std::cout << std::endl;//

    vector_pend.erase(vector_pend.begin());

    std::cout << "=> vector_pend A"  << std::endl;//
    for(i = 0; i < vector_pend.size(); i++)//
        std::cout << vector_pend[i] << " ";//
    std::cout << std::endl;//

///////////////////////patre 2////////////////////////

    for (i =2 ; i < vector_pend.size(); i++)//9
    {
        j = jacobstal[i];
        if (j > vector_pend.size())
        {
            std::cout << "j => vector_pend.size() " << j << std::endl;
            break;
        }
        insertion_point = std::lower_bound(vector_main.begin(), vector_main.end(), vector_pend[j - 1]);
        
        std::cout << "insertion_point " << *insertion_point << std::endl;

        vector_main.insert(insertion_point, vector_pend[j - 1]);
        vector_pend.erase(vector_pend.begin() + (j - 1));

    }

    std::cout << "vector_main A for"  << std::endl;//
    for(i = 0; i < vector_main.size(); i++)//
        std::cout << vector_main[i] << " ";//
    std::cout << std::endl;//

    std::cout << " => vector_pend A for"  << std::endl;//
    for(i = 0; i < vector_pend.size(); i++)//
        std::cout << vector_pend[i] << " ";//
    std::cout << std::endl;//

    for (i =0; i < vector_pend.size() ; i++)
    {
        insertion_point = std::lower_bound(vector_main.begin(), vector_main.end(), vector_pend[i]);
        vector_main.insert(insertion_point, vector_pend[i]);
    }
    end = clock();
    vector_sequence = vector_main;
    // print_vector('a',vector_sequence);//////
    // std::cout   << "Time to process a range of "
    //             /*<< this->number_of_elements*/
    //             <<  " elements with std::vector\t: "
    //             << end - start
    //             << " us"
    //             << std::endl;
}


void sort_vector2(std::vector<int> &vector_sequence)
{
    size_t i, j;
    clock_t start, end;
    std::vector<int>::iterator insertion_point;

    std::vector<int> vector_main; // Main vector (sorted during the process)
    std::vector<int> vector_pend; // Pending elements
    int jacobstal[14] = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731};

    // Step 1: Split into pairs
    int is_pended = -1;
    if (vector_sequence.size() % 2 != 0)
        is_pended = vector_sequence.back(); // Handle odd size case

    for (i = 0; i + 1 < vector_sequence.size(); i += 2) 
    {
        int max_val = std::max(vector_sequence[i], vector_sequence[i + 1]);
        int min_val = std::min(vector_sequence[i], vector_sequence[i + 1]);
        vector_main.push_back(max_val);
        vector_pend.push_back(min_val);
    }
    if (is_pended != -1)
        vector_pend.push_back(is_pended); // Add the leftover element to pending

    // Step 2: Sort the main group
    std::sort(vector_main.begin(), vector_main.end());

    // Step 3: Iteratively insert pending elements using Jacobsthal numbers
    for (i = 2; i < vector_pend.size(); ++i) 
    {
        j = jacobstal[i];
        if (j > vector_pend.size())
            break; // If Jacobsthal index exceeds vector_pend size, stop
        insertion_point = std::lower_bound(vector_main.begin(), vector_main.end(), vector_pend[j - 1]);
        vector_main.insert(insertion_point, vector_pend[j - 1]);
        vector_pend.erase(vector_pend.begin() + (j - 1));
    }

    // Step 4: Insert remaining pending elements into the main group
    for (i = 0; i < vector_pend.size(); ++i) {
        insertion_point = std::lower_bound(vector_main.begin(), vector_main.end(), vector_pend[i]);
        vector_main.insert(insertion_point, vector_pend[i]);
    }

    // Step 5: Output results
    vector_sequence = vector_main; // Update the original vector
    end = clock();

    print_vector('a', vector_sequence); // Print sorted vector
    std::cout << "Time to process a range of "
              << vector_sequence.size() << " elements with std::vector: "
              << end - start << " us" << std::endl;
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