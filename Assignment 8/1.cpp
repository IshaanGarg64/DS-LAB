#include <bits/stdc++.h>
using namespace std;
struct Node{
    int v; Node *l,*r;
    Node(int x){v=x;l=r=nullptr;}
};
void preorder(Node* root){ if(!root)return; cout<<root->v<<" "; preorder(root->l); preorder(root->r); }
void inorder(Node* root){ if(!root)return; inorder(root->l); cout<<root->v<<" "; inorder(root->r); }
void postorder(Node* root){ if(!root)return; postorder(root->l); postorder(root->r); cout<<root->v<<" "; }
int main(){
    Node* root=new Node(1);
    root->l=new Node(2);
    root->r=new Node(3);
    root->l->l=new Node(4);
    root->l->r=new Node(5);
    preorder(root);
    cout<<"\n";
    inorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";
    return 0;
}
