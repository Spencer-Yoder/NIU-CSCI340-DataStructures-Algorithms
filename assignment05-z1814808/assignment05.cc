/*  Spencer Yoder
    Z1814808
    CSCI 340-2
    I certify that this is my own work and where appropriate an extension 
    of the starter code provided for the assignment.
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "assignment05.h"

using namespace std;

const int MAX_SIZE = 40;
const int MAX_COUNT = 40;
const int WIDTH = 5;
const int ROW_SIZE = 8;

int mcount = 0;
int rcount = 0;

void display(int d) { //Function to display the values
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}

#define BINTREE_MAIN
#ifdef BINTREE_MAIN
int main() {
  vector<int> v(MAX_SIZE); //Make a vector
  for (int i=1; i<MAX_SIZE; i++) //For loop to generate numbers in teh vector
        v[i] = i;
  random_shuffle( v.begin(), v.end() ); //Mix them up

    binTree bt;
    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++) //add them into the tree
        bt.insert( *it );

    cout << "Height: " << bt.height() << endl; //display height
    cout << "Size: " << bt.size() << endl; //display size
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl; //show inorder
    mcount = rcount = 0;
    bt.inorder( display );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl; //show in pre order
    mcount = rcount = 0;
    bt.preorder( display );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl; //show in post order
    mcount = rcount = 0;
    bt.postorder( display );

    cout << endl;
    return 0;
}

//PUBLIC FUNCTIONS**********************************************************
void binTree::insert( int value ) //Call Private insert function
{
  insert(root, value);
}

int binTree::height() const //Call Private height function
{
  return height(root);
}

unsigned binTree::size() const //Call Private Size function
{
  return size(root);
}

void binTree::inorder(void(*)(int) ) //Call Private inorder function
{
  inorder(root, display );
}

void binTree::preorder( void(*)(int) ) //Call Private preorder function
{
  preorder(root, display);
}

void binTree::postorder( void(*)(int) ) //Call Private post order function
{
  postorder(root, display);
}


//PRIVATE FUNCTIONS*********************************************************
//This function inserts the number into the tree. It looks
//to see if the root is Null and if so it make a new node.
//If it is not null it looks at the size of the tree and
//decides to go left or right and call the function again.
void binTree::insert(Node*& r, int x)
{  
  if (r == NULL) //If root is null make new node
  {
      r = new Node(x);
      return;
  }
  
  if (height(r->right) < height(r->left)) //If the right side is smaller then the left, move to the right
  {
    insert(r->right, x);
  }

  else //Move to the left
  {
    insert(r->left, x);
  }
}


//The Size function gets the size of teh tree by recursively
//Calling itself and returning the size.
unsigned binTree::size( Node* r ) const
{
  if (r == NULL) //If there is noting there don't count it
    return 0;

  else //call function again on left and right
    return size(r->left) + 1 + size(r->right);
}


//The Height function looks at the numbers of layers in the tree.
//It recursively calls itself over and over
int binTree::height( Node* r) const
{  
  if(r == NULL) //If null remove 1
  {
      return -1;
  }
  
  else //Call itself again looking at left and right
  {
      return max(height(r->left), height(r->right)) + 1;
  }
}


//The inorder function transverses the tree in left to right,
//Bottom to top. It goes all the way to the left and works it
//way back up to the top, then to the right
void binTree::inorder( Node* r, void(*p)(int) )
{
 if(r)
    {
      inorder(r->left, p); //Move to the left all the way
      p(r->value); //get the value
      inorder(r->right, p); //move to the right
    }
}


//The preorder function transverses the tree in top to bottom,
//Left to right. It starts at the top and goes left. If there
//is no more left then it goes right.
void binTree::preorder( Node* r, void(*p)(int) )
{
  if(r)
    {
      p(r->value);//get value
      preorder(r->left, p); //move to the left
      preorder(r->right, p); //move to the right
    }
}


//The postorder function transverses the tree in bottom to top,
//left to right. It gets one layer at a time and then moves up one.
void binTree::postorder( Node* r, void(*p)(int) )
{
  if(r)
    {
      postorder(r->left, p); //move to the left
      postorder(r->right, p); //move to the right
      p(r->value); //get value
    }
}


#endif

/*
    Summary: No issues
*/

