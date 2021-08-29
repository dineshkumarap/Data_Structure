#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
}*head;

void create()
{
    int n,a;
    printf("Enter the size of list : ");
    scanf("%d",&n);
    struct node *te;

    printf("Enter the data for the list : \n");
    for(int i=1;i<=n;i++)
    {
        struct node * newnode;
        newnode=(struct node *)malloc(sizeof (struct node));
        scanf("%d",&a);
        if(i==1)
        { 
            head->data=a;
            head->next=NULL;
            te=head;
        }
        else
        {
            newnode->data=a;
            newnode->next=NULL;
            te->next=newnode;
            te=te->next;
        }
    }
}

void instatbeg()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof (struct node));
    int num;
    printf("\nEnter the data for inserting node at beginning: ");
    scanf("%d",&num);
    newnode->data=num;
    newnode->next=head;
    head=newnode;
}

void instatend()
{
    struct node *t,*newnode;
    t=head;
    newnode=(struct node *)malloc(sizeof (struct node));
    int num;
    printf("\nEnter the data for inserting node at end: ");
    scanf("%d",&num);
    newnode->data=num;
    newnode->next=NULL;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=newnode;
}

void instatmid()
{
    struct node *t,*newnode;
    t=head;
    newnode=(struct node *)malloc(sizeof (struct node));
    int num,s;
    printf("\nAt which index new node should be added (0 to ....): ");
    scanf("%d",&s);
    int i=1;
    while(i<s)
    {
        t=t->next;
        i++;
    }
    printf("\nEnter the data for inserting node : ");
    scanf("%d",&num);
    newnode->data=num;
    newnode->next=(t->next);
    t->next=newnode;
}

void deletenode()
{
    struct node *p,*t;
    t=head;
    int d;
    printf("\n Which index(node) of list should be deleted (0 to ....) : ");
    scanf("%d",&d);
    int i=1;
    while(i<d)
    {
        t=t->next;
        i++;
    }
    p=t->next;
    t->next=p->next;
}

void search()
{
    int num;
    printf("\nEnter the value to search it in the list : ");
    scanf("%d",&num);
    struct node *t;
    t=head;
    int i=0;
    while(t!=NULL)
    {
        if(t->data==num)
        {
            printf("Above value is in the list at %d index.\n",i);
            return;
        }
        t=t->next;
        i++;
    }
    printf("Above value is not in the list.\n");
}

void printlist()
{
    struct node *t;
    t=head;
    while(t!=NULL)
    {
        printf(" %d",t->data);
        t=t->next;
    }
    return;
}

int main()
{
    head=(struct node *)malloc(sizeof (struct node));
    int n;
    create();
    printf("\n1.Insert a node at beginning of list.\n2.Insert a node at middle of the list.\n3.Insert a node at end of the list");
    printf("\n4.Display the value of the list\n5.Delete a node from the list.\n6.Search the value in the list.\n7.Exit");
    while(n!=7)
    {
        printf("\nChoose any one from above function : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: instatbeg(); 
                    break;
            case 2: instatmid();
                    break;
            case 3: instatend();
                    break;
            case 4: printlist();
                    break;
            case 5: deletenode();
                    break;
            case 6: search();
                    break;
            case 7: return(0);
            default: printf("Choose a valid function...");
        };
    }
}