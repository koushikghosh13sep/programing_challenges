/*
The 3n + 1 Problem
PC/UVa IDs: 110101/100, Popularity: A, Success rate: low Level: 1
Consider the following algorithm to generate a sequence of numbers. Start with an
integer n. If n is even, divide by 2. If n is odd, multiply by 3 and add 1. Repeat this
process with the new value of n, terminating when n = 1. For example, the following
sequence of numbers will be generated for n = 22:
22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
It is conjectured (but not yet proven) that this algorithm will terminate at n = 1 for
every integer n. Still, the conjecture holds for all integers up to at least 1, 000, 000.
For an input n, the cycle-length of n is the number of numbers generated up to and
including the 1. In the example above, the cycle length of 22 is 16. Given any two
numbers i and j, you are to determine the maximum cycle length over all numbers
between i and j, including both endpoints.
Input
The input will consist of a series of pairs of integers i and j, one pair of integers per
line. All integers will be less than 1,000,000 and greater than 0.
Output
For each pair of input integers i and j, output i, j in the same order in which they
appeared in the input and then the maximum cycle length for integers between and
including i and j. These three numbers should be separated by one space, with all three
numbers on one line and with one line of output for each line of input.
Sample Input Sample Output
1 10 1 10 20
100 200 100 200 125
201 210 201 210 89
900 1000 900 1000 174



*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int e;
int *array;

int fun(unsigned int i){
	int length = 1;
	while(i != 1){
		if( (i < e) && (array[i] != 0)){
			return array[i] + length - 1;
		}
		length++;
		if((i % 2) == 0)
			i = i / 2;
		else
			i = 3*i + 1;
	}
	return length;
}
main(){
	time_t second1, second2;
	int s,len,i,maxlen=0;
	printf("enter the starting no\n");
	scanf("%d",&s);
	printf("enter the end no\n");
	scanf("%d",&e);

	array =(int*)malloc(sizeof(*array)*e);
	for(i = 0; i < e; i++)
		array[i] = 0;

//	second1 = time(NULL);
	for(i = s; i <= e; i++){
		len = fun(i);
		array[i] = len;
		if(maxlen < len)
			maxlen = len;
	}
//	second2 = time(NULL);
	printf("length %d\n",maxlen);
//	printf("time taken %d\n",second2 - second1);

}
