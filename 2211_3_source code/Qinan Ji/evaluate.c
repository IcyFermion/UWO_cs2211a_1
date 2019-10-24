//
// Created by Qinan ji, qji8@uwo.ca, 251035136, on 2019-10-23.
//

#include <stdio.h>
#include <stdlib.h>

// Input: none, read from stdin
// Effect: get the next operator of the expression
// this operator can be +, -, *, /, or ’\n’
// ’\n’ indicates the end of the expression input
// leading spaces should skipped
// Output: return the next operator of the expression.
char get_op() {
	char op = getchar();
	while(op==' ')
		op = getchar();
	return op;
}
// Input: none, read from stdin
// Effect: get the next numeric value of the expression
// Output: return the next numeric value of the expression.
float get_num() {
	float num;
	scanf("%f", &num);
	return num;
}

// Input: ’sub_exp’: the value of the current sub m_expression
// to the left of ’op’ location in stdin.
// ’op’ : an operator, ’*’ or ’/’. ’op’ could also be
// ’+’, ’-’, or ’\n’ indicating the end of the m_expression.
// "+’, ’-’, or ’\n’ should be pushed back to stdin.
// the rest of the m_expression will be read in from stdin
// Effect: the m_expression is evaluated using recursion:
// get next_num with get_num() and then get next_op with get_op()
// use ’sub_exp op next_num’ and ’next_op’ to do recursive call
// Output: this function returns the value of the current m_expression
float m_exp(float sub_exp, char op) {
	if(op=='+' || op == '-' || op == '\n')
	{
		ungetc(op, stdin);
		return sub_exp;
	}
	float next_num = get_num();
	char next_op = get_op();
	if(op == '*')
		return m_exp(sub_exp*next_num, next_op);
	if(op == '/')
		return m_exp(sub_exp/next_num, next_op);
	return 0;
}

// Input: none, the s_expression will be read in from stdin
// Effect: the s_expression is evaluated using
// a while loop or a do while loop:
// repeatedly get num with m_exp() and then get op with
// get_op() while op is ’+’ or ’-’; when op is ’\n’, exit loop.
// Output: this function returns the value of the s_expression
float s_exp(void) {
	char op = ' ';
	float num = get_num();
	float result = num;
	while(op!='\n')
	{
		op = get_op();
		if (op == '+')
		{
			result = result + m_exp(get_num(), get_op());
		}
		if (op == '-')
		{
			result = result - m_exp(get_num(), get_op());
		}
		if (op == '*' || op == '/')
		{
			result = m_exp(num, op);
		}
	}
	return result;
}

int main ()
{
	char continue_or_not;
	do{
		printf("Expression: \n");
		printf("%f\n", s_exp());
		printf("Continue? y is continue and n is quit\n");
		scanf("%c", &continue_or_not);
	} while (continue_or_not == 'Y' || continue_or_not == 'y');
}