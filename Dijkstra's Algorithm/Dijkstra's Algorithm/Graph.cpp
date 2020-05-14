#include "pch.h"
#include "Graph.h"

Graph::Graph(const int numNodes, const double density, const pair<double, double> distanceRange)
{
	this->numNodes = numNodes; 
	this->numEdges = 0; 
	

	adj = new double*[numNodes];
	for (int i = 0; i < numNodes; i++)
	{	
		nodeValues.push_back(0);
		adj[i] = new double[numNodes]; 
		for (int j = 0; j < numNodes; j++)
			adj[i][j] = 0;
	}

	default_random_engine randomGenerater(chrono::system_clock::now().time_since_epoch().count());

	uniform_real_distribution<double> densityDist (0.0, 1.0);
	uniform_real_distribution<double> distanceDist(distanceRange.first, distanceRange.second); 

	for (int i = 0; i < numNodes; i++)
	{
		for (int j = 0; j < numNodes; j++)
		{
			if (densityDist(randomGenerater) < density)
				addEdge(i, j, distanceDist(randomGenerater));
		}
	}
	
}

vector<int> Graph::getNeighbors(int nodeX)
{
	vector<int> neighbors; 
	for (int i = 0; i < numNodes; i++)
	{
		if (adj[nodeX][i] > 0)
			neighbors.push_back(adj[nodeX][i]);
	}

	return neighbors; 
}