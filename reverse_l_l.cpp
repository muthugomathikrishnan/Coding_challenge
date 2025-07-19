//link :https://leetcode.com/problems/reverse-linked-list/

// Solution 1: using stack



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        stack<int>st;
        ListNode * temp=head;
        while(temp) {st.push(temp->val); temp=temp->next;}
        temp=head;
        while(!st.empty()){ temp->val=st.top();st.pop();temp=temp->next;}
        return head;
    }
};

// TC -> O(N)
// SC -> O(N)


// Sol 2: Iteration method


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode * curr=head, *prev=nullptr,*N;
        while(curr){
            N=curr->next;
            curr->next=prev;
            prev=curr;
            curr=N;
        }
        head=prev;
        return head; // or return prev
    }
};

// TC -> O(N)
// SC -> O(1)
