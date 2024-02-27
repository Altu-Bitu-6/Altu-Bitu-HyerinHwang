#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkParentheses(const string& input) {
    stack<char> s;
    for (char c : input) {
        if ((c == '(') || (c == '[')) {
            s.push(c);
        } else if (c == ')') {
            if (!s.empty() && s.top() == '(') {
                s.pop();
            } else {
                return false;
            }
        } else if (c == ']') {
            if (!s.empty() && s.top() == '[') {
                s.pop();
            } else {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    while (true) {
        string input;
        getline(cin, input);

        if (input == ".") {
            break;
        }

        if (checkParentheses(input)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
