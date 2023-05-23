#include "Calculator.h"

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '!' || c == '&' || c == '|');
}

bool isLogicalOperator(char c) {
    return (c == '&' || c == '|');
}

bool isArithmeticOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isNumber(char c) {
    return (c >= '0' && c <= '9');
}

bool evaluateLogicalExpression(bool a, bool b, char op) {
    if (op == '&') {
        return (a && b);
    } else if (op == '|') {
        return (a || b);
    } else {
        return false;
    }
}

int evaluateArithmeticExpression(int a, int b, char op) {
    if (op == '+') {
        return (a + b);
    } else if (op == '-') {
        return (a - b);
    } else if (op == '*') {
        return (a * b);
    } else if (op == '/') {
        return (a / b);
    } else {
        return 0;
    }
}

int evaluatePostfixExpression(std::string postfix) {
    std::stack<int> operandStack;
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isNumber(c)) {
            operandStack.push(c - '0');
        } else if (isOperator(c)) {
            if (isLogicalOperator(c) && operandStack.size() >= 2) {
                bool operand1 = operandStack.top();
                operandStack.pop();
                bool operand2 = operandStack.top();
                operandStack.pop();
                operandStack.push(evaluateLogicalExpression(operand1, operand2, c));
            } else if (isArithmeticOperator(c) && operandStack.size() >= 2) {
                int operand1 = operandStack.top();
                operandStack.pop();
                int operand2 = operandStack.top();
                operandStack.pop();
                operandStack.push(evaluateArithmeticExpression(operand2, operand1, c));
            }
            else if (!isLogicalOperator(c) && !isArithmeticOperator(c)) {
                throw "Invalid operator!";
            }
            else {
                throw "Not enough operands!";
            }
        }
    }

    if (operandStack.size() == 1) {
        return operandStack.top();
    } else {
        throw "Invalid expression!";
    }
}

std::string infixToPostfix(std::string infix) {
    std::stack<char> operatorStack;
    std::string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isNumber(c)) {
            postfix += c;
        } else if (isOperator(c)) {
            if (operatorStack.empty() || operatorStack.top() == '(') {
                operatorStack.push(c);
            } else {
                char topOperator = operatorStack.top();
                while (!operatorStack.empty() && topOperator != '(' && (c != '&' || topOperator != '|' )) {
                    postfix += topOperator;
                    operatorStack.pop();

                    if (!operatorStack.empty()) {
                        topOperator = operatorStack.top();
                    }
                }
                operatorStack.push(c);
            }
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        } else {
            throw "Invalid character!";
        }
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}
