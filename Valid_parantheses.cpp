// Link :

// sol 1 : using stack 
class Solution {
public:
    bool isValid(string s) {
     stack<char>st;
     for(char c : s){
        if(c=='(' || c=='{' || c=='[') st.push(c);
        else{
            if(st.empty()) return false;
            else {
                char top=st.top();
                if(   (top=='(' && c==')')  || 
                      (top=='{' && c=='}')  ||
                      (top=='[' && c==']') )
                      st.pop();
                else return false;
            }
        }
     }
    return st.empty()? true : false;
        
    }
};


// TC -> O(N)
// SC -> O(N)


// Sol 2 : without stack 

class Solution {

private:
    bool Ismatch(char c1, char c2){
        if( (c1=='(' && c2==')') ||
            (c1=='{' && c2=='}') ||
            (c1=='[' && c2==']')  ) return true;
        return false;
    }
public:
    bool isValid(string s) {
     int top=-1;
     int n=s.length();

     for(int i=0;i<n;i++){

        if(top<0 || !Ismatch(s[top],s[i])){
            top++;
            s[top]=s[i];
        }
        else top--;
     }
     
    return top==-1;
        
    }
};
