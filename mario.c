#include <stdlib.h>
#include <stdio.h>

/*
Abraham Schultz
2019
This was a program i wrote as part of a google games event
the program solves the problem for when mario hits a coin box

on each time he hits the box he gets coins numbering the amount of times he has hit
the box up until that point.

but every third time he gets double the coins,
every 5th time he gets tripple the number of coins,
and every 15th time he gets  10 times the number of coins.

this was solved using the modulo function

the problem asked for the total number of coins after 1000 hits.

*/



int main (){

int i = 1;
int total= 0;
int temp;


// because we run the loop 1000 times
for (i; i < 1001; i++)
{

	if ( i % 15 == 0 )
		{
		temp = 10 *i;
		total =  total + temp;
                }// end if

	else if ( (i % 3 == 0) && (i % 15 != 0)&&(i % 5 !=0))
		{
		temp = 2 * i;
		total = total + temp;
		} // end if 
	 
	else if ((i % 5 == 0 )&& (i % 15 != 0)&&( i % 3 != 0))
		{
		temp = 3 * i;
		total = total + temp;
		} // end if

	else
	       {
		total = total + i;
       	       }// end else
printf("total for this loop %i  %i \n", i, total);
} // end for




printf("Total %i \n", total);

return 0;
} // end main



