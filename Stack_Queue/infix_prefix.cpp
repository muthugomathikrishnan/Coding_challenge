// link : https://www.geeksforgeeks.org/problems/infix-to-prefix-notation/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    bool isOperand(char c) {
        return ( (c >= 'a' && c <= 'z') ||
                 (c >= 'A' && c <= 'Z') ||
                 (c >= '0' && c <= '9') );
    }

    int prec(char c) {
        if (c == '^') return 3;
        else if (c == '*' || c == '/') return 2;
        else if (c == '+' || c == '-') return 1;
        return -1;
    }

  public:
    string infixToPrefix(string s) {
        // Step 1: reverse string
        reverse(s.begin(), s.end());

        // Step 2: swap brackets
        for (char &c : s) {
            if (c == '(') c = ')';
            else if (c == ')') c = '(';
        }

        // Step 3: infix → postfix
        stack<char> st;
        string res;

        for (char c : s) {
            if (isOperand(c)) {
                res += c;
            }
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
            }
            else if (isOperator(c)) {
                while (!st.empty() &&
                      ((prec(c) < prec(st.top())) ||
                       (prec(c) == prec(st.top()) && c != '^'))) {
                    res += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        // Step 4: reverse result to get prefix
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    string exp = "(a-b/c)*(a/k-l)";
    cout << sol.infixToPrefix(exp) << endl;
    return 0;
}
