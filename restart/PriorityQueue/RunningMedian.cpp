#include<iostream>
#include<queue>
using namespace std;
vector<int> RunningMedian(int *a , int n){

    priority_queue<int> max;
    priority_queue<int , vector<int> , greater<int>> min;
    vector<int> ans;
    max.push(a[0]);
    ans.push_back(a[0]);
    for(int i = 1; i < n ; i++){
        if(a[i] > max.top()){
            min.push(a[i]);
             if(min.size() - max.size() > 1){
                max.push(min.top());
                min.pop();
            }
        }
        if(a[i] < max.top()){
            max.push(a[i]);
            if(max.size() - min.size() > 1){
                min.push(max.top());
                max.pop();
            }
        }
        if(max.size() > min.size()){
            ans.push_back(max.top());
        }
        if(min.size() > max.size()){
            ans.push_back(min.top());
        }
        if(min.size() == max.size()){
            ans.push_back((max.top() + min.top())/2);
        }
    }

  return ans;
}
int main(){
    int a[]={5,4,3,2,1};
    vector<int> output = RunningMedian(a,5);
    for(int i = 0; i < 5 ;i++){
        cout<<output[i]<<endl;
    }
}