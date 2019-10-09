#include <stdio.h>
#include <math.h>

// author:
// qji8@uwo.ca
// 

// recursively get the result
float calculation(float a, int n)
{
	float result;
	if(n==0)
		return 1;
	else if(n%2==0) // if it is even number, run formula one
	{
		result = calculation(a,n/2);
		return result*result;
	}
	else // else, run formula 2
	{
		result = calculation(a,(n-1)/2);
		return result*result*a;
	}
}

int main()
{
	printf("input the base and exponent of expression, spilt with space: (for example, 1.1 2)\n");
	float base; int exponent;// two variable for base and exponent
	scanf("%f %d", &base, &exponent); // get the input
	printf("the final answer is: %f",calculation(base, exponent));// show result
}