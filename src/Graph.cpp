#include <iostream>
#include "Graph.h"

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::set;
using std::string;

void Graph::AddNeighbors(const string &node, const set<string> &neighbors)
{
	// Add neighbors to node if node previously exists in graph
	map<string, set<string>>::iterator it = m_adjacency_list.find(node);
	if (it != m_adjacency_list.end())
		it->second.insert(neighbors.begin(), neighbors.end());
	// Else insert node in graph with specified neighbors
	else
		m_adjacency_list.emplace(node, neighbors);
}

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
