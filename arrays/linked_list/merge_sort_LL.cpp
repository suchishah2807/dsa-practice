#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next; //pointer to the next element
    
    public:
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr; //for the last element the pointer of next element is null pointer
    }
};

Node* convertarrtoLL(vector <int> &arr){
    Node* head = new Node(arr[0]); // creates a new node with value of arr[0] and next=null pointer
    Node* mover = head; //this is a pointer that tranverses through array
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* merge_sorted_LL(Node* head1, Node* head2){
    Node* newhead = new Node(0);
    Node* temp = newhead;
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while(ptr1 && ptr2){
        if(ptr1->data > ptr2->data){
            temp->next = ptr2;
            temp = ptr2;
            ptr2 = ptr2->next;
        }
        else{
            temp->next = ptr1;
            temp = ptr1;
            ptr1 = ptr1->next;
        }
    }
    if(ptr1) temp->next = ptr1;
    if(ptr2) temp->next = ptr2;

    return newhead->next;
}
Node* merge(Node* head){
    if(!head || !head->next) return head;
    Node* h1 = head;
    Node* h2 = head;
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    h2 = slow->next;
    slow->next = nullptr;
    Node* head1 = merge(h1);
    Node* head2 = merge(h2);
    return merge_sorted_LL(head1, head2);
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<< head->data <<" ";
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}