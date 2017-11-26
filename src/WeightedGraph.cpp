#include "WeightedGraph.h"
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

const int INF = std::numeric_limits<unsigned int>::max();

/**
 * @brief Add a hash table of adjacent nodes S with associated costs for a given node N.
 * @param const string &node -> A given node N to which we want to add adjacent nodes with associated costs.
 * @param const unordered_map<string, int> &neighbors -> A set S of adjacent nodes that we want to add to N.
 * @return void
 * @details if N already exists in the graph, the nodes in S will be appended to its existing adjacency list.
 */
void WeightedGraph::AddNeighbors(const string &node, const unordered_map<string, int> &neighbors)
{
	unordered_map<string, unordered_map<string, int>>::iterator it = m_adjacency_list.find(node);
	if (it != m_adjacency_list.end())
		it->second.insert(neighbors.begin(), neighbors.end());
	else
		m_adjacency_list.emplace(node, neighbors);
}

const int *WeightedGraph::GetCost(const string &source, const string &target) const
{
	if (m_adjacency_list.count(source) > 0)
		if (m_adjacency_list.at(source).count(target) > 0)
			return &m_adjacency_list.at(source).at(target);

	return nullptr;
}

void WeightedGraph::DisplayCost(const string &source, const string &target) const
{
	if (nullptr != GetCost(source, target))
		cout << "The cost going from node " << source << " to node " << target << " is = " 
			<< *GetCost(source, target) << endl;
	else
		cout << "There is no path from node " << source << " to node " << target << endl;
}

bool WeightedGraph::Dijkstra(const std::string &start, const std::string &target) const
{
	return true;
}

/**
* @brief Display the graph as an adjacency list
* @return void
*/
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