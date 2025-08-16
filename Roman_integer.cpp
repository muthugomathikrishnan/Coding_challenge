// Link : https://leetcode.com/problems/roman-to-integer/submissions/1737512694/

// Sol 1 :
class Solution {
private:
    int char_num(char a){
        switch(a){
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default  : return 0;
        }
    }
public:
    int romanToInt(string s) {
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(i+1<n && char_num(s[i])<char_num(s[i+1]))
                ans-=char_num(s[i]);
            else 
                ans+=char_num(s[i]);
        }
        return ans;
    }
};
