#ifndef __GRAPH__
#define __GRAPH__

#include <map>
#include <string>
#include <set>

class Graph
{
public:
	void AddNeighbors(const std::string &node, const std::set<std::string> &neighbors);
	void Display() const;
private:
	std::map<std::string, std::set<std::string>> m_adjacency_list;
};

#endif // __GRAPH__