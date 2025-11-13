// Write a program for the evaluation of a Postfix expression
#include <iostream>
#include <stack>
#include <cctype>  // for isdigit()
#include <cmath>   // for pow()
using namespace std;
// Function to evaluate postfix expression
int evaluatePostfix(string expr) {
    stack<int> st;
    for (char c : expr) {
        // If character is whitespace, skip it
        if (c == ' ') continue;
        // If operand (single digit for simplicity)
        if (isdigit(c)) {
            st.push(c - '0');  // convert char to int
        }
        else {
            // Operator: pop two operands
            int op2 = st.top(); st.pop(); // second operand
            int op1 = st.top(); st.pop(); // first operand
            int result;
            switch (c) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
                default: 
                    cout << "Invalid operator: " << c << endl;
                    return -1;
            }
            // Push result back
            st.push(result);
        }
    }
    // Final result
    return st.top();
}
int main() {
    string postfix;  // Example: (2+3)*5
    cout<<"Enter Postfix Expression: ";
    getline(cin, postfix);
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Evaluated Result = " << evaluatePostfix(postfix) << endl;

    return 0;
}

