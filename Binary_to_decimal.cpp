// Link :https://www.geeksforgeeks.org/problems/binary-number-to-decimal-number3525/1

// Sol 1:  Using Bitwise Shift

class Solution {
  public:
    int binaryToDecimal(string &b) {
        int ans=0;
        int power=0;
        for(int i=b.length()-1;i>=0;i--){
            if(b[i]=='1') ans+=(1<<power);
            power++;
        }
        return ans;
    }
};

// TC -> O(N)
// SC -> O(1)
