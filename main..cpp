#include "Max_Heap.h"
#include <vector>

using namespace std;

int main()
{
	int ints[] = {20, 30, 10, 9, 8, 7, 6, 11, 9, 17, 18, 19};

	vector<int> v(ints, ints + (sizeof(ints)/sizeof(int)));

	/*Check whether it represents a valid heap*/
	if(Max_Heap<int>::is_heap(v.begin(), v.end()))
		cout << "Yes, it is a heap :D" << endl;
	else
		cout << "No it is not a heap :(" << endl;

	/*Creating a heap*/
	Max_Heap<int> heap_1(v);
	//cout << "Heap created: ";
	heap_1.levelorder_traversal();
	heap_1.print_tree();

	/*Getting height of heap*/
	cout << "Heap height: " << heap_1.height() << endl;

	/*Getting the max element*/
	cout << "Max element is: " << heap_1.find_max() << endl;

	/*Inserting a node*/
	heap_1.push_heap(5);
	cout << "After inserting 5: ";
	heap_1.print_tree();

    /*Delete the root*/
    heap_1.pop_heap();
    cout << "After deleting root: ";
    heap_1.print_tree();

    /*Sorting using heap sort*/
    //cout << "Heapsorting : ";
    //heap_sort<int>(v.begin(), v.end());

    /*Printing the sorted tree*/
    for(size_t i = 0; i < v.size(); i++)
    {
            cout << v[i] << " ";
    }
    cout << endl;

    /*Deleting 3 elements*/
    heap_1.pop_heap(), heap_1.pop_heap();
    heap_1.pop_heap();
    cout << "After 3 deletions: ";
    heap_1.levelorder_traversal();
    heap_1.print_tree();

    /*Height of tree*/
    cout << "Height: " << heap_1.height() << endl;

    return 0;
}
