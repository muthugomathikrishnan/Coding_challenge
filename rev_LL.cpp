// Link :https://www.naukri.com/code360/problems/reverse-linked-list_920513?leftPanelTabValue=SUBMISSION


Node* reverseLinkedList(Node *head)
{
    Node * prev=NULL,*curr=head;
    while(curr){
        Node * next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
