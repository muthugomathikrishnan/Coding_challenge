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



// sol :

// Stack class.
class Stack {
    vector<int>ans;
    int s,i;
public:
    
    Stack(int capacity) {
        s=capacity;
        i=0;
    }

    void push(int num) {
        if(i<s){
            ans.push_back(num);
            i++;
        }
    }

    int pop() {
        if(!ans.empty()){
            int r=ans.back();
            ans.pop_back();
            i--;
            return r;
        }
        return -1;
    }
    
    int top() {
        if(!ans.empty()) return ans.back();
        return -1;
    }
    
    int isEmpty() {
        return ans.empty();
    }
    
    int isFull() {
        return i==s;
    }
    
};
