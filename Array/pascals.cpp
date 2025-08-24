// Link :https://www.naukri.com/code360/problems/pascal-s-triangle_1089580?leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  if(n==1) return {{1}};
  vector<vector<long long int>>res;
  for(int i=0;i<n;i++){
    vector<long long int>a1(i+1,1);
    for(int j=1;j<i;j++){
        a1[j]=res[i-1][j-1] + res[i-1][j];
    }
    res.push_back(a1);
  }
  return res;
}
