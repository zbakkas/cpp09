#pragma once

#include <ctime>

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <ctime>
#include <exception>

class FordJohnsonAlgorithm
{

public:
	FordJohnsonAlgorithm();

	// main function
	FordJohnsonAlgorithm(FordJohnsonAlgorithm const &other);

	FordJohnsonAlgorithm &operator=(FordJohnsonAlgorithm const &other);

	~FordJohnsonAlgorithm();

	class PmergeVector
	{

	private:
		std::vector<int> vec;
		std::vector<int> positions;
		std::vector<std::pair<int, int> > vecPair;
		std::vector<int> mainChain;
		std::vector<int> pend;
		std::vector<int> jacobSequence;

		void getIntegerSequence(char *av[]);
		// create pair
		void createVectorPairs();
		// sort pairs
		void sortVectorPairs();
		// merge sort
		void merge(std::vector<std::pair<int, int> > &array, int begin, int mid, int end);
		// merge left and right
		void mergeSort(std::vector<std::pair<int, int> > &array, int begin, int end);
		// create main chain and pend;
		void createMainChainAndPend();
		// binary search
		int binarySearch(std::vector<int> array, int target, int begin, int end);
		// generate jacob_insertion_sequence
		void generateJacobInsertionSequence();
		// jacobsthal index
		int jacobsthal(int n);
		// generate positions
		void generatPositions();

		// insert to main chain
		void insertToMainChain();

	public:
		PmergeVector();
		~PmergeVector();
		void applyMergeInsertSort(char *av[]);
		void printBefore();
		void printAfter();
	};

	
	class exception : public std::exception
	{
	public:
		exception();
		virtual ~exception() throw();
		virtual const char *what() const throw();
	};
};