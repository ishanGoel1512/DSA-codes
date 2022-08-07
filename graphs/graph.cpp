#include<iostream>
using namespace std;
void print(int **edges , int n , int s)
{
    cout<<s<<endl;
    for(int i = 0 ; i< n ; i++)
    {
        if(edges[s][i]==1)
        {
            print(edges,n,i);
        }
    }
}
int main()
{
    int n; 
    int e;
    cin>>n>>e ; 
    int **edges = new int*[n];
    for(int i = 0; i<n;i++)
    {
        edges[i]= new int[n];
        for(int j=0; j<n;j++)
        {
            edges[i][j]= 0 ;
        }
    }
    for(int i = 0 ; i<e;i++)
    {
    int f ,s ;
    cin>>f>>s;
    edge[f][s]=1 ;
    edge[s][f]=1 ;
    }
    print(edges,n,0);
}
