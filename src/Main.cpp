#include <iostream>
#include <vector>

void BinarySearch(std::vector<int> l, int i);

int main(int argc, char *argv[])
{
	std::vector<int> my_list = { 1, 3, 5, 7, 9 };
	BinarySearch(my_list, 3);
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