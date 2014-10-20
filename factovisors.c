#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int *factor;

void find_factor(int n){
	int i;
	int sr = sqrt(n);
	for( i = 2; i <= sr; i++){
		while((n % i) == 0){
			factor[i]++;
			n = n / i; 
		}
	}
	factor[n]++;
}
int factovisors(int m){
	int sr = sqrt(m),k,i;
	for( i = 2; i <= sr; i++){
		while((m%i) == 0){
			if(factor[i] > 0){
				factor[i]--;
				m = m / i;
			}
			else
				break;
		}
	}
	if(factor[m] > 0){
		factor[m]--;
		m = 1;
	}
	if(m == 1)
		return 1;
	else
		return 0;
}
main(){
	int n,m,i,d;
	printf("enter the no n !\n");
	scanf("%d",&n);
	printf("enter the no m\n");
	scanf("%d",&m);
	
	factor = (int*) malloc(sizeof(int)*(n+1));
	for(i = 0; i <= n; i++)
		factor[i] = 0;
	
	for(i = n ; i >= 2; i--)
		find_factor(i);

//	for(i = 2; i <= n; i++)
//		printf("%d ---> %d\n",i,factor[i]);

	d = factovisors(m);
	
	if(d == 1)
		printf("%d divides %d!\n",m,n);
	else
		printf("%d does not divides %d!\n",m,n);
}
