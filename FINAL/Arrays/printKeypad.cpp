#include<iostream>
using namespace std; 
#include<string>
class Keypad{
    public:
    int n ; 
    string s; 
};
void printKeypad(int n , Keypad* k , string output){

    // base case
       if(n==0){
        cout<<output<<endl;
        return;
       }
    // recursive calls
        string input;  
        for(int i = 0 ; i < 8 ; i++){
            if(n % 10 == k[i].n){
                input = k[i].s;
            }
        }   

        for(int i = 0 ; i < input.size();i++){

            printKeypad(n/10 , k , input[i] + output );
        }

}
int main(){
    int number ; 
    cin>>number;
    Keypad *k = new Keypad[8];
    k[0].n = 2 ; k[0].s = "abc"; 
    k[1].n = 3 ; k[1].s = "def"; 
    k[2].n = 4 ; k[2].s = "ghi"; 
    k[3].n = 5 ; k[3].s = "jkl"; 
    k[4].n = 6 ; k[4].s = "mno"; 
    k[5].n = 7 ; k[5].s = "pqrs"; 
    k[6].n = 8 ; k[6].s = "tuv"; 
    k[7].n = 9 ; k[7].s = "wxyz"; 
    string output;
    printKeypad(number , k , output);
    
}