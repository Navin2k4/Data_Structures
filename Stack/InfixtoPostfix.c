#include<stdio.h>
#include<malloc.h>

char inf[40] , post[40] ; //Infix string and Pstfix String
int top = 0 , st[20] ; // Stack for operators
void postfix();
void push(int);
char pop();
void main(){
    printf("Enter the infix expression : ");
    scanf("%s",inf);
    postfix();
}
void postfix()
{
    int i;
    int j=0;
    for(i=0;inf[i]!='\0';i++){
        switch (inf[i])
        {
        case '+' : 
            while ( st[top] >= 1 )
                post[j++]=pop();
            push(1);
            break;
        case '-':
            while (st[top] >= 1)
                post[j++] = pop();
            push(2);
            break;
        case '*':
            while (st[top] >= 3)
                post[j++] = pop();
            push(3);
            break;
        case '/':
            while (st[top] >= 3)
                post[j++] = pop();
            push(4);
            break;
        case '^':
            while (st[top] >= 4)
                post[j++] = pop();
            push(5);
            break;
        case '(':
            push(0);
            break;
        case ')':
            while(st[top] != 0)
                post[j++] = pop();
            top--;
            break;
        default:
            post[j++] = inf[i];
        }
    }
    while (top > 0)
        post[j++] = pop();
    printf("\nExpression is : %s", post);
}
void push(int ele){
    top++;
    st[top] = ele ;
}
char pop(){
    int e1;
    char e;
    e1 = st[top] ;
    top--;
    switch (e1)
    {
    case 1 : 
        e = '+';
        break;
    case 2:
        e = '-';
        break;
    case 3:
        e = '*';
        break;
    case 4:
        e = '/';
        break;
    case 5:
        e = '^';
        break;
    }
    return (e);
}
