#include "pch.h"
#include "PriorityQueue.h"

void PriorityQueue::sink(int i)
{
	int left_index  = left(i); 
	int right_index = right(i);
	
	if (left_index < size() && right_index < size())
	{
		int smallest_index = min(left_index, right_index);
		
		if (heapElements[smallest_index] < heapElements[i])
		{
			swap(heapElements[smallest_index], heapElements[i]);
			sink(smallest_index);
		}
	}
}
void PriorityQueue::swim(int i)
{
	int parent_index = parent(i);

	if (heapElements[i] != NULL && heapElements[i] < heapElements[parent_index])
	{
		swap(heapElements[i], heapElements[parent_index]); 
		swim(parent_index);
	}
}

void PriorityQueue::push(int key)
{
	heapElements.push_back(key);
	int key_index = size() - 1;

	swim(key_index);
}
int  PriorityQueue::pop()
{
	int temp = -1; 
	if (!is_empty())
	{
		temp = heapElements[0];
		heapElements[0] = heapElements.back();  
		heapElements.pop_back();
		sink(0); 
	}

	return temp; 

} 
int	 PriorityQueue::top()
{
	if (!is_empty())
		return heapElements[0]; 
}