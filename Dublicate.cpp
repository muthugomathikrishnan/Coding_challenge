// Link :

// sol 1: using set
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(int n: nums){
            if(st.find(n)!=st.end()) return true;
            else st.insert(n);
        }
        return false;
    }
};

// TC -> O(N)
// SC -> O(N)

// Sol 2
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
            if (freq[n] == 2) return true;
        }
        return false;
    }
};
