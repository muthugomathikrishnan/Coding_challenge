// Link : https://leetcode.com/problems/move-zeroes/submissions/1298641939/
void pushZerosAtEnd(vector<int> &arr) 
{
	int left=0;
	for(int r=0;r<arr.size();r++){
		if(arr[r]!=0){
			swap(arr[r],arr[left]);
			left++;
		}
	}
}
