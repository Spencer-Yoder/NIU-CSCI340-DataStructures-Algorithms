/*  Spencer Yoder
    Z1814808
    CSCI 340-2
    I certify that this is my own work and where appropriate an extension 
    of the starter code provided for the assignment.
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include <algorithm>
using namespace std;

const int HEAP_SIZE = 50;
const int PRINT_COUNT = 8;
const int PRINT_SIZE = 5;

//This function sorts the vector to make sure that it is in a
//heap. It looks to see if the left side is less than the heap
//size and calls comapar the left and the size.
void heapify(vector < int >& v, int heap_size, int r, bool (*compar)(int, int))
{
  int left = 2 * (r); //get the left and right double of r
  int right = 2 * (r) + 1;
  int biggest;
  int temp;

  if (left <= heap_size && compar(v[left], v[r]))//If the left is smaller then the heao and the left is smaller then r
    {
      biggest = left; //make it the biggest one
    }

  else//else the biggest one is r
    {
      biggest = r;
    }

  if (right <= heap_size && compar(v[right], v[biggest]))//if the right is smaller the heap_size and then compar the right to the biggest one
    {
      biggest = right; //set right to biggest
    }
  
  if(biggest != r) //If the biggest one is not the r
    {
      temp = v[r];//temp equals vector the r
      v[r] = v[biggest];//r equals the biggest
      v[biggest] = temp;//and the biggest then equals r

      heapify(v, heap_size, biggest, compar); //recersive call heapify
    }
}

//This function builds the heap by going through the vector and calling heapify
void build_heap(vector < int >& v, int heap_size, bool (*compar)(int, int))
{
  for (int i = heap_size; i > 0; i--)//Start at the end and work to the start of the vector
    {
      heapify(v, heap_size, i, compar);//call heapify
    }

}

//This function checks to see if e1 is less than e2
bool less_than(int e1, int e2)
{
  if(e1 < e2)//If e1 is less than e2, if it is return true
    return true; 

  else
    return false;
}

//This function check to see if e1 is greater than e2
bool greater_than(int e1, int e2)
{
  if(e1 > e2)//If it is return true
    return true;

  else
    return false;
}

//This funciton extracts the first element in the vector and moves the last
//element into the first, updates heap_size, and then calls heapify. It
//retunrs the OG roor.
int extract_heap(vector < int >& v, int& heap_size, bool (*compar)(int, int))
{
  int temp = v[1];//save the first element in a temp

  v[1] = v[heap_size];//Make the last be the first
  v[heap_size] = temp;;//make the first be the last

  heap_size--;//make the heap smaller

  heapify(v, heap_size, 1, compar);//Time to heapify!!

  return temp;
}


//This funciton make the vector into a sorted vector by calling
//extract_heap in a for loop from the end to the beging+1 of the vector.
//Then it reverse the vector to be in the correct order
void heap_sort(vector < int >& v, int heap_size, bool (*compar)(int, int))
{ 
  for(int i = heap_size; i >= 2; --i)//Start at the end of the vector and move to the beging
    {
      extract_heap(v, heap_size, compar);//call extraxt_heap 
    }

  reverse(v.begin()+1, v.end()); //Flip the vector to be inthe correct order
}

//The print function prints the elements of the vector
//from start to finish
void print_vector(vector < int >& v, int pos, int size)
{
  int num = 0; //count how many numbers are on each line

  for(int count = 1; count <= size; count++)//go throught the whole vector starting at v[1]
    {
      if (num == PRINT_COUNT)//if there is 8 numbers on a line, make a new line
	{
	  cout<< endl;
	  num = 0; //clear the counter
	}
      
      cout << setw(PRINT_SIZE) << v[count];//do the actual output
      num++;
    }
  cout<< endl;
}



int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    for (int i=1; i<=HEAP_SIZE; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+HEAP_SIZE+1 );

    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    
    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, HEAP_SIZE, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, HEAP_SIZE, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );
    
    return 0;
}



/*
    Summary: No issues
*/
