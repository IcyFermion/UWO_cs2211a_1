#include <stdio.h>
#include <stdlib.h>

// author:
// qji8@uwo.ca

int usr_mode;
void kiloToMiles ( char direction, float number );// the function to convert km and miles
void MeterToFeet ( char direction, float number );// the function to convert meter and feet
void cenToInch ( char direction, float number );// the function to cm and inch
void celsToFahre ( char direction, float number );// the function to celsius and fahrenheit

int calculation ()
{
	char direction;// the direction of calculation
	float number;// the value of calculation
	// information
	printf("\n\nPlease input \"Mode(char)\" first, then return; Input: \"Direction(char) Data(float)\" in the next line\n");
	printf("Mode table\n 1=km<->mile;\n 2=meter<->feet;\n 3=cm<->inch;\n 4=celsius<->fahrenheit;\n 5 exit\n");
	printf("Direction is the first upper case letter of data, for example: Kilometers = K\n");
	rewind(stdin);
	scanf("%d",&usr_mode);// get input
	if ( usr_mode == 1 ) // mode selection
	{
		scanf(" %c %f", &direction, &number);
		kiloToMiles(direction, number);
	} else if ( usr_mode == 2 )
	{
		scanf(" %c %f", &direction, &number);
		MeterToFeet(direction, number);
	} else if ( usr_mode == 3 )
	{
		scanf(" %c %f", &direction, &number);
		cenToInch(direction, number);
	} else if ( usr_mode == 4 )
	{
		scanf(" %c %f", &direction, &number);
		celsToFahre(direction, number);
	} else if ( usr_mode == 5 )
	{
		return 0;
	} else
		printf("input is invalid\n");
	calculation();
	return 0;
}

// main function of the program
int main ( )
{
	calculation();
}

// implementation of the declarion
void kiloToMiles ( char direction, float number )
{
	printf("calculation of km<->miles\n");
	if ( direction == 'K' )
		printf("%.2f Kilometers is %.2f Miles\n", number, number * 0.6213);
	else if ( direction == 'M' )
		printf("%.2f Miles is %.2f Kilometers\n", number, number * 1.60934);
	else
		printf("re-enter!\n");
}
// implementation of the declarion
void MeterToFeet ( char direction, float number )
{
	printf("calculation of meter<->feet\n");
	if ( direction == 'M' )
		printf("%.2f Meters is %.2f Feet\n", number, number * 3.2808);
	else if ( direction == 'F' )
		printf("%.2f Feet is %.2f Meters\n", number, number * 0.3048);
	else
		printf("re-enter!\n");
}
// implementation of the declarion
void cenToInch ( char direction, float number )
{
	printf("calculation of cm<->inch\n");
	if ( direction == 'C' )
		printf("%.2f Centimetre is %.2f Inches\n", number, number * 0.393701);
	else if ( direction == 'I' )
		printf("%.2f Inches is %.2f Centimetre\n", number, number * 2.54);
	else
		printf("re-enter!\n");
}
// implementation of the declarion
void celsToFahre ( char direction, float number )
{
	printf("calculation of C<->F\n");
	if ( direction == 'C' )
		printf("%.2f Celsius is %.2f Fahrenheit\n", number, number * ( 9.0 / 5 ) + 32);
	else if ( direction == 'F' )
		printf("%.2f Fahrenheit is %.2f Celsius\n", number, ( number - 32 ) / 1.8);
	else
		printf("re-enter the direction!\n");
}