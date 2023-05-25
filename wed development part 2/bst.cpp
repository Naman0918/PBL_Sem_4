#include <iostream>
using namespace std;
class node{
    public:
    node*right;
    node*left;
    int data;
    node(int value)
    {
        data=value;
        right=NULL;
        left=NULL;
        
        
    }
};
class bst{
    public:
    
    node*root;
    bst(){
        root=NULL;
    }
    node*insert(node*root,int val){
        node*newnode=new node(val);
        if(root==NULL){
            return newnode;
        
        }
        else {
           if (root->data>val)
           {
            root->left=insert(root->left,val);
        }
        else if(root->data<val)
        {
            root->right=insert(root->right,val);
        }
        else{
            cout<<"cant insert the elements!!!";
        }
         return root;
    }
   
}
void search(node*root,int value)
{
    if(root==NULL)
    {
        cout<<"\n the value not found";
    }
    else
    {
        if(root->data==value)
        {
            cout<<"\n the value is found!!!";
        }
        else if(root->data>value){
            search(root->left,value);
            
        }
        else{
            search(root->right,value);
        }
        
    }
    
}
void inorder(node*root)
{
        if(root!=NULL)
        {
            inorder(root->left);
              cout<<" ";
            cout<<root->data;
              cout<<" ";
            inorder(root->right);
              cout<<" ";
 
        }
}


node* deletetion(node*root,int value1)
{
    if(root==NULL){
        return NULL;
    }
    else if(value1>root->data){
        root->right=deletetion(root->right,value1);
        
    }
    else if(value1<root->data){
        root->left=deletetion(root->left,value1);
    }
    else{
        if(root->right==NULL&&root->left==NULL){
            return NULL;
        }
        else if(root->left==NULL){
            node*temp=root->left;
            return temp;
        }
        else if(root->right==NULL){
            node*temp=root->right;
            return temp;
        }
        else{
            node*newnode=findmax(root->left);
            root->data=newnode->data;
            deletetion(root->left,newnode->data);
        }
    }
    
    
    
}
node*findmax(node*root)
{
        node*current=root;
        if(root==NULL){
            return NULL;
        }
        while(current->right!=NULL){
            current=current->right;
            
        }
        return current;
    }

}
;
int main() {
   int n,a,p;
   bst b1;
   cout<<"enter the number of elements that you want to add:";
   cin>>n;
   for(int i=0;i<n;i++){
       cout<<"\n the element is: ";
       cin>>a;
       b1.root=b1.insert(b1.root,a);
       
   }
   cout<<"\n the elements are insert successfully!!!";
   b1.inorder(b1.root);
   b1.search(b1.root,34);
   b1.deletetion(b1.root,43);
   b1.inorder(b1.root);
   
}