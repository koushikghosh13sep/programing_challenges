/*
PC/UVa IDs: 110102/10189, Popularity: A, Success rate: high Level: 1
Have you ever played Minesweeper? This cute little game comes with a certain op-
erating system whose name we can’t remember. The goal of the game is to find where
all the mines are located within a M × N field.
The game shows a number in a square which tells you how many mines there are
adjacent to that square. Each square has at most eight adjacent squares. The 4 × 4 field
on the left contains two mines, each represented by a “*” character. If we represent the
same field by the hint numbers described above, we end up with the field on the right:
*...
*100
....
2210
.*..
1*10
....
1110
Input
The input will consist of an arbitrary number of fields. The first line of each field
contains two integers n and m (0 < n, m ≤ 100) which stand for the number of lines
and columns of the field, respectively. Each of the next n lines contains exactly m
characters, representing the field.
Safe squares are denoted by “.” and mine squares by “*,” both without the quotes.
The first field line where n = m = 0 represents the end of input and should not be
processed.
Output
For each field, print the message Field #x: on a line alone, where x stands for the
number of the field starting from 1. The next n lines should contain the field with the
“.” characters replaced by the number of mines adjacent to that square. There must
be an empty line between field outputs.

Sample Input Sample Output
4 4 Field #1:
*... *100
.... 2210
.*.. 1*10
.... 1110
3 5 
**... 
..... 
.*... 
0 0 
Field #2:
**100
33200
1*100

*/
#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 100
int **a;
char **c;
int m,n;
int mine_no;
int getline1(char s[], int l){ 
	int i;
	char c;
	for ( i = 0; (c = getc(stdin)) != EOF && c != '\n'; ++i){
		s[i] = c;
//		if ( c == '\n'){
//			s[i] = '\n';
//			++i;
//		}
	}
	s[i] = '\0';
	return i;
}

void linecopy1(char s[], char d[]){
	int i;
	for( i = 0; s[i] != '\0'; i++)
		d[i] = s[i];
}

void input(){
	printf("enter row\n");
	scanf("%d",&m);
	printf("enter col\n");
	scanf("%d",&n);
	int i,j;
	a = (int**)malloc(sizeof(int*)*m);
	for(i = 0; i < m; i++)
		a[i] = (int*)malloc(sizeof(int)*n);

	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			a[i][j] = 0;
	
	c = (char**)malloc(sizeof(char*)*m);
	for(i = 0; i < m; i++)
		c[i] = (char*)malloc(sizeof(char)*n);
	int l;
	
	char line[100],ch;
	scanf("%c",&ch);
	for(i = 0; i < m; i++){
		getline1(line,MAXLINE);
		linecopy1(line,c[i]);
	}
}
void display(){
	int i,j;
	for(i = 0; i < m; i++){
		for( j = 0; j < n; j++)
			printf("%c",c[i][j]);
		printf("\n");
	}
	printf("\n");
	printf("\n");
	for(i = 0; i < m; i++){
		for( j = 0; j < n; j++){
			if(a[i][j] == 52)
				printf("*");
			else
				printf("%d",a[i][j]);
		}
		printf("\n");
	}
}
int mines_no(int i, int j){
	int k = 0;
	if(c[i][j] == '*'){
		return 52;
	}
	if(i != 0){
		if(j != 0)
		 	if(c[i-1][j-1] == '*') k++;
		if(c[i-1][j] == '*') k++;
		if(j != n-1)
			if(c[i-1][j+1] == '*') k++;
	}
	if( j != 0 )
		if(c[i][j-1] == '*') k++;
	if(j != n-1)
		if(c[i][j+1] == '*') k++;
	if(i != n-1 ){
		if( j != 0)
			if(c[i+1][j-1] == '*') k++;
		if(c[i+1][j] =='*') k++;
		if(j != n-1)
			if(c[i+1][j+1] == '*') k++;
	}
	return k;
}
void mines(){
	int i, j;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			a[i][j] = mines_no(i,j);
		}
	}
}
			
main(){
	input();
	mines();
	display();
}
