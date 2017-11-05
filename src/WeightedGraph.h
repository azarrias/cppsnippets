#ifndef __WEIGHTED_GRAPH__
#define __WEIGHTED_GRAPH__

#include <unordered_map>

class WeightedGraph
{
public:
	void WeightedGraph::AddNeighbors(const std::string &node, const std::unordered_map<std::string, int> &neighbors);
private:
	std::unordered_map<std::string, std::unordered_map<std::string, int>> m_adjacency_list;
};

#endif // __WEIGHTED_GRAPH__
