// Link : https://www.naukri.com/code360/problems/occurs-once_1214969?leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h> 
int occursOnce(vector<int> &a, int n){
	int res=0;
	for(int n: a) res^=n;
	return res; 
}
