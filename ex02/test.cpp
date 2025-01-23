#include <iostream>
#include <vector>
#include <algorithm>

// Function to print a vector
void printVector(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

// Function to generate Jacobsthal numbers up to a given size
std::vector<int> generateJacobsthalNumbers(size_t size) {
    std::vector<int> jacobsthal = {0, 1};
    while (jacobsthal.back() < size) {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 
                      2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

// Recursive Ford-Johnson-inspired sorting function
void recursiveSort(std::vector<int>& arr) {
    if (arr.size() <= 1) return; // Base case: single element is already sorted

    std::vector<int> larger, smaller;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (i + 1 < arr.size()) {
            if (arr[i] > arr[i + 1]) {
                larger.push_back(arr[i]);
                smaller.push_back(arr[i + 1]);
            } else {
                larger.push_back(arr[i + 1]);
                smaller.push_back(arr[i]);
            }
        } else {
            smaller.push_back(arr[i]); // Struggler
        }
    }

    // Recursively sort both groups
    recursiveSort(larger);
    recursiveSort(smaller);

    // Merge the sorted groups
    std::vector<int> jacobsthal = generateJacobsthalNumbers(smaller.size());
    std::vector<int> result = larger; // Start with the sorted larger group
    for (size_t i = 0; i < smaller.size(); ++i) {
        size_t idx = jacobsthal[i] < smaller.size() ? jacobsthal[i] : i;
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), smaller[idx]);
        result.insert(pos, smaller[idx]);
    }

    arr = result; // Update the original array
}

int main() {
    // Input sequence
    std::vector<int> sequence = {8, 7, 100, 27, 46, 11, 53, 2, 0};

    std::cout << "Original sequence: ";
    printVector(sequence);

    // Sort the sequence
    recursiveSort(sequence);

    std::cout << "Sorted sequence: ";
    printVector(sequence);

    return 0;
}
