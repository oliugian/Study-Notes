#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

static Node * MakeNode(const Item * pi);
static BOOLEAN ToLeft(const Item * i1,const Item * i2);
static BOOLEAN ToRight(const Item * i1,const Item * i2);
static void AddNode(Node * new,Node * root);
static void InOrder(const Node * root,void (* pfun)(Item item));

void InitializeTree(Tree * ptree)
{
    ptree->root=NULL;
    ptree->size=0;
}

BOOLEAN EmptyTree(const Tree * ptree)
{
    if (ptree->root==NULL)
	return True;
    else
	return False;
}

BOOLEAN FullTree(const Tree * ptree)
{
    if (ptree->size==MAXITEMS)
	return True;
    else
	return False;
}

int TreeItems(const Tree * ptree)
{
    return ptree->size;
}

BOOLEAN AddItem(const Item * pi,Tree * ptree)
{
    Node * new;
    if (FullTree(ptree))
    {
	fprintf(stderr,"Tree is full\n");
	return False;
    }
    if (SeekItem(pi,ptree))
    {
	fprintf(stderr,"Attempted to add duplicate item\n");
	return False;
    }
    new=MakeNode(pi);
    if (new==Null)
    {
	fprintf(stderr,"Couldn't create node\n");
	return False;
    }
    ptree->size++;
    if (ptree->root==NULL)
	ptree->root=new;
    else
	AddNode(new,ptree->root);
    return True;
}



