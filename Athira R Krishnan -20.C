#include<stdio.h>
#include<conio.h>

struct node
{
  struct node *left;
  int data;
  struct node *right;
};
typedef struct node node;
node *getNode();

void main()
{
  int n,i,item,a[10],ch,op;
  node *first=NULL;
  clrscr();
  do
  {
    printf("1.Insert  2.Display  3.Search 4.PreOrder Traversal 5.Deletion ");
    printf("\nEnter ur choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1 : printf("\nEnter the number of elements to be inserted :");
	       scanf("%d",&n);
	       printf("\nEnter the elements : ");
	       for(i=0;i<n;i++)
	       {
		 scanf("%d",&a[i]);
	       }
	       for(i=0;i<n;i++)
	       LCreate(&first,a[i]);
	       break;
      case 2: printf("\n Displaying the Tree : \n ");
	      Ldisplay(first,i);
	      break;
      case 3: printf("Enter elements to be searched : ");
	      scanf("%d",&item);
	      Lsearch(first,item);
	      break;
      case 4: printf("preorder traversal : ");
	      Preorder(first);
	      break;
      case 5: printf("Enter elements to be deleted : ");
	      scanf("%d",&item);
	      Ldelete(&first,item);
	      break;
      default:printf("Wrong choice!!!");
    }
  printf("\n Do u want to continue (1/0): ");
  scanf("%d",&op);
}while(op==1);
getch();
}


LCreate(node **first,int n)
{
  node *current=*first,*temp;
  int val,i;
  if((*first)==NULL)
  {
    *first=getNode();
    (*first)->data=n;
    (*first)->left=NULL;
    (*first)->right=NULL;
    return;
  }
  while(current!=NULL)
  {
    if(n<current->data)
    {
      if(current->left!=NULL)
	current=current->left;
      else
      {
	 temp=getNode();
	 current->left=temp;
	 temp->data=n;
	 temp->left=NULL;
	 temp->right=NULL;
	 return;
      }
    }
    else
    {
      if(n> current->data)
      {
	if(current->right!=NULL)
	  current=current->right;
	else
	{
	  temp=getNode();
	  current->right=temp;
	  temp->data=n;
	  temp->left=NULL;
	  temp->right=NULL;
	  return;
	}
      }
      else
      {
	printf("Wrong dta");
	exit(0);
      }

    }
}
return;
}

Ldisplay(node *first,int  level)
{
  int i;
  if((first)!=NULL)
  {
     Ldisplay((first)->right,level+1);
     printf("\n");
     for(i=0;i<level;i++)
       printf(" ");
     printf("%d",(first)->data);
    Ldisplay((first)->left,level+1);
  }
  return;
}

Lsearch(node *first,int item)
{
  node *temp;
  if((first)==NULL)
  {
    printf("Tree is Empty");
    return;
  }
  if(item==first->data)
  {
    printf("element is at root");
    return;
  }
  else if(item<first->data)
  {
    Lsearch(first,item);
    printf("element on left tree");
    return;
  }
  else
  {
    Lsearch(first,item);
    printf("ELement on right tree");
    return;
  }
}

Preorder(node *first)
{
  if(first!=NULL)
  {
    printf("%d \t",first->data);
    Preorder(first->left);
    Preorder(first->right);
  }
  else
  {
    return;
  }
  return;
}

Ldelete(node **first,int item)
{
  node *current;
  if(*first==NULL)
  {
    printf("Empty Tree");
    return;
  }
  if(item<(*first)->data)
    Ldelete(&((*first)->left),item);
  else
  {
    if(item > (*first)->data)
      Ldelete(&((*first)->right),item);
    else
    {
      current=*first;
      if(current->right==NULL)
      {
	(*first)=(*first)->left;
	printf("Element Deleted : %d ",current->data);
	free(current);

      }
    else
    {
    current = (*first)->right;
    while(current->left !=NULL)
      current=current->left;
      current->left = (*first)->left;
      current=(*first);
      (*first) = (*first)->right;
      printf("Element Deleted : %d ",current->data);
      free(current);

    }
  }
}
return;
}


node *getNode()
{
 node *p;
 p=(node *)malloc(sizeof(node));
 return p;
}


freenode(node *p)
{
  free(p);
  return;
}