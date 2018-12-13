	CSCI 340				Computer Assignment 06	  	           Spring 2017

<h2>Binary Search Tree Class (15 points) [Due March 27, 2017]</h2>

For this computer assignment, implement a derived class to represent a binary search tree. Since a binary search tree is also a binary tree, implement your binary search tree class from the base class of binary trees, which you implemented in your previous assignment.

You are required to implement the binary search tree class in assignment06.cc file. You will need assignment06.h and assignment06main.cc, which are fully implemented. assignment06.cc already contains necessary headers. All files are available within the repository.

The definition of the derived binary search tree class is given here to facilitate the following description: 

```c++
class BST : public binTree{
public:
	BST():binTree(){}         			// constructor
	
	void insert(int);          			// insert an item in the tree
	
	bool search(int);          			// search an item in the tree
	
	bool remove(int);          			// remove an item in the tree
                                    	// returns true when successful
	
	int sumOfRange(const int lower, 	// the sum of values
					const int upper); 	//  between the range [lower, upper]
                                            
                                     
private:
	void insert(Node*&, int); 			// private version of insert(int)
	bool search(Node*&, int); 			// private version of search(int)
	bool remove(Node*&, int); 			// private version of remove(int)
	
	int sumOfRange(Node*& n, 			// private version of sumtOfRange
					int lower, const int upper); 
};
```
The above *public* functions simply call their *private* versions. The *private* versions of `insert()`, `remove()`, `search()` and `sumOfRange()` functions can be implemented as recursive functions. You can assume there are no identical numbers to be inserted into the tree.

When you implement the `remove()` function, consider three possible cases: the node to be removed (1) is a leaf; (2) has only one child; and (3) has two children. In the first case, simply delete the node. In the second case, bypass the node making a new link from its parent to its child, and delete the node. In the third case, find the immediate predecessor of the node – first move to the left child of the node, and then move to rightmost node in the sub-tree, replace the value of the node with its immediate predecessor, and delete the predecessor. The pseudo-code is shown below:
<span style="color:#000; font-family: Monaco; font-size: 1em;">
BinarySearchTree-Remove(Node n, int x)
if n is empty 
&nbsp;&nbsp;&nbsp;&nbsp;stop
if n’s data is greater than x
&nbsp;&nbsp;&nbsp;&nbsp;recursive call to BinarySearchTree-Remove(n’s left link, x)
if n’s data is less than x
&nbsp;&nbsp;&nbsp;&nbsp;recursive call to BinarySearchTree-Remove(n’s right link, x)
if n has two non-empty children
&nbsp;&nbsp;&nbsp;&nbsp;pred &leftarrow; find n’s immediate predecessor
&nbsp;&nbsp;&nbsp;&nbsp;copy pred’s data to n
&nbsp;&nbsp;&nbsp;&nbsp;recursive call to BinarySearchTree-Remove(n’s left link, pred’s data)
else if n is leaf
&nbsp;&nbsp;&nbsp;&nbsp;delete n
&nbsp;&nbsp;&nbsp;&nbsp;n &leftarrow; null
else // n has one child
&nbsp;&nbsp;&nbsp;&nbsp;temp &leftarrow; n
&nbsp;&nbsp;&nbsp;&nbsp;n &leftarrow; n’s only child
&nbsp;&nbsp;&nbsp;&nbsp;delete temp

</span>

**Programming Notes:**

* You need to copy your `assignment05.h` and `assignment05.cc` files into your local repository for `assignment06`[^1]. You may need to add a line of code in `assignment05.h` to make `BST` a friend class of your `Node` class if necessary. You need to comment out the statement `#define BINTREE_MAIN` in `assignment05.cc` since there is a new `main` method in `assignment06main.cc` file. 

* The three files `assignment06.h`, `assignment06.cc`, and `assignment06main.cc` are included within the repository. You need to add the implementation of `BST` class in `assignment06.cc`.

* In the final version of your assignment, you are not supposed to change existing implementation, including the `main` method, provided to you in the original files `assignment06.h` and `assignment06main.cc`. 

* To compile the source file, execute `g++ -Wall assignment05.cc assignment06.cc assignment06main.cc –o assignment06.exe`.  To test your program, execute `./assignment06.exe &> assignment06.out`. You can find the correct output of this program in file `results06.out` included within the repository.

* Add documentation to your source file (e.g. https://google.github.io/styleguide/cppguide.html#Comments).

* Prepare your `Makefile` so that the TA only needs to invoke the command `make` to compile your source file and produce the executable file `assignment06.exe`.  Make sure you use exactly the same file names specified here, i.e. `assignment06.h`, `assignment06.cc`, `assignment06main.cc` and `assignment06.exe`, in your `Makefile`. Otherwise your submission will get 0 points.

This semester you will need to make at least ***three commits*** to your local repository and ***three pushes*** to your master repository for each assignment. This will show the evolution of your assignments over time and the thought process behind the code. You will need to make sure your final ***push*** to your master repository is completed before the assignment is due (the system time stamps actions), if the assignment is late the TA will mark off points.

When your program is ready for grading, ***commit*** and ***push*** your local repository to remote git classroom repository and follow _**Assignment Submission Instructions**_. 

[^1]: ```git add assignment05.h assignment05.cc```
