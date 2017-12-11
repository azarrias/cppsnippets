#ifndef __KNAPSACK_SET__
#define __KNAPSACK_SET__

#include <unordered_map>

class KnapsackSet
{
public:
	void AddItem(const std::string &name, int value, int cost);
	int GetCost(const std::string &name) const;
	int GetValue(const std::string &name) const;
	int Knapsack(int maxCost);
private:
	std::unordered_map<std::string, std::pair<int, int>> m_items;
};

#endif // __KNAPSACK_SET__
