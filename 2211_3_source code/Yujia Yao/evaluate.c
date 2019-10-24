//
// Yujia Yao, yyao272@uwo.ca
//

#include <stdio.h>
#include <stdlib.h>

char get_op() {
	char op = getchar();
	while(op==' ')
		op = getchar();
	return op;
}

float get_num() {
	float num;
	scanf("%f", &num);
	return num;
}

float m_exp(float sub_exp, char op) {
	if(op=='+' || op == '-' || op == '\n'){
		return sub_exp;
		ungetc(op, stdin);
	}
	float next_num = get_num();
	char next_op = get_op();
	if(op == '*')
		return m_exp(sub_exp*next_num, next_op);
	if(op == '/')
		return m_exp(sub_exp/next_num, next_op);
}

float s_exp(void) {
	char op;
	float n = get_num();
	float ans = n;
	do
	{
		op = get_op();
		if (op == '+' || op == '-')
		{
			if(op == '+')
				ans += m_exp(get_num(), get_op());
			if (op == '-')
				ans -= m_exp(get_num(), get_op());
		}
		if (op == '*' || op == '/')
			ans = m_exp(n, op);
	} while(op!='\n');
	return ans;
}

int main ()
{
	do{
		printf("Expression: \n");
		printf("%f\n", s_exp());
		printf("Continue? y is continue and n is quit\n");
		char c = getchar();
		if(c != 'y' && c!= 'Y')break;
	} while (1);
}