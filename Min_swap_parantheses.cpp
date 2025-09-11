// Link : https://www.naukri.com/code360/problems/minimum-number-of-swaps-for-bracket-balancing_1115682?leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h> 
int miniNumSwaps(string brackets, int n) {
	int cnt_l=0,cnt_r=0;
	int imb=0,swap=0;

	for(char c: brackets){
		if(c=='(') {
			cnt_l++;
			if(imb>0){ 
				swap+=imb;
				imb--;
			}
		}
		else {
			cnt_r++;
			imb=(cnt_r-cnt_l);
		}
	}
	return swap;
}
