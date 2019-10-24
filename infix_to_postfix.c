#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int stack[SIZE];
int top=-1;

void push(char ch)
{
    top++;
    stack[top]=ch;
}
 char pop()
 {
     char x;
     x=stack[top];
     top--;
     return x;
 }

 int precedence(char ch)
 {
     if(ch=='^')
     {
         return 3;
     }else if(ch=='/' ||ch=='*')
     {
         return 2;
     }else if(ch=='+' ||ch=='-')
     {
         return 1;
     }else
     {
         return 0;
     }
 }

 int main()
 {
     char p[SIZE];//postfix expression
     char q[SIZE];//infix expression
     int i=0,j=0;
     char ch;
     printf("enter the infix expression:\n");
     scanf("%s",q);

     push('(');
     while(q[i]!='\0')
     {
         ch=q[i];
         if(ch=='(')
         {
             push(ch);
         }else if((ch>='a' &&ch<='z')||(ch>='A' &&ch<='Z')||(ch>='0' &&ch<='9'))
         {
             p[j]=ch;
             j++;
         }else if(ch=='/' || ch=='*' || ch=='+' || ch=='-' || ch=='^')
         {
             if((precedence(ch)<=precedence(stack[top])))//poping operator whose has higher or same precedence as current read operator from stack
             {
                 p[j]=pop(stack[top]);
                 j++;
             }
                push(ch);

         }else if(ch==')')
         {
             while(stack[top]!='(')
                 {
                     p[j]=pop(stack[top]);
                     j++;
                 }
               top--;
         }
         else
         {
             break;
         }
         i++;
     }
   p[j]='\0';
     printf("%s\n",p);
     return 0;

 }

