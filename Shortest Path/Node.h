#pragma once

class Node
{
private:
	int vertex_name_data;
	float weight_key; // The key is the weight of vertex 
public:
	//constructors
	Node();
	Node(float key, int data);
	Node(const Node& other);
	//distructor
	~Node();

	//getters
	const int get_vertex_name_data() { return this->vertex_name_data; }
	const float get_weight_key() { return this->weight_key; }
	//setters
	bool set_weight_key(float key);
	bool set_vertex_name_data(int data);
};
