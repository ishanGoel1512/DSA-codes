#include<iostream>
using namespace std;
#include<string>
int returnPermutations(string input,string output[]){
    //base case 
    if(input.size()==1){
        output[0] = input;
        return 1;
    }
    // recursive calls
    int k = 0;
    string o1[100];
    int smallAns = returnPermutations(input.substr(1) , o1);
    for(int i = 0 ; i < smallAns ; i++){
        for(int j = 0 ; j < input.size() ; j++){
             output[k++] = o1[i].substr(0,j) + input[0] + o1[i].substr(j,input.size()-j-1) ;
        }
    }
    return smallAns * input.size();
}
int main(){

    string input ; 
    cin>> input ; 
    string *output = new string[100];
    int length = returnPermutations(input,output);
    for(int i = 0 ; i <  length;i++){
        cout<< output[i] <<endl;
    }

}