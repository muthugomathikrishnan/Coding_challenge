// Link : https://www.naukri.com/code360/problems/implement-queue-using-linked-list_8161235?leftPanelTabValue=SUBMISSION

/**
 * Definition of linked list
 * class Node {
 * 
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 * 
 * Definition of Queue
 * struct Queue {
 *   Node* front;
 *   Node* rear;
 *   void push(int);
 *   int pop();
 *   
 *   Queue() {
 *       front = rear = NULL;
 *   }
 * };
 */

void Queue::push(int x) {
    Node * temp=new Node(x);
    if(front==nullptr){
        front=temp;
        rear=temp;
    }
    else {
        rear->next=temp;
        rear=temp;
    }
}

int Queue::pop() {
    if(front==nullptr) return -1;
    Node * temp=front;
    front=front->next;
    int val=temp->data;
    delete temp;
    return val;
}   
