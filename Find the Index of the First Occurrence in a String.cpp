// Liink :

class Solution {
public:
    int strStr(string h, string n) {
        int l1=h.size();
        int l2=n.size();
        if(l1<l2) return -1;
        for(int i=0;i<l1;i++){
            if(h[i]==n[0]){
                bool flag=1;
                for(int j=0;j<l2;j++){
                        if(h[i+j]!=n[j]){ flag=0; break;}
                }
            if(flag) return i;
            }
        }        
        return -1;
    }
};
