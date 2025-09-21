// Link : https://www.naukri.com/code360/problems/largest-rectangle-in-a-histogram_1058184?leftPanelTabValue=SUBMISSION

int largestRectangle(vector < int > & heights) {
  int n=heights.size();
  int maxi=-1e9;
  for(int i=0;i<n;i++){
    // expand left
    int left=i;
    while(left>0 && heights[left-1]>=heights[i]) left--;
    // expand right
    int right=i;
    while(right<n-1 && heights[right+1]>=heights[i]) right++;
    int width=right-left+1;
    maxi=max(maxi,heights[i]*width);
  }
  return maxi;
}


// optimal solution:
#include<bits/stdc++.h>
int largestRectangle(vector < int > & heights) {
  int n=heights.size();
  int maxi=-1e9;
  stack<int>st;
  for(int i=0;i<=n;i++){
    int h=(i==n ? 0:heights[i]);
    while(!st.empty() && h<heights[st.top()]){
      int height=heights[st.top()];
      st.pop();
      int right=i;
      int left=st.empty()? -1 : st.top();
      int width=right-left-1;
      maxi=max(maxi,height*width);

    }
    st.push(i);
  }
  return maxi;
}
