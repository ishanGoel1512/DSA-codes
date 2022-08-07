#include<iostream>
using namespace std;
#include "treenode.h"
#include<queue>
#include<utility>
#include<math.h>
TreeNode<int>* maximum(TreeNode<int>* root1 , TreeNode<int>* root2)
{    
   
    if(root1->data >= root2->data)
    {  
         return root1;
    }
    if(root2->data > root1->data)
    {
        return root2; 
    }
    
}
TreeNode<int>* minimum(TreeNode<int>* root1 , TreeNode<int>* root2)
{   

    if(root1->data <= root2->data)
    {   
         return root1;
    }
    if(root2->data < root1->data)
    {
        return root2; 
    }
    
}

pair<TreeNode<int>*,TreeNode<int>*> second_largest(TreeNode<int>* root)
{
    if(root==NULL)
    {
        pair<TreeNode<int>*,TreeNode<int>*> one ; 
        one.first = root ; 
        one.second = root ; 
        return one ; 
    }
     
     pair<TreeNode<int>*,TreeNode<int>*> ans ; 
     ans.first = root ; 
     ans.second = NULL;
     /*if(ans.second > ans.first)
     {
         ans.first = ans.second ; 
     }*/

     for(int i = 0 ; i < root->children.size(); i++)
     {      
         pair<TreeNode<int>*,TreeNode<int>*> temp = second_largest(root->children[i]);

         if(ans.second == NULL && temp.second == NULL)
         {
             ans.second = minimum(ans.first,temp.first);
             ans.first = maximum(ans.first,temp.first) ; 
             cout<<ans.second ; 
             return ans ; 
         }

         if(ans.second!=NULL && temp.second!=NULL)
         {
             if(ans.first->data < temp.first->data)
             {   
                 ans.second = maximum(temp.second,minimum(ans.first,ans.second));
                 ans.first = temp.first;
                 cout<<ans.second ; 
                 return ans ;
             }
             else 
             {
                     ans.second = maximum(temp.second,minimum(ans.first,ans.second));
                     return ans ; 
             }
         }
             if(temp.second==NULL && ans.second!=NULL)
             {
             ans.second = maximum(ans.second,minimum(ans.first,temp.first));
             ans.first = maximum(ans.first,temp.first);
             return ans;
             }
             if(ans.second==NULL && temp.second!=NULL)
             {
                 ans.second = maximum(temp.second , minimum(ans.first,temp.first));
                 ans.first = maximum(ans.first,temp.first);
                 return ans ; 
             }

     }

     return ans ; 
}

void print_levelwise(TreeNode<int> * root)                   //  PRINT LEVEWISE
{
    queue<TreeNode<int>*> printing;
    printing.push(root);
    while(printing.size()!=0)
    {    TreeNode<int> *front = printing.front();
         printing.pop();
         cout<<front->data<<":";
       for(int i = 0 ; i<front->children.size(); i++)
       {
           cout<<front->children[i]->data<<",";
           printing.push(front->children[i]);

       }
       cout<<endl;
    }
}
TreeNode<int>* take_Input_levelwise()                 /// INPUT LEVEL WISE
{
    int rootData;
    cout<<"Enter root Data : "<<endl; 
    cin>>rootData;
    TreeNode<int> * root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0)
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter the no. of children of"<<front->data <<endl;
        int numchild;
        cin>>numchild;
        for(int i = 0; i<numchild; i++)
        {   int childData;
            cout<<"enter the "<<i << " of the "<<front->data<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;


}
int main()
{
    TreeNode<int>* root = take_Input_levelwise();
    print_levelwise(root);
    pair<TreeNode<int>*,TreeNode<int>*> ans = second_largest(root);
    cout<<ans.second->data<<endl;
}