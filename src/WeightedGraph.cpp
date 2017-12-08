#include "WeightedGraph.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

using std::cout;
using std::endl;
using std::min_element;
using std::pair;
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

const int* WeightedGraph::GetCost(const string &source, const string &target) const
{
	if (m_adjacency_list.count(source) > 0)
		if (m_adjacency_list.at(source).count(target) > 0)
			return &m_adjacency_list.at(source).at(target);

	return nullptr;
}

const unordered_map<string, int>* WeightedGraph::GetNeighbors(const string &node) const
{
	if (m_adjacency_list.count(node) > 0)
		return &m_adjacency_list.at(node);

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

/**
 * @brief Calculate the shortest path for a weighted graph using Dijkstra's algorithm.
 * @param const std::string & start -> Starting node S
 * @param const std::string & target -> Target node T
 * @return bool -> True if a path was found, false otherwise
 * @details Dijkstra's algorithm only works when all weights are positive (otherwise, use Bellman-Ford)
 */
bool WeightedGraph::Dijkstra(const std::string &start, const std::string &target) const
{
	unordered_map<string, int> closed_set;
	unordered_map<string, int> open_set;
	unordered_map<string, string> parents;
	unordered_map<string, int>::const_iterator it_N;
	string N;
	int N_cost, K_cost;

	open_set.insert(pair<string, int>(start, 0));

	while (1)
	{
		it_N = min_element(open_set.begin(), open_set.end(),
			[](const pair<string, int>& l, const pair<string, int>& r) -> bool { return l.second < r.second; });

		N = it_N->first;
		N_cost = it_N->second;

		closed_set.insert(*it_N);
		open_set.erase(N);

		if (N == target)
			return true;
		else if (nullptr == GetNeighbors(N))
			return false;
		else
		{
			for (unordered_map<string, int>::const_iterator it_K = GetNeighbors(N)->begin(); it_K != GetNeighbors(N)->end(); ++it_K)
			{
				if (closed_set.find(it_K->first) == closed_set.end())
				{
					K_cost = it_K->second + N_cost;
					if (open_set.find(it_K->first) == open_set.end())
					{
						open_set.emplace(pair<string, int>(it_K->first, K_cost));
						parents.emplace(pair<string, string>(it_K->first, N));
					}
					else if (K_cost < open_set.find(it_K->first)->second)
					{
						open_set.at(it_K->first) = K_cost;
						parents.at(it_K->first) = N;
					}
				}
			}
		}
	}
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
