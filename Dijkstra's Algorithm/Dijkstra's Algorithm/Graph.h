#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <chrono> 

using namespace std; 

class Graph 
{
private:
	int numNodes;
	int numEdges; 
	double **adj; 
	vector<int> nodeValues;

public:
	Graph(const int numNodes, const double density, const pair<double, double> distanceRange);
	~Graph() {};
	int getNumOFNodes(); 
	int getNumOfEdges();
	
	bool isAdjacent(int nodeX, int nodeY);
	vector<int> getNeighbors(int nodeX); 

	void addEdge(int nodeX, int nodeY, double dist);
	void deleteEdge(int nodeX, int nodeY);

	int getNodeValue(int nodeX);
	void setNodeValue(int nodeX, int value);

	double getEdgeValue(int nodeX, int nodeY);
	void setEdgeValue(int nodeX, int nodeY, double value);

	friend ostream& operator<<(ostream& os, Graph& g);
};

inline int Graph::getNumOFNodes() { return numNodes; }
inline int Graph::getNumOfEdges() { return numEdges; }
inline int Graph::getNodeValue(int nodeX) { return nodeValues[nodeX]; }
inline double Graph::getEdgeValue(int nodeX, int nodeY) { return adj[nodeX][nodeY]; }

inline bool Graph::isAdjacent(int nodeX, int nodeY)  { return adj[nodeX][nodeY] > 0; }

inline void Graph::setNodeValue(int nodeX, int value) { nodeValues[nodeX] = value; }
inline void Graph::setEdgeValue(int nodeX, int nodeY, double value)
{
	if (!isAdjacent(nodeX, nodeY))
		numEdges++; 

	adj[nodeX][nodeY] = value;
	adj[nodeY][nodeX] = value;
}
inline void Graph::addEdge(int nodeX, int nodeY, double dist) 
{ 
	adj[nodeX][nodeY] = dist;
	adj[nodeY][nodeX] = dist; 
	numEdges++; 
} 
inline void Graph::deleteEdge(int nodeX, int nodeY)
{
	adj[nodeX][nodeY] = 0; 
	adj[nodeY][nodeX] = 0; 
	numEdges--; 
}
