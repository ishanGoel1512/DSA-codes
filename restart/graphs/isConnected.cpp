#include<iostream>
using namespace std;
#include<queue>
void BFS(int** edges , int n , int sv , bool* visited){

    queue<int> seen ; 
    seen.push(sv);
    visited[sv] = true;
    while(!seen.empty()){
        int top = seen.front();
        seen.pop();
        cout<< top << endl;
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

}
bool isConnected(int** edges , int n ,int sv){

    bool *visited = new bool[n];
    for(int i = 0 ; i < n ; i++){
        visited[i] = false ; 
    }
    BFS(edges,n,sv,visited);

    for(int i = 0 ; i < n ;i++){
        if(visited[i]){
            continue;
        }
        else{
            return false;
        }
    }

    return true;

}
int main(){
     int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {

        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
   cout << isConnected(edges ,n ,0);

}