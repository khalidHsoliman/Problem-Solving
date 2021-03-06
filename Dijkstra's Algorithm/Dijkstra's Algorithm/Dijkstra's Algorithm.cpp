// Dijkstra's Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include "Graph.h"
#include "PriorityQueue.h"
#include <iostream>
#include <math.h>

using namespace std;

ostream& operator<<(ostream& os, Graph& g)
{
	cout << " Vertices : "; 
	for (int i = 0; i < g.getNumOFNodes(); i++)
	{
		cout << g.getNodeValue(i) << "  "; 
	}

	cout << endl; 
	cout << " Edges : " << endl;

	for (int i = 0; i < g.getNumOFNodes(); i++)
	{
		for (int j = i; j < g.getNumOFNodes(); j++)
		{
			if (g.isAdjacent(i,j))
				cout << g.getNodeValue(i) << " <--" << g.getEdgeValue(i, j) << "--> " << g.getNodeValue(j) << endl;
		}
	}
	return os;
}

ostream& operator<<(ostream& os, PriorityQueue& pq)
{
	for (int i = 0; i < log2(pq.size()) + 1; i++)
	{
		for (int j = pow(2, i) - 1; j < pow(2, i + 1) - 1 && j < pq.size(); j++)
		{
			cout << " " << pq.heapElements[j] << " "; 
		}

		cout << endl;
	}

	return os; 
}

int main()
{
	PriorityQueue pq; 
	pq.push(4);
	pq.push(6);
	pq.push(5);
	pq.push(1);
	pq.push(2);
	pq.push(4); 
	pq.push(8);
	pq.push(9);
	cout << pq << endl;

	cout << pq.pop() << endl;
	cout << pq << endl; 

	cout << pq.pop() << endl;
	cout << pq << endl;
	cout << pq.size() << endl;
	cout << boolalpha << pq.contains(9) << endl;
	


}

