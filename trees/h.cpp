#include <iostream>
#include<vector>
using namespace std;
int minStartValue(vector<int>& nums) {
    
    int min=0,sum=0;
    for (int i = 0; i < nums.size(); i++){
        sum+=nums[i];
        min=min<sum?min:sum;
    }
    
    return 1-min;
}
int main() {
    vector<int> nums{5,-5,4,-2,3,1}; 
    cout<<minStartValue(nums)<<endl;  
  return 0;
}