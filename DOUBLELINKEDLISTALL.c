/* Program of double linked list*/
# include <stdio.h>
# include <malloc.h>
#include<stdlib.h>
struct node
{
struct node *prev;
int info;
struct node *next;
}*head;
typedef struct node nodetype;
void create_list(int m);
void create_list(int m);
void addatbeg(int m);
void del(int m);
void display();
void addafter(int m,int po);
main()
{
int choice,n,m,po,i;
head=NULL;
while(1)
{
printf("1.Create List\n");
printf("2.Add at begining\n");
printf("3.Add after\n");
printf("4.Delete\n");
printf("5.Display\n");
printf("6.exit\n");
printf("Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("How many nodes you want : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the element : ");
scanf("%d",&m);
create_list(m);

}
break;
case 2:
printf("Enter the element : ");
scanf("%d",&m);
addatbeg(m);
break;
case 3:
printf("Enter the element : ");
scanf("%d",&m);
printf("Enter the position after which this element is

inserted : ");

scanf("%d",&po);
addafter(m,po);
break;
case 4:
printf("Enter the element for deletion : ");
scanf("%d",&m);
del(m);
break;
case 5:
display();
break;
case 6:
// exit();
default:
printf("Wrong choice\n");

}/*End of switch*/
}/*End of while*/
}/*End of main()*/
void create_list(int num)
{
struct node *q,*tmp;
tmp= (nodetype *)malloc(sizeof(struct node));
tmp->info=num;
tmp->next=NULL;
if(head==NULL)
{
tmp->prev=NULL;
head->prev=tmp;
head=tmp;
}

else
{
q=head;
while(q->next!=NULL)
{
q=q->next;

}
q->next=tmp;
tmp->prev=q;
}
}/*End of create_list()*/
void addatbeg(int num)
{
struct node *tmp;
tmp=(nodetype *)malloc(sizeof(struct node));
tmp->prev=NULL;
tmp->info=num;
tmp->next=head;
head->prev=tmp;
head=tmp;
}/*End of addatbeg()*/
void addafter(int num,int c)
{
struct node *tmp,*q;
int i;
q=head;
for(i=0;i<c-1;i++)
{
q=q->next;
if(q==NULL)
{
printf("There are less than %d elements\n",c);
return;
}
}
tmp=(nodetype *)malloc(sizeof(struct node) );
tmp->info=num;
q->next->prev=tmp;
tmp->next=q->next;
tmp->prev=q;
q->next=tmp;
}/*End of addafter() */
void del(int num)
{
struct node *tmp,*q;
if(head->info==num)
{
tmp=head;
head=head->next; /*first element deleted*/
head->prev = NULL;
free(tmp);
return;
}
q=head;
while(q->next->next!=NULL)
{
if(q->next->info==num) /*Element deleted in between*/
{
tmp=q->next;
q->next=tmp->next;
tmp->next->prev=q;
free(tmp);
return;
}
q=q->next;
}
if(q->next->info==num) /*last element deleted*/
{ tmp=q->next;
free(tmp);
q->next=NULL;
return;
}
printf("Element %d not found\n",num);
}/*End of del()*/
void display()
{
struct node *q;
if(head==NULL)
{
printf("List is empty\n");
return;
}
q=head;
printf("List is :\n");
while(q!=NULL)
{
printf("%d ", q->info);
q=q->next;
}
printf("\n");
}/*End of display() */
