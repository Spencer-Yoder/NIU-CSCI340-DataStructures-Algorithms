/*  Spencer Yoder
    Z1814808
    CSCI 340-2
    I certify that this is my own work and where appropriate an extension
    of the starter code provided for the assignment.
*/ 
#include <iostream>
#include <stack>
#include <string>
#include <fstream>


//This program reads lines from a file and inputs
//them into a string. It then goes character by character
//adding them into a stack and checking to see if the char
//is open or closed and check the top of the stack if it is
//closed.
int 
main()
{
  std::ifstream input("assignment98.in"); //open the input file
  
  std::string line;//string to store the line from the file

  while(std::getline(input, line))//while loop to keep going until there is no more line in the file
  {
    std::stack<char> stack; //Make a new stack to stor the string in
    bool check = true;//bool that stores if the string is well formed
      
    if (line.size() == 1) //to check to see if the string is longer then 1, if not stop looking
      check = false;

    else//start looking at whole string
      {	  
	for(std::string::iterator it=line.begin(); it !=line.end(); ++it)//iterate though the string
	  {
	 
	    if(*it == '{' || *it == '(' || *it=='[')//If it is open symble add it
	      stack.push(*it);
	  
	    else if(*it == '}' && stack.top() == '{')//If closed and match the top. pop it
	      stack.pop();

	    else if (*it == ')' && stack.top() == '(')//If closed and match the top. pop it
	      stack.pop();

	    else if (*it == ']' && stack.top() == '[')//If closed and match the top. "Flick it, Pull it, Twist it, Bop it,"
	      stack.pop();

	    else//else return false
	      check = false;
	  }

      }

    if(check == true)//If it passed all the test. It is all good
	std::cout <<  line << " Is  Well-Formed." <<std::endl;

    else//else it is a bad string
	std::cout<< line << " Is Not Well-Fomred." <<std::endl;

  }
  
  
    return 0;
}
