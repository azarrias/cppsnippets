#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <iterator>
#include <algorithm>
#include <functional>
#include <numeric>
#include "Timer.h"
#include "Graph.h"
#include "WeightedGraph.h"

using std::vector;
using std::bind;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::cout;
using std::endl;
using std::swap;
using std::string;

int LinearSearch(const vector<int> &l, int n);
int BinarySearch(const vector<int> &l, int i);
int FindSmallestElement(const vector<int> &l, size_t i = 0);
void SelectionSort(vector<int> &l);
void QuickSort(vector<int> &l);
void QuickSort(vector<int> &l, size_t start, size_t end);

int main(int argc, char *argv[])
{
	static const size_t SORTED_VECTOR_SIZE = 10000000;
	static const size_t TEST_VECTOR_SIZE = 5000;

	// Fill vector with random numbers
	random_device rnd_device;
	mt19937 mersenne_engine(rnd_device());
	uniform_int_distribution<int> dist(0, 9999);

	auto generator = std::bind(dist, mersenne_engine);
	vector<int> test_vector(TEST_VECTOR_SIZE);
	generate(begin(test_vector), end(test_vector), generator);

	// Generate sorted vector
	vector<int> sorted_vector(SORTED_VECTOR_SIZE);
	iota(begin(sorted_vector), end(sorted_vector), 0);

	//vector<int> test_vector2 = { 6, 1, 4, 9, 0, 3, 5, 2, 7, 8 };
	
	Timer timer;
	timer.Start();
	LinearSearch(sorted_vector, 9999999);
	cout << "Linear Search (" << SORTED_VECTOR_SIZE << " elements): took " 
		<< timer.Elapsed() << " milliseconds." << endl;

	timer.Start();
	BinarySearch(sorted_vector, 9999999);
	cout << "Binary Search (" << SORTED_VECTOR_SIZE << " elements): took " 
		<< timer.Elapsed() << " milliseconds." << endl;

	timer.Start();
	SelectionSort(test_vector);
	cout << "Selection Sort (" << TEST_VECTOR_SIZE << " elements): took "
		<< timer.Elapsed() << " milliseconds." << endl;

	// Test quick sort
	timer.Start();
	QuickSort(test_vector);
	cout << "Quick Sort (" << TEST_VECTOR_SIZE << " elements): took "
		<< timer.Elapsed() << " milliseconds." << endl;

	//for (int x : test_vector2)
	//	cout << x << " ";
	//	getchar();

	// Create graph and display it's adjacency list
	Graph my_graph;
	my_graph.AddNeighbors("Sant Andreu", { "Fabra i Puig", "Torras i Bages" });
	my_graph.AddNeighbors("Fabra i Puig", { "Sant Andreu", "La Sagrera"});
	my_graph.AddNeighbors("La Sagrera", { "Fabra i Puig", "Congres", "Camp de l'Arpa", "Navas", "Onze de Setembre" });
	my_graph.AddNeighbors("Navas", { "Clot", "La Sagrera" });
	my_graph.AddNeighbors("Clot", { "Glories", "Navas", "Encants", "Bac de Roda" });
	my_graph.AddNeighbors("WIP", {});
	my_graph.Display();

	if (my_graph.BreadthFirstSearch("WIP", "Clot"))
		cout << "Path found";
	else
		cout << "Path not found";

	// Create weighted graph and display it's adjacency list
	WeightedGraph w_graph;
	w_graph.AddNeighbors("Start", { { "A", 6 }, {"B", 2} });
	w_graph.AddNeighbors("B", { {"A", 3}, {"Fin", 5} });
	w_graph.AddNeighbors("A", { {"Fin", 1} });

	return 0;
}

/**
 * @brief Linear search implementation
 * @param const vector<int> & l -> Sorted list of elements
 * @param int n -> Element that we want to find in that list
 * @return int -> Index of the element in the list, -1 if not found
 * @details Worst-Case: O(n)
 */
