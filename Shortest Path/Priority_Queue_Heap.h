#pragma once
#include <iostream>
#include "Node.h"
#include "Utils.h"

using namespace std;

class Priority_Queue_Heap {
private:
	Node** NodeArr = nullptr;
	int* index_vertex_array; // Array of index vertex
	int _maxSize; // max size of heap
	int _heapSize; 
	static int left(int node);
	static int right(int node);
	static int parent(int node);
	void FixHeap(int node);
public:
	//constructors
	Priority_Queue_Heap(Node** i_NodeArr, int size);  //BuildHeap
	void operator=(const Priority_Queue_Heap&) = delete;
	Priority_Queue_Heap(const Priority_Queue_Heap&) = delete;
	//distructor
	~Priority_Queue_Heap();
	//getters
	Node** getNodeArr() { return this->NodeArr; }
	Node* min() const { return NodeArr[0]; } // return the minimum pair of the Priority queue

	void Swap(Node*& a, Node*& b);
	void MakeEmpty();
	bool isEmpty();
	Node* DeleteMin();
	//void insert(Node* item);
	void Decrease_key(int vertex, float newkey);
	void Decrease_key_helper(int place, float newkey);

	void printHeap();
};