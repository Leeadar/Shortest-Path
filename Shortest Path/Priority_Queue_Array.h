#pragma once
#include <iostream>
#include "Node.h"
#include "Utils.h"

using namespace std;

class Priority_Queue_Array {
private:
	Node** NodeArr = nullptr;
	int* index_vertex_array; // Array of index vertex
	int _min_index; // The index of the node with the minimum key in the queue
	int _maxSize;
	int _logicalSize;
public:
	//constructors
	Priority_Queue_Array(Node** i_NodeArr, int size);

	//distructor
	~Priority_Queue_Array();
	//getters
	Node** getNodeArr() { return this->NodeArr; }
	Node* min() { return NodeArr[_min_index]; }

	int findMinKeyIndex();

	bool isEmpty() { return _logicalSize==0; };
	Node* DeleteMin();

	void Decrease_key(int vertex, float newkey);
	void Decrease_key_helper(int place, float newkey);
	void printArrayQueue();
	void printArrayIndex();

};