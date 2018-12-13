	CSCI 340						Computer Assignment 98	             Spring 2017
	
                  
<h2>Syntax Checker (Extra Credit up to 10 Points)</h2>

For this computer assignment, you are to write and implement a C++ program to implement the a syntax parser that will determine if a string is well-formed. 

The string(s) will contain symbols “{, }, [, ], (, )” is said to be well-formed if the different types of brackets match in the correct order. (e.g. “([]){()}” is well-formed, as is “[[({})]]”, but “{)” and “{[()}]” are not).  You will implement the syntax checker using an STL stack.

Your program will read data from `assignment98.in` and parse each string, where there is one string per line in the file. It will then output the string and if it is well-formed or not. The output will look as follows:

```text
String: [[({})]] is well-formed.
String: [[[} is NOT well-formed.
String: ((([]))) is well-formed.
String: [](){}[[]] is well-formed.
String: (){}[[]]) is NOT well-formed.
```

Starter code is provided in `assignment98.cc` within this Git repository.

**Programming Notes:**

* Do not change existing implementation in `assignment98.cc`. But you need to include any necessary headers and add necessary global constants. 
 
* You are not allowed to use any I/O functions from the C library, such as `scanf` or `printf`. Instead, use the I/O functions from the C++ library, such as `cin` or `cout`.

* To compile the source file, execute `g++ -std=c++11 -c -g -Wall -Wextra assignment98.cc –o assignment98.exe`.  This will create the executable file `assignment98.exe`.

* Add documentation to your source file (e.g. https://google.github.io/styleguide/cppguide.html#Comments).

* A basic Makefile is provided. 

* When your program is ready, ***commit*** and ***push*** your local repository to remote git classroom repository and follow _**Assignment Submission Instructions**_.  
