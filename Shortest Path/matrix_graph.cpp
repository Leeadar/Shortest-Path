#include "matrix_graph.h"

//constructor
matrix_graph::matrix_graph(int n) : num0fVertex(n)
{
	if (n <= 0)
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	matrix = new edge* [num0fVertex];

	for (int i = 0; i < num0fVertex; i++) //create matrix
	{
		matrix[i] = new edge [num0fVertex];
	}

	for (int i = 0; i < num0fVertex; i++) //init matrix
	{
		for (int j = 0; j < num0fVertex; j++)
		{
			matrix[i][j].isEdge = false;
			matrix[i][j].weight = 0;
		}
	}
}//distructor
matrix_graph::~matrix_graph()
{
	for (int k = 0; k < num0fVertex; k++)
	{
			delete[] matrix[k];
	}
	delete[] matrix;
}
bool matrix_graph::IsAdjacent(int u, int v)
{
	isVertexValid(u);
	isVertexValid(v);
	return matrix[u - 1][v - 1].isEdge;
}

void matrix_graph::AddEdge(int u, int v, float c)
{
	isVertexValid(u);
	isVertexValid(v);
	if (matrix[u - 1][v - 1].isEdge || u==v)
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	matrix[u - 1][v - 1].isEdge = true;
	matrix[u - 1][v - 1].weight = c;
}

void matrix_graph::RemoveEdge(int u, int v)
{
	isVertexValid(u);
	isVertexValid(v);
	if (matrix[u - 1][v - 1].isEdge == false)
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	matrix[u - 1][v - 1].isEdge = false;
	matrix[u - 1][v - 1].weight = 0;
}

//return a linked list of the neighbors of u
vertex* matrix_graph::GetAdjList(int u)
{
	vertex* newVertex, *firstVertex, *tempVertex;
	firstVertex = nullptr;
	tempVertex = nullptr;

	isVertexValid(u);

	for (int i = 0; i < num0fVertex; i++)
	{
		if (matrix[u - 1][i].isEdge)
		{
			if (firstVertex == nullptr)
			{
				firstVertex = new vertex(i + 1, matrix[u - 1][i].weight);
				tempVertex = firstVertex;
			}
			else
			{
				newVertex = new vertex(i + 1, matrix[u - 1][i].weight);
				tempVertex->set_next_vertex(newVertex);
				tempVertex = tempVertex->get_next_vertex();
			}
		}
	}
	return firstVertex;
}



void matrix_graph::isVertexValid(int u)
{
	if (u > num0fVertex || u <= 0)
	{
		cout << "invalid input" << endl; //The edge vertex does not exist
		exit(1);
	}
}

Edge_con_vertex** matrix_graph::ArrayOfEdges(int& num0fEdges) // create and return an array of edges
{
	if (num0fVertex <= 0)
		return nullptr;

	int edge_count = 0;
	for (int i = 0; i < num0fVertex; i++)
	{
		for (int j = 0; j < num0fVertex; j++)
		{
			if (matrix[i][j].isEdge == true)
			{
				edge_count++;
			}
		}
	}

	Edge_con_vertex** o_edge_array = new Edge_con_vertex*[edge_count];
	int index = 0;

	for (int i = 0; i < num0fVertex; i++)
	{
		for (int j = 0; j < num0fVertex; j++)
		{
			if (matrix[i][j].isEdge == true)
			{
				Edge_con_vertex* edge = new Edge_con_vertex(i+1, j+1, matrix[i][j].weight);
				o_edge_array[index] = edge;
				index++;
			}
		}
	}

	num0fEdges = edge_count;
	return o_edge_array;

}