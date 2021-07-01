#pragma once
#include "Edge_con_vertex.h" 
#include "linked_list_graph.h"
#include "matrix_graph.h"
#include "Bellman_Ford.h"
#include "Utils.h"
#include "Node.h"
#include "Priority_Queue_Array.h"
#include "Priority_Queue_Heap.h"
#include "vertex.h"


float* Dijkstra_Priority_Queue_Array_linked_list(int num0fVertex, linked_list_graph* linked_list, int s);
float* Dijkstra_Priority_Queue_Array_matrix(int num0fVertex, matrix_graph* matrix, int s);
float* Dijkstra_Priority_Queue_Heap_linked_list(int num0fVertex, linked_list_graph* linked_list, int s);
float* Dijkstra_Priority_Queue_Heap_matrix(int num0fVertex, matrix_graph* matrix, int s);