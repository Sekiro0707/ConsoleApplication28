#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool ismatz(char optim, char cols) {
    return (optim == '(' && cols == ')') ||
        (optim == '{' && cols == '}') ||
        (optim == '[' && cols == ']');
}

void chalsn(const string& str) {
    stack<char> brac;
    stack<int> post;
    int ertugint = -1;

    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            brac.push(ch);
            post.push(i);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (brac.empty() || !ismatz(brac.top(), ch)) {
                ertugint = i;
                break;
            }
            else {
                brac.pop();
                post.pop();
            }
        }
        else if (ch == ';') {
            break;
        }
    }

    if (ertugint == -1 && brac.empty()) {
        cout << "The line is correct!" << endl;
    }
    else {
        if (ertugint == -1 && !brac.empty()) {
            ertugint = post.top();
        }

        cout << "The line contains an error: ";
        for (int i = 0; i <= ertugint; ++i) {
            cout << str[i];
        }
        cout << endl;
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    chalsn(input);
    return 0;
}
