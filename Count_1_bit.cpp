// Link  :https://www.geeksforgeeks.org/problems/set-bits0143/1
class Solution {
  public:
    int setBits(int n) {
       int count=0;
       while(n){
           n&=n-1;
           count++;
       }
       return count;
        
    }
};
