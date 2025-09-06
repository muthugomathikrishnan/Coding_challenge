// Link : https://www.naukri.com/code360/problems/postfix-to-prefix_1788455?leftPanelTabValue=SUBMISSION

#include<bits/stdc++.h>
bool isOperator(char c){
    return (c=='^' || c=='*' || c=='/' || c=='+' || c=='-');
}

string postfixToPrefix(const string &s){
    stack<string> st;
    for(char c : s){
        if(isOperator(c)){
            string s1 = st.top(); st.pop();
            string s2 = st.top(); st.pop();
            string temp = c + s2 + s1; 
            st.push(temp);
        }
        else  st.push(string(1, c));  
    }
    return st.top();
}
