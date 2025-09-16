// Link : https://leetcode.com/problems/minimum-moves-to-capture-the-queen/submissions/1772679896/
class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
      int rook=2,bishop=2;
      if(a==e || b==f){
        if(a==e and c==a){
            if(b>d && d>f) return 2;
            if(b<d && d<f) return 2;
        }
        else if(b==f and d==b){
            if(a>c && c>e) return 2;
            if(a<c && c<e) return 2;
        }
      rook=1;
      }
      
      if(abs(c-e)==abs(d-f)){
        if(abs(a-c)==abs(b-d)){
            if(a>c && a<e){
                if(d>b && b>f) return 2;
                if(d<b && b<f) return 2;
            }

            if(c>a && a>e){
                if(d>b && b>f) return 2;
                if(d<b && b<f) return 2;
            }
        }
       bishop=1;
      }
     
      return min(bishop,rook);
    }
};
