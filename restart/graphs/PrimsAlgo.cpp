#include<iostream>
using namespace std;
int findVertex(int* weights , bool* visited , int n){
    int minVertex = -1;
    for(int i = 0 ; i < n ; i++){
        if(!visited[i] && (minVertex ==-1 || weights[i] < weights[minVertex])){
            minVertex = i ; 
        } 
    }
    return minVertex;
}
void primsAlgo(int **edge , int n ){
    bool *visited = new bool[n];
    int* parent  = new int[n];
    int* weight = new int[n];
    parent[0] = -1;
    weight[0] = 0;
    for(int i = 1 ; i < n ; i++){
        weight[i] = INT16_MAX;
        visited[i] = false;
     }  
        for(int i = 0 ; i < n ; i++){
            // if(edge[count][i]!= 0 && !visited[i]){
            //     if(weight[count] < weight[i])
            //     weight[i] = edge[count][i];
            //     parent[i] = count;  
            // }
            ///Find MinVertex
            int minVertex = findVertex(weight,visited,n);
            visited[minVertex] = true;
            ///Explore un visited neighbours 
            for(int j = 0 ; j < n;j++){
                if(edge[minVertex][j]!= 0 && !visited[j]){
                if(edge[minVertex][j] < weight[j]){
                    weight[j] = edge[minVertex][j];
                parent[j] = minVertex;
                }
            }
            }
        }

        for(int i = 1; i < n;i++ ){
            if(parent[i] < i){
                cout<< parent[i] <<" "<<i<<" "<<weight[i]<<endl;
            }
            else{
                cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
            }
        }
}
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

       primsAlgo(edges,n);  

}