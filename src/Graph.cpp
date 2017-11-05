#include <iostream>
#include <queue>
#include <unordered_set>
#include "Graph.h"

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::queue;
using std::set;
using std::string;
using std::unordered_set;

/**
 * @brief Add a set of adjacent nodes S for a given node N. 
 * @param const string & node -> A given node N to which we want to add adjacent nodes.
 * @param const set<string> & neighbors A set S of adjacent nodes that we want to add to a given node.
 * @return void
 * @details If N already exists in the graph, the nodes in S will be appended to its adjacency list.
 */
void Graph::AddNeighbors(const string &node, const set<string> &neighbors)
{
	map<string, set<string>>::iterator it = m_adjacency_list.find(node);
	if (it != m_adjacency_list.end())
		it->second.insert(neighbors.begin(), neighbors.end());
	else
		m_adjacency_list.emplace(node, neighbors);
}

/**
 * @brief Get the neighbors of a given node
 * @param const string & node -> Node of which we want to get its list of adjacent nodes
 * @return const set<string>& -> Adjacent nodes returned
 * @details map::at throws an out_of_range exception if the node does not exist in the graph
 */
const set<string>& Graph::GetNeighbors(const string &node) const
{
	return m_adjacency_list.at(node);
}

/**
 * @brief Display the graph as an adjacency list
 * @return void
 */
void Graph::Display() const
{
	for (map<string, set<string>>::const_iterator it = m_adjacency_list.begin(); it != m_adjacency_list.end(); ++it)
	{
		cout << it->first << " adjacent to [";
		if (it->second.size() > 0) 
		{
			cout << *(it->second.begin());
			for (set<string>::const_iterator it2 = next(it->second.begin()); it2 != it->second.end(); ++it2)
				cout << ", " << *it2;
		}
		cout << "]" << endl;
	}
}

/**
 * @brief Breadth First Search implementation, looks for the shortest path from S to T 
 * @param const string & start -> Starting node S
 * @param const string & target -> Target node T
 * @return bool -> True if a path was found, false otherwise
 * @details O(V+E), where V is number of nodes and E is number of edges and O(1) <= O(E) <= O(V^2)
 */
bool Graph::BreadthFirstSearch(const string &start, const string &target) const
{
	// Search Queue
	queue<string> open_set;
	// Visited nodes
	unordered_set<string> closed_set;
	string node;

	for (const string &node : GetNeighbors(start))
		open_set.push(node);

	while (!open_set.empty())
	{
		node = open_set.front();
		open_set.pop();
		if (closed_set.find(node) == closed_set.end())
		{
			if (target == node)
				return true;
			else
			{
				// This if only to skip nodes that are not in the graph
				if (m_adjacency_list.count(node) > 0)
				{
					for (const string &n : GetNeighbors(node))
						open_set.push(n);
				}
				closed_set.insert(node);
			}
		}
	}

	return false;
}