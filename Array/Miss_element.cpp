// Link :https://www.naukri.com/code360/problems/missing-number_6680467?leftPanelTabValue=SUBMISSION
int missingNumber(vector<int>&a, int N) {
    vector<int>freq(N+1,0);
    for(int i:a) freq[i]++;
    for(int i=1;i<=N;i++){ if(freq[i]==0) return i; }
    return -1;

}
