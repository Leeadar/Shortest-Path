#pragma once
#include <iostream>

using namespace std;

class Edge_con_vertex
{
private:
	int origin_vertex;
	int dest_vertex;
	float weight;
public:
	//constructor
	Edge_con_vertex(int origin_vertex, int dest_vertex,float weight);

	//distructor
	~Edge_con_vertex() {};

	//getters

	int get_origin_vertex() { return origin_vertex; }
	int get_dest_vertex() { return dest_vertex; }
	float get_weight() { return weight; }
};