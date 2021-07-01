#include <iostream>
#include <fstream>
#include "Priority_Queue_Heap.h"
#include "Priority_Queue_Array.h"
#include "matrix_graph.h"
#include "linked_list_graph.h"
#include "Bellman_Ford.h"
#include "Utils.h"
#include "Dijkstra.h"

using namespace std;

void isFloat(const char* s);
float check_weight_valid(const char* s);
void isInteger(const char* s);
void readFromTxt(const char* str, linked_list_graph*& o_linked_list, matrix_graph*& o_matrix, int& origin_vertex, int& dest_vertex);
int check_vertex_valid(const char* s, int n);
void printWeight(const char* func_name, int dest_vertex, float* d);
bool get_num(istream& infile, char* s);

/// main:
int main(int argc, char* argv[])
{
	matrix_graph* matrix = nullptr;
	linked_list_graph* linked_list = nullptr;
	int origin_vertex, dest_vertex;
	float* d;

	readFromTxt(argv[1], linked_list, matrix, origin_vertex, dest_vertex);

	d = Dijkstra_Priority_Queue_Heap_linked_list(linked_list->get_num0fVertex(), linked_list, origin_vertex);
	printWeight("Adjacency Dijkstra heap", dest_vertex, d);
	delete d;

	d = Dijkstra_Priority_Queue_Array_linked_list(linked_list->get_num0fVertex(), linked_list, origin_vertex);
	printWeight("Adjacency Dijkstra array", dest_vertex, d);
	delete d;

	d = Bellman_Ford_linked_list(linked_list->get_num0fVertex(), origin_vertex, linked_list);
	printWeight("Adjacency Bellman Ford", dest_vertex, d);
	delete d;

	d = Dijkstra_Priority_Queue_Heap_matrix(matrix->get_num0fVertex(), matrix, origin_vertex);
	printWeight("Matrix Dijkstra heap", dest_vertex, d);
	delete d;

	d = Dijkstra_Priority_Queue_Array_matrix(matrix->get_num0fVertex(), matrix, origin_vertex);
	printWeight("Matrix Dijkstra array", dest_vertex, d);
	delete d;

	d = Bellman_Ford_matrix(matrix->get_num0fVertex(), origin_vertex, matrix);
	printWeight("Matrix Bellman Ford", dest_vertex, d);
	delete d;

}

// Print the Weight of the Route to dest_vertex
void printWeight(const char* func_name, int dest_vertex, float* d)
{
	if (d[dest_vertex - 1] == INFINITE)
	{
		cout << func_name << " No route" << endl;
	}
	else
	{
		cout << func_name << " " << d[dest_vertex - 1] << endl;
	}
}

//Read the data from the file to the linked_list and the matrix
void readFromTxt(const char* str, linked_list_graph*& o_linked_list, matrix_graph*& o_matrix, int& origin_vertex, int& dest_vertex)
{
	ifstream infile;
	bool end_of_file = false;
	char s[MAXSIZE];
	char ch;
	int n, u, v;
	int i = 0;
	float weight;

	infile.open(str);
	if (!infile)
	{
		cout << "Invalid Input." << endl;
		exit(1);
	}


	end_of_file = get_num(infile, s); // get n
	if (end_of_file)
	{
		cout << "Invalid Input." << endl;
		exit(1);
	}
	isInteger(s); //check if n is integer
	n = atoi(s);

	if (n <= 0) //check if num of vertex is positive
	{
		cout << "Invalid Input." << endl;
		exit(1);
	}
	end_of_file = get_num(infile, s); // get origin_vertex
	if (end_of_file)
	{
		cout << "Invalid Input." << endl;
		exit(1);
	}
	origin_vertex = check_vertex_valid(s, n);

	end_of_file = get_num(infile, s); // get dest_vertex
	if (end_of_file)
	{
		cout << "Invalid Input." << endl;
		exit(1);
	}
	dest_vertex = check_vertex_valid(s, n);

	linked_list_graph* linked_list = new linked_list_graph(n);
	matrix_graph* matrix = new matrix_graph(n);
	while (!infile.eof() && !end_of_file)
	{
		if (!infile.good())
		{
			cout << "Invalid Input." << endl;
			exit(1);
		}

		end_of_file = get_num(infile, s);
		if (!end_of_file) // if this is not the end of the file we need to get new 3 numbers
		{
			u = check_vertex_valid(s, n); //check if u is a number

			end_of_file = get_num(infile, s);
			if (end_of_file)
			{
				cout << "Invalid Input." << endl;
				exit(1);
			}
			v = check_vertex_valid(s, n); // check if v is a number

			end_of_file = get_num(infile, s);
			if (end_of_file)
			{
				cout << "Invalid Input." << endl;
				exit(1);
			}
			weight = check_weight_valid(s);



			linked_list->AddEdge(u, v, weight); // Add the edge to the linked list
			matrix->AddEdge(u, v, weight); // Add the edge to the matrix
		}

	}

	o_linked_list = linked_list;
	o_matrix = matrix;

	infile.close();
}

//Get a number from file
bool get_num(istream& infile, char* s)
{
	char ch = ' ';
	int i = 0;

	while (ch == ' ' || ch == '\n' || infile.eof()) // Read first blank spaces
	{
		if (infile.eof())
		{
			return true;
		}
		infile.get(ch);
	}
	while (!infile.eof() && ch != ' ' && ch != '\n')
	{
		if (ch < '0' || ch > '9')
		{
			if (ch != '.')
			{
				cout << "Invalid Input." << endl;
				exit(1);
			}
		}
		s[i] = ch;
		i++;
		infile.get(ch);
	}
	s[i] = '\0';

	return false;
}

// Check if s is a valid vertex
int check_vertex_valid(const char* s, int n)
{
	isInteger(s);
	int u = atoi(s);
	if (u <= 0 || u > n)
	{
		cout << "Invalid Input." << endl;
		exit(1);
	}
	return u;
}

// Check if s is a valid weight
float check_weight_valid(const char* s)
{
	isFloat(s);
	float weight = atof(s);
	if (weight < 0)
	{
		cout << "Invalid Input." << endl;
		exit(1);
	}
	return weight;
}

//Check if s is an integer
void isInteger(const char* s)
{
	if (strcmp(s, "") == 0)     // empty string
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	int i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != ' ') && (!isdigit(s[i])))	//invalid num
		{
			cout << "invalid input" << endl;
			exit(1);
		}
		i++;
	}
}

//Check if s is a float
void isFloat(const char* s)
{
	int i = 0;
	int dot_count = 0;

	if (s[0] == '.')
	{
		cout << "invalid input" << endl;
		exit(1);
	}

	while (s[i] != '\0')
	{
		if ((!isdigit(s[i])) && (s[i] != '.'))
		{
			cout << "invalid input" << endl;
			exit(1);
		}
		if ((s[i] == '.') && ((!isdigit(s[i + 1]) || !isdigit(s[i - 1]) || dot_count == 1)))
		{
			cout << "invalid input" << endl;
			exit(1);
		}
		else if ((s[i] == '.') && isdigit(s[i + 1]) && isdigit(s[i - 1]))
		{
			dot_count++;
		}
		i++;
	}
}