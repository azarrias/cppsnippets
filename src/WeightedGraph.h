#ifndef __WEIGHTED_GRAPH__
#define __WEIGHTED_GRAPH__

#include <unordered_map>

class WeightedGraph
{
public:
	void AddNeighbors(const std::string &node, const std::unordered_map<std::string, int> &neighbors);
	const int *GetCost(const std::string &source, const std::string &target) const;
	void DisplayCost(const std::string &source, const std::string &target) const;
	bool Dijkstra(const std::string &start, const std::string &target) const;
	void Display() const;
private:
	std::unordered_map<std::string, std::unordered_map<std::string, int>> m_adjacency_list;
};

#endif // __WEIGHTED_GRAPH__
