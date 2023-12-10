#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cstddef>

class MinPriorityQueue {
private:
	std::vector<int> heap;

	size_t getLeft(size_t) const;
	size_t getRight(size_t) const;
	size_t getParent(size_t) const;
	void minHeapify(std::vector<int>&, size_t, size_t);
	void buildHeap(std::vector<int>&);
public:
	MinPriorityQueue() = default;
	MinPriorityQueue(std::vector<int>&&);

	void insert(int val);
	int extractMin();
	void print();
	void heapSort();
	void decreaseKey(size_t, int);
};
#endif  //MINPRIORITYQUEUE_H
