#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter node data:" <<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter data to the left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data to the right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

int height(node* root){
    if(root==NULL){
        return 0;
    }

    int left1=height(root->left);
    int right1=height(root->right);

    int ans=max(left1,right1)+1;
    return ans;
}


int main(){
    node* root=buildTree(root);
    
    int val=height(root);
    cout<<val<<endl;
    return 0;
}

