#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(NULL), next(NULL) {}
};

// Circular Linked List Node
struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(NULL) {}
};

// Doubly Linked List Operations
class DoublyLinkedList {
public:
    DNode* head = NULL;

    void insertFirst(int val) {
        DNode* node = new DNode(val);
        if (!head) head = node;
        else { node->next = head; head->prev = node; head = node; }
    }

    void insertLast(int val) {
        DNode* node = new DNode(val);
        if (!head) { head = node; return; }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = node;
        node->prev = temp;
    }

    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        DNode* node = new DNode(val);
        node->next = temp->next;
        node->prev = temp;
        if (temp->next) temp->next->prev = node;
        temp->next = node;
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) { insertFirst(val); return; }
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        DNode* node = new DNode(val);
        node->prev = temp->prev;
        node->next = temp;
        temp->prev->next = node;
        temp->prev = node;
    }

    void deleteNode(int key) {
        if (!head) return;
        DNode* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
    }

    void search(int key) {
        int pos = 1;
        DNode* temp = head;
        while (temp) {
            if (temp->data == key) { cout << "Found at position " << pos << endl; return; }
            temp = temp->next; pos++;
        }
        cout << "Not Found\n";
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int size() {
        int cnt = 0;
        DNode* temp = head;
        while (temp) { cnt++; temp = temp->next; }
        return cnt;
    }

    bool isPalindrome() {
        if (!head) return true;
        DNode* start = head, *end = head;
        while (end->next) end = end->next;
        while (start && end && start != end && end->next != start) {
            if (start->data != end->data) return false;
            start = start->next;
            end = end->prev;
        }
        return true;
    }

    DNode* reverseInGroups(DNode* head, int k) {
        DNode* curr = head;
        DNode* prev = NULL;
        DNode* next = NULL;
        int count = 0;
        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            curr->prev = next;
            prev = curr;
            curr = next;
            count++;
        }
        if (next) head->next = reverseInGroups(next, k);
        if (head->next) head->next->prev = head;
        return prev;
    }
};

// Circular Linked List Operations
class CircularLinkedList {
public:
    CNode* head = NULL;

    void insertFirst(int val) {
        CNode* node = new CNode(val);
        if (!head) {
            head = node;
            node->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        node->next = head;
        temp->next = node;
        head = node;
    }

    void insertLast(int val) {
        CNode* node = new CNode(val);
        if (!head) { head = node; node->next = head; return; }
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = node;
        node->next = head;
    }

    void deleteNode(int key) {
        if (!head) return;
        CNode *curr = head, *prev = NULL;
        while (curr->data != key) {
            if (curr->next == head) return;
            prev = curr;
            curr = curr->next;
        }
        if (curr == head && curr->next == head) { head = NULL; return; }
        if (curr == head) {
            prev = head;
            while (prev->next != head) prev = prev->next;
            head = head->next;
            prev->next = head;
        } else if (curr->next == head) prev->next = head;
        else prev->next = curr->next;
        delete curr;
    }

    void display() {
        if (!head) return;
        CNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl; // repeat head at end
    }

    int size() {
        if (!head) return 0;
        int cnt = 0;
        CNode* temp = head;
        do { cnt++; temp = temp->next; } while (temp != head);
        return cnt;
    }

    bool isCircular() {
        if (!head) return false;
        CNode* temp = head->next;
        while (temp && temp != head) temp = temp->next;
        return (temp == head);
    }

    void splitList(CNode*& head1, CNode*& head2) {
        if (!head) return;
        CNode* slow = head;
        CNode* fast = head;
        while (fast->next != head && fast->next->next != head) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next->next == head) fast = fast->next;
        head1 = head;
        if (head->next != head) head2 = slow->next;
        fast->next = slow->next;
        slow->next = head;
    }
};

// Parity Helper
int parity(int x) {
    int c = 0;
    while (x) { if (x & 1) c++; x >>= 1; }
    return c;
}

// Remove Even Parity Nodes
void removeEvenParity(DoublyLinkedList& dll, CircularLinkedList& cll) {
    DNode* tempD = dll.head;
    while (tempD) {
        if (parity(tempD->data) % 2 == 0) {
            DNode* next = tempD->next;
            dll.deleteNode(tempD->data);
            tempD = next;
        } else tempD = tempD->next;
    }
    if (!cll.head) return;
    CNode* curr = cll.head;
    do {
        if (parity(curr->data) % 2 == 0)
            cll.deleteNode(curr->data);
        curr = curr->next;
    } while (curr != cll.head);
}

// 2D Matrix to Doubly Linked List
struct DMatrixNode {
    int data;
    DMatrixNode *right, *down, *left, *up;
    DMatrixNode(int val) : data(val), right(NULL), down(NULL), left(NULL), up(NULL) {}
};

DMatrixNode* constructDLLFromMatrix(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<DMatrixNode*>> nodes(n, vector<DMatrixNode*>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            nodes[i][j] = new DMatrixNode(mat[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (j + 1 < m) nodes[i][j]->right = nodes[i][j + 1];
            if (j - 1 >= 0) nodes[i][j]->left = nodes[i][j - 1];
            if (i + 1 < n) nodes[i][j]->down = nodes[i + 1][j];
            if (i - 1 >= 0) nodes[i][j]->up = nodes[i - 1][j];
        }
    return nodes[0][0];
}

int main() {
    DoublyLinkedList dll;
    dll.insertLast(1);
    dll.insertLast(2);
    dll.insertLast(3);
    dll.insertLast(2);
    dll.insertLast(1);
    cout << (dll.isPalindrome() ? "True" : "False") << endl;
}
