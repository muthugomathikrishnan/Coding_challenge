// link :https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue {
    stack<int>input,output;
public:
    MyQueue() {
    }
    
    void push(int x) {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        input.push(x);
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }
    
    int pop() {
        if(input.empty()) return -1;
        int val=input.top();
        input.pop();
        return val;
    }
    
    int peek() {
        if(input.empty()) return -1;
        return input.top();
    }
    
    bool empty() {
        if(!input.empty()) return 0;
        return 1;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
