/*Little Timmy is exceptionally good at math tables, so his maths teacher decided to make things a bit more interesting. His teacher takes two numbers A and B and merges the tables of A and B in sorted order (ascending order), removing the duplicates and thus creates supertable of A and B and asks Little Timmy the Nth number in the supertable.
Given A, B and N, calculate the Nth number in the supertable of A and B.

Input
First line contains number of test cases T . Each test case contains three integers A , B and N .

Output
For each test case print the Nth number of the supertable.

Constraints:
1<=T<=300000
1<=A, B<=1000
1<=N<=1000000000

Explanation
Test Case #1:

A=3, B= 5
Table of A = 3 , 6 , 9 , 12 ,15 ,18 and so on
Table of B =5 , 10 , 15 , 20 and so on
After Merging : 3, 5, 6, 9 ,10 , 12 ,15 ,15, 18, 20 and so on
Remove Duplicates : 3 , 5 , 6, 9 , 10 , 12 , 15 , 18 , 20 and so on
For N= 2 , 2nd element of the supertable is 5 .

Test Case #2:

For N=3 , 3rd element of the supertable is 6.

*/

#include<stdio.h>
#include<stdlib.h>
int fun(int a, int b, int n){
	int size = a+b-1;
	int *temp_array;
	temp_array = (int*)malloc(sizeof(*temp_array)*size);
	
	int ta = a, tb = b;
	int i;
	printf("size %d\n",size);
	for(i=0; i < size; i++){
					
		if(ta < tb){
			temp_array[i] = ta;
			ta = ta + a;
		}else {
			temp_array[i] = tb;
			tb = tb + b;
		}
	}
	
	int sub_q = n / size;
	int sub_r = n % size;
	printf("%d %d\n",sub_q,sub_r);
	printf("a %d b %d\n",a,b);
	int result = sub_q*a*b + temp_array[sub_r-1];
	printf("aaa %d %d\n",sub_q*a*1000 , temp_array[sub_r-1]);
	free(temp_array);
	return result;
}
			
main(){
	int a,b, n;
	int i, in_size;
//	scanf("%d",&in_size);
//	for(i = 0; i < in_size; i++){
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&n);
		printf("\na %d b %d n%d \n",a,b,n);
		printf("\nresult %d\n",fun(a,b,n));
//	}
}
