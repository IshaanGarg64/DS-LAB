#include <iostream>
using namespace std;

class stack{
    int arr[1000];
    int top;
public:
    stack(){ top = -1; } // constructor initializes empty Stack

    void push(int x){
        if(top == 999){
            cout << "Stack Overflow! " << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " is pushed " << endl;
    }

    void pop(){
        if(top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;  // just move the pointer down
        cout << "popped from stack\n";
    }

    int Top(){
        if(top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        cout<< "Peek Element is : "<<arr[top]<<endl;
    }

    bool empty(){
        return top == -1;
    }
    bool isFull() {
        return top == 1000 - 1;
    }
    // (v) Display stack elements
    void display() {
        if (empty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main(){
    stack s;
    int choice, value;

    do {
        cout << "\n------ Stack Menu ------" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                if (s.empty())
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;

            case 4:
                if (s.isFull())
                    cout << "Stack is full." << endl;
                else
                    cout << "Stack is not full." << endl;
                break;

            case 5:
                s.display();
                break;

            case 6:
                s.Top();
                break;

            case 7:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while(choice != 7);

    return 0;
}


