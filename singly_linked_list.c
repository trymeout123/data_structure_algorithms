#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* ptrdiff;
};

struct Node* head=NULL;

void addnode(int x)
{
	struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
   if(head==NULL)
   {
   	newnode->data=x;
   	newnode->ptrdiff=(struct Node*)(uint_p(NULL)^uint_p(newnode));
   	return;
   }
}

int main()
{
    addnode(5);
	return 0;
}
