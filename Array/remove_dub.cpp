// Link : https://www.naukri.com/code360/problems/remove-duplicates-from-sorted-array_1102307?leftPanelTabValue=SUBMISSION
int removeDuplicates(vector<int> &arr, int n) {
	int c=0;
	for(int i=1;i<n;i++){
		if(arr[i]==arr[i-1]) {c++; arr[i-1]=arr[i];} 
	}
	return n-c;
}
