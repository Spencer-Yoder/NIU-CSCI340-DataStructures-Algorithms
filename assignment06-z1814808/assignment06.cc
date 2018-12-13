/*  Spencer Yoder
    Z1814808
    CSCI 340-2
    I certify that this is my own work and where appropriate an extension 
    of the starter code provided for the assignment.
*/
#include <iostream>
#include "assignment05.h"
#include "assignment06.h"


//PUBLIC FUNCTIONS***********************************************
//The public insert function calls the private function 
void BST::insert(int x)
{
  insert(root, x);
}

//Public search function calls the private function
bool BST::search(int x)
{
  return search(root, x);
}

//Public function that calls the private function
bool BST::remove(int x)
{
   return remove(root, x);
}

//Public function that call the private function
int BST::sumOfRange(const int lower, const int upper)
{
  return sumOfRange(root, lower, upper);
}


//PRIVATE FUNCTIONS*********************************************
//The insert function starts by checking to see if the r is empty.
//If it is then it make a new node. If it is not then it check to
//to see if the value of x is greater or lessthan the value in the
//tree. It then make a recursave call.
void BST::insert(Node*& r, int x)
{
  if (r == NULL) //If the r is empty
    {
      r = new Node(x); //make new node
      return;
    }

  if (x > r->value) //If the value of x is greater then the value of r then move to the right
    insert(r->right, x);

  else //else move to the left and look again
    insert(r->left, x);
}

//The Search function look to see if a value is in the tree or not.
//If the r is not null then it looks to see if the value of x is
//Greater or less then the value in the tree. It make recrusave
//calls to move with in the tree.
bool BST::search(Node*& r, int x)
{
  if(r != NULL) //If r is NULL stop
    {
      if(r->value == x) // If the value of x is the value of r in the tree. it is found
	return true;

      if(x < r->value)//If x is less then the r, move left
	search(r->left, x);

      else //else move right in the tree
	search(r->right, x);
    }
}

//The remove function finds x in the tree and looks to see how many
//leaves it has. It then removes the node and fixes the tree.
bool BST::remove(Node*& r, int x)
{
  if(r == NULL) //If the r is NULL stop
    return false;

  if (x < r->value) //If the value of x is more then x, move to the left
      remove(r->left, x);

  if(x > r->value) //If the value of x is less then x, move to the right.
    remove(r->right, x);


  
  if(x == r->value) //If x is found in the tree
   {
     if(r->left == NULL && r->right == NULL)//If there is no leaves
       {
	 delete r; //delete the node
	 r = NULL;//set it to NULL
	 return true;//Stop
       }

     else if(r->left == NULL)//If there is only one leaf
       {
	 r = r->right;//repoint the pointer
	 return true;
       }
     
     else if(r->right == NULL)//If there is only one leaf
       {
	 r = r->left;//repoint the pointer
	 return true;
       }
      
     else if(r->left != NULL && r->right != NULL)//If there is 2 leaves
       {
	 Node *tempNode = r;//Make temp node
	 Node *attach = r->right;//Make node to find the right subtree most left node
	 
	 while(attach->left != NULL)//Look in the right sub tree to find the smalles node
	   attach = attach->left;//update temp pointer node

	 attach->left = r->left;//remap pointers
	 r = r->right;
	 
	 delete tempNode;//delete the tempNode
	 return true;
       }//end else if
   }//end if
}//end function

//Sum of range function takes and lower and upper number and
//adds up the numbers in the tree that are within the 2 numbers.
int BST::sumOfRange(Node*& r, int lower, const int upper)
{
  if (!r)//If there is no r
    return 0; //stop

  if (r->value == upper && r->value == lower)//If the lower and upper are the same number
    return r->value;//return the one number

  if (r->value <= upper && r->value >= lower)//If r is between upper and lower keep looking
    return r->value + sumOfRange(r->left, lower, upper) + sumOfRange(r->right, lower, upper);//recrusive call the function adding up the numbers it finds

  else if(r->value < lower)//If the value of r is less then the lower number move to the right in the tree
    return sumOfRange(r->right, lower, upper);

  else //if the value of r is more then the upper move to the left
    return sumOfRange(r->left, lower, upper);

}
/*
    Summary: + Height incorrect after delete(-3)
    		+ Preorder/Post traversal incorrect(-6.5)
		+ 2 warnings(-2)
*/



