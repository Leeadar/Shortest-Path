#include "Priority_Queue_Array.h"


Priority_Queue_Array::Priority_Queue_Array(Node** i_NodeArr, int size) : _maxSize(size), _logicalSize(size) //constructor
{
	index_vertex_array = new int[size];
	NodeArr = i_NodeArr;
	_min_index = findMinKeyIndex();
	for (int i = 0; i < size; i++) //init array
	{
		index_vertex_array[i] = i;
	}
}

Priority_Queue_Array::~Priority_Queue_Array() //distructor
{
	delete[] index_vertex_array;
}

Node* Priority_Queue_Array::DeleteMin()
{
	int min_vertex, last_vertex; 
	if (_logicalSize < 1)
		return nullptr;

	last_vertex = NodeArr[_logicalSize - 1]->get_vertex_name_data();
	index_vertex_array[last_vertex - 1] = _min_index; //The last vertex moves to the min_vertex index
	
	min_vertex = NodeArr[_min_index]->get_vertex_name_data();
	index_vertex_array[min_vertex - 1] = -1; // The min_vertex deleted from the queue

	Node* curr_min = NodeArr[_min_index];
	NodeArr[_min_index] = NodeArr[_logicalSize-1];
	
	_logicalSize--;

	_min_index = findMinKeyIndex();
	return curr_min;
}

int Priority_Queue_Array::findMinKeyIndex()
{
	float min_key;
	int min_index = 0;

	if (_logicalSize > 0)
	{
		min_key = NodeArr[0]->get_weight_key();

		for (int i = 1; i < _logicalSize; i++)
		{
			if (min_key == INFINITE && NodeArr[i]->get_weight_key() != INFINITE)
			{
				min_index = i;
				min_key = NodeArr[min_index]->get_weight_key();
			}
			else if (NodeArr[i]->get_weight_key() < min_key && NodeArr[i]->get_weight_key()!= INFINITE)
			{
				min_index = i;
				min_key = NodeArr[min_index]->get_weight_key();
			}
		}
	}
	return min_index;
}

void Priority_Queue_Array::Decrease_key(int vertex, float newkey)
{
	int place = index_vertex_array[vertex - 1];
	Decrease_key_helper(place, newkey);
}

void Priority_Queue_Array::Decrease_key_helper(int place, float newkey)
{
	if (NodeArr[_min_index]->get_weight_key() == INFINITE || NodeArr[_min_index]->get_weight_key() > newkey)
	{
		NodeArr[place]->set_weight_key(newkey);
		_min_index = place;
	}
	else
	{
		NodeArr[place]->set_weight_key(newkey);
	}
}

void Priority_Queue_Array::printArrayQueue()
{
	cout << "Min Vertex in queue: Weight=" << NodeArr[_min_index]->get_weight_key() << " Name= " << NodeArr[_min_index]->get_vertex_name_data()<< endl<<endl;
	cout << "Vertex in queue:" << endl;
	for (int i = 0; i < _logicalSize; i++)
	{
		cout << "Weight: " << NodeArr[i]->get_weight_key() << " Name:" << NodeArr[i]->get_vertex_name_data() << endl;
	}
}

void Priority_Queue_Array::printArrayIndex()
{

	for (int i = 0; i < _maxSize; i++)
	{
		cout <<"Vertex name: " << i+1 << " , Index: "<<index_vertex_array[i]<< endl;
	}
}