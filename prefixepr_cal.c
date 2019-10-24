#include<stdio.h>
#include<string.h>
#define SIZE 50

int stack[SIZE];
int top=-1;

void push(int x)
{
    top++;
    stack[top]=x;
}

int pop()
{
    int x;
    x=stack[top];
    top--;
    return x;
}

int main()
{
    char p[SIZE];
    char ch;
    int i=0,z;
    int x,y;
    int result;
    printf("enter prefix expression:\n");
    scanf("%s",p);
    strrev(p);
    while(p[i]!='\0')
    {
       ch=p[i];
       if(ch>='0'&&ch<='9')
       {
         z=ch-48;
         push(z);
       }else
       {
           x=pop();
           y=pop();
          if(ch=='/')
          {
             push((y/x));
          }else if(ch=='*')
          {
              push((y*x));
          }else if(ch=='+')
          {
              push((y+x));
          }else if(ch=='-')
          {
              push((y-x));
          }else
          {
              push((y^x));
          }
       }
       i++;
    }
    result=stack[top];
    printf("result of prefix expression is %d\n",result);
    return 0;
}
