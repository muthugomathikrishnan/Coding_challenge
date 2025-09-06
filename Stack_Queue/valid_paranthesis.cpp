// Link : https://www.naukri.com/code360/problems/valid-parenthesis_795104?leftPanelTabValue=SUBMISSION
bool isValidParenthesis(string s)
{
    stack<char> st;
    for (char c : s) {
        if(c=='{' || c=='[' || c=='(') st.push(c);
        else{
            if(st.empty()) return 0;
            if((st.top()=='(' && c==')') || (st.top()=='{' && c=='}') 
            || (st.top()=='[' && c==']') ) st.pop();
            else return 0;
        }

    }
    return st.empty();  // ? concise return
}
