#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include"Obj.h"

Grid solution;
typedef struct nList
{
       Node node;
       struct nList *parent;
}nodeList;
vector <nodeList *>open;
vector <nodeList *>checkedList;

void print_open() ;
int isPresent(Grid );
void expand();
void solve(Grid);
bool notInClosedList(Grid );
void printPath(nodeList *);

void insertopen(Grid B,nodeList *parent)
{
     int h,size,i=0,j,value,depth=0;
     nodeList *l;
     if(parent!=NULL)
     {
          depth = (parent->node).depth + 1;
     }
     Node n(B,depth);
     
     size=open.size();
     value = depth + B.value;
     if(notInClosedList(B))
     {
     	if(isPresent(B)==-1)
		 {
		             l=(nodeList *)malloc(sizeof(nodeList));
		             l->node=n;
		             l->parent = parent; 
		             open.push_back(l);
		             j=size;
		             while(j>0 && value < (open[j-1]->node).func_value)
		             {
		                    open[j]=open[j-1];
		                    j--;
		             }
		             open[j]=l;
		 }
		 else
		 {
		     j=isPresent(B);
		     if(open[j]->node.func_value>value)
		     {
                      open.erase(open.begin()+j);
                      insertopen(B,parent);
		     }
		 }  
     } 
}
void print_open()
{
    int i,size=open.size();
     for(i=0;i<size ;i++)
     {
         printf("\tInside print_open %d\n",i);
          (open[i]->node).printNode();
     }
}
int isPresent(Grid B)
{
     int i,size,present=-1;
     size=open.size();
     for(i=0;i<size && present==-1;i++)
     {
                    if(open[i]->node.B==B)
                    {
                                              present=i;
                    }
     }
     return present;
}
void solve(Grid B)
{
     insertopen(B,NULL);
     while(!((open[0]->node).B==solution))
     {
            expand();
     }
     printf("\nSteps are:\n\n");
     printPath(open[0]);

} 
void expand()
{
     Grid original,temp;
     nodeList *tempList;
     tempList=open[0];
     
     checkedList.push_back(tempList);
     open.erase(open.begin());
     
     int x,y,index;
     original=(tempList->node).B;
     temp=original;
     index=original.getBlank();
     x=index%3;
     y=index/3;
     if(x+1<=2)
     {  
           temp=original;
           temp.moveTile(y,x,y,x+1);
           insertopen(temp,tempList);
     }
     if(y+1<=2)
     {
             temp=original;
             temp.moveTile(y,x,y+1,x);
             insertopen(temp,tempList);
     }
     if(x-1>=0)
     {
             temp=original;
             temp.moveTile(y,x,y,x-1);
             insertopen(temp,tempList);
        }
        if(y-1>=0)
        {
          temp=original;
          temp.moveTile(y,x,y-1,x);
          insertopen(temp,tempList);
        }
}                                  
bool notInClosedList(Grid B)
{
     int i,size;
     size=checkedList.size();
     for(i=0;i<size;i++)
     {
                        if(checkedList[i]->node.B==B)
                        {
                            return false;
                        }
     }
     return true;
}
void printPath(nodeList *l)
{
       if(l!=NULL)
       {
               printPath(l->parent);
               (l->node).printNode();
               printf("\n\n");
       }
}

int main()
{
    Grid b(1);
    solve(b);
    return 1;
}
