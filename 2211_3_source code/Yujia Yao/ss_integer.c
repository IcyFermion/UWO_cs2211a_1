#include <stdio.h>

//
// Yujia Yao, yyao272@uwo.ca
//

const char segment[11][3][3] = {{{ ' ', '_', ' ' }, { '|', ' ', '|' }, { '|', '_', '|' }},
                                {{ ' ', ' ', ' ' }, { ' ', ' ', '|' }, { ' ', ' ', '|' }},
                                {{ ' ', '_', ' ' }, { ' ', '_', '|' }, { '|', '_', ' ' }},
                                {{ ' ', '_', ' ' }, { ' ', '_', '|' }, { ' ', '_', '|' }},
                                {{ ' ', ' ', ' ' }, { '|', '_', '|' }, { ' ', ' ', '|' }},
                                {{ ' ', '_', ' ' }, { '|', '_', ' ' }, { ' ', '_', '|' }},
                                {{ ' ', '_', ' ' }, { '|', '_', ' ' }, { '|', '_', '|' }},
                                {{ ' ', '_', ' ' }, { ' ', ' ', '|' }, { ' ', ' ', '|' }},
                                {{ ' ', '_', ' ' }, { '|', '_', '|' }, { '|', '_', '|' }},
                                {{ ' ', '_', ' ' }, { '|', '_', '|' }, { ' ', '_', '|' }},
                                {{ ' ', ' ', ' ' }, { ' ', '-', '-' }, { ' ', ' ', ' ' }}
};

int main ()
{
	char ch = 'y';
	while ( ch == 'y' || ch == 'Y' )
	{
		printf("\n Enter an integer : ");
		int num;
		scanf("%d",&num);
		int n = num;
		int c = 0, pos = 0;
		if ( n > 0 )
		{
			positive:
			while ( num > 0 )
			{
				num = num / 10;
				c++;
			}

			int arr[c];

			while ( n > 0 )
			{
				arr[pos] = n % 10;
				n = n / 10;
				pos++;
			}

			for ( int i = c - 1; i >= 0; i-- )
			{
				for ( int j = 0; j < 3; j++ )
				{
					printf("\n");
					for ( int k = 0; k < 3; k++ )
					{
						printf("%c", segment[arr[i]][j][k]);
					}
				}
			}
		} else
		{
			n = -n;
			num = -num;
			for ( int j = 0; j < 3; j++ )
			{
				printf("\n");
				for ( int k = 0; k < 3; k++ )
				{
					printf("%c", segment[10][j][k]);
				}
			}
			goto positive;
		}
		n = num = 0;

		printf("\ncontinue(Y/N):");
		ch = getchar();
	}
}

