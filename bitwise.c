/*
bitwise.c
Abraham Schultz
Last edited 3/4/2019 12:33 pm

This is a homework assignment for Temple University CIS 2107.

The c program will ask for two unsignedd integers from the user using 
stdn.  Then it will perform  arithimatic operations +,- * >, < using bitwise
operators only.
*/

#include <stdio.h>



unsigned int add(unsigned int, unsigned int);
unsigned int sub(unsigned int, unsigned int);
unsigned int mul(unsigned int, unsigned int);
unsigned int lt(unsigned int, unsigned int);
unsigned int gt(unsigned int, unsigned int);
unsigned int getByte(unsigned int, unsigned int);

int main(int argc, char **argv)
{

 unsigned int i, j;


 printf("Enter an integer ");

 scanf("%u", &i);
 printf("\nEnter another integer ");
 scanf("%u", &j);
 printf("\ni + j = %u\n", add(i,j));
 printf("\ni - j = %u\n", sub(i,j));
 printf("\ni * j = %u\n", mul(i,j));
 printf("i > j = %s\n", (gt(i,j) ? "TRUE" : "FALSE"));
 printf("i < j = %s\n", (lt(i,j) ? "TRUE" : "FALSE"));
 printf("jth byte of i = %ux\n", getByte(i,j));

 return 0;
}

unsigned int add(unsigned int i, unsigned int j)
{

    // Iterate till there is no carry   
    while (j != 0) 
    { 
        // carry now contains common  
        //set bits of x and j 
        int carry = i & j;   
  
        // Sum of bits of x and y where at  
        //least one of the bits is not set 
        i = i ^ j;  
  
        // Carry is shifted by one so that adding 
        // it to x gives the required sum 
        j = carry << 1; 
    } 

 return i;
}

unsigned int sub(unsigned int i, unsigned int j)
{


    // Iterate till there 
    // is no carry 
    while (j != 0) 
    { 
        // borrow contains common  
        // set bits of y and unset 
        // bits of x 
        int borrow = (~i) & j; 
  
        // Subtraction of bits of x  
        // and y where at least one 
        // of the bits is not set 
        i = i ^ j; 
  
        // Borrow is shifted by one  
        // so that subtracting it from 
        // x gives the required sum 
        j = borrow << 1; 
    } 


 return i;
}

unsigned int mul(unsigned int x, unsigned int y)
{
/* call the add function x times */
 	int product = 0;
 /* use the less than function and the add function in loop */
	for (int i = 0; lt(i,x); i = add(i,1)) {
	
	product = add(product,y);
	
 						}
 return product;
}

/* returns non-zero if i is less than j or zero otherwise */
unsigned int lt(unsigned int i, unsigned int j)
{
        unsigned int temp;
 	unsigned int x =i;
 	unsigned int y =j;
// we XOR to get bit where x doesnt have bit y 
 	temp = x ^ y;
 	x = temp & x;
 	y = temp & y;
//  check to see if they are the same
	if (temp == 0)
	return 0;

	//this loop should push x and y one bit at a time until x or y is 0
	while (y != 0 && x != 0){

	x = x >> 1;
	y = y >> 1;

}
	// if x is 0 then it is smaller than y
 	if (x == 0)
 	return 1;

	// else x is greater than y 
 	else  
 	return 0;

 
}

/* returns non-zero if i is greater than j or zero otherwise */
unsigned int gt(unsigned int i, unsigned int j)
{
 	unsigned int temp;
 	unsigned int x =i;
 	unsigned int y =j;
 
 	temp = x ^ y;
 	x = temp & x;
 	y = temp & y;

	if (temp == 0)
	return 0;

	while (y != 0 && x != 0){

	x = x >> 1;
	y = y >> 1;

}
 	if (x == 0)
 	return 0;

 	else  
 	return 1;

 




}

/* returns the jth byte of i */
unsigned int getByte(unsigned int i, unsigned int j)
{

	unsigned int x = i;
	unsigned int y = j;


	x = x  >>  j -1 ;

	x = x & 1;

	if (x)
	return 1;
	else 
	return 0;

}
