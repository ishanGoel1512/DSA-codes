#include<iostream>
using namespace std;
void rearrange(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}
int main(){
    int a[] = {-12 ,-11 , 3 , 4 , 7 , 3 , -1 , -2 , -5 };
    rearrange(a , 9);
    for(int i = 0 ; i < 9 ; i++){
        cout<<a[i] << endl;
    }
}