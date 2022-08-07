#include<iostream>
using namespace std; 
#include<queue>
bool hasPath(int **edges , int n , int sv , int  ev){
     bool* visited = new bool[n];
     for(int i = 0 ; i < n;i++){
         visited[i] = false ; 
     }

    queue<int> seen ; 
    seen.push(sv);
    visited[sv] = true;
    while(!seen.empty()){
        int top = seen.front();
        seen.pop();
         for(int i = 0 ;i < n ; i ++){
            if( i == top){
                 continue;
            }
             if(edges[i][top] == 1 && !visited[i] ){
                 seen.push(i);
                 visited[i] = true;
            }
        }
    }

    return visited[ev];
}
int main(){
     int n , e ; 
    cin>>n>>e;
    int ** edges = new int*[n];
    for(int i = 0 ; i < n ; i++){
        edges[i] = new int[n];
        for(int j = 0 ; j < n ; j++){
            edges[i][j] = 0 ; 
        }
    }
    for(int i = 0 ; i< e;i++){

        int f,s ;
        cin>> f >> s;
        edges[f][s] = 1 ; 
        edges[s][f] = 1 ;
    }
    
    cout << hasPath(edges,n,1,3) <<endl;


}