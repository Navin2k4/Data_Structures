#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100

char stack[max];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}

int matches(char a,char b){
    if((a=='(')&&(b==')'))
        return 1;
    if ((a == '[') && (b == ']')) 
        return 1; 
    if ((a == '{') && (b == '}')) 
        return 1;
    return 0;
}

int isbalanced(char* s){
    int i;
    char popped;
    for(i=0;i<strlen(s);i++){
        if( s[i] == '[' || s[i] =='(' || s[i] == '{')
            push(s[i]);
        if (s[i] == ']' || s[i] == ')' || s[i] == '}')
        {
            if(isEmpty()){
                printf("\nRight brackets are more than left.\n");
                return 0;
            }
            else{
                popped = pop();
                if(!matches(popped,s[i])){
                    printf("\nMismatching Brackets");
                    return 0;
                }
            }
        }
    }
    if(isEmpty()){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char exp[max];
    int balanced;
    printf("Enter the Expression : ");
    gets(exp);
    balanced = isbalanced(exp);
    if(balanced){
        printf("The brackets are well balanced.");
    }
    else{
        printf("The brackets are not balanced");
    }
    return 0;
}