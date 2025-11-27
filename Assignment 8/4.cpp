#include <bits/stdc++.h>
using namespace std;
struct Node{
    int v; Node *l,*r;
    Node(int x){v=x;l=r=nullptr;}
};
bool isBST(Node* root,long long minv,long long maxv){
    if(!root) return true;
    if(root->v<=minv||root->v>=maxv) return false;
    return isBST(root->l,minv,root->v)&&isBST(root->r,root->v,maxv);
}
int main(){
    Node* root=new Node(10);
    root->l=new Node(5);
    root->r=new Node(15);
    root->r->l=new Node(12);
    root->r->r=new Node(20);
    if(isBST(root,LLONG_MIN,LLONG_MAX)) cout<<"True\n";
    else cout<<"False\n";
    return 0;
}
