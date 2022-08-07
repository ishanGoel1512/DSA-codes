#include<iostream>
using namespace std;
#include<string>
int returnPermutations(string input,string output[]){
    
    //base case 
    if(input.size()==1){
        output[0] = input[0];
        return 1;
    }
   
    // recursive calls
    int k = 0;
    string o1[100];
    int smallAns = returnPermutations(input.substr(1) , o1);
    for(int i = 0 ; i < smallAns ; i++){
        for(int j = 0 ; j < input.size();i++){
             output[k++] = o1[i].substr(0,j) + input[0] + o1[i].substr(j+1,input.size()-j-1) ;
        }
    }
    return smallAns * input.size();
}
int returnPermutations1(string input, string output[]){
	if(input.size()==1)
    {
        output[0]=input[0];
        return 1;
        
    }
    int index=0;
    for(int i=0 ;i<input.size();i++)
    {
        string smalloutput[1000];
        int ans= returnPermutations1(input.substr(0,i)+input.substr(i+1,input.size()-i-1),smalloutput);
        for(int j=0;j<ans;j++)
        {
            output[index++]=input[i]+smalloutput[j];
        }
    }
return index;
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