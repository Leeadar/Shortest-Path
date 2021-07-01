#pragma once
#include <iostream>
#include "vertex.h"
#include "Edge_con_vertex.h"
#include "vertex.h"

using namespace std;

class linked_list_graph
{
private:
	vertex** Neighbors_list;
	int num0fVertex;
public:
	//constructors
	linked_list_graph(int n); 
	void operator=(const linked_list_graph&) = delete;
	linked_list_graph(const linked_list_graph&) = delete;
	//distructor
	~linked_list_graph();

	//getters
	int get_num0fVertex() { return num0fVertex; }
	//setters

	void AddEdge(int u, int v, float c);
	void print_linked_list();
	void RemoveEdge(int u, int v);
	void isVertexValid(int u);
	vertex* GetAdjList(int u);

	Edge_con_vertex** ArrayOfEdges(int& num0fEdges);

};