// Link : https://www.naukri.com/code360/problems/maximum-of-all-subarrays-of-size-k_1170789?leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h> 
vector<int> maxOfSubarray(vector<int> nums, int n, int k) 
{
	if(n<k) return {};
	deque<int>dq;
	vector<int>ans;

	for(int i=0;i<n;i++){
		if(!dq.empty() && dq.front()<=i-k) dq.pop_front();
		while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();
		dq.push_back(i);
		if(i>=k-1) 
			ans.push_back(nums[dq.front()]);
	}
	return ans;
}
