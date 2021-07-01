#pragma once
class vertex {
	int name;
	vertex* next;
	float weight;

public:
	//constructors
	vertex(int name, float weight): name(name) , weight(weight), next(nullptr){};
	//distructor
	~vertex() {};

	//getters
	const int get_name() { return this->name; }
	vertex* get_next_vertex() { return this->next; }
	const float get_weight() { return this->weight; }
	//setters
	void set_next_vertex(vertex* next_vertex) { next = next_vertex; };
};