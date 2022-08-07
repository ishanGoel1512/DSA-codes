using namespace std;
#include"TrieNode.h" 
#include<string>
#include<vector>
class Trie{
    TrieNode *root;
    public:
    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode* root , string word){
        ///User needs to pass root in order to access dictionary 
        /// therefore making helper function 
        
        //Base case
        if(word.size()==0){
            root->isTerminal = true;
            return; 
        }
        // Small Calculation 
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // Recursive call 
        insertWord(child,word.substr(1));
    }
    void insertWord(string word){
    insertWord(root,word);
    }


bool search(TrieNode* root ,string word){
/// Base Case
if(word.size() ==0){
   return  root->isTerminal;
}
/// Small Calculation 
    int index = word[0] - 'a';
    if(root->children[index]!=NULL){
      return search( root->children[index] , word.substr(1));
    }
    else{
        return false;
    }
}
///Search Helper
bool search(string word){
    return search(root,word);
}

void removeWord(TrieNode* root , string word){
// base case
if(word.size()==0){
            root->isTerminal = false;
            return; 
        }
//Small calculation
    TrieNode* child;
    int index = word[0] - 'a';
    if(root->children[index]!=NULL){
     child = root->children[index];
    }
    else{ 
        return ;
    }
    removeWord(child,word.substr(1));

    // Remove Child Node if it is useless
    if(child->isTerminal == false){
        for(int i = 0 ; i < 26 ;i++){
            if(child->children[i] !=NULL){
                return;
            }
        }
        delete child;
        root->children[index] = NULL;
    }
}
void removeWord(string word){
    removeWord(root , word);
}
//// pattern matching 
    bool patternMatching(vector<string> check , string word){

        for(int i = 0 ; i < check.size() ; i++){

            while(check[i].size()!=0){
                insertWord(check[i]);
                check[i] = check[i].substr(1);
            }
        }

        return search(word);
    }

        string palindrome(string word){
                string ans;
                for(int i = 0 ; i < word.length();i++){
                    ans.at(i) = word[word.size()-i-1];
                }
                return ans;
        }
    bool palinPair(vector<string> check)
    {
            for(int i = 0 ; i < check.size(); i++){
                insertWord(check[i]);
            }
            bool ans ; 
            for(int i = 0 ; i < check.size();i++){
                ans+= search(palindrome(check[i]));
            }

            if(ans >= 1){
                    return true;
            }
            else{
                return false;
            }

    }

};
