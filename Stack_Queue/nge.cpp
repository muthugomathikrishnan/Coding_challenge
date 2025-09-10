// Link :
vector<int> countGreater(vector<int>&arr, vector<int>&query) {
    int q1=query.size();
    vector<int>ans;
    for(int i: query){
        int cnt=0;
        for(int j=i+1;j<arr.size();j++)
            if(arr[j]>arr[i]) cnt++;
        ans.push_back(cnt);
    }
    return ans;
}
