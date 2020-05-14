#include "pch.h"
#include "ShortestPath.h"


#include "ShortestPath.h"

ShortestPath::ShortestPath(Graph &graph, int startNode, int endNode)
{
	updateGraph(graph, startNode, endNode);
}

void ShortestPath::updateGraph(Graph &graph, int startNode, int endNode)
{
	initialize(graph);

	currStartNode = startNode;
	currEndNode = endNode;
	pathExists = run(startNode, endNode);
}

list<int> ShortestPath::path()
{
	if (!exists()) 
		return list<int>();
	else if (currStartNode == currEndNode) 
		return list<int>(2, currStartNode);

	list<int> path;
	int currNode = currEndNode;

	path.push_front(currNode);
	while (previous[currNode] != -1) {
		path.push_front(previous[currNode]);
		currNode = previous[currNode]; 
	}

	return path;
}

void ShortestPath::initialize(Graph &graph)
{
	currGraph = &graph;

	pQueue.clear();
	visited.clear();
	previous.clear();

	for (int i = 0; i < currGraph->getNumOFNodes(); i++) {
		currGraph->setNodeValue(i, numeric_limits<double>::max()); 
		visited.push_back(false); 
		previous.push_back(-1); 
	}
}

bool ShortestPath::run(int startNode, int endNode)
{
	currGraph->setNodeValue(startNode, 0.0); 
	pQueue.push(startNode); 

	int currNode; 
	double distFromStart = 0.0; 
	vector<int> neighbors; 

	while (!pQueue.is_empty()) { 
		currNode = pQueue.pop(); 
		visited[currNode] = true; 
		if (currNode == endNode) return true; 

		// acquire and iterate the neighboring nodes
		currGraph->getNeighbors(currNode, neighbors);
		for (vector<int>::iterator it = neighbors.begin(); it != neighbors.end(); ++it) {
			// compute the shortest distance from the starting node
			distFromStart = currGraph->getNodeValue(currNode) + currGraph->getEdgeValue(currNode, *it);

			// keep the shortest distance if it is less than the current value at the neighboring node AND
			// if the neighboring node has not yet been visited
			if ((distFromStart < currGraph->getNodeValue(*it)) && !visited[*it]) {
				currGraph->setNodeValue(*it, distFromStart); // update the new value
				previous[*it] = currNode; // keep track of the parent node

				if (pQueue.contains(*it)) // u
					pQueue.changePriority(*it, distFromStart);
				else 
					pQueue.push(*it, distFromStart);
			}
		}
	}

	return false; 
}

