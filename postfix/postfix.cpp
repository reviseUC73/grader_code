#include <iostream>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iomanip> // for setprecision function

using namespace std;

// Function to evaluate a postfix expression and return the result
double evaluatePostfix(string expression)
{
    stack<double> operandStack; // stack to store operands

    // iterate through the string
    for (int i = 0; i < expression.length(); i++)
    {
        // if the current character is an operand, push it to the stack
        if (isdigit(expression[i]))
        {
            string operand = ""; // string to store the operand

            // extract the complete operand by iterating until a non-digit character is encountered
            while (i < expression.length() && isdigit(expression[i]))
            {
                operand += expression[i];
                i++;
            }

            // convert the operand string to double and push it to the stack
            operandStack.push(atof(operand.c_str()));
        }
        // if the current character is an operator, perform the operation
        else if (expression[i] == '+' || expression[i] == '-' ||
                 expression[i] == '*' || expression[i] == '/')
        {
            // pop the two operands from the stack
            double operand2 = operandStack.top();
            operandStack.pop();
            double operand1 = operandStack.top();
            operandStack.pop();

            double result = 0; // variable to store the result of the operation

            // perform the operation and store the result
            if (expression[i] == '+')
                result = operand1 + operand2;
            else if (expression[i] == '-')
                result = operand1 - operand2;
            else if (expression[i] == '*')
                result = operand1 * operand2;
            else if (expression[i] == '/')
                result = operand1 / operand2;

            // push the result back to the stack
            operandStack.push(result);
        }
    }

    // return the result from the stack
    return operandStack.top();
}

int main()
{
    string expression; // string to store the postfix expression
    string postfixExpression = ""; // string to store the complete postfix expression

    // read the postfix expression from the input
    while (cin >> expression)
    {
        if (expression == "=") // if the last token is encountered, break the loop
            break;

        // add the token to the postfix expression string
        postfixExpression += " " + expression;
    }

    // evaluate the postfix expression and print the result
    cout << fixed << setprecision(4) << evaluatePostfix(postfixExpression) << endl;

    return 0;
}
