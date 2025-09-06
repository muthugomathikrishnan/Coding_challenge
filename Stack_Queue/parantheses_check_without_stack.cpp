// Link : https://www.naukri.com/code360/problems/valid-parenthesis_795104?leftPanelTabValue=SUBMISSION
bool ismatch(char c1,char c2){
    return (c1=='(' && c2==')') || (c1=='[' && c2==']') || (c1=='{' && c2=='}');
}

bool isValidParenthesis(string s)
{
    int top=-1;
    int l=s.length();
    for(int i=0;i<l;i++){
        if(top<0 || !ismatch(s[top],s[i]) ){
            top++;
            s[top]=s[i];
        }
        else top--;
    }
    return top==-1;
}