int LinearSearch(const vector<int> &l, int n)
{
	for (size_t i = 0; i < l.size(); ++i)
	{
		if (l[i] == n)
			return i;
	}

	return -1;
}

/**
 * @brief Binary search implementation
 * @param std::vector<int> l -> Sorted list of elements
 * @param int i -> Element that we want to find in that list
 * @return int -> Index of the element in the list, -1 if not found
 * @details Worst-Case: O(log n)
 */
int BinarySearch(const vector<int> &l, int i) 
{
	int low = 0;
	int high = l.size() - 1;
	int middle;
	int guess;

	while (low <= high) 
	{
		middle = (high + low) / 2;
		guess = l[middle];
		if (guess == i)
			return i;
		else if (guess > i)
			high = middle - 1;
		else
			low = middle + 1;
	}

	return -1;
}

/**
 * @brief Finds the smallest element in a list, with O(n) complexity
 * @param const std::vector<int> & l -> List of elements
 * @param size_t i -> Starting index (optional)
 * @return int -> Index of the smallest element in the list / -1: The element cannot be found in the list
 */
int FindSmallestElement(const vector<int> &l, size_t i)
{
	if (l.size() < 1 || l.size() <= i)
		return -1;

	int smallest = l[i];
	int smallest_index = i;

	for (; i < l.size(); ++i)
	{
		if (l[i] < smallest)
		{
			smallest = l[i];
			smallest_index = i;
		}
	}

	return smallest_index;
}

/**
 * @brief Selection Sort implementation (ascending)
 * @param std::vector<int> & l -> List of elements that must be sorted
 * @return void
 * @details Worst-Case: O(n^2)
 */
void SelectionSort(vector<int> &l)
{
	int smallest_index = 0;

	for (size_t i = 0; i < l.size(); ++i)
	{
		smallest_index = FindSmallestElement(l, i);
		swap(l[smallest_index], l[i]);
	}
}

/**
 * @brief Median of Three for QuickSort partitioning, solves the problem of sorted input
 * @param vector<int> & l -> List of elements to be sorted
 * @param size_t left -> Index to the leftmost element of the list
 * @param size_t right -> Index to the rightmost element of the list
 * @return int -> Value of the pivot to be used in QuickSort
 */
int MedianOfThree(vector<int> &l, size_t left, size_t right)
{
	// Sort the left, center and right elements ascending
	int center = (left + right) / 2;
	if (l[center] < l[left])
		swap(l[left], l[center]);
	if (l[right] < l[left])
		swap(l[left], l[right]);
	if (l[right] < l[center])
		swap(l[center], l[right]);

	// Hide the pivot, by putting it at the end of the container, and return it
	swap(l[center], l[right]);
	return l[right];
}

/**
 * @brief QuickSort implementation (ascending). Performance heavily depends on the choice of an optimal pivot.
 * @param vector<int> & l -> List of elements to be sorted
 * @return void
 * @details Worst-Case: O(n^2), Average-Case: O(n log n)
 */
void QuickSort(vector<int> &l)
{
	QuickSort(l, 0, l.size() - 1);
}

void QuickSort(vector<int> &l, size_t left, size_t right)
{
	int pivot;
	size_t i, j;

	// Base case: Vector with 2 elements
	if (right - left == 1 && l[right] < l[left])
		swap(l[left], l[right]);
	// Recursive case (with more than 2 elements)
	else if (right - left > 1)
	{
		pivot = MedianOfThree(l, left, right);
		i = left;
		j = right - 1;

		while (true)
		{
			while (l[++i] < pivot);
			while (pivot < l[--j]);
			if (i < j)
				swap(l[i], l[j]);
			else
				break;
		}

		// Restore pivot position after hiding it
		swap(l[i], l[right]);

		QuickSort(l, left, i - 1);
		QuickSort(l, i + 1, right);
	}
}
