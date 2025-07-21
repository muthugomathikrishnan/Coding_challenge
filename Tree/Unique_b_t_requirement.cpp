
class Solution {
  public:
    bool isPossible(int a, int b) {
        if(a==2 && b==2) return 0;
        return (a==2 || b==2);
        
    }
};

// TC -> O(1)
// SC -> O(1)
