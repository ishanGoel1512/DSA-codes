#include<iostream>
using namespace std;
int findVertex(int*distance , bool* visisted , int  n){
    int minVertex = -1;
    for(int i = 0 ; i < n ;i++){
        if(!visisted[i] &&(minVertex==-1 || distance[i] < distance[minVertex] )){
            minVertex = i ;
        }
    }
     return minVertex;
}
void dijkstra(int **edges , int n ){

    bool *visited = new bool[n];
    int *distance = new int[n];
    for(int i = 0 ; i < n ;i++){
        visited[i] = false;
        distance[i] = INT16_MAX;
    }
    distance[0] = 0 ; 
    for(int i = 0 ; i< n;i++){
        int minVertex = findVertex(distance , visited ,n);
        visited[minVertex] = true; 
        for(int j = 0 ; j < n ; j++){
            if(!visited[j] && edges[minVertex][j]!=0){
                int dist = distance[minVertex] + edges[minVertex][j];
                if(dist < distance[j]){
                    distance[j] = dist;
                }
            }
        }
    }

    for(int i = 0 ; i < n ;i++){
        cout<< i << " "<<distance[i] << endl;
    }

    delete [] visited;
    delete [] distance;
}
// 5 7               
// 0 1 4 
// 0 2 8 
// 1 3 5 
// 1 2 2 
// 2 3 5 
// 2 4 9 
// 3 4 4 
int main(){
    int n , e ;
    cin>>n>>e ;
    int ** edges = new int*[n] ;
    for(int i =0 ; i < n ; i++){
        edges[i] = new int[n];
        for(int j = 0 ; j < n ; j++){
            edges[i][j] = 0 ; 
        }
    }
        for(int i =0;i<e ; i++){
                int f,s,w;
                cin>>f>>s>>w;
                edges[f][s] = w ; 
                edges[s][f] = w;
         }

       dijkstra(edges,n); 
       for(int i = 0 ; i < n ; i++){
           delete [] edges[i];
       }
       
       delete [] edges; 
}