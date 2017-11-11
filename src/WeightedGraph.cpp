#include "WeightedGraph.h"
#include <iostream>
#include <string>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

void WeightedGraph::AddNeighbors(const string &node, const unordered_map<string, int> &neighbors)
{
	unordered_map<string, unordered_map<string, int>>::iterator it = m_adjacency_list.find(node);
	if (it != m_adjacency_list.end())
		it->second.insert(neighbors.begin(), neighbors.end());
	else
		m_adjacency_list.emplace(node, neighbors);
}

void WeightedGraph::Display() const
{
	for (unordered_map<string, unordered_map<string, int>>::const_iterator it = m_adjacency_list.begin(); it != m_adjacency_list.end(); ++it)
	{
		cout << it->first << " adjacent to [";
		if (it->second.size() > 0)
		{
			cout << "(" << it->second.begin()->first << ", " << it->second.begin()->second << ")";
			for (unordered_map<string, int>::const_iterator it2 = next(it->second.begin()); it2 != it->second.end(); ++it2)
				cout << ", (" << it2->first << ", " << it2->second << ")";
		}
		cout << "]" << endl;
	}
}