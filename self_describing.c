/*
PC/UVa IDs: 110607/10049, Popularity: C, Success rate: high Level: 2
Solomon Golomb’s self-describing sequence f (1), f (2), f (3), . . . is the only non-
decreasing sequence of positive integers with the property that it contains exactly f (k)
occurrences of k for each k. A few moment’s thought reveals that the sequence must
begin as follows:
n1 	1 2 3 4 5 6 7 8 9 10 11 12
f (n)	1 2 2 3 3 4 4 4 5 5  5  6

In this problem you are expected to write a program that calculates the value of f (n)
given the value of n.
Input
The input may contain multiple test cases. Each test case occupies a separate line and
contains an integer n (1 ≤ n ≤ 2, 000, 000, 000). The input terminates with a test case
containing a value 0 for n and this case must not be processed.
Output
For each test case in the input, output the value of f (n) on a separate line.
Sample Input
100
9999
123456
1000000000
0
Sample Output
21
356
1684
438744
*/
#include<stdio.h>
int self_describing(int n){
	int i,j,k,l,m,flage=0;
	k = 1;
	j = 1;
	m = 1;
	while(1){
		for(i = 0; i < k; i++){
			for(l = 0; l < k; l++){
				printf("%d -- %d\n",j,m);
				j++;
				if(j > n){
					flage = 1;
					return m;
				}
			}
			m++;
		}
		k++;
	}	
}
main(){
	int n,x;
	printf("input\n");
	scanf("%d",&n);
	x =  self_describing(n);
	printf("%d\n",x);
}
