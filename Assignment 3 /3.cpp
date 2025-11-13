#include <iostream>
#include <stack>
#include <string>
using namespace std;
class solution {
public:
    bool isValid(string expr) {
        stack<char> s;
        for (int i = 0; i < expr.size(); i++) {
            if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {  // opening
                s.push(expr[i]);
            } else {  // closing
                if (s.size() == 0) return false;
                if ((s.top() == '(' && expr[i] == ')') ||
                    (s.top() == '[' && expr[i] == ']') ||
                    (s.top() == '{' && expr[i] == '}')) {
                    s.pop();
                } else {  // no match
                    return false;
                }
            }
        }
        return s.size() == 0;
    }
};

int main() {
    string s;
    cout << "Enter the string : ";
    getline(cin, s);

    solution obj;
    if (obj.isValid(s)) {
        cout << "Balanced !!";
    } else {
        cout << "Not Balanced ";
    }
    return 0;
}