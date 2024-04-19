#include<stdio.h>
#include<stdlib.h>
#define v 7
void setzero(int arr [][v]);
void insert(int arr[][v] ,int source , int destination);
void print(int arr[][v]);
void vertex();
int main ()
{
    int arr[v][v];
    setzero(arr);
  //  print(arr);
  insert(arr,1,2);
  insert(arr,1,5);
  insert(arr,1,4);
  insert(arr,2,6);
  insert(arr,2,7);
  insert(arr,2,3);
//  printf("\t");
  vertex();
  printf("\n");
  print(arr);

}
void setzero(int arr [][v])
{
    int i,j;
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            arr[i][j]=0;
        }
    }
}
void insert(int arr[][v] ,int source , int destination)
{
    arr[source][destination]=1;
    arr[destination][source]=1;
}
void print(int arr[][v])
{
    int i,j;
    for( i=1;i<=v;i++)
    {
        printf("%d->",i);
        for(j=1;j<=v;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
void vertex ()
{
    printf("   ");
    int i;
    for(int i=1;i<=v;i++)
    {
        
        printf("%d ",i);
    }
}
