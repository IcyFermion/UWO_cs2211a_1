
#include <stdio.h>

int main(void) {

	int i, denom;
	double e, precision, temp;

	printf("Please enter the precision:");
	scanf("%lf", &precision);

	for (i = 1, denom = 1, e = 1, temp = 1; temp > precision; i++)
	{
		temp = ((double)1 / (denom *= i));
		e += temp;
	}

	printf("The approximation of e is %.10lf\n", e);

	return 0;
}
