/*Program in C for converting an Infix Expression to Postfix Expression.
Program should support for both parenthesized and free parenthesized expressions with the operators: +, -, *, /, % (Remainder), ^ (Power) and alphanumeric operands. */



#include<stdio.h>
#include<stdlib.h>

// Declare infix, postfix expressions and stack arrays
char infix[30], postfix[30], stack[30];
int top = -1; // Initialize stack top to -1 (empty stack)

// Function to push an operator onto the stack
void push(char item)
{
    top = top + 1; // Increment the top index
    stack[top] = item; // Add the item to the stack
}

// Function to pop an operator from the stack
char pop()
{
    char item;
    item = stack[top]; // Retrieve the top element from the stack
    top = top - 1; // Decrement the top index
    return item; // Return the popped item
}

// Function to define operator precedence
int prec(char symb)
{
    int p; // Declare precedence value
    switch(symb)
    {
        case '#' : p = -1; // '#' used as initial symbol in the stack
                   break;
        case '(' :
        case ')' : p = 0; // Parentheses have the lowest precedence
                   break;
        case '+' :
        case '-' : p = 1; // Addition and subtraction have precedence 1
                   break;
        case '*' :
        case '/' :
        case '%' : p = 2; // Multiplication, division, and modulus have precedence 2
                   break;
        case '^' :
        case '$' : p = 3; // Exponentiation has the highest precedence
                   break;
    }
    return p; // Return precedence value
}

// Function to convert infix to postfix
void evaluate()
{
    int i = 0, j = 0; // i for infix traversal, j for postfix
    char symb, temp;
    push('#'); // Push '#' as a sentinel value onto the stack

    // Traverse each character of the infix expression
    for(i = 0; infix[i] != '\0'; i++)
    {
        symb = infix[i]; // Get the current character (operator or operand)
        switch(symb)
        {
            // If the character is '(', push it onto the stack
            case '(' : push(symb);
                       break;

            // If the character is ')', pop until '(' is found
            case ')' : temp = pop();
                       while(temp != '(' )
                       {
                           postfix[j] = temp; // Append operators to postfix
                           j++;
                           temp = pop();
                       }
                       break;

            // If the character is an operator, pop operators with higher or equal precedence
            case '+' :
            case '-' :
            case '*' :
            case '/' :
            case '%' :
            case '^' :
            case '$' : while( prec(stack[top]) >= prec(symb) )
                       {
                           temp = pop(); // Pop operator from stack
                           postfix[j] = temp; // Add operator to postfix
                           j++;
                       }
                       push(symb); // Push the current operator onto the stack
                       break;

            // If the character is an operand (alphanumeric), add it to postfix
            default: postfix[j] = symb;
                     j++;
        }
    }

    // Pop all remaining operators from the stack
    while(top > 0)
    {
        temp = pop();
        postfix[j] = temp;
        j++;
    }
    postfix[j] = '\0'; // End the postfix expression with a null character
}

// Main function to input infix expression and display the postfix result
void main()
{
    printf("\nEnter the valid infix expression:\t");
    scanf("%s", infix); // Take the infix expression input from the user
    evaluate(); // Call the evaluate function to convert infix to postfix
    printf("\nThe entered infix expression is :\n %s \n", infix);
    printf("\nThe corresponding postfix expression is :\n %s \n", postfix);
}
