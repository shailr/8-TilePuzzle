#ifndef _Obj_h
#define _Obj_h
using namespace std;
void print_openList();

class Grid
{
      public :
               int tiles[3][3];
               int value;
               
      public :
            Grid();
            Grid(int a);      
            void printGrid();
            int man_dist();
            void moveTile(int i1,int j1,int i2,int j2);
            bool operator==(Grid b);
            bool operator<=(Grid b);
            bool operator>=(Grid b);
            bool operator<(Grid b);
            bool operator>(Grid b);
            void operator=(Grid b);
            int getBlank();               
};
        
Grid :: Grid(int a)
{
    int i,j,count[9]={0};
	printf("Enter the tiles in Row ordered form.(Use 0 for blank)\n");
    for(i=0;i<=2;i++)
    {
       for(j=0;j<=2;j++)
       {
            scanf("%d",&tiles[i][j]);
            if(tiles[i][j]<0 || tiles[i][j]>8)
            {
                  printf("Invalid value. Try again.\n");
                  j--;
            }
            else 
            {
                 count[tiles[i][j]]++;
                 if(count[tiles[i][j]]>1)
                 {
                    printf("Repeatation. Try again.\n");
                    j--; 
                 }                 
            }
       }
    } 
    man_dist();
}
 void Grid :: printGrid()
{
    int i,j;
    for(i=0;i<=2;i++)
    {
                     for(j=0;j<=2;j++)
                     {
                                      printf("%d ",tiles[i][j]);                               
                     }
                     printf("\n");
    }
    printf("Distance=> %d, ",value);
}
int Grid :: man_dist()
{
 
	int solutionx[]={2,0,1,2,0,1,2,0,1};
	int solutiony[]={2,0,0,0,1,1,1,2,2};
	int val=0,i,j;
	for(i=0;i<=2;i++)
	{
	    for(j=0;j<=2;j++)
	    { 
	       val=val + abs(j-solutionx[tiles[i][j]])+abs(i-solutiony[tiles[i][j]]);                             
	    }
	}
	value=val;
	return val;
}
void Grid :: moveTile(int i1,int j1,int i2,int j2)
{
      if(!(i1>2 || i1<0 || j1<0 || j1>2 || i2>2 || i2<0 || j2<0 || j2>2))
      { 
        int temp;
        temp=tiles[i1][j1];
        tiles[i1][j1]=tiles[i2][j2];
        tiles[i2][j2]=temp;
        man_dist();
      }
      else
      {
          printf("Can not moveTile Value Invalid index\t%d%,%d,%d,%d\n",i1,j1,i2,j2);
          getch();
          exit(1);
      }
}
bool Grid :: operator==(Grid b)
{
     int i,j;
     bool rvalue=true;
     for(i=0;i<=2 && rvalue;i++)
     {
              for(j=0;j<=2 && rvalue;j++)
              {
                       if(tiles[i][j]!=b.tiles[i][j])
                       {
                               rvalue=false;
                       }                                  
              }
     }
     return rvalue;
}
void Grid :: operator=(Grid B)
{
     int i,j;
     for(i=0;i<=2 ;i++)
        for(j=0;j<=2;j++)
        {
                     tiles[i][j]=B.tiles[i][j];
        }
     value=B.value;
}
int Grid :: getBlank()
{
    int i=0,found=0;
    while(!found)
    {
                 if(tiles[0][i]==0)
                 {
                                   found=1;break;
                 }
                 i++;
    }
    return i;
}
Grid :: Grid()
{
    int i,j;
    for(i=0;i<=2;i++)
    {
                     for(j=0;j<=2;j++)
                     {
                                      tiles[i][j]=i*3+j+1;                                  
                     }
    }
    tiles[2][2]=0;
    man_dist();
}

bool Grid :: operator<=(Grid b)
{
     return value<=b.value;
}
bool Grid :: operator>=(Grid b)
{
     return value>=b.value;
}
bool Grid :: operator<(Grid b)
{
     return value<b.value;
}
bool Grid :: operator>(Grid b)
{
     return value>b.value;
}

class Node
{
    public:
           int depth;
           Grid B;
           int func_value;
           Node(Grid b1,int h);
           void printNode();
           void operator=(Node n);
           bool operator==(Node n);
           bool operator<(Node n);
           bool operator>(Node n);
};
void Node :: printNode()
{
            B.printGrid();
            printf("func_val=>%d, depth=>%d\n",func_value,depth);
}
Node :: Node(Grid b1,int h)
{
       B=b1;
       depth=h;
       func_value=h+b1.man_dist();
}
void Node :: operator=(Node n)
{
           B=n.B;
           depth=n.depth;
           func_value=n.func_value;
}
bool Node :: operator<(Node n)
{
     return func_value<n.func_value;
}
bool Node :: operator>(Node n)
{
     return func_value>n.func_value;
}
bool Node :: operator==(Node n)
{
     if( B==n.B)
     {
         return true;
     }
         else 
     {
         return false;
     }
}
#endif
