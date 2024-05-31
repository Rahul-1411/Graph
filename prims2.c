#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int n; // no of vertices global declaration
 int cost_mat[10][10]; // global declaration
void vertex ( int n);
void print(int cost_mat[][10]);
void insert(int cost_mat [][10], int s, int d, int cost);
void prims(int cost_mat [][10], int n);
int main ()
{
    int i,j; // for loop
    int s,d; // for source and destination
    int cost ;// cost 
    char ch;
    printf("Enter the no.of vertices \n");
    scanf("%d",&n);
    // initialise every index of the matrix as max as possible
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cost_mat[i][j]=999;
        }
    }
    vertex(n);
    printf("\n");
    print(cost_mat);
    printf("\n");
     do
    {
        printf("Enter the source vertex :");
        scanf("%d", &s);
        printf("Enter the destination vertex :");
        scanf("%d", &d);
        printf("Enter the cost of the edge and the vertices: ");
        scanf("%d",&cost);
        insert(cost_mat,s,d,cost);
        printf(" DO you want to contiune\n");
        ch = getch();
    } while (ch == 'y' || ch == 'Y');
    vertex(n);
    printf("\n");
    print(cost_mat);
    printf("\n");
    prims(cost_mat,n);
    return 0;


}
void insert(int cost_mat [][10], int s, int d, int cost )
{
    cost_mat[s][d] = cost_mat[d][s] = cost;

}
void vertex ( int n)
{
    printf("   ");
    int i;
    for(int i=1;i<=n;i++)
    {
        
        printf("%d   ",i);
    }
}
void print(int cost_mat[][10])
{
    int i,j;
    for( i=1;i<=n;i++)
    {
        printf("%d->",i);
        for(j=1;j<=n;j++)
        {
            printf("%d ",cost_mat[i][j]);
        }
        printf("\n");
    }
}
void prims(int cost_mat[][10], int n)
{
    int i,j; // for loop
    int s,d ; // for source and destination
    int a, b;
    int min; 
    int mincost=0; // find the minimum cost
    int visited[n];
    int nv=1; // no of vertices
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
    }
    // start from the first vertex here you can choose from user also
    visited[1]=1;
    while(nv<n)
    {
        for(i=1,min=999;i<=n;i++)
        
            for(j=1;j<=n;j++)
            
                if(cost_mat[i][j]< min)
                
                    if(visited[i]!=0)
                    {
                    min = cost_mat[i][j];
                    s=a=i;
                    d=b=j;
                    }
                
             
        if(visited[s]==0 || visited[d]==0)
        {
            printf("\n Source is %d -> destination is %d and cost is %d", s,d,min);
            nv++;
            mincost+=min;
            visited[b]=1;

        }
        cost_mat[a][b]=cost_mat[b][a]=999;
        
       
    }
    printf("\n The total cost of Minimum spanning tree is %d",mincost);
}