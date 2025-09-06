// Link : https://www.naukri.com/code360/problems/postfix-to-infix_8382386?leftPanelTabValue=SUBMISSION

bool isOperator(char c){
    return (c=='^' || c=='*' || c=='/' || c=='+' || c=='-');
}

string postToInfix(string s) {
    stack<string>st;
    for(char c:s){
        if(isOperator(c)){
            string s1=st.top(); st.pop();
            string s2=st.top(); st.pop();
            string temp="(" + s2+ c + s1+")";
            st.push(temp);
        }
        else st.push(string(1,c));
    }
    return st.top(); 
}
