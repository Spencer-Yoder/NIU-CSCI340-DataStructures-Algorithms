/*  Spencer Yoder
    Z1814808
    CSCI 340-2

    I certify that this is my own work and where appropriate an extension 
    of the starter code provided for the assignment.
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>	//Used for setw()

const int DATA_RANGE = 100;
const int DATA_SIZE = 100;
const int DATA_SEED = 7;
const int SEARCH_SEED = 9;

//The Linear search function check the numbers in the
//Vector one number at a time in order, from start to finish.
//It uses a while loop to setp through the vector one by one.
//If the current place in the vector = X then it returs
//True. If the loop gets to the end befor the number is 
//found then ir returns false.
bool linear_search(const std::vector<int>& inputVec, const int x, int& comparisons){
	int total = inputVec.size();

	comparisons = 0;
	// TA : Sample comment: Iterating through all elements of input vector to check for 'x'
	while (comparisons < total)
	{
		if (inputVec[comparisons] == x)		// TA : Sample comment: Found 'x' in Input Vector
		{
			comparisons++;
			return true;
		}
		comparisons++;
	}

	return false;

}

//The Binary Search function, searchs the vector if a number
//is bigger or smaller then the middle abount. It calculates
//the middle by getting the end  point and the start point,
//adds them togeather and divides by 2. If start and end point
//come togeather then the function return false. 
bool binary_search(const std::vector<int>& inputVec, const int x, int& comparisons){

	comparisons = 0;

	int size = inputVec.size();
	int start = inputVec[0];
	int end = inputVec[size];
	int mid = 0;


	while (start <= end){

		comparisons++;

		mid = (start + end) / 2;

		if (x == inputVec[mid]){
			return true;
		}

		else if(x < inputVec[mid]){
			end = mid - 1;
		}

		else{
			start = mid + 1;
		}
	}

	comparisons++;
	return false;
}

//function print_ved takes the vector vec and displays it.
//It users iterators to step through the vector
//until it reaches the end of the vector. It counts
//the number of numbers on a line are starts a new
//if it reaches 10. There is a width of 6 spaces
//between of the numbers in the output list.
void print_vec( const std::vector<int>& vec ){
	int count = 0;	//Temp Variable to move though the vector.
	int NO_ITEM = 0; //Variable to count how many number are on each line.

	for (std::vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		//if loop to check how many numbers are on each line
		if (NO_ITEM ==10){	// TA : Avoid magic numbers like '10'
			std::cout << "\n";	//create a new line
			NO_ITEM = 0;
		}

		std::cout << std::setw(6) << vec[count];	//out put the object in the vector

		count++;
		NO_ITEM++;
	}
}

void average_comparisons(const std::vector<int>& inputVec, const std::vector<int>& searchVec, bool (*search)(const std::vector<int>&, const int, int&) ) {
    int i, comparison=0, sum=0, found = 0;
    bool res;
    for (i=0; i<(int)searchVec.size(); i++) {
        res = search( inputVec, searchVec[i], comparison );
        sum += comparison;
        if ( res )
           found++;
    }
    std::cout << found << " numbers are found. The average number of comparisons in each search: " << (double)sum/(double)searchVec.size() << std::endl << std::endl;
}

int random_number() {
    return rand()%DATA_RANGE+1;
}

int main () {

    // -------- create unique random numbers ------------------//
    std::vector<int> inputVec(DATA_SIZE);
    srand(DATA_SEED);
    generate(inputVec.begin(), inputVec.end(), random_number);
    sort(inputVec.begin(), inputVec.end());
    std::vector<int>::iterator it = unique(inputVec.begin(), inputVec.end());
    inputVec.resize( it - inputVec.begin() );
    random_shuffle( inputVec.begin(), inputVec.end() );

    std::cout << "------ Data source: " << inputVec.size() << " unique random numbers ------" << std::endl; 
    print_vec(inputVec);
    std::cout << std::endl;

    // -------- create random numbers to be searched ---------//
    std::vector<int> searchVec(DATA_SIZE/2);
    srand(SEARCH_SEED);
    generate(searchVec.begin(), searchVec.end(), random_number);

    std::cout << "------ " << searchVec.size() << " random numbers to be searched: ------" << std::endl;
    print_vec(searchVec);
    std::cout << std::endl;

    std::cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    std::cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    sort(inputVec.begin(), inputVec.end());
    std::cout << "------- numbers in data source are now sorted ---------" << std::endl << std::endl;
    std::cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    std::cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    return 0;

}
/*	TA:
	Summary of Issues:	
		
	1. Documentation needs to be improved, every function documentation costs 5 points, docbox costs 5 points
	2. Avoid magic numbers usage in code, can cost 1 for each magic number
	3. Makefile is incomplete, refer notes/slides
*/


