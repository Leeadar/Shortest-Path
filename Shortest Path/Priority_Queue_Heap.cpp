#include "Priority_Queue_Heap.h"

Priority_Queue_Heap::Priority_Queue_Heap(Node** i_NodeArr, int size) : _maxSize(size), _heapSize(size)
{
	NodeArr = i_NodeArr;

	index_vertex_array = new int[size];
	for (int i = 0; i < size; i++) //init array
	{
		index_vertex_array[i] = i;
	}

	for (int i = size / 2 - 1; i >= 0; i--) //floyd algorithm
	{
		FixHeap(i);
	}
}

Priority_Queue_Heap::~Priority_Queue_Heap()
{
	delete[] index_vertex_array;
}

int Priority_Queue_Heap::parent(int node)
{
	return (node - 1) / 2;
}

int Priority_Queue_Heap::left(int node)
{
	return (2 * node + 1);
}

int Priority_Queue_Heap::right(int node)
{
	return (2 * node + 2);
}


void Priority_Queue_Heap::FixHeap(int node)
{
	int min;
	int _left = left(node);
	int _right = right(node);
 	if ((_left < _heapSize) && (NodeArr[_left]->get_weight_key()!= INFINITE)&&(((NodeArr[_left]->get_weight_key() < NodeArr[node]->get_weight_key())|| (NodeArr[node]->get_weight_key()== INFINITE))))
		min = _left;
	else min = node;
	if ((_right < _heapSize) && (NodeArr[_right]->get_weight_key() != INFINITE) && (((NodeArr[_right]->get_weight_key() < NodeArr[min]->get_weight_key()) || (NodeArr[node]->get_weight_key() == INFINITE))))
		min = _right;

	if (min != node)
	{
		Swap(NodeArr[node], NodeArr[min]);
		FixHeap(min);
	}
}


void Priority_Queue_Heap::Swap(Node*& a, Node*& b) // Swap two nodes
{
	int a_index, b_index, a_name, b_name;

	a_name = a->get_vertex_name_data() - 1;
	b_name = b->get_vertex_name_data() - 1;

	a_index = index_vertex_array[a_name];
	b_index = index_vertex_array[b_name];

	index_vertex_array[a_name] = b_index;
	index_vertex_array[b_name] = a_index;

	Node* temp = a;
	a = b;
	b = temp;
}
void Priority_Queue_Heap::Decrease_key(int vertex, float newkey)
{
	int place = index_vertex_array[vertex - 1];
	Decrease_key_helper(place, newkey);
}

void Priority_Queue_Heap::Decrease_key_helper(int place, float newkey)
{
	if (place >= _maxSize || place < 0)
	{
		cout << "invalid input" << endl; //input place outOfBound
		exit(1);
	}
	
	Node* Item = NodeArr[place];

	if  ((Item->get_weight_key() != INFINITE) && (newkey >= Item->get_weight_key()))
	{
		cout << "invalid input" << endl; //current input is lower then current value
		exit(1);
	}

	Item->set_weight_key(newkey);

	int i = place;
	while ((i > 0) && (NodeArr[parent(i)]->get_weight_key() > Item->get_weight_key() || NodeArr[parent(i)]->get_weight_key() == INFINITE))
	{
		NodeArr[i] = NodeArr[parent(i)];
		index_vertex_array[NodeArr[parent(i)]->get_vertex_name_data() - 1] = i;
		i = parent(i);
	}
	NodeArr[i] = Item;
	index_vertex_array[Item->get_vertex_name_data() - 1] = i;
}
void Priority_Queue_Heap::MakeEmpty() { //release array
	if (NodeArr) {
		for (int i = 0; i < _heapSize; i++)
			delete NodeArr[i];
	}
	NodeArr = nullptr;
}

bool Priority_Queue_Heap::isEmpty() {
	if (!_heapSize)
		return true;
	else
		return false;
}

Node* Priority_Queue_Heap::DeleteMin()
{
	if (_heapSize < 1)
		return nullptr;

	index_vertex_array[NodeArr[0]->get_vertex_name_data() - 1] = INFINITE;
	Node* min = NodeArr[0];
	_heapSize--;
	NodeArr[0] = NodeArr[_heapSize];

	index_vertex_array[NodeArr[0]->get_vertex_name_data() - 1] = 0;

	FixHeap(0);
	return (min);
}


void Priority_Queue_Heap::printHeap()
{
	for (int i = 0; i < _heapSize; i++)
	{
		cout <<"Weight: " << NodeArr[i]->get_weight_key()<<" Name:" <<NodeArr[i]->get_vertex_name_data() <<endl;
	}
	for (int i = 0; i < _maxSize; i++)
	{
		cout <<  "vertex name: " << i + 1 << " index: " << index_vertex_array[i] << endl;
	}
}