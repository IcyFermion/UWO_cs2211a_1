#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// author:
// qji8@uwo.ca
// 

// the function to see if a number is even number or odd;
int even(int n)
{
	if((n-(int)(n/2)*2)==0)
		return 1;
	else if((n-(int)n/2)==1)
		return 0;
}

// the function to get a power n. a is base and n is exponent
float exponent(float a, int n) 
{
	if(n==0) return 1;
	else if (n==1) return a;
	else if(even(n)==1)
	{
		float res = exponent(a,n/2);
		return res*res;
	}
	else
	{
		float res = exponent(a,(n-1)/2);
		return res*res*a;
	}
}

int main()
{
	printf("what is the base number?\n");
	float a = 0; // a is the base number of expression
	scanf("%f", &a); // get input a
	printf("what is the exponent number?\n");
	int e = 0; // e is exponent number of expression
	scanf("%d", &e);// get input e
	float result = exponent(a, e);
	printf("%f power %d is: %f",a, e, result); // calculate it
	return 0;
}