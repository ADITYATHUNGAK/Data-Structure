/*Program in C for the following Stack Applications
a) Evaluation of Suffix expression with single digit operands and operators: +,-,*,/,%,^.
b) Solving Tower of Hanoi problem with n disks.*/

/*ALGORITHM
Step 1: Initialize an empty stack to hold operands during evaluation. Scan the postfix expression from left to right.
Step 2: If the symbol is an operand, push it onto the stack.
Step 3: If the symbol is an operator, perform the following steps:
        Pop the required number of operands from the stack (for binary operators, pop two operands). 
        Assign he first operand popped to opnd2 and the second operand popped to opnd1.
        Perform the operation using the current operator: res = opnd1 (operator) opnd2.
        Push the result of the operation (res) back onto the stack.
Step 4: Continue scanning the postfix expression until all symbols are processed.
Step 5: The final result of the postfix expression will be the only value remaining on the stack. Pop this value to obtain the result.
*/


//Part (a): Evaluation of Postfix (Suffix) Expression

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

// Function to compute result based on the operator and operands
float compute(char symbol, float op1, float op2)
{
    switch (symbol)
    {
        case '+': return op1 + op2;     // Addition
        case '-': return op1 - op2;     // Subtraction
        case '*': return op1 * op2;     // Multiplication
        case '/': return op1 / op2;     // Division
        case '^':
        case '$': return pow(op1, op2); // Power operation
        default : return 0;             // Default case
    }
}

void main()
{
    float s[20], res, op1, op2; // Stack to store operands, result, and operand values
    int top, i;                 // Top of stack and iterator for the expression
    char postfix[20], symbol;   // Postfix expression and symbol being evaluated

    // Input the postfix expression
    printf("\nEnter the postfix expression:\n");
    scanf("%s", postfix);

    top = -1; // Initialize stack top to -1 (empty stack)

    // Traverse the postfix expression
    for (i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i]; // Get the current symbol

        if (isdigit(symbol)) // If symbol is a digit, push it onto the stack
            s[++top] = symbol - '0'; // Convert char to integer
        else // If symbol is an operator, perform the operation
        {
            op2 = s[top--];  // Pop second operand from stack
            op1 = s[top--];  // Pop first operand from stack
            res = compute(symbol, op1, op2); // Compute result
            s[++top] = res;  // Push result back onto the stack
        }
    }

    // The final result is at the top of the stack
    res = s[top--];
    printf("\nThe result is : %f\n", res); // Display the result
}

