/*  Spencer Yoder
    Z1814808
    CSCI 340-2
    I certify that this is my own work and where appropriate an extension 
    of the starter code provided for the assignment.
*/
#ifndef ASSIGNMENT5
#define ASSIGNMENT5

class binTree;
class BST;

class Node {

  friend class binTree; //Make Node and friend of binTree calss

  int value; //Give each node a value, left, and right
  Node *left;
  Node *right;

  Node (int value1) //Node insert function.
   {
     value = value1; //set the new value to the value
     left = NULL; //make both pointer set to NULL
     right = NULL;
   }

};

class binTree {
 public:
        int height() const; //Public height function that calls the private function
        unsigned size() const; // public size function that call the private function
	
	virtual void insert( int ); //Public virtual insert function that calls the private function
        void inorder( void(*)(int) ); //Public function that calls the private version
        void preorder( void(*)(int) ); //Public function that calls the private version
        void postorder( void(*)(int) ); //Public function that calls the private version

 protected:
        Node* root = NULL; //Store the Root

 private:
        int height( Node* ) const; //Function that calculate the height
        unsigned size( Node* ) const; //Function that gets the size
	void insert( Node*&, int ); //Function that inserts a new node
        void inorder( Node*, void(*)(int) ); //Function that gets the tree in inorder
        void preorder( Node*, void(*)(int) ); //Function that gets the value in preorder
        void postorder( Node*, void(*)(int) ); //Function that gets the value in postorder
};

#endif
