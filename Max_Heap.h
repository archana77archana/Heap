#ifndef __Max_Heap_H__
#define __Max_Heap_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;
using std::ostream;
using std::cout;
using std::swap;
using std::endl;

template <class T>
class Max_Heap
{
	private:
		vector<T> data;
		size_t heap_size;

		/*Maintain the heap properly by moving node
		at index down the heap*/
		void heapify_down(size_t index);

		/*Make a heap out of the elements in the vector*/
		void make_heap();

		/*Maintain the heap properly by moving node
		at index up the heap*/
		void heapify_up(size_t index);

		//void pop_heap_without_delete();

	public:

		/*Creates a heap, provided the ranges*/
		Max_Heap(
			typename vector<T>::iterator v_begin,
			typename vector<T>::iterator v_end
			)
		{
			/*Making sure that there is atleast one element in the
			vector*/
			assert((v_end - v_begin) > 0);

			/*Starting index = 1
			Index location is left free*/
			data.push_back(0);
			size_t v_size = v_end - v_begin;
			for(typename vector<T>::iterator itr = v_begin; itr != v_end; itr++)
			{
				data.push_back(*itr);
			}

			heap_size = v_size;

			/*Heapifying using Floyd's heap creation algorithm*/
			make_heap();
		}

		/*Creates a heap using an entire vector*/
		Max_Heap(vector<T> v);

		/*push the value to the last and then re_heapify*/
		void push_heap(T value);

		/*delete_root and re-heapify*/
		void pop_heap();

		void levelorder_traversal(ostream& out) const;

		static bool is_heap(typename vector<T>::iterator first, typename vector<T>::iterator last);

		void print_tree(ostream& out);

		T find_max() const
		{
			return peek();
		}

		T peek() const
		{
			return data[1];
		}

		bool empty() const
		{
			return (heap_size == 0);
		}

		size_t size() const
		{
			return heap_size;
		}

		int height()
		{
            return int(log(double(heap_size))/log(2.0));
		}

};

template<class T>
bool Max_Heap<T>::is_heap(typename vector<T>::iterator first,
                          typename vector<T>::iterator last)
{
	size_t parent = 0, left = 0, right = 0, size = 0;
	size = last - first;
	cout << "size: " << size << endl;

	for(parent = 0; parent < size/2; parent++)
	{
		left = (parent << 1) + 1;
		right = left + 1;

		if((first + left) < last)
		{
			cout << "Comparing " << *(first + parent)
				<< " and " << *(first + left) << endl;

			if(*(first + left) > *(first + parent))
			{
				return false;
			}
		}
	}

	return true;
}

#include "Max_Heap.cpp"
#endif
