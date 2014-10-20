/*
PC/UVa IDs: 110502/10018, Popularity: A, Success rate: low Level: 1
The reverse and add function starts with a number, reverses its digits, and adds the
reverse to the original. If the sum is not a palindrome (meaning it does not give the
same number read from left to right and right to left), we repeat this procedure until
it does.
For example, if we start with 195 as the initial number, we get 9,339 as the resulting
palindrome after the fourth addition:
	195
+	591
	 —–
	786

	786
+	687
	 ——
	1,473

	1,473
+	3,741
 	——
	5,214

	5,214
+	4,125
 	——
	9,339

This method leads to palindromes in a few steps for almost all of the integers. But
there are interesting exceptions. 196 is the first number for which no palindrome has
been found. It has never been proven, however, that no such palindrome exists.
You must write a program that takes a given number and gives the resulting
palindrome (if one exists) and the number of iterations/additions it took to find it.
You may assume that all the numbers used as test data will terminate in an answer
with less than 1,000 iterations (additions), and yield a palindrome that is not greater
than 4,294,967,295.
Input
The first line will contain an integer N (0 < N ≤ 100), giving the number of test cases,
while the next N lines each contain a single integer P whose palindrome you are to
compute.
Output
For each of the N integers, print a line giving the minimum number of iterations to find
the palindrome, a single space, and then the resulting palindrome itself.
Sample Input Sample Output
3 4 9339
195 5 45254
265 3 6666
750 


*/
#include<stdio.h>

int reverse(int r){
	int q, sum = 0;
	while(r != 0){
		q = r % 10;
		sum = sum*10 + q;
		r = r / 10;
	}
	return sum;
}
void reverse_add(int n){
	int rev,sum;
	int count=0;
	rev = reverse(n);
	while( rev != n){
		count++;
		n = n + rev;
		rev = reverse(n);
	}
	printf("count = %d  sum = %d\n",count, n);
}
main(){
	int n;
	printf("enter the no\n");
	scanf("%d",&n);
	reverse_add(n);
}
