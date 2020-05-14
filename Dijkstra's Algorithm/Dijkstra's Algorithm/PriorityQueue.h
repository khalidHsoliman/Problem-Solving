#pragma once
#include<vector>
#include<algorithm>

using namespace std; 

class PriorityQueue
{
private:
	vector<int> heapElements;
	
	int parent(int i); 
	int left  (int i); 
	int right (int i); 

	int  min(int a, int b);

	void sink(int i);
	void swim(int i); 

public:
	PriorityQueue() {};
	~PriorityQueue() {};

	int  size(); 
	int  top();
	int pop();
	bool is_empty();
	bool contains(int key);
	void push(int key);
	void clear();

	friend ostream& operator<<(ostream& os, PriorityQueue& pq);
};

inline int  PriorityQueue::parent(int i) { if (i != 0)return (i - 1) / 2; else return 0; }
inline int  PriorityQueue::left  (int i) { return (2 * i + 1); }
inline int  PriorityQueue::right (int i) { return (2 * i + 2); }
inline int  PriorityQueue::size() { return heapElements.size(); }
inline int	PriorityQueue::min(int a, int b) {return (heapElements[a] < heapElements[b]) ? a : b; }
inline bool PriorityQueue::is_empty() { return size() == 0; }
inline bool PriorityQueue::contains(int key) { return (find(heapElements.begin(), heapElements.end(), key) != heapElements.end()); }
inline void PriorityQueue::clear() { heapElements.clear(); }