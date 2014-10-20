#include<stdio.h>

#define MAXDIGITS 100

#define PLUS 1
#define MINUS -1

typedef struct{
	char digits[MAXDIGITS];
	int signbit;
	int lastdigit;
} bignum;

void print_bignum(bignum *n){
	int i;
	if(n->signbit == MINUS) printf("-");
	for( i = n
