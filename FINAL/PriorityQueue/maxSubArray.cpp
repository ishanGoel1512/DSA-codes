// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        int *sum = new int[N+1];
        sum[0] = 0 ; 
        sum[1] = Arr[0];
        for(int i = 2; i <=N ; i++){
            sum[i] = sum[i-1] + Arr[i-1];
        }
        
        priority_queue<int , vector<int> , greater<int>> pq; 
        
        for(int i = 1 ; i <=N ; i++){
            for(int j = i ; j <=N ; j++){
                
                int x = sum[j] - sum[i-1];
                
                if(pq.size() < K){
                    pq.push(x);
                }
                else{
                    if(pq.top() < x){
                        pq.pop();
                        pq.push(x);
                    }
                    
                }
            }
        }
        return pq.top();
    }
};

// { Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends