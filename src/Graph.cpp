#include "Graph.h"

void Graph::AddNeighbors(const std::string &node, const std::set<std::string> &neighbors)
{
	// Add neighbors to node if node previously exists in graph
	std::map<std::string, std::set<std::string>>::iterator it = m_adjacency_list.find(node);
	if (it != m_adjacency_list.end())
		it->second.insert(neighbors.begin(), neighbors.end());
	// Else insert node in graph with specified neighbors
	else
		m_adjacency_list.emplace(node, neighbors);
}