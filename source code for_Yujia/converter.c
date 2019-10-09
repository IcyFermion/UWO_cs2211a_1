#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// author: yyao272@uwo.ca
//

// function convert km <-> miles
void km()
{
	char opt; float param;
	scanf(" %c %f", &opt, &param);
	if(opt=='K')
		printf("%.4f Kilometers is %.4f Miles\n", param, param*0.6213);
	else if (opt=='M')
		printf("%.4f Miles is %.4f Kilometers\n", param, param*1.60934);
	else
		write(2,"warning: wrong data type\n",25);
}

// function convert Meters <-> Feet
void mf()
{
	char opt; float param;
	scanf(" %c %f", &opt, &param);
	if(opt=='M')
		printf("%.4f Meters is %.4f Feet\n", param, param*3.2808);
	else if (opt=='F')
		printf("%.4f Feet is %.4f Meters\n", param, param*0.3048);
	else
		write(2,"warning: wrong data type\n",25);
}

// function convert Centimetre <-> Inches
void ci()
{
	char opt; float param;
	scanf(" %c %f", &opt, &param);
	if(opt=='C')
		printf("%.4f Centimetre is %.4f Inches\n", param, param*0.393701);
	else if (opt=='I')
		printf("%.4f Inches is %.4f Centimetre\n", param, param*2.54);
	else
		write(2,"warning: wrong data type\n",25);
}

// function convert Celsius <-> Fahrenheit
void cf()
{
	char opt; float param;
	scanf(" %c %f", &opt, &param);
	if(opt=='C')
		printf("%.4f Celsius is %.4f Fahrenheit\n", param, param*(9.0/5)+32);
	else if (opt=='F')
		printf("%.4f Fahrenheit is %.4f Celsius\n", param, (param-32)/1.8);
	else
		write(2,"warning: wrong data type\n",25);
}

int converter()
{
	Begin:
	// the function will start with >>> as a command typer
	//   char* is set as buffer for wrong input
	printf("\n>>> "); char act_s; scanf("%c", act_s); int act = atoi(act_s);
	if(act==1||act==2||act==3||act==4||act==5) // only this 5 is valid
	{
		printf("Mode %d\n", act);
		switch(act) 
		{
			case 1:
				km();
				break;
			case 2:
				mf();
				break;
			case 3:
				ci();
				break;
			case 4:
				cf();
				break;
			case 5:
			  printf("exit...");
				exit(1);
			default:
				break;
		}
	}
	else{ // error for wrong input
		printf("(mode %s)", act_s);
		write(2, "warning: wrong mode. ", 21);
	}
	rewind(stdin); // clear buffer
	goto Begin; // go back function
	return 0;
}

int main(int argc, char* argv[])
{
	// main function's intro
	printf("------------------------\nUser guide\n------------------------\n\
Input format\nmode\ntype data\n\n\
Input the conversion mode first.\n  1 for Kilometers & Miles\n  2 for Meters and Feet\n  3 for Centimetre & Inches\n  4 for Celsius & Fahrenheit\n  5 for quit\n\
  Type the other keys, including return, back to step 1\n\n\
Then input the initial letter of the Input data type, and input the data.\n\
  e.g. You want to change 30 Miles into kilometers, input:\n  `1`\n  `M 30`\n  1 stands for the mode 1, `M 30` means the input data is 30 miles,\n  and you want to know how many kilometers it is.\n");
	// calculation
	converter();
}