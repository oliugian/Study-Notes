    #include<stdio.h>
    #include<stdlib.h>
    struct node
    {int value;
     struct node *next;
    };
    struct node *create(int a[],int n)
    {struct node *head,*q;
     for(head=NULL;n;n--)
       {q=(struct node*)malloc(sizeof(struct node ));
	q->value=*a++;
	q->next=head;head=q;
       }
     return(head);
    }
    struct node *copy(struct node*h)
    {struct node *head,*p,*q,*u,*v;
     head=NULL;p=h;
     while(p)
       {q=(struct node *)malloc(sizeof(struct node));
	q->value=p->value;
	v=head;
	while(v!=NULL&&v->value<q->value)
	{u=v;v=v->next;}
	if(v==head)head=q;
	else u->next=q;
	q->next=v;p=p->next;
       }
	return(head);
    }
    int d[]={5,9,3,4,5,7,8};
    main()
    {struct node *h1,*h2,*p;
     h1=create(d,sizeof(d)/sizeof(d[0]));
     for(p=h1;p;p=p->next)
       printf("%5d",p->value);
     printf("\n\n");
     h2=copy(h1);
     for(p=h2;p;p=p->next)
       printf("%5d",p->value);
     printf("\n");
    }
