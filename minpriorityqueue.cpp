#include<iostream>
#include "minpriorityqueue.h"

size_t MinPriorityQueue::getLeft(size_t idx) const {
	return 2 * idx + 1;
} 
size_t MinPriorityQueue::getRight(size_t idx) const {
	return 2 * idx + 2;
}
size_t MinPriorityQueue::getParent(size_t idx) const {
	return (idx - 1) / 2;
}

void MinPriorityQueue::minHeapify(std::vector<int>& heap, size_t index,size_t heapSize) {
	size_t smallInex = index;
	size_t left = getLeft(index);
	size_t right = getRight(index);
	if(heap[smallInex] > heap[left] && left < heap.size()) {
		smallInex = left;
	} 
	if(heap[smallInex] > heap[right] && right < heap.size()) {
		smallInex = right;
	}
	if(smallInex != index) {
		std::swap(heap[index], heap[smallInex]);
		minHeapify(heap, smallInex, heapSize);
	}
}

void MinPriorityQueue::buildHeap(std::vector<int> & heap) {
	for(int i = heap.size() / 2 - 1 ; i >= 0; --i) {
		minHeapify(heap, i, heap.size());
	}
}

MinPriorityQueue::MinPriorityQueue(std::vector<int>&& v) : heap(v){
	buildHeap(v);
}

void MinPriorityQueue::insert(int val) {
	heap.push_back(val);
	int idx = heap.size() - 1;
	while(idx > 0 && heap[idx] < heap[getParent(idx)]) {
		std::swap(heap[idx] ,heap[getParent(idx)]);
		idx = getParent(idx);
	}
}
int MinPriorityQueue::extractMin() {
	if(heap.empty()) {
		throw("Heap is empty \n");
	}
	int min = heap.front();
	heap[0] = heap.back();
	heap.pop_back();
	minHeapify(heap,0,heap.size());
	return min;
}

void MinPriorityQueue::print() {
	for(const auto& val : heap) {
		std::cout << val << " ";
	}
}
void MinPriorityQueue::heapSort() {
	buildHeap(heap);
	for(int i = heap.size() - 1; i >= 0; --i) {
		std::swap(heap[0], heap[i]);
		minHeapify(heap, 0, i);
		}
}

void MinPriorityQueue::decreaseKey(size_t idx, int newVal) {
	if(idx  < heap.size() && newVal < heap[idx]) {
		throw std::out_of_range("Range is not correct or value must be lower \n");
	} else {
		heap[idx] = newVal;
		while(idx > 0 && heap[getParent(idx)] > heap[idx]) {
			std::swap(heap[idx], heap[getParent(idx)]);
			idx = getParent(idx);
		}
	}
}



