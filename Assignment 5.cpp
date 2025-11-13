#include <iostream>
Using namespace std;

Struct Node {
    Int data;
    Node* next;
    Node(int v){ data = v; next = NULL; }
};

Node* head = NULL;

Void insertBegin(int v){
    Node* t = new Node(v);
    t->next = head;
    head = t;
}

Void insertEnd(int v){
    Node* t = new Node(v);
    If(!head){ head = t; return; }
    Node* p = head;
    While(p->next) p = p->next;
    p->next = t;
}

Void insertAfterValue(int val, int v){
    Node* p = head;
    While(p && p->data != val) p = p->next;
    If(p){
        Node* t = new Node(v);
        t->next = p->next;
        p->next = t;
    }
}

Void insertBeforeValue(int val, int v){
    If(!head) return;
    If(head->data == val){ insertBegin(v); return; }
    Node* p = head;
    While(p->next && p->next->data != val) p = p->next;
    If(p->next){
        Node* t = new Node(v);
        t->next = p->next;
        p->next = t;
    }
}

Void deleteBegin(){
    If(!head) return;
    Node* t = head;
    Head = head->next;
    Delete t;
}

Void deleteEnd(){
    If(!head) return;
    If(!head->next){ delete head; head = NULL; return; }
    Node* p = head;
    While(p->next->next) p = p->next;
    Delete p->next;
    p->next = NULL;
}

Void deleteValue(int val){
    If(!head) return;
    If(head->data == val){ deleteBegin(); return; }
    Node* p = head;
    While(p->next && p->next->data != val) p = p->next;
    If(p->next){
        Node* t = p->next;
        p->next = p->next->next;
        delete t;
    }
}

Void searchNode(int val){
    Node* p = head; int pos = 1;
    While(p){
        If(p->data == val){ cout<<val<<” found at position “<<pos<<endl; return; }
        Pos++; p = p->next;
    }
    Cout<<”Not found\n”;
}

Void display(){
    Node* p = head;
    While(p){ cout<<p->data<<”->”; p = p->next; }
    Cout<<”NULL\n”;
}

Int countAndDeleteOccurrences(int key){
    Int cnt = 0;
    While(head && head->data == key){ cnt++; deleteBegin(); }
    Node* p = head;
    While(p && p->next){
        If(p->next->data == key){
            Cnt++;
            Node* t = p->next;
            p->next = p->next->next;
            delete t;
        } else p = p->next;
    }
    Return cnt;
}

Int findMiddle(){
    Node *s = head, *f = head;
    While(f && f->next){
        S = s->next;
        F = f->next->next;
    }
    Return s ? s->data : -1;
}

Void reverseList(){
    Node *prev = NULL, *cur = head, *nxt;
    While(cur){
        Nxt = cur->next;
        Cur->next = prev;
        Prev = cur;
        Cur = nxt;
    }
    Head = prev;
}

Int main(){
    Int ch,v,x,pos,key;
    Do{
        Cout<<”\n1 Insert Begin\n2 Insert End\n3 Insert Before Value\n4 Insert After Value\n5 Delete Begin\n6 Delete End\n7 Delete Value\n8 Search\n9 Display\n10 Count & Delete Key\n11 Find Middle\n12 Reverse\n0 Exit\n”;
        Cin>>ch;
        If(ch==1){ cin>>v; insertBegin(v); }
        Else if(ch==2){ cin>>v; insertEnd(v); }
        Else if(ch==3){ cin>>x>>v; insertBeforeValue(x,v); }
        Else if(ch==4){ cin>>x>>v; insertAfterValue(x,v); }
        Else if(ch==5){ deleteBegin(); }
        Else if(ch==6){ deleteEnd(); }
        Else if(ch==7){ cin>>v; deleteValue(v); }
        Else if(ch==8){ cin>>v; searchNode(v); }
        Else if(ch==9){ display(); }
        Else if(ch==10){ cin>>key; cout<<countAndDeleteOccurrences(key)<<endl; }
        Else if(ch==11){ cout<<findMiddle()<<endl; }
        Else if(ch==12){ reverseList(); }
    }while(ch!=0);
}



