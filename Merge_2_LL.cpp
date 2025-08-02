// Link :https://leetcode.com/problems/merge-two-sorted-lists/submissions/1721032584/?page=1&difficulty=EASY

// Sol 1 : brute force approach

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* create(vector<int>&temp){
        ListNode * dummy=new ListNode(-1);
        ListNode *curr=dummy;
        for(int i=0;i<temp.size();i++){
            curr->next=new ListNode(temp[i]);
            curr=curr->next;
        }
        return dummy->next;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>temp;
        while(list1) {temp.push_back(list1->val); list1=list1->next;}
        while(list2) {temp.push_back(list2->val); list2=list2->next;}
        sort(temp.begin(),temp.end());
        ListNode * head=create(temp);
        return head;
    }
};

// TC -> O((m + n) log(m + n))
// SC -> O(m + n)


// Sol 2 : with out extra space 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * dummy=new ListNode(-1);
        ListNode * temp=dummy;
        while(list1 && list2){
            if(list1->val < list2->val){
                temp->next=list1;
                list1=list1->next;
            }
            else {
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }

        if(list1) { temp->next=list1; list1=list1->next;}
        if(list2)  { temp->next=list2; list2=list2->next;}
        return dummy->next;
    }
};


// TC -> O(M + N)
// SC -> O(1) 
