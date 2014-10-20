/*
PC/UVa IDs: 110104/706, Popularity: A, Success rate: average Level: 1
A friend of yours has just bought a new computer. Before this, the most powerful
machine he ever used was a pocket calculator. He is a little disappointed because he
liked the LCD display of his calculator more than the screen on his new computer! To
make him happy, write a program that prints numbers in LCD display style.
Input
The input file contains several lines, one for each number to be displayed. Each line
contains integers s and n, where n is the number to be displayed (0 ≤ n ≤ 99, 999, 999)
and s is the size in which it shall be displayed (1 ≤ s ≤ 10). The input will be terminated
by a line containing two zeros, which should not be processed.
Output
Print the numbers specified in the input file in an LCD display-style using s “-” signs
for the horizontal segments and s “|” signs for the vertical ones. Each digit occupies
exactly s + 2 columns and 2s + 3 rows. Be sure to fill all the white space occupied by
the digits with blanks, including the last digit. There must be exactly one column of
blanks between two digits.
Output a blank line after each number. You will find an example of each digit in the
sample output below.
Sample Input
2 12345
3 67890
0 0
Sample Output


*/

#include<stdio.h>
#define MAXLINE 10
char array[70][6];

FILE *fp;
int getline1(char s[], int l){ 
	int i;
	char c;
	for ( i = 0; (c = getc(fp)) != EOF && c != '\n'; ++i){
		s[i] = c;
		if ( c == '\n'){
			s[i] = '\n';
			++i;
		}
	}
	s[i] = '\0';
	return i;
}

void linecopy1(char s[], char d[]){

	int i;
	for( i = 0; s[i] != '\0'; i++)
		d[i] = s[i];
//		d[i] = '\0';
//
//	i = 0;
//	while((d[i] = s[i]) != '\0')
//		i++;
}
void getarray(){
	char line[MAXLINE];
	int len;
	fp = fopen("display","r");
	int i = 0;
	while( (len = getline1(line,MAXLINE) ) > 0){
		linecopy1(line,array[i]);
		array[i][4]=' ';
		array[i][5]='\0';
//			printf("%s\n",array[i]);		
	i++;
	}
}

void display(){
	int i, j;
	for (i = 0; i < 70; i++){
//		for(j = 0; j < 5; j++){
			printf("%s",array[i]);
//		}
		printf("\n");
	}
}
	  	
main(){
	int no,r,q;	
	getarray();
//	display();
	int a[10];
	scanf("%d",&no);
	r = no;
	int i = 0;
	while(r != 0){
		q = r % 10;
		a[i] = q;
		r = r / 10;
		i++;
	}
	int j,k;
	for(k = 0; k < 7; k++){
		for (j  = i-1; j >= 0; j--)
			printf("%s",array[(7*a[j]) + k]);
		printf("\n");
	}
	
}
