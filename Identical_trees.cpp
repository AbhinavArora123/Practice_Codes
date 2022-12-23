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

bool identical(node* root1,node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1!=NULL && root2==NULL){
        return false;
    }
    if(root1==NULL && root2!=NULL){
        return false;
    }
    bool left=identical(root1->left,root2->left);
    bool right=identical(root1->right,root2->right);
    bool ans= root1->data==root2->data;

    if(left && right && ans){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    node* root1=createList(root1);
    node* root2=createList(root2);

    cout<<identical(root1,root2)<<endl;
    return 0;
}