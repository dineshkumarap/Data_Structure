#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
        struct node * new;
        new=(struct node *)malloc(sizeof (struct node));
        scanf("%d",&a);
        if(i==1)
        { 
            head->data=a;
            head->prev=NULL;
            head->next=NULL;
            te=head;
        }
        else
        {
            new->data=a;
            new->prev=te;
            new->next=NULL;
            te->next=new;
            te=te->next;
        }
    }
}

void instatbeg()
{
    struct node *new;
    new=(struct node *)malloc(sizeof (struct node));
    int num;
    printf("\nEnter the data for inserting node at beginning: ");
    scanf("%d",&num);
    new->data=num;
    new->next=head;
    new->prev=NULL;
    head->prev=new;
    head=new;
}

void instatend()
{
    struct node *t,*new;
    t=head;
    new=(struct node *)malloc(sizeof (struct node));
    int num;
    printf("\nEnter the data for inserting node at end: ");
    scanf("%d",&num);
    while(t->next!=NULL)
    {
        t=t->next;
    }
    new->data=num;
    new->next=NULL;
    new->prev=t;
    t->next=new;
}

void instatmid()
{
    struct node *t,*new;
    t=head;
    new=(struct node *)malloc(sizeof (struct node));
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
    new->data=num;
    new->next=(t->next);
    (t->next)->prev=new;
    t->next=new;
    new->prev=t;
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
    (p->next)->prev=t;
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
    printf("\nIn forward direction, ");
    while(t->next!=NULL)
    {
        printf(" %d",t->data);
        t=t->next;
    }
    printf(" %d",t->data);
    printf("\nIn reverse direction, ");
    while(t!=NULL)
    {
        printf(" %d",t->data);
        t=t->prev;
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