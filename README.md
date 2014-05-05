Heap
====

Introduction 

• A binary heap is a data structure created using a binary tree with two additional constraints:

– The shape property : the tree is a complete binary tree ; that is all the levels of the tree, excepts possibly the l ast one (deepest) are fully filled, and if the last level of th e tree is not complete, the nodes of that level are filled from left to right.

– The heap property : the value at each node is greater than or equal to (or equivalently less than or equal to) each of its children. 

• Heaps with a mathematical "greater than or equal to " comparison function are called max-heaps ; those with a mathematical "less than or equal to" comparison function are called min-heaps . 

• Min-heaps are often used to implement priority queues . Since ordering of siblings is not specified by the heap property, a single node’s two children can be freely interchanged unless doing so violates the shape property.

• The term ‘ heap ’ was originally coined in the context of heapsort , but it has since come to refer to ‘ garbage collected storage ’, such as the programming languages Lisp and Java provide. 

• Our heap data structure is not a garbage collected storage and whenever we refer to heap in this presentation, we shall mean the structure that we j ust defined above.

Heap implementation

• Heaps are commonly implemented with an array.

• Any binary tree can be stored in an array, but because a heap is always an almost complete binary tree, it can be stored compactly.

• No space is required for pointers; instead, the parent and children of each node can be found by arithmetic on array indices. 
