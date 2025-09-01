// Link : https://www.naukri.com/code360/problems/stack-using-queue_795152?leftPanelTabValue=SUBMISSION

class Stack {
	queue<int>q;

   public:
    Stack() {  }

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }

    void push(int x) {
        q.push(x);
        int n=getSize();
        for(int i=0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(isEmpty()) return -1;
        int r=q.front();
        q.pop();
        return r;
    }

    int top() {
        if(isEmpty()) return -1;
        return q.front();
    }
};
