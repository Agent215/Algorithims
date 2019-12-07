/*
fibDynamic.cpp

Abraham Schultz
12/7/2019

a program to compute the nth Fibonacci number in linear time
this program uses dynamic programing.
This only will give you results up to the size that the c++ long long variable can store
which is 9223372036854775807 .
*/
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <readline/readline.h>
#include <readline/history.h>
#include <iostream>
#include <string>

using namespace std;

int main ()
{

// hold user input
char * buf;
// prompt user
printf("Please type fibanachi number to compute\n" );
// get user input and wait for user to hit enter
buf = readline("");
// convert to int
long long fib = atoi(buf);

cout << "you entered" << fib  << endl;
// a table to store results
vector <long long> memoTable;
//counter
int i = 0;
long long f = 0;

for ( i =0 ; i < fib+1 ; i++)
{	if (i <= 2)
		{f =1;}
	else
		{f = memoTable.at(i -1) + memoTable.at(i-2);}
    // we add the result to our memo table
	memoTable.push_back(f);
} // end for

cout << "the " << fib << "th fib number is" <<  memoTable.at(fib) << endl;;

return memoTable.at(fib);
} // end main
