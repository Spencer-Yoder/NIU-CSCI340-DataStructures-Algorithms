/*  Spencer Yoder
    Z1814808
    CSCI 340-2
    I certify that this is my own work and where appropriate an extension 
    of the starter code provided for the assignment.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string.h>
#include "assignment9.h"
using namespace std;


vector<int> order;//Vector order saves the order that the graph was transversed in
vector<int> steps;//Vector steps saves each move between the nodes in the graph
vector<bool> visited;//Vector visited keeps track if a node was visited yet


#define ASSIGNMENT9_TEST
#ifdef  ASSIGNMENT9_TEST

//The graph function opens the file and reads it for the info in it.
//It reads line by line and savest the data to the correct varables.
graph::graph( const char* filename )
{
  int vec_pos = 0;//Varable used to keep track of what line it is on
  string temp;//string used for getline
  
  ifstream infile(filename, ios::in);//Open file
  
  infile >> size;//Get the first line with the total size 
  
  adj_list = vector<list<int>> (size);//make adj_list with the correct number of nodes
  
  getline(infile, temp);//start getting lines
  getline(infile, temp);
  
  for(unsigned int i = 0; i < temp.size(); i++)//save the node letters in the vector labels
    {
      if(!isspace(temp[i]))//do not save white spaces
	labels.push_back(temp[i]);//add to labels
    }
  
  while(getline(infile, temp))//get the next lines
    {
      int counter = 0;//varable to keep track of where in the line a 1 is
      for(unsigned int i = 1; i < temp.size(); i++)//step through the line on place at a time
	{
	  if(!isspace(temp[i]))//skip white space
	    {
	      if(temp[i] == 49)//If the string is == to 49(ascii number for 1) 
		adj_list[vec_pos].push_back(counter);//add it to the vector list

	      counter++;
	    }//end of if
	}// end of for
      
      vec_pos++;
    }//end of while
  infile.close();//close the file
}//end of function


//This function prints the order of the graph from start to end.
void graph::print() const
{
  cout << "\nNumber of vertices in the graph: " << size <<endl <<endl;
  cout << "-------- graph -------" <<endl;
  
  for(int i = 0; i < size; i++)//Step through the vector
    {
      cout << labels[i] << ": ";//print the node
      
      for(list<int>::const_iterator iter = adj_list[i].begin(); iter != adj_list[i].end(); iter++)//iterate through the list
      {
	cout << labels[*iter] << ", ";//print edges
      }
      cout << endl;
    }
  
  cout << "------- end of graph ------" <<endl <<endl;
}


//This function is the public funciton that calls the private function for stepping through the graph
//and prints the transvers and edges.
void graph::traverse( )
{
  int count = 0;//used for printing the "(" ")"
    
  visited = vector<bool> (size, false);//set vector visited to size and to false
  
  for(int i = 0; i < size; i++)//call depth_first only on nodes that are false
    { 
      if(visited[i] == false)//if false
	{
	  int temp = steps.size();//get size befor the function
	  depth_first(i);//call function
	  steps.erase(steps.begin() + temp);//delete teh doubble entry for the steps vector
	}
    }
  
  
  cout << "------- travere of graph ------" <<endl;//print stuff
  
  for (vector<int>::iterator iter = order.begin(); iter != order.end(); iter++)//print the nodes in order of being visited
    {
      cout << labels[*iter] << " ";//print
    }
  
  cout <<endl;  
  
  for(vector<int>::iterator iter = steps.begin(); iter != steps.end(); ++iter)//Print the where the edges are
    {
      if (count == 0)//print (
	cout << "(";
            
      cout << labels[*iter];//print
      
      count++;

      if (count == 1)//print the : or the ) depending on what has been printed
	cout << ", ";
      
      if (count == 2)
	{
	  cout << ") ";
	  count = 0;
	}
      
    }//end of for
  cout << "\n--------- end of traverse -------" <<endl <<endl;
  
}


//This function does all of the hard work of rhe transvers function.
//it goes through the vector of list one by on looking to see if the
//node is already false. If it is, it used recursion for keep going
void graph::depth_first(int pos )
{
  if(!visited[pos])//check to see the node is visited
    {
      order.push_back(pos);//add the order to the vector order and steps
      steps.push_back(pos);
      
      visited[pos] = true;//set visited to true
      
      for(list<int>::const_iterator iter = adj_list[pos].begin(); iter != adj_list[pos].end(); iter++)//iterate throught the nodes list looking at the connecting nodes
	{
	  if(!visited[*iter])//if not visited
	    {
	      steps.push_back(pos);//add to steps
	      depth_first(*iter);//call recursion function
	    }//end of if
	}//end of for
    }//end of if
}//end of function
  

int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "args: input-file-name\n";
        return 1;
    }
    
    graph g(argv[1]);

    g.print();
    
    g.traverse();

    return 0;
}

#endif
