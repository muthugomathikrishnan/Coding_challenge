// link : https://www.naukri.com/code360/problems/day-23-:-infix-to-postfix-_1382146?leftPanelTabValue=SUBMISSION

#include<bits/stdc++.h>
using namespace std;

int prec(char c){
	if(c=='^') return 3;
	else if(c=='*' || c=='/') return 2;
	else if(c=='+' || c=='-') return 1;
	return -1;
}

string infixToPostfix(string exp){
	stack<char>st;
	string res;
	for(char c: exp){
		if((c>='a'&& c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
			res+=c;
		else if(c=='(') st.push('(');
		else if(c==')'){
			while(st.top()!='('){
				res+=st.top();
				st.pop();
			}
			st.pop();
		}

		else {
			while(!st.empty() && prec(c)<=prec(st.top())){
				res+=st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while(!st.empty()){
		res+=st.top();
		st.pop();
	}

	return res;
}
