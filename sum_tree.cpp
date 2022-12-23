#include<iostream>
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


node* createList(node* root){
    cout<<"Enter root data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }
    cout<<"Enter left of root "<<data<<endl;
    root->left=createList(root->left);
    cout<<"Enter right of root "<<data<<endl;
    root->right=createList(root->right);

}

pair<bool,int> isSum(node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p=make_pair(true,root->data);
        return p;
    }
    pair<bool,int> leftAns=isSum(root->left);
    pair<bool,int> rightAns=isSum(root->right);

    bool left1=leftAns.first;
    bool right1=rightAns.first;

    bool eq= root->data==leftAns.second+rightAns.second;

    pair<bool,int> ans;
    if(left1 && right1 && eq){
        ans.first=true;
        ans.second=2*root->data;
    }
    else{
        ans.first=false;
    }
    return ans;
}

int main(){
    node* root=createList(root);
    cout<<isSum(root).first<<endl;
}