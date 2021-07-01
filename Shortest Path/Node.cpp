#pragma once
#include "Node.h"

//constructors
Node::Node() : weight_key(0), vertex_name_data(0)
{
}

Node::Node(float key, int data) : weight_key(key), vertex_name_data(data)
{
}

Node::Node(const Node& other) {
	this->vertex_name_data = other.vertex_name_data;
	this->weight_key = other.weight_key;
}
//distructor
Node::~Node()
{
}

bool Node::set_weight_key(float key) {
	this->weight_key = key;
	return true;
}

bool Node::set_vertex_name_data(int data) {
	this->vertex_name_data = data;
	return true;
}
