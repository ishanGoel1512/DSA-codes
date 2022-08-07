#include<iostream>
using namespace std;
#include<vector>
void DFS(int** edges , int n,int sv , bool* visited){
            visited[sv] = true ; 
        for(int i = 0 ; i < n ;i++){
            if(i ==sv ){
                continue; 
            }
         if(!visited[i] && edges[sv][i] == 1){ 
                    DFS(edges,n,i,visited);
                }
            }
}
int island(int**edges , int n ){

     bool* visited = new bool[n];
    for(int i = 0 ; i < n ;i++){
        visited[i] = false; 
    }
    
    int count = 0 ; 
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            DFS(edges,n,i,visited);
            count++;
        }
    }
    return count;
}
int main(){
    int n , e ; 
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i = 0 ; i < n ; i++){
        edges[i] = new int[n];
        for(int j = 0 ; j< n ;j++){
            edges[i][j] = 0 ;
        }
    }

   
    for(int i = 0 ; i < e ;i++){
         int f,s; 
         cin>>f>>s;
         edges[f][s] = 1;
         edges[s][f] = 1; 
    }

    cout<<island(edges , n )<<endl;
}