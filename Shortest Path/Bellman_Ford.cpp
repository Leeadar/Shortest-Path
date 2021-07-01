#include "Bellman_Ford.h"


float* Bellman_Ford_linked_list(int n, int s, linked_list_graph* linked_list)
{
	Edge_con_vertex** edges_arr;
	int num0fEdges;
	edges_arr = linked_list->ArrayOfEdges(num0fEdges); //init array

	float* d = Bellman_Ford_algorithm(n, edges_arr, s, num0fEdges);
	for (int i = 0; i < num0fEdges; i++) //realese array
	{
		delete edges_arr[i];
	}
	delete[] edges_arr;
	return d;
}

float* Bellman_Ford_matrix(int n, int s, matrix_graph* matrix)
{
	Edge_con_vertex** edges_arr;
	int num0fEdges;
	edges_arr = matrix->ArrayOfEdges(num0fEdges); //init array
	float* d = Bellman_Ford_algorithm(n, edges_arr, s, num0fEdges);
	for (int i = 0; i < num0fEdges; i++) //realese array
	{
		delete edges_arr[i];
	}
	delete[] edges_arr;
	return d;
}


float* Bellman_Ford_algorithm(int n, Edge_con_vertex** edges_arr, int s, int num0fEdges)
{
	Edge_con_vertex* edge;
	float d_v, d_u, u_v_weight;

	float* d = new float[n];
	for (int i = 0; i < n; i++) //init
	{
		if (i == s - 1)
		{
			d[i] = 0;
		}
		else
		{
			d[i] = INFINITE;
		}

	}
	for (int i = 0; i < n; i++) // Main loop
	{
		for (int j = 0; j < num0fEdges; j++)
		{
			edge = edges_arr[j];
			RELAX(d, edge->get_origin_vertex(), edge->get_dest_vertex(), edge->get_weight());
		}
	}
	for (int j = 0; j < num0fEdges; j++)    //Check Termination                                                                                                                         
	{
		edge = edges_arr[j];
		d_v = d[edge->get_dest_vertex() - 1];
		d_u = d[edge->get_origin_vertex() - 1];
		u_v_weight = edge->get_weight();

		if ((d_u != INFINITE))
		{
			if ((d_v > d_u + u_v_weight) || (d_v == INFINITE))
			{
				return nullptr; // Negative-Cycle
			}
		}
	}
	return d;
}
