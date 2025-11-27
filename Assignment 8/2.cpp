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
Node* searchRec(Node* root,int x){
    if(!root||root->v==x) return root;
    if(x<root->v) return searchRec(root->l,x);
    return searchRec(root->r,x);
}
Node* searchNonRec(Node* root,int x){
    while(root){
        if(root->v==x) return root;
        root=(x<root->v)?root->l:root->r;
    }
    return nullptr;
}
Node* minNode(Node* root){ while(root&&root->l) root=root->l; return root; }
Node* maxNode(Node* root){ while(root&&root->r) root=root->r; return root; }
Node* succ(Node* root,Node* x){
    if(x->r) return minNode(x->r);
    Node* succ=nullptr;
    while(root){
        if(x->v<root->v){ succ=root; root=root->l; }
        else if(x->v>root->v) root=root->r;
        else break;
    }
    return succ;
}
Node* pred(Node* root,Node* x){
    if(x->l) return maxNode(x->l);
    Node* pred=nullptr;
    while(root){
        if(x->v>root->v){ pred=root; root=root->r; }
        else if(x->v<root->v) root=root->l;
        else break;
    }
    return pred;
}
int main(){
    Node* root=nullptr;
    vector<int> a={20,10,30,5,15,25,35};
    for(int x:a) root=insert(root,x);
    int key;cin>>key;
    Node* x=searchRec(root,key);
    if(x) cout<<"Found\n"; else cout<<"Not Found\n";
    x=searchNonRec(root,key);
    if(x) cout<<"Found\n"; else cout<<"Not Found\n";
    cout<<minNode(root)->v<<"\n";
    cout<<maxNode(root)->v<<"\n";
    Node* s=succ(root,searchRec(root,key));
    if(s) cout<<s->v<<"\n"; else cout<<"No Successor\n";
    Node* p=pred(root,searchRec(root,key));
    if(p) cout<<p->v<<"\n"; else cout<<"No Predecessor\n";
    return 0;
}
