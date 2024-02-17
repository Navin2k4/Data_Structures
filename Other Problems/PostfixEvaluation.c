
#include <stdio.h>
#include <ctype.h>
#define maxstack 100
#define maxpost 100

int stack[maxstack];
int top = -1;

void push(int item)
{
    stack[++top] = item;
}

int pop()
{
    int item;
    item = stack[top--];
    return item;
}

int eval(char postfix[])
{
    int i;
    char ch;
    int A, B;
    int val;
    for (i = 0; postfix[i] != ')'; i++)
    {
        ch = postfix[i];
        if (isdigit(ch))
            push(ch - '0');
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            A = pop();
            B = pop();
            switch (ch)
            {
            case '+':
                val = B + A;
                break;
            case '-':
                val = B - A;
                break;
            case '*':
                val = B * A;
                break;
            case '/':
                val = B / A;
                break;
            default:
                break;
            }
            push(val);
        }
    }
    printf("The resultant value of the expression is : %d", pop());
}

int main()
{
    int i;
    char postexp[maxpost];
    printf("Enter the postfix expression, Enter ) to end : ");

    for (i = 0; i <= maxpost - 1; i++){
        scanf("%c", &postexp[i]);
        if (postexp[i] == ')'){
            break;
        }
    }
    eval(postexp);
    getch();
    return 0;
}