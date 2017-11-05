#include "WeightedGraph.h"
#include <string>
#include <unordered_map>

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
