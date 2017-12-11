#include "KnapsackSet.h"
#include <algorithm>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::max;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

void KnapsackSet::AddItem(const string &name, int value, int cost)
{
	m_items[name] = pair<int, int>(value, cost);
}

int KnapsackSet::GetValue(const std::string &name) const
{
	if (m_items.count(name) > 0)
		return m_items.at(name).first;
	return -1;
}

int KnapsackSet::GetCost(const std::string &name) const
{
	if (m_items.count(name) > 0)
		return m_items.at(name).second;
	return -1;
}

int KnapsackSet::Knapsack(const int maxCost)
{
	if (maxCost < 1 || m_items.size() < 1)
		return -1;

	vector<vector<int>> grid(m_items.size(), vector<int>(maxCost));
//	for (size_t i = 0; i <= m_items.size(); ++i)
	for (std::unordered_map<string, std::pair<int, int>>::const_iterator it = m_items.begin(); it != m_items.end(); ++it)
	{
		cout << it->first << endl;
/*		for (size_t j = 0; j <= maxCost; ++j)
		{
			if (i == 0 || j == 0)
				grid[i][j] = 0;
			else
				grid[i][j] = max()
		}*/
	}

	return grid[grid.size() - 1][maxCost - 1];
}