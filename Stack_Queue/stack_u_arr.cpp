// link : https://www.geeksforgeeks.org/problems/implement-stack-using-array/1
class MyStack {
  vector<int>ans;
  public:
    void push(int x) {
        ans.push_back(x);
    }

    int pop() {
        if(!ans.empty()){
            int r=ans.back();
            ans.pop_back();
            return r;
        }
        return -1;
        
    }
};

