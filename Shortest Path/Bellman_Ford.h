#pragma once
#include "Edge_con_vertex.h" 
#include "linked_list_graph.h"
#include "matrix_graph.h"
#include "Utils.h"

float* Bellman_Ford_algorithm(int n, Edge_con_vertex** edges_arr, int s, int num0fEdges);
float* Bellman_Ford_linked_list(int n, int s, linked_list_graph* linked_list);
float* Bellman_Ford_matrix(int n, int s, matrix_graph* matrix);