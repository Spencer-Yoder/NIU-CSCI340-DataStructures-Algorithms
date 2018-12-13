/*  Spencer Yoder
    Z1814808
    CSCI 340-2
    I certify that this is my own work and where appropriate an extension 
    of the starter code provided for the assignment.
*/
#include "assignment08.h"
using namespace std;

//This makes a new temp new entry "e" and sets the string into
//the correct strings in the entry.
Entry* get_entry(const string& line)
{
  int pos = 2;//used to step throught the string. Starts at 2 to skip the "A:"
  int first_length = 0;//length of the key
  int second_length = line.size();//length of the discreption
  Entry *e = new Entry();//new temp entry

  while(line[pos] != ':')//find the length of the first string
  {
    first_length++;
    pos++;
   }

  second_length = second_length - first_length - 2;//calculate the length of the second by takeing the whole thing by subtracting the first and the ":"
 
  (*e).key = line.substr(2, first_length);//set the key
  (*e).description = line.substr(pos+1, second_length);//set the discreption
  
  return e; //return the temp entry
}


//This function removes the first part of the string up until the ":"
string get_key(const string& line)
{
  string temp;//temp string to save it in

  for (string::const_iterator iter = line.begin()+2; iter != line.end(); ++iter) //iterrate through the string starting at position 2
    {
      temp.push_back(*iter);
    }
  
  return temp;
}


//********************************************************Class Funcitons*********************************************************************************
//This function searches the vector of entries looking at the keys to see
//if it matches. If it does then it returns true. other wise it return false
int HT::search(const string& key)
{
  int pos;//var to look at where is should be
  int start;//var that is used to keep the starting postions after pos has chenged
  bool test = false;

  pos = hashing(key);//get where is should be

  start = pos;//save pos to start

  //While loop starts at where is should be and moves on if it was not there
  while(!test)
    {
      if ((*hTable)[pos].key == key)//If found return true
	{
	  return pos;
	}
      
      pos++;
      
      if (pos > table_size)//if pos is larger then the table move to the front
	pos = 0;
      
      
      if (pos == start)//if it has gone throught the whole thing already
	return -1;
    }
  return -1;
}


//This function inserts the entry into the table. If the
//spot is full it then moves to the next spot until it finds a
//open slot
bool HT::insert(const Entry& e)
{
  int pos;
  bool test = false;

  if (table_size == item_count)//check to see if the table is full
    {
      cout << "Error: The Table is Full!" <<endl;
      return false;
    }

  for (int i = 0; i <= table_size; i++)//Check to see if the key is already in the table
   {
     if (e.key == (*hTable)[i].key)
	{
	  cout << "Error: The key is already in the Table!" <<endl;
	  return false;
	}
    }
  
  
  pos = hashing(e.key);//get where is should go

  while (!test)
    {
      if ((*hTable)[pos].key == "---" || (*hTable)[pos].key == "+++")//If the spot is free added it to the table
	{
	  (*hTable)[pos].key = e.key;//set key and description
	  (*hTable)[pos].description = e.description;
	  item_count++;//increase the count in the table
	  return true;
	}


      else//look for the next open spot
	{
	  pos++;

	  if (pos > table_size)//pos it bigger then table start at 0
	    pos = 0;
	}
    }

  return false;
}


//This function removes the entry in the table by setting the key equal
//to all +++ and decreases the item count in the table by one
bool HT::remove(const string& s)
{
  int pos;
  int start;
  bool test = false;

  //use the search function to see if the key is in the table
  if (search(s) == -1)
    return false;


  //get where is should be
  pos = hashing(s);
  start = pos;

  while(!test)//look for the key in the table
    {
      if ((*hTable)[pos].key == s)//if found set key to +++ and decrease item
	{
	  (*hTable)[pos].key = "+++";
	  item_count--;
	  return true;
	}

      else//keep looking in the table
	{
	  pos++;

	  if (pos > table_size)//if larger than table set equal to start
	    pos = 0;

	  if(pos == start)//if it made one compleate look of the table
	    return false;
	}
    }
  return false;
}


//Function print all of the used entries in the table
void HT::print()
{
  cout << "\n----Hash Table----"<<endl;

  for (int i = 0; i <= table_size; i++)//step through the while table 
    {
      if ((*hTable)[i].key.compare("---") != 0)//If it does not have --- in the key
	{
	  if ((*hTable)[i].key.compare("+++") != 0)//if it does not have +++ in the key print out the information
	    cout << i << ": " << (*hTable)[i].key << " " << (*hTable)[i].description << endl;
	  
	}
    }

  cout << "------------------" <<endl <<endl;
}
  

//********************************************Main program**********************************************************************************************

// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
int HT::hashing(const string& key) {
   return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}

int main(int argc, char** argv ) {
    if ( argc < 2 ) {
        cerr << "argument: file-name\n";
        return 1;
    }

    HT ht;
    ifstream infile(argv[1], ios::in);
    string line;
    infile >> line;    
    while ( !infile.eof() ) {
        if ( line[0] == 'A' ) { 
            Entry* e = get_entry( line );
            ht.insert( *e );
            delete e;
        }
        else {
            string key = get_key(line);
            if ( line[0] == 'D' ) {
                cout << "Removing " << key << "...\n";
                bool removed = ht.remove( key );
                if ( removed )
                    cout << key << " is removed successfully...\n\n";
                else
                    cout << key << " does not exist, no key is removed...\n\n";
            }
            else if ( line[0] == 'S' ) {
                int found = ht.search( key );
                if ( found < 0 ) 
                    cout << key << " does not exit in the hash table ..." << endl << endl;
                else
                   cout << key << " is found at table position " << found << endl << endl;
            }
            else if ( line[0] == 'P' ) {
                cout << "\nDisplaying the table: " << endl;
                ht.print();
            }
            else
                cerr << "wrong input: " << line << endl;
        }
        infile >> line;
 
    }

    infile.close();
    return 0;
}

/*
	Summary: No issues
*/

