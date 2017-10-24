#include <iostream>
#include <vector>
#include <list>

void BinarySearch(std::vector<int> l, int i);
int FindSmallestElement(std::vector<int> l, size_t i = 0);

int main(int argc, char *argv[])
{
	std::vector<int> my_vector = { 1, 3, 5, 7, 9 };
	std::vector<int> my_vector2 = { 3, 4, 1, 6 };
	std::list<int> my_list = { 1, 3, 5, 7, 9 };
	BinarySearch(my_vector, 3);
	std::cout << FindSmallestElement(my_vector2, 1);
	getchar();
}

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

int FindSmallestElement(std::vector<int> l, size_t i)
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

/*int SelectionSort(std::vector<int> &l)
{
	int smallest_idx;

	while (l.size() > 0)
	{
		smallest_idx = FindSmallestElement(l)
		v.push_back(l.
	}
	for (int element : l)
	{
		v.push_back(l)
	}
}*/