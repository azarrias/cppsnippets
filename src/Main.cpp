#include <iostream>
#include <vector>
#include <list>

void BinarySearch(std::vector<int> l, int i);
int FindSmallestElement(const std::vector<int> &l, size_t i = 0);
int SelectionSort(std::vector<int> &l);

int main(int argc, char *argv[])
{
	std::vector<int> my_vector = { 1, 3, 5, 7, 9 };
	std::vector<int> my_vector2 = { 3, 4, 1, 6 };
	std::list<int> my_list = { 1, 3, 5, 7, 9 };
	BinarySearch(my_vector, 3);
	SelectionSort(my_vector2);
	for (int x : my_vector2) 
		std::cout << x << " ";
	getchar();
}

/**
 * @brief -> Binary search implementation, with O(log n) complexity
 * @param std::vector<int> l -> Sorted list of elements
 * @param int i -> Element that we want to find in that list
 * @return void
 */
void BinarySearch(std::vector<int> l, int i) 
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
		{
			std::cout << i << " is found in position " << middle << std::endl;
			return;
		}
		else if (guess > i)
			high = middle - 1;
		else
			low = middle + 1;
	}

	std::cout << i << " can't be found" << std::endl;
}

/**
 * @brief Finds the smallest element in a list, with O(n) complexity
 * @param const std::vector<int> & l -> List of elements
 * @param size_t i -> Starting index (optional)
 * @return int -> Index of the smallest element in the list / -1: The element cannot be found in the list
 */
int FindSmallestElement(const std::vector<int> &l, size_t i)
{
	if (l.size() < 1 || l.size() <= i)
		return -1;

	int smallest = l[i];
	int smallest_index = i;

	for (i + 1; i < l.size(); ++i)
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
int SelectionSort(std::vector<int> &l)
{
	if (l.size() < 1)
		return -1;

	int smallest_index = 0;

	for (size_t i = 0; i < l.size(); ++i)
	{
		smallest_index = FindSmallestElement(l, i);
		std::swap(l[smallest_index], l[i]);
	}

	return 0;
}