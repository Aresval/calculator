#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <string>
#include <stack>
#include <map>

bool isOperator(char c);
bool isLogicalOperator(char c);
bool isArithmeticOperator(char c);
bool isNumber(char c);
bool evaluateLogicalExpression(bool a, bool b, char op);
int evaluateArithmeticExpression(int a, int b, char op);
int evaluatePostfixExpression(std::string postfix);
std::string infixToPostfix(std::string infix);


#endif // CALCULATOR_H
