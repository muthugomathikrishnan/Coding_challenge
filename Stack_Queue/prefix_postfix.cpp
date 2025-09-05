// Link : https://www.naukri.com/code360/problems/convert-prefix-to-postfix_8391014

bool opreator(char c){
	return (c=='^' || c=='*' || c=='/' || c=='+' || c=='-');
}
string preToPost(string s){
	stack<string>st;
	int n=s.length();
	for(int i=n-1;i>=0;i--){
		if( opreator(s[i]) ){
			string s1=st.top(); st.pop();
			string s2=st.top(); st.pop();
			string temp=s1+s2+s[i];
			st.push(temp);	
		}

		else st.push(string(1,s[i]));
	}
	return st.top();	
}

