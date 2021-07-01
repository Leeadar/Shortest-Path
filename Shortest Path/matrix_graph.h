#pragma once
#include <iostream>
#include "vertex.h"
#include "Edge_con_vertex.h"

using namespace std;

struct edge {
	bool isEdge;
	float weight;
};

class matrix_graph
{
private:
	int num0fVertex;
	edge** matrix =nullptr;
public:
	//constructors
	matrix_graph(int n); // MakeEmptyGraph(n)
	void operator=(const matrix_graph&) = delete;
	matrix_graph(const matrix_graph&) = delete;
	//distructor
	~matrix_graph();

	//getters
	int get_num0fVertex() { return num0fVertex; }
	//setters

	bool IsAdjacent(int u, int v);
	void AddEdge(int u, int v, float c);
	void RemoveEdge(int u, int v);
	vertex* GetAdjList(int u);
	void isVertexValid(int u);

	Edge_con_vertex** ArrayOfEdges(int& num0fEdge);
};