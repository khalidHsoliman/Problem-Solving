#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <limits>

#include "Graph.h"
#include "PriorityQueue.h"

using namespace std;

class ShortestPath
{
public:
	
	ShortestPath(Graph &graph, int startNode, int endNode);

	void updateGraph(Graph &graph, int startNode, int endNode);
	bool exists();
	list<int> path();
	double pathCost();

private:
	void initialize(Graph &graph);
	bool run(int startNode, int endNode);

	Graph *currGraph;
	PriorityQueue pQueue;
	int currStartNode;
	int currEndNode;
	bool pathExists;
	vector<bool> visited;
	vector<int> previous;
};

inline bool ShortestPath::exists()
{
	return pathExists;
}

inline double ShortestPath::pathCost()
{
	return currGraph->getNodeValue(currEndNode); 
}


