#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

#define SIZE 5

// 1) Simple Queue
class Queue {
    int arr[SIZE], front, rear;
public:
    Queue() { front = -1; rear = -1; }
    bool isFull() { return rear == SIZE - 1; }
    bool isEmpty() { return front == -1 || front > rear; }
    void enqueue(int val) {
        if (isFull()) cout << "Queue Full\n";
        else { if (front == -1) front = 0; arr[++rear] = val; }
    }
    void dequeue() {
        if (isEmpty()) cout << "Queue Empty\n";
        else front++;
    }
    void peek() {
        if (isEmpty()) cout << "Queue Empty\n";
        else cout << arr[front] << endl;
    }
    void display() {
        if (isEmpty()) cout << "Queue Empty\n";
        else for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

// 2) Circular Queue
class CircularQueue {
    int arr[SIZE], front, rear;
public:
    CircularQueue() { front = -1; rear = -1; }
    bool isFull() { return (rear + 1) % SIZE == front; }
    bool isEmpty() { return front == -1; }
    void enqueue(int val) {
        if (isFull()) cout << "Queue Full\n";
        else {
            if (front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            arr[rear] = val;
        }
    }
    void dequeue() {
        if (isEmpty()) cout << "Queue Empty\n";
        else {
            if (front == rear) front = rear = -1;
            else front = (front + 1) % SIZE;
        }
    }
    void peek() {
        if (isEmpty()) cout << "Queue Empty\n";
        else cout << arr[front] << endl;
    }
    void display() {
        if (isEmpty()) cout << "Queue Empty\n";
        else {
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % SIZE;
            }
            cout << endl;
        }
    }
};

// 3) Interleave Queue
void interleaveQueue(queue<int>& q) {
    int n = q.size();
    queue<int> firstHalf;
    for (int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}

// 4) First Non-Repeating Character
void firstNonRepeating(string str) {
    queue<char> q;
    int freq[26] = {0};
    for (char c : str) {
        freq[c - 'a']++;
        q.push(c);
        while (!q.empty() && freq[q.front() - 'a'] > 1) q.pop();
        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
    cout << endl;
}

// 5a) Stack using Two Queues
class StackUsingTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) { q2.push(q1.front()); q1.pop(); }
        swap(q1, q2);
    }
    void pop() {
        if (q1.empty()) cout << "Empty\n";
        else q1.pop();
    }
    void top() {
        if (q1.empty()) cout << "Empty\n";
        else cout << q1.front() << endl;
    }
    bool empty() { return q1.empty(); }
};

// 5b) Stack using One Queue
class StackUsingOneQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) cout << "Empty\n";
        else q.pop();
    }
    void top() {
        if (q.empty()) cout << "Empty\n";
        else cout << q.front() << endl;
    }
    bool empty() { return q.empty(); }
};

int main() {
    cout << "1) Simple Queue\n";
    Queue q1; q1.enqueue(10); q1.enqueue(20); q1.enqueue(30); q1.display(); q1.dequeue(); q1.display(); q1.peek();

    cout << "\n2) Circular Queue\n";
    CircularQueue cq; cq.enqueue(1); cq.enqueue(2); cq.enqueue(3); cq.enqueue(4); cq.display(); cq.dequeue(); cq.display(); cq.peek();

    cout << "\n3) Interleave Queue\n";
    queue<int> q; q.push(4); q.push(7); q.push(11); q.push(20); q.push(5); q.push(9);
    interleaveQueue(q);
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    cout << endl;

    cout << "\n4) First Non-Repeating Character\n";
    firstNonRepeating("aabc");

    cout << "\n5a) Stack using Two Queues\n";
    StackUsingTwoQueues s1; s1.push(10); s1.push(20); s1.push(30); s1.top(); s1.pop(); s1.top();

    cout << "\n5b) Stack using One Queue\n";
    StackUsingOneQueue s2; s2.push(5); s2.push(15); s2.push(25); s2.top(); s2.pop(); s2.top();
}
