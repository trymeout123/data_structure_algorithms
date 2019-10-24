#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node* next;
};

struct Node* head;
void print()
{
    struct Node* temp;
    temp=head;
    if(head==NULL)
    {
        printf("list is empty.\n");
    }else{
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    }
}

void addatbeg(int x)
{
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=x;
    new_node->next=head;
    head=new_node;
}


void addatend(int x)
{
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp;
    temp=head;
    new_node->data=x;
    if(head==NULL)
    {
        new_node->next=head;
        head=new_node;
    }else{
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
    }
}

void addatpos(int x,int pos)
{
    int i;
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp;//to traverse in list
    new_node->data=x;
    temp=head;
    if(head==NULL)
    {
        printf("list is empty.\n");
    }
    else{
            if(pos==1)
            {
                new_node->next=head;
                head=new_node;
                return;
            }
    for(i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    if (temp==NULL||temp->next == NULL) //if position more than number element in list
         return;
    new_node->next=temp->next;
    temp->next=new_node;
    }
}

void delitem(int n)
{
    struct Node* temp;
    struct Node* temp1;
    int i;
    temp=head;
    if(head==NULL)
    {
        printf("list is empty\n");
    }else{
        if(n==1)
        {
            head=temp->next;
            free(temp);

        }else{
        for(i=1;i<n-1;i++)
        {
            temp=temp->next;
        }
            if (temp == NULL || temp->next == NULL) //if position more than number element in list
         return;

        temp1=temp->next->next;
        free(temp->next);
        temp->next=temp1;
        }
    }
}

int main()
{
    head=NULL;
    int x,i,n;
    printf("enter 1 to add element at beginning\n");
    printf("enter 2 to add element at end\n");
    printf("enter 3 to add element at n th position\n");
    printf("enter 4 to delete element from n th position \n");
    printf("enter 5 display currently present element in list\n");
    printf("enter 6 to exit the loop\n");
    while(1)
    {
        printf("enter your choice\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:printf("enter the value\n");
            scanf("%d",&x);
            addatbeg(x);
            print();
            printf("\n");
            break;
            case 2:printf("enter the value\n");
            scanf("%d",&x);
            addatend(x);
            print();
            printf("\n");
            break;
            case 3:printf("enter the value and position\n");
            scanf("%d%d",&x,&n);
            addatpos(x,n);
            print();
            printf("\n");
            break;
            case 4:printf("enter the position of node which to be deleted\n");
            scanf("%d",&n);
            delitem(n);
            print();
            printf("\n");
            break;
            case 5:print();
            printf("\n");
            break;
            case 6:exit(0);
            default:
                printf("enter correct choice\n");
        }
    }
    return 0;
}
