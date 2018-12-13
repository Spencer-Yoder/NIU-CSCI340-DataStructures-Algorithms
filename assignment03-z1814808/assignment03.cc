/*  Spencer Yoder
    Z1814808
    CSCI 340-2

    I certify that this is my own work and where appropriate an extension
    of the starter code provided for the assignment.
*/ 
#include <iostream>
#include <set>
#include <iomanip> //used for setw 
#include <string> //Used for string for the main loop

using std::set;

const int NO_ITEMS = 8; //Const int for the number of items on a line
const int ITEM_W = 6; //Const int for the output width

//Function doses the main clacluation for
//finding if a number is prime or not. It
//Divides the numbers in the set by the count var
//and looks at the remander to see if it is 0 or
//not. If there is a remander then it is not divisble
//by the count. The count starts at 2 because that is
//first main prime number. It goes until the last
//number in the set.
void sieve(set<int>& s, const int lower, const int upper)
{
  int temp = 0; //Varable to store the remander

  for(int count = 2; count <= upper; count++) //for loop to divide the whole set by a number starting at 2
  {  
    for(set<int>::iterator it = s.begin(); it != s.end(); it++) //For loop that steps through the set one by one
      {
	temp = *it % count; //Get the remander from dividing the the number in the set by count varable

	if( count != *it) //if count is not equal to the number in the set.
	  {
	    if(temp == 0) //if the remander is 0 deleate it. Because it aint prime
	      {
		s.erase(it);
	      }//if
	  }//if 
      } //for
  } //for
}

//Print function that prints out the size and all
//of the prime numbers in the set. It only prints
//8 numbers on a line with 6 (or 7) spaces between
//each number.
void print_primes(const set<int>& s, const int lower, const int upper)
{
  int count_num = 0; //Variable to keep track of how many numbers are on the line 

  //Print how many prime numbers there is
  std::cout<< "There are " << s.size() << " prime numbers between " << lower << "  and " << upper << ": " <<std::endl;
    
  for (set<int>::const_iterator it = s.begin(); it != s.end(); it++) //for loop to step through set
  {
    if(count_num == NO_ITEMS) //If count = 8 make a new line
      {
	std::cout << std::endl;
	count_num = 0;
      }

      count_num++;
      std::cout <<std::setw(ITEM_W) << *it << " "; //Extra space needed to Make it look like results03.out
  }

  std::cout << std::endl << std::endl; //Make some new  empty lines
  
}

//Function that does the heavy lifting for the program
//It ask the user if they want to keep going or stop,
//and how many number do you want in the set. It takes
//the users responces and adds that many number to the set
void run_game(set<int>& s)
{
  
  int lower = 0; //Variable for the upper and lower limit inputed by the user 
  int upper = 0;
  std::string ans = ""; //string need to ask it the user wants to keep playing

  do {//do while loop to keep the game playing
    s.clear(); //Delete all of the contents of the set
    
    std::cout << "Please input lower bound and upper bound and hit enter (e.g. 10 100): " <<std::endl; //get upper and lower limit
    std::cin >> lower >> upper;

    std:: cout << std::endl; //Make some new lines
    
    if (lower >=  upper) //If the input are invalid
    {
      std::cout << "Invalid input! Please input the range again." <<std::endl;
      std::cin >> lower >> upper;
    }

    for(int i = lower; i <= upper; i++) //for loop to add numbers to the set
    {
      s.insert(i);
    }

    sieve(s, lower, upper); //call function
 
    print_primes(s, lower, upper); //call function
    
    std::cout << "Do You want to continue or not? Please answer yes or no and hit enter: " <<std::endl; //Does the user want to keep playing this Very fun game?
    std::cin >> ans;

  }while (ans == "Yes" || ans == "yes");
}

int main()
{
    set<int> s;
    run_game(s);
    return 0;
}

/*
 Summary: + No issues
*/


