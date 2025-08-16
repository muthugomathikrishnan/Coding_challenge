// Link :https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

// Sol 1 : using stack
class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        stack<char>st;
        for(char c:s){
            if(!st.empty() && (st.top()=='(' && c==')'))
            {
                st.pop();
                continue;
            }
            else st.push(c);
        }

        while(!st.empty()){
            count++;
            st.pop();
        }
        return count;
    }
};


// Sol 2:without stack
class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0,open=0;
        for(char c:s){
            if(c=='(') open++;
            else if(c==')'){
                if(open>0) open--;
                else count++;
            }
            }
        return count+open;
    }
};
