
#include "Max_Heap.h"
#include <cassert>
#include <iomanip>
#include <cmath>

using std::endl;
using std::swap;
//using std::floor;
using std::setw;

/*Creates a heap, provided the ranges*/
//template<class T>
//Max_Heap<T>::Max_Heap(typename vector<T>::iterator v_begin,
//					  typename vector<T>::iterator v_end)
//{
	/*Making sure that there is atleast one element in the
	vector*/
//	assert((v_end - v_begin) > 0);

	/*Starting index = 1
	Index location is left free*/
//	data.push_back(0);
//	size_t v_size = v_end - v_begin;
//	for(vector<T>::iterator itr = v_begin; itr != v_end; itr++)
//	{
//		data.push_back(*itr);
//	}

//	heap_size = v_size;

	/*Heapifying using Floyd's heap creation algorithm*/
//	make_heap();
//}

template<class T>
void Max_Heap<T>::make_heap()
{
	if(data.size() <= 1)
		return;
	else
		for(size_t i = (data.size()/2); i >= 1; i--)
		{
			heapify_down(i);
		}
}

template<class T>
void Max_Heap<T>::heapify_down(size_t index)
{
	/*comparing node with children*/
	assert(index <= heap_size);

	/*left -> 2i*/
	size_t left = (index << 1);
	/*right -> 2i + 1*/
	size_t right = (index << 1) + 1;

	size_t largest = index;

	if((left <= heap_size) && (data[left] > data[largest]))
	{
		largest = left;
	}

	if((right <= heap_size) && (data[right] > data[largest]))
	{
		largest = right;
	}

	if(largest != index)
	{
		swap(data[index], data[largest]);
		heapify_down(largest);
	}
}

template<class T>
Max_Heap<T>::Max_Heap(vector<T> v)
{
	/*Making sure that there is atleast one element*/
	assert(v.size() > 0);

	/*Starting index = 1
	index 0 is left free*/
	data.push_back(0);
	size_t v_size = v.end() - v.begin();

	for(typename vector<T>::iterator itr = v.begin(); itr != v.end(); itr++)
	{
		data.push_back(*itr);
	}

	heap_size = v_size;

	make_heap();
}

template<class T>
void Max_Heap<T>::heapify_up(size_t index)
{
	assert(index <= heap_size);
	size_t parent = index/2;

	if(data[index] > data[parent])
	{
		swap(data[index], data[parent]);
		heapify_up(parent);
	}

	return;
}

template<class T>
void Max_Heap<T>::push_heap(T value)
{
	data.push_back(value);
	heap_size++;
	heapify_up(heap_size);
	return;
}

template<class T>
void Max_Heap<T>::pop_heap()
{
	assert(!empty());

	/*If only one element left in the heap*/
	if(heap_size == 1)
	{
		heap_size = 0;
		data.clear();
	}

	/*More than one element*/
	else
	{
		data[1] = data[heap_size];
		--heap_size;
		data.pop_back();
		heapify_down(1);
	}
}

template<class T>
void Max_Heap<T>::levelorder_traversal(ostream &out = cout) const
{
	for(size_t i = 1; i < data.size(); i++)
	{
		out << data[i] << " ";
	}

	out << endl;
}

template<class T>
void Max_Heap<T>::print_tree(ostream &out = cout)
{
	out << endl;
	size_t h = height();
	vector<size_t> spaces;
	spaces.push_back(0);
	for(size_t i = 0; i <= h; i++)
	{
		spaces.push_back((spaces[i] + 1) * 2);
	}

	reverse(spaces.begin(), spaces.end());

	for(size_t i = 0; i < spaces.size(); i++)
	{
		out << spaces[i] << " ";
	}

	out << endl;

	size_t counter = 1;

	/*No. of levels*/
	for(size_t i = 0; i <= h; i++)
	{
		/*No. of nodes in one level*/
		for(size_t k = 0; k < pow(2.0, i*1.0); k++)
		{
			if(counter > heap_size)
				break;

			/*Print space before no.*/
			for(size_t j = 0; j < spaces[i]; j++)
			{
				out << ' ';
			}

			/*Print no.*/
			out << setw(3) << data[counter++];

			/*Print space before no.*/
			for(size_t j = 0; j < spaces[i] + 1; j++)
			{
				out << ' ';
			}
		}

		out << endl;

		if(counter > heap_size)
			break;

		/*Printing arrows*/
		size_t count_1 = spaces[i], count_2 = 0, count_3 = 1;

		/*No. of lines*/
		for(size_t j = 0; j < spaces[i]/2; j++)
		{
			/*No. of arrows per level*/
			for(size_t k = 0; k < pow(2.0, i * 1.0); k++)
			{
				/*Spaces before left arrow*/
				for(size_t l = 0; l < count_1 - count_3; l++)
				{
					out << ' ';
				}

				/*Left arrow*/
				out << "/";

				/*Spaces between left and right arrows*/
				for(size_t l = 0; l < 3 + count_2; l++)
				{
					out << ' ';
				}

				/*Right arrow*/
				out << "\\";

				for(size_t l = 0; l < count_1 - count_3; l++)
				{
					out << ' ';
				}

				/*Extra one space*/
				out << ' ';
			}

			cout << endl;
			count_2 += 2;
			count_3++;
		}
	}

	out << endl;
}

