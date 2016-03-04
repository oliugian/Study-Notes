#define NULL 0
#define LEN sizeof(struct student)
#include <stdlib.h>
#include <stdio.h>
struct student { long int        num;
		 int             score;
		 struct student *next;};
int n;

struct student *creat()
{  struct student *head,*p1,*p2;
   n=0;
   head=NULL;
   p1=p2=(struct student *)malloc(LEN);
   scanf("%ld,%d",&p1->num,&p1->score);
   while (p1->num!=0)
   {  n=n+1;
      if (n==1) head=p1;
      else      p2->next=p1;
      p2=p1;
      p1=(struct student *)malloc(LEN);
      scanf("%ld,%d",&p1->num,&p1->score);
   }
   p2->next=NULL;
   return (head);
}

void print(head)
struct student *head;
{  struct student *p;
   int k=0;
   printf("\n");
   p=head;
   if (head!=NULL)
   do { k=k+1;
	printf("%d  %ld  %d\n",k,p->num,p->score);
	p=p->next;
      } while (p!=NULL);
}

struct student *dele(head,num)
struct student *head;
long int num;
{  struct student *p1,*p2;
   if (head==NULL) {printf("\n list null!\n");return (head);}
   p1=head;
   while (num!=p1->num&&p1->next!=NULL) {p2=p1;p1=p1->next;}
   if (num==p1->num)
   {  if (p1==head) head=p1->next;
      else          p2->next=p1->next;
      printf("%ld %d was deleted!\n",p1->num,p1->score);
      n=n-1;
   }
   else printf("%ld not been found!\n",num);
   return (head);
}

struct student *insert(head,p)
struct student *head,*p;
{  struct student *p1,*p2;
   p1=p2=head;
   if (head==NULL) {head=p;n=n+1;p->next=NULL;return (head);}
   while (p1->num<=p->num&&p1->next!=NULL) {p2=p1;p1=p1->next;}
   if (p1->next==NULL){p1->next=p;p->next=NULL;}
   else if (p1!=head){p->next=p1;p2->next=p;}
   else {head=p;p->next=p1;}
   n=n+1;
   return (head);
}

main()
{ struct student *creat(),*dele();
  void print();
  struct student *head,*p;
  long int num;
  head=creat();
  print(head);
  printf("\ninput num was deleting:");
  scanf("%ld",&num);
  while (num!=0)
  {  head=dele(head,num);
     print(head);
     scanf("%ld",&num);
  }
  p=(struct student *)malloc(LEN);
  scanf("%ld,%d",&p->num,&p->score);
  while (p->num!=0)
  {  head=insert(head,p);
     print(head);
     p=(struct student *)malloc(LEN);
     scanf("%ld,%d",&p->num,&p->score);
  }
}


