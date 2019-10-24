#include <stdio.h>

//
// Created by Qinan ji, qji8@uwo.ca, 251035136, on 2019-10-23.
//

const char segment[10][3][3] = {{{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}}, // initialization for segment 0; array#1
                                {{' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}}, //  initialization for segment 1; array#2
                                {{' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}},  //  initialization for segment 2; array#3
                                {{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}}, //  initialization for segment 3; array#4
                                {{' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}}, // initialization for segment  4; array#5
                                {{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}}, //  initialization for segment 5; array#6
                                {{' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}}, // initialization for segment  6; array#7
                                {{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}}, //  initialization for segment 7; array#8
                                {{' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}}, // initialization for segment 8; array#9
                                {{' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}}};  //  initialization for segment 9; array#10

int main() {

	// use a three dimensional array of characters to store the 10 digits.
	// x[array_index][row_index][column_index]

	char ch;

	/* do loop execution */
	do { //do while loop to keep on asking to run program

		// number
		int num;

		printf("\n Please enter your integer : ");

		scanf("%d", &num);

		/* local variable definition */
		int n = num; //making copy of number

		int c = 0, pos = 0;

		if(n>0)
		{
			while (num > 0) //counting how many digits in number

			{
				num = num / 10;
				c++;
			}

			int arr[c]; //array according to number of digits

			while (n > 0) {

				arr[pos] = n % 10; //breaking number and storing remainder in array
				n = n / 10;
				pos++;
			}

			for (int i = c - 1;
			     i >= 0; i--) //iterating arr from behind because remainder is stored in reverse order of number
			{
				for (int j = 0; j < 3; j++) {
					printf("\n");
					for (int k = 0; k < 3; k++) {
						printf("%c", segment[arr[i]][j][k]); //printing 3d array values
					}
				}
			}
		}
		else
		{
			n = -n; num = -num;
			printf("   \n --\n   ");
			while (num > 0) //counting how many digits in number

			{
				num = num / 10;
				c++;
			}

			int arr[c]; //array according to number of digits

			while (n > 0) {

				arr[pos] = n % 10; //breaking number and storing remainder in array
				n = n / 10;
				pos++;
			}

			for (int i = c - 1;
			     i >= 0; i--) //iterating arr from behind because remainder is stored in reverse order of number
			{
				for (int j = 0; j < 3; j++) {
					printf("\n");
					for (int k = 0; k < 3; k++) {
						printf("%c", segment[arr[i]][j][k]); //printing 3d array values
					}
				}
			}
		}


		printf("\n You want to continue(Y/N):");
		scanf("%c", &ch);

	} while (ch == 'Y' || ch == 'y');
	return 0;
}

