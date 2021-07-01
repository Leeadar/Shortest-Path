#include "Dijkstra.h"

float* Dijkstra_Priority_Queue_Array_linked_list(int num0fVertex, linked_list_graph* linked_list, int s)
{
	Node** NodeArr = new Node * [num0fVertex];
	float d_v, d_u, u_v_edge_weight;
	int u, v;

	float* d = new float[num0fVertex];

	for (int i = 0; i < num0fVertex; i++) //init NodeArr
	{
		if (i == s - 1)
		{
			Node* node = new Node(0, i + 1);
			NodeArr[i] = node;
			d[i] = 0;
		}
		else
		{
			Node* node = new Node(INFINITE, i + 1);
			NodeArr[i] = node;
			d[i] = INFINITE;
		}
	}
	
	Priority_Queue_Array Q(NodeArr, num0fVertex);

	while (Q.isEmpty() == false)
	{
		Node* min_vertex = Q.DeleteMin();
		u = min_vertex->get_vertex_name_data();
		d_u = min_vertex->get_weight_key();

		vertex* temp_vertex = linked_list->GetAdjList(u);
		while (temp_vertex != nullptr) //dijkstra algorithm
		{
			v = temp_vertex->get_name();
			u_v_edge_weight = temp_vertex->get_weight();
			d_v = d[v - 1];

			if (RELAX(d, u, v, u_v_edge_weight))
			{
				d_v = d[v - 1];
				Q.Decrease_key(v, d_v);
			}
			temp_vertex = temp_vertex->get_next_vertex();
		}

		delete min_vertex;
	}
	delete[] NodeArr;
	return d;
}


float* Dijkstra_Priority_Queue_Array_matrix(int num0fVertex, matrix_graph* matrix, int s)
{
	Node** NodeArr = new Node * [num0fVertex];
	float  d_v, d_u, u_v_edge_weight;
	int v, u;

	float* d = new float[num0fVertex];

	for (int i = 0; i < num0fVertex; i++) //init NodeArr
	{
		if (i == s - 1)
		{
			Node* node = new Node(0, i + 1);
			NodeArr[i] = node;
			d[i] = 0;
		}
		else
		{
			Node* node = new Node(INFINITE, i + 1);
			NodeArr[i] = node;
			d[i] = INFINITE;
		}
	}

	Priority_Queue_Array Q(NodeArr, num0fVertex);

	while (Q.isEmpty() == false)
	{
		Node* min_vertex = Q.DeleteMin();
		u = min_vertex->get_vertex_name_data();
		d_u = min_vertex->get_weight_key();

		vertex* temp_next;
		vertex* temp_vertex = matrix->GetAdjList(u);
		while (temp_vertex != nullptr) //dijkstra algorithm
		{
			v = temp_vertex->get_name();
			u_v_edge_weight = temp_vertex->get_weight();
			d_v = d[v - 1];

			if (RELAX(d, u, v, u_v_edge_weight))
			{
				d_v = d[v - 1];
				Q.Decrease_key(v, d_v);
			}
			//temp_vertex = temp_vertex->get_next_vertex();
			temp_next = temp_vertex->get_next_vertex();
			delete temp_vertex;
			temp_vertex = temp_next;
		}
		delete min_vertex;
	}
	delete[] NodeArr;
	return d;

}

float* Dijkstra_Priority_Queue_Heap_linked_list(int num0fVertex, linked_list_graph* linked_list, int s)
{
	Node** NodeArr = new Node * [num0fVertex];
	float d_v, d_u, u_v_edge_weight;
	int u, v;

	float* d = new float[num0fVertex];

	for (int i = 0; i < num0fVertex; i++) //init NodeArr
	{
		if (i == s - 1)
		{
			Node* node = new Node(0, i + 1);
			NodeArr[i] = node;
			d[i] = 0;
		}
		else
		{
			Node* node = new Node(INFINITE, i + 1);
			NodeArr[i] = node;
			d[i] = INFINITE;
		}
	}

	Priority_Queue_Heap Q(NodeArr, num0fVertex);

	while (Q.isEmpty() == false)
	{
		Node* min_vertex = Q.DeleteMin();
		u = min_vertex->get_vertex_name_data();
		d_u = min_vertex->get_weight_key();

		vertex* temp_vertex = linked_list->GetAdjList(u);
		while (temp_vertex != nullptr) //dijkstra algorithm
		{
			v = temp_vertex->get_name();
			u_v_edge_weight = temp_vertex->get_weight();
			d_v = d[v - 1];

			if (RELAX(d, u, v, u_v_edge_weight))
			{
				d_v = d[v - 1];
				Q.Decrease_key(v, d_v);
			}
			temp_vertex = temp_vertex->get_next_vertex();
		}
		delete min_vertex;
	}
	delete[] NodeArr;

	return d;
}


float* Dijkstra_Priority_Queue_Heap_matrix(int num0fVertex, matrix_graph* matrix, int s)
{
	Node** NodeArr = new Node * [num0fVertex];
	float  d_v, d_u, u_v_edge_weight;
	int v, u;

	float* d = new float[num0fVertex];

	for (int i = 0; i < num0fVertex; i++) //init NodeArr
	{ 
		if (i == s - 1)
		{
			Node* node = new Node(0, i + 1);
			NodeArr[i] = node;
			d[i] = 0;
		}
		else
		{
			Node* node = new Node(INFINITE, i + 1);
			NodeArr[i] = node;
			d[i] = INFINITE;
		}
	}

	Priority_Queue_Heap Q(NodeArr, num0fVertex);

	while (Q.isEmpty() == false)
	{
		Node* min_vertex = Q.DeleteMin();
		u = min_vertex->get_vertex_name_data();
		d_u = min_vertex->get_weight_key();

		vertex* temp_vertex = matrix->GetAdjList(u);
		while (temp_vertex != nullptr) //dijkstra algorithm
		{
			v = temp_vertex->get_name();
			u_v_edge_weight = temp_vertex->get_weight();
			d_v = d[v - 1];

			if (RELAX(d, u, v, u_v_edge_weight))
			{
				d_v = d[v - 1];
				Q.Decrease_key(v, d_v);
			}
			temp_vertex = temp_vertex->get_next_vertex();
		}
		delete min_vertex;
	}
	delete[] NodeArr;
	return d;

}