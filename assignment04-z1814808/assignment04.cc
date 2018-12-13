/*  Spencer Yoder
    Z1814808
    CSCI 340-2
    I certify that this is my own work and where appropriate an extension
    of the starter code provided for the assignment.
*/ 
#include <iostream>
#include <iomanip>
#include <string>
#include "assignment04.h"

//Function that checks to see if both
//queue are empty. If they both are
//empty it returs true. But if they
//have things in them...you know I can
//not return true then.
bool Stack::empty() const {
  if(q1.empty() && q2.empty())//If empty return true
     return true;

  else
    return false;//else return that false thing
}


//Function that gets the size from the
//both queue and adds them togeather.
//It return the value then
int Stack::size() const {
  return (q1.size() + q2.size());//do Math, and return 
}


//Function that show that the first
//element in the "stack". But it is
//the last element in the queue. It
//return the "first" or last element
int Stack::top(){
  int temp;
  
  if(!q1.empty())//if q1 has the elements save the last one
    temp = q1.back();

  else//else q2 has the elements and save the last one
    temp = q2.back();

  return temp;//return the element
}


//Function that adds elements in to the "stack"
//If q1 is empty then it will add the element into
//q2. If both are empty it adds it to q2.
void Stack::push(const int& val) {
  if(!q1.empty())//If q1 is not empty add val to it
    q1.push(val);

  else//else add to q2
    q2.push(val);
}


//Function that removes elements from the stack.
//It checks to see which queue has elements in it
//and moves the elements from that one into the
//other queue. It moves elements until it has only
//one left and then removes it for ever. 
void Stack::pop() {
  if(!q1.empty())//If q1 has the data
    {
      while(q1.size() > 1)//loop unitl there is only 1 left
	{
	  q2.push(q1.front());//move the element from q1 -> q2
	  q1.pop();//remove the element from q1
	}
      q1.pop();//remove the last element with out moveing it
    }

  
  else
    {
      while(q2.size() > 1)//loop until there is 1 left
	{
	  q1.push(q2.front());//move elements q2 -> q1
	  q2.pop();
	}
      q2.pop();//pop the last one
    }
  
}

int main() {
    Stack s;
    std::string op;
    int val = 0;
 
   std::cout << "operation -- size front end" << std::endl;
   std::cin >> op;
   while ( !std::cin.eof() ) {
        if ( op == "push" ) {
            std::cin >> val;
            s.push( val );
            std::cout << op << " " << val << "    -- ";
        }
        else if ( op == "pop" ) {
            s.pop();
            std::cout << op << "       -- ";
        }
        else {
            std::cerr << "Error input: " << op << std::endl;
            return 1;
        }
        std::cout << std::setw(3) << s.size() << std::setw(5) << s.top() << std::endl;
        std::cin >> op;
    }

    while ( !s.empty() )
        s.pop();
    std::cout << "End -- size of Stack is: " << s.size() << std::endl;

    return 0;
}

/*
    Summary of changes: No issues
*/
