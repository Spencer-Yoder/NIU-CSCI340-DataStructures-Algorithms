/*  Spencer Yoder
    Z1814808
    CSCI 340-2
    I certify that this is my own work and where appropriate an extension 
    of the starter code provided for the assignment.
*/
#ifndef ASSIGNMENT08_H
#define ASSIGNMENT08_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct Entry { 
    std::string key;
    std::string description;
    
    Entry() { key = "---"; }
};

class HT {
    private:
        std::vector<Entry>* hTable;
        int table_size;
        int item_count;
        int hashing(const std::string&);
    public:
	//The constructor sets the max table size to 11 and makes new entries for the size of the table
        HT(int size = 11)
	  {
	    table_size = size;
	    hTable = new vector<Entry>(size);

	    for(int i = 0; i < size; i++)
	      {
		Entry e;
		(*hTable).push_back(e);
	      }
	  };
	
        ~HT()
	{
	  
	};
        bool insert(const Entry&);
        int search(const std::string&);
        bool remove(const std::string&);
        void print();
};

#endif
