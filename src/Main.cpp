#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <iterator>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

int LinearSearch(const vector<int> &l, int n);
int BinarySearch(const vector<int> &l, int i);
int FindSmallestElement(const vector<int> &l, size_t i = 0);
int SelectionSort(vector<int> &l);

int main(int argc, char *argv[])
{
	// Fill vector with random numbers
	random_device rnd_device;
	mt19937 mersenne_engine(rnd_device());
	uniform_int_distribution<int> dist(0, 9999);

	auto generator = std::bind(dist, mersenne_engine);
	vector<int> test_vector(3000);
	generate(begin(test_vector), end(test_vector), generator);

	// Generate sorted vector
	vector<int> sorted_vector(100000);
	iota(begin(sorted_vector), end(sorted_vector), 0);

	LinearSearch(sorted_vector, 999);
	BinarySearch(sorted_vector, 999);
	SelectionSort(test_vector);

	//	for (int x : test_vector)
	//		cout << x << " ";
	//	getchar();

	return 0;
}

/**
 * @brief Linear search implementation, with O(n) complexity
 * @param const vector<int> & l -> Sorted list of elements
 * @param int n -> Element that we want to find in that list
 * @return int -> Index of the element in the list, -1 if not found
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
 * @brief Binary search implementation, with O(log n) complexity
 * @param std::vector<int> l -> Sorted list of elements
 * @param int i -> Element that we want to find in that list
 * @return int -> Index of the element in the list, -1 if not found
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
 * @brief Selection Sort implementation (ascending), with O(n^2) complexity
 * @param std::vector<int> & l -> List of elements that must be sorted
 * @return int -> 0: success / -1: the list cannot be sorted
 */
int SelectionSort(vector<int> &l)
{
	if (l.size() < 1)
		return -1;

	int smallest_index = 0;

	for (size_t i = 0; i < l.size(); ++i)
	{
		smallest_index = FindSmallestElement(l, i);
		swap(l[smallest_index], l[i]);
	}

	return 0;
}