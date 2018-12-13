/*  Spencer Yoder
    Z1814808
    CSCI 340-2
    I certify that this is my own work and where appropriate an extension 
    of the starter code provided for the assignment.
*/
#include <iostream>
#include <vector>
#include <cstdlib> //Used for rand
#include <iomanip> //Used for setw
#include <algorithm> //Used for sort

using namespace std;

const int DATA_SIZE = 200;
const int SEARCH_SIZE = 100;
const int DATA_SEED = 7;
const int SEARCH_SEED = 9;

const int NUM_PER_LINE = 12; //const int for how may numbers are on a line
const int WIDTH = 5; //const int for the spaceing between numbers

//genRndNums function generates random numbers and
//adds them into a vector that is passed in. It uses
//rand to random gernerat numbers.
void genRndNums( vector<int>& v, int seed ) {

 const int LOW = 1; //The min and max that the numbers can be
 const int HIGH = 200;

  srand (seed);  //initialize the random number generator
  
  v.erase(v.begin(), v.end()); //clear the vector
  
  if (seed == DATA_SEED){ //if the seed is Data for the vector    
    for (int i = 1; i <= DATA_SIZE; i++) //loop as many times as it take to equal the DATA_SIZE
      v.push_back(rand() % (HIGH - LOW + 1) + LOW); //Generate and the add number to the vector
  }

  else{
    for (int i = 1; i <= SEARCH_SIZE; i++) //loop to add elements into the vector
      v.push_back(rand() % (HIGH - LOW + 1) + LOW);
  }
	  
}

//Linear Search function linear searches for  a number
//in order from start to end. It used iterators to find
//and calculate the position where the number is.
int linearSearch( const vector<int>& inputVec, int x) {
  vector<int>::const_iterator it; //create iterator it
  
  it = find(inputVec.begin(), inputVec.end(), x); //STL function to do the search

  auto pos = distance(inputVec.begin(), it); //find out what location the number is in the vector
  
  if (it != inputVec.end()){ //if the number is found
    return pos;
  }

  else
    return -1;
  
}

//Binary Search function uses a STL equal_range to find
//where the bounds of the number. If it finds the number
//then it returns the location to is.
int binarySearch( const vector<int>& inputVec, int x) {

  pair<vector<int>::const_iterator, vector<int>::const_iterator> it; //create a pair of iterator to stor the upper and lower bounds

  it  = equal_range(inputVec.begin(), inputVec.end(), x); //STL function to do the search

  if(it.first != it.second) //If the iterator do not match then return the position to the number
    return *it.first;

  else
    return -1;


}

//Serach function that call the correct search function and
//counts how many of the numbers in the search vector are
//found in the input vector. 
int search( const vector<int>& inputVec, const vector<int>& searchVec, int (*p)( const vector<int>&, int) ){

  int temp = 0;
  int count = 0;

  for (int i = 0; i <=(int)inputVec.size(); ++i) //for loop to step all the way throu the vector
    {
      temp = p(inputVec, searchVec[i]); //call the correct search function and get results and store in temp

      if(temp >= 0) //if the number was found
	count++;
    }

  return count; //return the total found
}

//Sort function that sorts the vector useing a STL sort function
void sortVector (vector<int>& inputVec) {
  sort(inputVec.begin(), inputVec.end());
}

//Print stat function that calclates the percentages
//and displays them.
void printStat (int totalSucCnt, int vec_size) {
  double total = 0;

  total = totalSucCnt /(double) vec_size; //Have to change 1 int into a double to out put the total as a double 
  total = total *100;

  cout << "Successful searches: " << fixed << setprecision(2) << total << "%" <<endl;
}

//Print function that prints the contents of both vectors.
void print_vec( const vector<int>& vec ){
        int NO_ITEM = 0; //Variable to count how many number are on each line.

        for (vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter) //for loop out out put all of the numbers in the vector
        {
                //if to check how many numbers are on each line
                if (NO_ITEM == NUM_PER_LINE){
                        cout << "\n";      //create a new line
                        NO_ITEM = 0;
                }

		cout << setw(WIDTH) << *iter; //out put the number via an iterator
		
                NO_ITEM++;
        }

	cout << endl;

}

int main() {
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED); //call function to random gernate numbers for the data vector
    genRndNums(searchVec, SEARCH_SEED); //make numbers for the search vector

    cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec ); //display inputVec contents
    cout << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec ); //dispay search vector contents

    cout << "\nConducting linear search on unsorted data source ..." << endl;
    int linear_search_count = search( inputVec, searchVec, linearSearch ); //linear search the unstored vector
    printStat ( linear_search_count, SEARCH_SIZE ); //display stats

    cout << "\nConducting binary search on unsorted data source ..." << endl;
    int binary_search_count = search( inputVec, searchVec, binarySearch ); //binary search the undtored
    printStat ( binary_search_count, SEARCH_SIZE );//show stats

    sortVector( inputVec ); //sort the stupid thing

    cout << "\nConducting linear search on sorted data source ..." << endl;
    linear_search_count = search( inputVec, searchVec, linearSearch );//linear search the sorted
    printStat ( linear_search_count, SEARCH_SIZE );//show stats time

    cout << "\nConducting binary search on sorted data source ..." << endl;
    binary_search_count = search( inputVec, searchVec, binarySearch ); //binary search the sotred 
    printStat ( binary_search_count, SEARCH_SIZE );//show the stats the last time

    return 0;
}

/*	TA:
	Summary of Issues:	No issues
	*/
