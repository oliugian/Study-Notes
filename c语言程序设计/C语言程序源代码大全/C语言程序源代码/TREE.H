/*  TREE.H - - binary search tree */

typedef struct item
{
     char petname[20];
     char petkind[20];
} Item;
#define MAXITEMS 10
typedef enum boolean {False,True} BOOLEAN;
typedef struct node
{
     Item item;
     struct node * left;
     struct node * right;
} Node;
typedef struct tree
{
    Node * root;
    int size;
} Tree;

void InitializeTree(Tree * ptree);
BOOLEAN EmptyTree(const Tree * ptree);
BOOLEAN FullTree(const Tree * ptree);
int TreeItems(const Tree * ptree);
BOOLEAN AddItem(const Item * pi,Tree * ptree);
BOOLEAN SeekItem(const Item * pi,Tree * ptree);
void Traverse(const Tree * ptree,void (* pfun)(Item item));
