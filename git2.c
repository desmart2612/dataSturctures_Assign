#include<stdio.h>
#include<string.h>

int main(void)
{
    char element, equation[100];
    int i, j, length;
    int top;

    top = -1;
    length = 0;

    printf("Enter your equation below putting an '=' at the end of the equation:\n");
    for(i = 0; i < 100;i++)
    {
        scanf(" %c",&equation[i]); // Added a space before %c to skip any whitespace characters
        length++;
        if(equation[i] == '=')
            break;
    }

    char stack[length];

    for(i = 0; i < length; i++) // Changed the loop condition to iterate over the entire equation
    {
        if(equation[i] != '=')
        {
            element = equation[i];

            if(equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/' || equation[i] == '%')
            {
                if(top == -1)
                {
                    top++;
                    stack[top] = equation[i];
                }
                else if(stack[top] == '(')
                {
                    top++;
                    stack[top] = equation[i];
                }
                else
                {
                    while(top != -1 && stack[top] != '(')
                    {
                        printf("%c", stack[top]);
                        top--;
                    }
                    top++;
                    stack[top] = element;
                }
            }
            else if(equation[i] == '(')
            {
                top++;
                stack[top] = element;
            }
            else if(equation[i] == ')')
            {
                while(top != -1 && stack[top] != '(')
                {
                    printf("%c", stack[top]);
                    top--;
                }
                if(top != -1)
                    top--; // Pop the '(' symbol from the stack
            }
            else
            {
                printf("%c",equation[i]);
            }
        }
        else
        {
            while(top != -1)
            {
                printf("%c",stack[top]);
                top--;
            }

            break;
        }
    }

    return 0;
}

