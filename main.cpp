#include <iostream>
#include <stdexcept>
#include "minpriorityqueue.h"

int main()
{
	try {
	std::vector<int> v = {15,2,5,2,6,3,-7,10};
	MinPriorityQueue mq(std::move(v));	
//	std::cout << "\nMin Priority Queue - ";
	mq.print();
//	std::cout << "\nInsert value of 20 which compl is O(logn) - ";
//	mq.insert(20);
//	mq.print();
//	int minElem = mq.extractMin();
//	std::cout << "\nExtract min res is - " << minElem << std::endl;
	std::cout << "\nAfter sorting which complexity is nlogn res is - ";
	mq.heapSort();
	mq.print();
	
	} catch(const std::exception& e) {
		std::cout << e.what() << std::endl;

	}
}
