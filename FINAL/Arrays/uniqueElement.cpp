#include<iostream>
using namespace std;
#include<string>
#include<vector>
int uniqueElement(int input[],int n ,vector<int> output ){

    //  base case
        if(n==2){
            output.push_back(input[0]);
            output.push_back(input[1]);
            return output[0];
        }

    // recursive call 
    
    int smallAns = uniqueElement(input+1,n-1,output);
    output.push_back(smallAns);
    for(auto i = output.begin(); i != output.end(); ++i){
        if(*i == input[0]){
            output.erase(i);
        }
    }
    return output[0];
}
int main(){
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0 ; i < n ;i++ ){
        cin >> input[i];
    }
    vector<int> output;
    int ans = uniqueElement(input,n,output);
    cout << ans; 
}