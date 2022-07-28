heap is a data structure that keeps track of either the min element or the max element in the data structure.

Binary tree- each node has max degree of 2(<=2). so each node has either 0 or 1 or 2 childs at max.

perfect Binary tree- in this tree, all the levels are completely filled. meaning say at ith level there can
be max of 2^(i-1) nodes at that level(1 based levelling). if all the levels of a tree has these number of nodes 
then that tree is perfect binary tree.

almost complete binary tree- in this tree - 
1. leaves should be the present only at the last and second last level.
2. leaves at the same level must be filled from left to right.
3. almost complete binary tree will not have all levels completely filled. if it is filled then it is called
perfect binary tree.

complete binary tree=perfect binary tree + almost complete binary tree.

heap - 1.tree based data structure.
2. it is a nearly complete binary tree.(all levels are completely filled except the last one and is filled
from left to right).
3. this ds follows heap property.

two types of heap - A. min heap. ---> keeps track of min element at the root node.
B. max heap. ---> keeps track of the max element at the root node.

max heap- it is a complete binary tree in which the root node should always be the maximum and same goes for
all the root of the subtrees.(this is the heap property).
min heap - just vice versa.

representation of heap-
1. array implementation 

if parent = i  (i starts from 0).
then left child =2*i+1;
then right child=2*i+2;

if child=i
then parent =ceil(i/2)-1;

in a perfect binary tree, max nodes at given height h(0 based indexing) is 2^h.
max nodes in the entire tree upto height h is 2^(h + 1) - 1;

max size of the array= 2^(h+1)-1; (where h=height of the perfect binary tree - 0 based indexing).
and h=floor(log(n)-base2). (where n= no of nodes in the tree).

in a complete binary tree , range of leaves (0 based) = floor(n/2) to (n - 1).
range of internal nodes = 0 to (n/2 - 1).
 
if the array is in decending order then it will lead to a max heap else will lead to a min heap.

a leaf node always follow the min/max heap property as it is the max as well as the min element for
its (empty) subtree.

Heapify = the process of rearranging the heap by comparing each parent with his children recursively is
known as Heapify. here we assume that except the ith node, the rest of the subtree is a max heap/min heap.

max_heap_operations : 

1. find max = O(1).
2. delete max = O(log n).
3. insert = O(log n).
4. increase key = O(log n).
5. decrease key = O(log n).
6. find min = O(n).
7. delete random element = O(n).
8. search random element = O(n).