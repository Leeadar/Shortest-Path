#include "linked_list_graph.h"

//constructor
linked_list_graph::linked_list_graph(int n) : num0fVertex(n)
{

	Neighbors_list = new vertex * [num0fVertex];

	for (int i = 0; i < num0fVertex; i++)
	{
		Neighbors_list[i] = nullptr;
	}
}
//distructor
linked_list_graph::~linked_list_graph()
{
	vertex* temp_next, *temp;
	for (int i = 0; i < num0fVertex; i++)
	{
		temp = Neighbors_list[i];
		while (temp)
		{
			temp_next = temp->get_next_vertex();
			delete temp;
			temp = temp_next;
		}
	}
	delete[] Neighbors_list;
}

void linked_list_graph::AddEdge(int u, int v, float c)
{
	isVertexValid(u);
	isVertexValid(v);
	if (u == v)
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	vertex* temp = Neighbors_list[u - 1];

	if (Neighbors_list[u - 1] == nullptr)
	{
		Neighbors_list[u - 1] = new vertex(v, c);
	}
	else
	{
		if (temp->get_name() == v)
		{
			cout << "invalid input" << endl; //The edge already exist in the first vertex
			exit(1);
		}

		//check that the edge does not exist
		while (temp->get_next_vertex() != nullptr)
		{
			if (temp->get_name() == v)
			{
				cout << "invalid input" << endl; //The edge already exist
				exit(1);
			}
			temp = temp->get_next_vertex();
		}
		temp->set_next_vertex(new vertex(v, c)); // insert to the next of the last vertex
	}
}

void linked_list_graph::print_linked_list() //print
{
	for (int i = 0; i < num0fVertex; i++)
	{
		vertex* temp = Neighbors_list[i];
		cout << i+1 << ": ";
		while (temp)
		{
			cout << temp->get_name() << "," << temp->get_weight() << " -> ";
			temp = temp->get_next_vertex();
		}
		cout << endl;
	}
}

void linked_list_graph::RemoveEdge(int u, int v)
{
	vertex* temp = Neighbors_list[u-1];
	vertex* prev;
	if (temp->get_name() == v)
	{
		Neighbors_list[u - 1] = temp->get_next_vertex();
		delete temp;
		return;
	}
	prev = temp;
	while (prev->get_next_vertex())
	{
		if (prev->get_next_vertex()->get_name() == v)
		{
			temp = prev->get_next_vertex();
			prev->set_next_vertex(temp->get_next_vertex());
			delete temp;
			return;
		}
		prev = prev->get_next_vertex();
	}
	cout << "invalid input" << endl; //The edge does not exist
	exit(1);
}

void linked_list_graph::isVertexValid(int u)
{
	if (u > num0fVertex || u <= 0)
	{
		cout << "invalid input" << endl; //The edge vertex does not exist
		exit(1);
	}
}


vertex* linked_list_graph::GetAdjList(int u)
{
	return Neighbors_list[u - 1];

}

//Return the graph in array of Edges
Edge_con_vertex** linked_list_graph::ArrayOfEdges(int& num0fEdges)
{
	int edge_count = 0;

	if (num0fVertex <= 0)
		return nullptr;

	for (int i = 0; i < num0fVertex; i++)
	{
		vertex* temp = Neighbors_list[i];

		while (temp != nullptr)
		{
			edge_count++;
			temp = temp->get_next_vertex();
		}
	}

	Edge_con_vertex** o_edge_array = new Edge_con_vertex * [edge_count];
	int index = 0;



	for (int i = 0; i < num0fVertex; i++)
	{
		vertex* temp = Neighbors_list[i];
		while (temp != nullptr)
		{
			Edge_con_vertex* edge = new Edge_con_vertex(i + 1, temp->get_name(), temp->get_weight());
			o_edge_array[index] = edge;
			index++;
			temp = temp->get_next_vertex();
		}
	}
	num0fEdges = edge_count;

	return o_edge_array;
}