// Link : https://www.naukri.com/code360/problems/min-stack_3843991?leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h> 
class minStack
{
	stack<pair<int,int>>st;
	int mini;
	
	public:
		
		minStack() 
		{ 
			while(!st.empty()) st.pop();
			mini=INT_MAX;
		}
		
		void push(int num)
		{
			if(st.empty()) mini=num;
			else mini=min(num,st.top().second);
			st.push({num,mini});
		}
		
		int pop()
		{
			if(st.empty()) return -1;
			int n=st.top().first;
			st.pop();

			return n;

		}
		
		int top()
		{
		if(!st.empty()) return st.top().first;
		return -1;
		}
		
		int getMin()
		{
		if(!st.empty()) return st.top().second;
		return -1;
		}
};
