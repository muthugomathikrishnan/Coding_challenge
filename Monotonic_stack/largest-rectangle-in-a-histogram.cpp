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
