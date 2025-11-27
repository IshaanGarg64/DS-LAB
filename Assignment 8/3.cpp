#include <bits/stdc++.h>
using namespace std;
struct Node{
    int v; Node *l,*r;
    Node(int x){v=x;l=r=nullptr;}
};
Node* insert(Node* root,int x){
    if(!root) return new Node(x);
    if(x<root->v) root->l=insert(root->l,x);
    else if(x>root->v) root->r=insert(root->r,x);
    return root;
}
Node* minNode(Node* root){ while(root&&root->l) root=root->l; return root; }
Node* deleteNode(Node* root,int key){
    if(!root) return root;
    if(key<root->v) root->l=deleteNode(root->l,key);
    else if(key>root->v) root->r=deleteNode(root->r,key);
    else{
        if(!root->l){ Node* t=root->r; delete root; return t; }
        else if(!root->r){ Node* t=root->l; delete root; return t; }
        Node* t=minNode(root->r);
        root->v=t->v;
        root->r=deleteNode(root->r,t->v);
    }
    return root;
}
int maxDepth(Node* root){
    if(!root) return 0;
    return 1+max(maxDepth(root->l),maxDepth(root->r));
}
int minDepth(Node* root){
    if(!root) return 0;
    if(!root->l) return 1+minDepth(root->r);
    if(!root->r) return 1+minDepth(root->l);
    return 1+min(minDepth(root->l),minDepth(root->r));
}
void inorder(Node* root){ if(!root)return; inorder(root->l); cout<<root->v<<" "; inorder(root->r); }
int main(){
    Node* root=nullptr;
    vector<int>a={20,10,30,5,15,25,35};
    for(int x:a) root=insert(root,x);
    int del;cin>>del;
    root=deleteNode(root,del);
    inorder(root);
    cout<<"\n"<<maxDepth(root)<<"\n"<<minDepth(root)<<"\n";
    return 0;
}
