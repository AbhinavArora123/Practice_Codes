#include<iostream>
#include<vector>
#include<queue>
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

vector<int> zigzag(node* root){
    vector<int> result;
    if(root==NULL){
        return result;
    }
    queue<node*> q;
    q.push(root);

    bool leftToright=true;

    while(!q.empty()){
        int size=q.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            node* temp=q.front(); //frontnode
            q.pop();

            int index= leftToright? i : size-i-1;
            ans[index]=temp->data;

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        //changing right to left:
        leftToright = !leftToright;
        for(auto i:ans){
            result.push_back(i);
        }
    }
    return result;
}

int main(){
    node* root=createList(root);
    vector<int> a= zigzag(root);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }

    // cout<<zigzag(root)<<endl;
    return 0;
}