#include<iostream>
#include<algorithm>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
        node(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }
};

node* createTree(node* root){
    cout<<"Enter root data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter data left of "<<data<<endl;
    root->left=createTree(root->left);
    cout<<"Enter data right of "<<data<<endl;
    root->right=createTree(root->right);
    return root;
}


pair<bool,int> isBalanced(node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    pair<int,int> left=isBalanced(root->left);
    pair<int,int> right=isBalanced(root->right);

    bool leftans=left.first;
    bool rightans=right.first;

    bool diff = abs(left.second-right.second)<=1;

    pair<bool,int> ans;
    ans.second=max(right.second,left.second)+1;

    if(leftans && rightans && diff){
        ans.first=true;
    }
    else{
        ans.first=false;
    }
    return ans;
}

int main(){
    node* root=createTree(root);

    // cout<<height(root)<<endl;
    cout<<isBalanced(root).first<<endl;
    // pair<bool,int> ans=isBalanced(root);
    
    return 0;
}