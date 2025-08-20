// Link :https://www.naukri.com/code360/problems/maximum-time_2239060?leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
double maxTime(int n, int speed, vector<vector<int>> &locations)
{
 double max_t=0.0;
 for(int i=0;i<n;i++){
     for(int j=i+1;j<n;j++){
         double dx=locations[i][0]-locations[j][0];
         double dy=locations[i][1]-locations[j][1];
         double dis=sqrt(dx*dx +dy*dy);
         double time=dis/speed;
         max_t=max(max_t,time);
     }
 }
 return max_t;
}
